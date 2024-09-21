#include <iostream>
#include <fstream>
#include <vector>
#include <string>
#include <sstream> 

// Uncomment the line below to run in pre-release mode
//#define PRE_RELEASE

struct STUDENT_DATA {
    std::string firstName;
    std::string lastName;
    std::string email;
    STUDENT_DATA(const std::string& first, const std::string& last, const std::string& email = "")
        : firstName(first), lastName(last), email(email) {}
};

std::vector<STUDENT_DATA> processStudents() {
    std::vector<STUDENT_DATA> students;
    std::ifstream inputFile("Resources/StudentData.txt");
    if (!inputFile.is_open()) {
        std::cerr << "Error opening StudentData.txt file" << std::endl;
        return students;
    }
    std::string line;
    while (std::getline(inputFile, line)) {
        std::stringstream ss(line);
        std::string firstName, lastName;
        if (std::getline(ss, lastName, ',') && std::getline(ss, firstName)) {
            students.emplace_back(firstName, lastName);
        }
    }
    inputFile.close();
    return students;
}

// Process emails when in pre release
std::vector<STUDENT_DATA> processStudentsEmail() {
    std::vector<STUDENT_DATA> students = processStudents();
#ifdef PRE_RELEASE
    std::ifstream emailFile("Resources/StudentData_Emails.txt");
    if (!emailFile.is_open()) {
        std::cerr << "Error opening StudentData_Emails.txt file" << std::endl;
        return students;
    }
    std::string email;
    size_t index = 0;
    while (std::getline(emailFile, email) && index < students.size()) {
        students[index].email = email;
        ++index;
    }
    emailFile.close();
#endif
    return students;
}

int main() {
    std::vector<STUDENT_DATA> students;

#ifdef PRE_RELEASE
    std::cout << "Running pre-release version of the software." << std::endl;
#else
    std::cout << "Running standard version of the software." << std::endl;
#endif

    students = processStudentsEmail(); 

// print out the names only if in debug mode
#ifdef _DEBUG
    std::cout << "[Student List:]" << std::endl;
    for (const STUDENT_DATA& student : students) {
#ifdef PRE_RELEASE
        std::cout << student.lastName << ", " << student.firstName << ", " << student.email << std::endl;
#else
        std::cout << "First Name:" << student.firstName << " Last Name: " << student.lastName << std::endl;
#endif
    }
#endif

    return 1;
}