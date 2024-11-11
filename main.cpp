#include <iostream>
using namespace std;

struct Student {
    string surname;
    string initials;
    int birthYear;
    int dormitoryNumber;
    int roomNumber;
};

void inputStudents(Student students[], int n) {
    for (int i = 0; i < n; ++i) {
        cout << "Enter surname: ";
        cin >> students[i].surname;
        cout << "Enter initials: ";
        cin >> students[i].initials;
        cout << "Enter birth year: ";
        cin >> students[i].birthYear;
        cout << "Enter dormitory number: ";
        cin >> students[i].dormitoryNumber;
        cout << "Enter room number: ";
        cin >> students[i].roomNumber;
    }
}

// Find by dormitory and year
void findStudentsByDormitoryAndYear(const Student students[], int n, int dormitoryNumber, int birthYear) {
    bool found = false;
    for (int i = 0; i < n; ++i) {
        if (students[i].dormitoryNumber == dormitoryNumber && students[i].birthYear == birthYear) {
            cout << "Student: " << students[i].surname << " " << students[i].initials << endl;
            found = true;
        }
    }
    if (!found) {
        cout << "No students found matching the criteria." << endl;
    }
}

// Find bt room 
void findStudentsByRoomNumber(const Student students[], int n, int roomNumber, int dormitoryNumber1, int dormitoryNumber2) {
    bool found = false;
    for (int i = 0; i < n; ++i) {
        if (students[i].roomNumber == roomNumber && 
            (students[i].dormitoryNumber == dormitoryNumber1 || students[i].dormitoryNumber == dormitoryNumber2)) {
            cout << "Student: " << students[i].surname << endl;
            found = true;
        }
    }
    if (!found) {
        cout << "No students found matching the criteria." << endl;
    }
}

int main() {
    int n;
    cout << "Enter the number of students: ";
    cin >> n;
    Student* students = new Student[n]; // Pointer to array of students

    inputStudents(students, n);

    int choice;
    cout << "Enter 1 to find students by dormitory and year, or 2 to find students by room number: ";
    cin >> choice;

    if (choice == 1) {
        int dormitoryNumber, birthYear;
        cout << "Enter dormitory number: ";
        cin >> dormitoryNumber;
        cout << "Enter birth year: ";
        cin >> birthYear;
        findStudentsByDormitoryAndYear(students, n, dormitoryNumber, birthYear);
    } else if (choice == 2) {
        int roomNumber, dormitoryNumber1, dormitoryNumber2;
        cout << "Enter room number: ";
        cin >> roomNumber;
        cout << "Enter first dormitory number: ";
        cin >> dormitoryNumber1;
        cout << "Enter second dormitory number: ";
        cin >> dormitoryNumber2;
        findStudentsByRoomNumber(students, n, roomNumber, dormitoryNumber1, dormitoryNumber2);
    } else {
        cout << "Invalid choice." << endl;
    }

    delete[] students; // When memory created it should be deleted
}
