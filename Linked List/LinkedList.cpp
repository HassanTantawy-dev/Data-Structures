#include <iostream>
#include <string>
using namespace std;

struct subject
{
    string name;
    int studentCount;
    subject *next;
};
struct Student
{
    string name;
    string subject[10];
    int subjectCount;
};
subject *head = nullptr;
// add subject
void addSubject(string subjectName)
{
    subject *newsubject = new subject;
    newsubject->name = subjectName;
    newsubject->studentCount = 0;
    newsubject->next = nullptr;
    if (head == nullptr)
    {
        head = newsubject;
    }
    else
    {
        subject *temp = head;
        while (temp->next != nullptr)
        {
            temp = temp->next;
            temp->next = newsubject;
        }
        cout << "Subject added successfully!" << endl;
    }
};
// register student to subject
void registerStudent(Student &student, string subjectName)
{
    subject *temp = head;
    while (temp != nullptr && temp->name != subjectName)
    {
        temp = temp->next;
    };
    if (temp == nullptr)
    {
        cout << "subject not found!" << endl;
        return;
    }
    student.subject[student.subjectCount] = subjectName;
    student.subjectCount++;
};
// display subjects
void displaysubjects()
{
    if (head == nullptr)
    {
        cout << " No subjects available!" << endl;
        return;
    }
    cout << "/n Available Subjects: " << endl;
    subject *temp = head;
    while (temp != nullptr)
    {
        cout << "Subject Name: " << temp->name << ", Student Count: " << temp->studentCount << endl;
        temp = temp->next;
    }
};
// show registrations
void showRegistrations()
{
    if (head == nullptr)
    {
        cout << "No subjects available!" << endl;
        return;
    }
    cout << "/n Registered Students: " << endl;
    subject *temp = head;
    while (temp != nullptr)
    {
        cout << temp->name << ": " << temp->studentCount << " students registered." << endl;
        temp = temp->next;
    }
};
// show student subjects
void showStudentSubjects(Student student)
{
    if (student.subjectCount == 0)
    {
        cout << "No subjects registered for this student!" << endl;
        return;
    }
    cout << "\n" << student.name << "is registered in: ";
    for (int i = 0; i < student.subjectCount; i++)
    {
        cout << "-" << student.subject[i] << endl;
    }
};
int main()
{
    Student student;
    student.subjectCount = 0;
    int choice;
    string name;

    cout << "Enter student name: ";
    getline(cin, student.name);
    while (true)
    {
        cout << "\n ==== University Course Registration System ====\n"<< endl;
        cout << "1. Add Subject" << endl;
        cout << "2. Register Student to Subject" << endl;
        cout << "3. Display Subjects" << endl;
        cout << "4. Show Registrations" << endl;
        cout << "5.check Student Subjects" << endl;
        cout << "6. Exit\n"<< endl;
        cout << "Enter your choice: ";
        cin >> choice;
        cin.ignore();

        switch (choice)
        {
        case 1:
            cout << "Enter subject name: ";
            getline(cin, name);
            addSubject(name);
            break;
            case 2:
            cout << "Enter subject name to register: ";
            getline(cin, name);
            registerStudent(student, name);
            break;
            case 3:
                displaysubjects();
                break;
        case 4:
            showRegistrations();
            break;
        case 5:
            showStudentSubjects(student);
            break;
        case 6:
            cout << "Exiting the system. Goodbye!" << endl;
            return 0;
        default:
            cout << "Invalid choice! Please try again." << endl;
        }
    }
};
