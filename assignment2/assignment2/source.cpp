#include <iostream>
#include <fstream>
#include <vector>
#include <string>
#include <sstream>

// Define the STUDENT_DATA struct
struct STUDENT_DATA {
    std::string firstName;
    std::string lastName;

    STUDENT_DATA(const std::string& first, const std::string& last)
        : firstName(first), lastName(last) {}
};
int main()
{
    std::vector<STUDENT_DATA> students;
    std::ifstream inputFile("StudentData.txt");

    if (!inputFile.is_open()) {
        std::cerr << "Error opening file!" << std::endl;
        return 1;
    }
}