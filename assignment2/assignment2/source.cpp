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

std::vector<STUDENT_DATA> readStudentData() {
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
        if (std::getline(ss, firstName, ',') && std::getline(ss, lastName)) {
            students.emplace_back(firstName, lastName);
        }
    }
    inputFile.close();
    return students;
}

#ifdef PRE_RELEASE
void readEmailData(std::vector<STUDENT_DATA>& students) {
    std::ifstream emailFile("Resources/StudentData_Emails.txt");
    if (!emailFile.is_open()) {
        std::cerr << "Error opening StudentData_Emails.txt file" << std::endl;
        return;
    }

    std::string email;
    size_t index = 0;
    while (std::getline(emailFile, email) && index < students.size()) {
        students[index].email = email;
        ++index;
    }
    emailFile.close();
}
#endif

int main() {
#ifdef _DEBUG
    std::cout << "Running in Debug mode" << std::endl;
#else
    std::cout << "Running in Release mode" << std::endl;
#endif

#ifdef PRE_RELEASE
    std::cout << "This is a Pre-Release version" << std::endl;
#else
    std::cout << "This is a Standard version" << std::endl;
#endif

    std::vector<STUDENT_DATA> students = readStudentData();

#ifdef PRE_RELEASE
    readEmailData(students);
#endif

    for (const auto& student : students) {
        std::cout << "First Name: " << student.firstName
            << ", Last Name: " << student.lastName;
#ifdef PRE_RELEASE
        std::cout << ", Email: " << student.email;
#endif
        std::cout << std::endl;
    }

    return 0;
}