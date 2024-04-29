//I232560
 //Emaan Arshad
 //Task 2
#include <iostream>

using namespace std;

void grade(int av) {
    if (av >= 90) cout << "Grade A\n";
    else if (av >= 80 && av < 89) cout << "Grade B\n";
    else if (av >= 70 && av < 79) cout << "Grade C\n";
    else if (av >= 60 && av < 69) cout << "Grade D\n";
    else cout << "Grade F\n";
}

int main() {
    int number;
    cout << "Enter the number of students: ";
    cin >> number;

    int** matrix = new int*[number];
    for (int i = 0; i < number; i++) {
        matrix[i] = new int[3];
    }

    for (int i = 0; i < number; i++) {
        for (int j = 0; j < 3; j++) {
            cout << "Enter marks (maths, eng, science) for student " << i + 1 << ": ";
            cin >> matrix[i][j];
        }
    }

    int total = 0, av = 0;
    for (int i = 0; i < number; i++) {
        total = 0;
        for (int j = 0; j < 3; j++) {
            total += matrix[i][j];
        }
        av = total / 3;

        cout << "\nStudent " << i + 1 << ":\n";
        cout << "Total: " << total << "\n";
        cout << "Average: " << av << "\n";
        cout << "Grade: ";
        grade(av);
    }

    for (int i = 0; i < number; i++)
        delete[] matrix[i];

    delete[] matrix;

    return 0;
}
