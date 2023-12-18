#include <iostream>
#include <vector>
#include <algorithm>

class Student {
private:
    std::string firstName;
    std::string lastName;
    double averageGrade;

public:
    Student(const std::string& fName, const std::string& lName, double avgGrade)
        : firstName(fName), lastName(lName), averageGrade(avgGrade) {}

    double getAverageGrade() const {
        return averageGrade;
    }

    friend bool operator<(const Student& s1, const Student& s2) {
        return s1.averageGrade < s2.averageGrade;
    }

    friend std::ostream& operator<<(std::ostream& out, const Student& student) {
        out << student.firstName << " " << student.lastName << ": " << student.averageGrade;
        return out;
    }
};

// Функція для пошуку студента з найвищим балом
Student findStudentWithHighestGrade(const std::vector<Student>& students) {
    auto maxElement = std::max_element(students.begin(), students.end());
    return *maxElement;
}

int main() {
    // Створюємо вектор студентів
    std::vector<Student> students = {
        {"John", "Doe", 85.5},
        {"Alice", "Smith", 92.0},
        {"Bob", "Johnson", 88.7},
        // Додайте інших студентів за потреби
    };

    // Знаходимо студента з найвищим балом
    Student studentWithHighestGrade = findStudentWithHighestGrade(students);

    // Виводимо ім'я знайденого студента на екран
    std::cout << "Студент з найвищим балом: " << studentWithHighestGrade << std::endl;

    return 0;
}
