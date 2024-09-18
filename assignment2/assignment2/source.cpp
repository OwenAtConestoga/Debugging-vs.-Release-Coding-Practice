#include <iostream>
#include <fstream>
#include <vector>
#include <string>
#include <sstream>


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

	if (!inputFile.is_open())
	{
		std::cerr << "Error opening file" << std::endl;
		return 2;
	}

    std::string line;
    // Read each line from the file
    while (std::getline(inputFile, line)) {
        std::stringstream ss(line);
        std::string firstName, lastName;

        // Parse first name and last name (separated by a comma)
        if (std::getline(ss, firstName, ',') && std::getline(ss, lastName)) {
            // Use the constructor to create a student object
            students.emplace_back(firstName, lastName);
        }
    }

    inputFile.close();

    // Output the students to check
    for (const auto& student : students) {
        std::cout << "First Name: " << student.firstName << ", Last Name: " << student.lastName << std::endl;
    }

    return 0;
}