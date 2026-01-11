#include <iostream>
using namespace std;

class Employee {
private:
    string name;
    int empid;
    double currentSalary;
    double newSalary;
    string status;

public:
    void inputData() {
        cout << "Enter Employee Name: ";
        cin >> name;
        cout << "Enter Employee ID: ";
        cin >> empid;
        cout << "Enter Present Salary: ";
        cin >> currentSalary;
        newSalary = currentSalary;
        status = "No Change";
    }

    int getEmpId() {
        return empid;
    }

    void increment(float percentage) {
        newSalary = currentSalary + (currentSalary * percentage / 100);
        status = "Incremented";
    }

    void decrement(float percentage) {
        newSalary = currentSalary - (currentSalary * percentage / 100);
        status = "Decremented";
    }

    void display() {
        cout << "\nEmployee ID: " << empid;
        cout << "\nName: " << name;
        cout << "\nOld Salary: " << currentSalary;
        cout << "\nNew Salary: " << newSalary;
        cout << "\nStatus: " << status << endl;
    }
};

int main() {
    int n, id, choice;
    float percentage;

    cout << "Enter number of employees: ";
    cin >> n;

    Employee e[n];

    for (int i = 0; i < n; i++) {
        e[i].inputData();
    }

    cout << "\nEnter Employee ID to change salary: ";
    cin >> id;

    for (int i = 0; i < n; i++) {
        if (e[i].getEmpId() == id) {
            cout << "\n1. Increment\n2. Decrement\nEnter choice: ";
            cin >> choice;

            cout << "Enter percentage: ";
            cin >> percentage;

            if (choice == 1) {
                e[i].increment(percentage);
            } else if (choice == 2) {
                e[i].decrement(percentage);
            } else {
                cout << "Invalid choice!";
            }

            e[i].display();
            break;
        }
    }

    return 0;
}
