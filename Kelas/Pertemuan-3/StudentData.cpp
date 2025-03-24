#include <iostream>
#include <array>

#include <string>

class Student {
private:
    std::string nim;
    std::string name;
    float grade;

public:
    void setNim(const std::string& nim) {
        this->nim = nim;
    }

    void setName(const std::string& name) {
        this->name = name;
    }

    void setGrade(float grade) {
        this->grade = grade;
    }

    std::string getNim() const {
        return nim;
    }

    std::string getName() const {
        return name;
    }

    float getGrade() const {
        return grade;
    }
};

void inputStudentData(Student students[], int& count) {

    Student student;
    std::string nim, name;
    float grade;

    std::cout << "Enter NIM: ";
    std::cin >> nim;
    student.setNim(nim);

    std::cout << "Enter Name: ";
    std::cin.ignore(); // Clear the newline character from the input buffer
    std::getline(std::cin, name);
    student.setName(name);

    std::cout << "Enter Grade: ";
    std::cin >> grade;
    student.setGrade(grade);

    students[count] = student;
    count++;

}

void displayStudents(const Student students[], int count) {

    std::cout << "\nList of Students:\n";
    for (int i = 0; i < count; i++) {
        const auto& student = students[i];

        std::cout << "NIM: " << student.getNim() 
                  << ", Name: " << student.getName() 
                  << ", Grade: " << student.getGrade() << "\n";
    }
}

int main() {
    Student students[100]; // Fixed size array for 100 students
    int count = 0; // To keep track of the number of students

    int choice;

    do {
        std::cout << "\nMenu:\n";
        std::cout << "1. Add Student\n";
        std::cout << "2. Display Students\n";
        std::cout << "3. Exit\n";
        std::cout << "Enter your choice: ";
        std::cin >> choice;

        switch (choice) {
            case 1:
                inputStudentData(students, count);

                break;
            case 2:
                displayStudents(students, count);

                break;
            case 3:
                std::cout << "Exiting program.\n";
                break;
            default:
                std::cout << "Invalid choice. Please try again.\n";
        }
    } while (choice != 3);

    return 0;
}
