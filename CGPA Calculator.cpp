#include <iostream>
#include <vector>
#include <iomanip>

using namespace std;

double gradeToPoint(char letterGrade) {
    switch (letterGrade) {
        case 'O': return 10.0;
        case 'A+': return 9.0;
        case 'A': return 8.0;
        case 'B+': return 7.0;
        case 'B': return 5.0;
        case 'U': return 0.0;
        default:  return -1.0; // Invalid grade
    }
}

int main() {
    int numCourses;
    cout << "Enter the number of courses: ";
    cin >> numCourses;

    double totalGradePoints = 0.0;
    double totalCreditHours = 0.0;

    for (int i = 1; i <= numCourses; ++i) {
        cout << "Course " << i << ":\n";
        char letterGrade;
        cout << "Enter the letter grade (S, A, B, C, D, E, U): ";
        cin >> letterGrade;

        double creditHours;
        cout << "Enter the credit hours for the course: ";
        cin >> creditHours;

        double gradePoints = gradeToPoint(letterGrade);
        if (gradePoints == -1.0) {
            cout << "Invalid grade entered. Please enter a valid grade.\n";
            return 1; // Exit with an error code
        }

        totalGradePoints += gradePoints * creditHours;
        totalCreditHours += creditHours;
    }

    if (totalCreditHours > 0) {
        double cgpa = totalGradePoints / totalCreditHours;
        cout << fixed << setprecision(2); // Display CGPA with 2 decimal places
        cout << "Your CGPA is: " << cgpa << endl;
    } else {
        cout << "No courses or invalid input. Cannot calculate CGPA." << endl;
    }

    return 0;
}
