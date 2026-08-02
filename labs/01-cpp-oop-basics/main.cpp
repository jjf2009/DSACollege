#include <iostream>
using namespace std;
class Employee {
private:
    int em_id;
    string name;
    double salary;
    string status;
    double newsalary;
public:
    void inputData() {
        cout << "Enter The Employee id: ";
        cin >> em_id;
        cin.ignore();
        cout << "Enter Your Name: ";
        getline(cin, name);
        cout << "Enter your Salary: ";
        cin >> salary;
        newsalary = salary;
        status = "No Change";}
    void displayData() {
        cout << em_id << "\t" << name << "\t" << salary << "\t" 
            << newsalary << "\t" << status << "\n";}
    void increment(double percent) {
        newsalary = salary + (salary * percent / 100.0);
        status = "Promoted";}
    void decrement(double percent) {
        newsalary = salary - (salary * percent / 100.0);
        status = "Demoted"; }
    bool changeSalary(int id) {
        if (em_id == id) {
            int choice;
            double percent;
            cout << "Enter 1 to increment, 2 for decrement: ";
            cin >> choice;
            cout << "Enter percentage: ";
            cin >> percent;
            if (choice == 1) {
                increment(percent); } 
                else if (choice == 2) {
                decrement(percent);
            } else {
                cout << "Invalid choice.\n";}
            return true; }
        return false;  } };
int main() {
    int n, id;
    cout << "Enter the number of Employees: ";
    cin >> n;
    Employee s[n];
    for (int i = 0; i < n; i++) {
        s[i].inputData();}
    while (1) {
        cout << "Enter Employee id to change Salary (or -1 to exit): ";
        cin >> id;
        if (id == -1) break;
        bool found = false;
        for (int i = 0; i < n; i++) {
            if (s[i].changeSalary(id)) {
                found = true;
                break; }}
        if (!found) {
            cout << "Employee Does not Exist\n";} }
    cout << "Employee ID\tName\tPresent Salary\tNew Salary\tStatus\n";
    for (int i = 0; i < n; i++) {
        s[i].displayData(); }
    return 0;}
