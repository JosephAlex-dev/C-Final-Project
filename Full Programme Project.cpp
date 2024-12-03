#include <iostream>
#include <string>
using namespace std;

class Employee {
private:
    string name;
    double salary;
    int id;
public:
    Employee() : name("Unnamed"), salary(0.0), id(0) {}
    Employee(const string& empName, double empSalary) : name(empName), salary(empSalary), id(0) {}
    Employee(const string& empName, double empSalary, int empId) : name(empName), salary(empSalary), id(empId) {}
    virtual ~Employee() {}
    virtual void inputDetails() {
        cout << "Enter your name: "; cin >> name;
        cout << "Enter your salary: "; cin >> salary;
        cout << "Enter your ID: "; cin >> id;
    }
    virtual void displayDetails() const {
        cout << "Name: " << name << ", Salary: $" << salary << ", ID: " << id << endl;
    }
};

class Manager : public Employee {
private:
    string department;
public:
    Manager() : Employee() {}
    void inputDetails() override {
        Employee::inputDetails();
        cout << "Enter your department: "; cin >> department;
    }
    void displayDetails() const override {
        Employee::displayDetails();
        cout << "Department: " << department << endl;
    }
};

int main() {
    char continueInput;
    do {
        cout << "Enter 1 for Employee or 2 for Manager: ";
        int choice; cin >> choice;
        Employee* emp = nullptr;
        if (choice == 1) emp = new Employee();
        else if (choice == 2) emp = new Manager();
        else { cout << "Invalid choice! Please enter 1 or 2.\n"; continue; }
        emp->inputDetails();
        emp->displayDetails();
        cout << "Do you want to enter another employee? (y/n): ";
        cin >> continueInput;
        delete emp;
    } while (continueInput == 'y' || continueInput == 'Y');
    return 0;
}
