#include <iostream>
#include <cstring>
using namespace std;

struct Student
{
    char name[30];
    char className[10];
    float mMath;
    float mPhysical;
};

void addStudent(Student* list, int& n) {
    cout << "Enter student name: ";
    cin.ignore(); // to ignore the newline character left by previous cin
    cin.getline(list[n].name, 30);
    cout << "Enter student class name: ";
    cin >> list[n].className;
    cout << "Enter math mark: ";
    cin >> list[n].mMath;
    cout << "Enter physical mark: ";
    cin >> list[n].mPhysical;
    n++;
}

void searchStudentByName(Student* list, int n) {
    char searchName[30];
    cout << "Enter student name to search: ";
    cin.ignore(); // to ignore the newline character left by previous cin
    cin.getline(searchName, 30);
    bool found = false;
    for (int i = 0; i < n; i++) {
        if (strcmp(list[i].name, searchName) == 0) {
            cout << "Student found:\n";
            cout << "Name: " << list[i].name << endl;
            cout << "Class: " << list[i].className << endl;
            cout << "Math mark: " << list[i].mMath << endl;
            cout << "Physical mark: " << list[i].mPhysical << endl;
            found = true;
            break;
        }
    }
    if (!found) {
        cout << "Student not found.\n";
    }
}

void searchAndEditStudentClass(Student* list, int n) {
    char searchName[30];
    cout << "Enter student name to search: ";
    cin.ignore(); // to ignore the newline character left by previous cin
    cin.getline(searchName, 30);
    bool found = false;
    for (int i = 0; i < n; i++) {
        if (strcmp(list[i].name, searchName) == 0) {
            cout << "Student found:\n";
            cout << "Name: " << list[i].name << endl;
            cout << "Current class: " << list[i].className << endl;
            cout << "Enter new class name: ";
            cin >> list[i].className;
            found = true;
            break;
        }
    }
    if (!found) {
        cout << "Student not found.\n";
    }
}
void displayInformationStudent(Student* list,int n){
	for (int i =0;i < n;++i){
		cout << i+1 << endl; 
		cout << "Name: " << list[i].name << endl;
		cout << "Class: " << list[i].className << endl ;
		cout << "Marks Math: " << list[i].mMath << endl;
		cout << "Marks Physical: " << list[i].mPhysical << endl;
		cout << "\n";
}
} 

int main() {
    Student list[50];
    int n = 0;
    char choice;
    do {
        cout << "1. Add a new student.\n";
        cout << "2. Search a student by name.\n";
        cout << "3. Search a student by name and edit class of the student.\n";
        cout << "4. Exit.\n";
        cout << "5. Display Information Student.\n";
        cout << "Enter your choice (1-5): ";
        cin >> choice;
        switch (choice) {
            case '1':
                addStudent(list, n);
                break;
            case '2':
                searchStudentByName(list, n);
                break;
            case '3':
                searchAndEditStudentClass(list, n);
                break;
            case '4':
                cout << "Exiting program.\n";
                break;
            case '5':
            	displayInformationStudent(list, n);
            	break;
            default:
                cout << "Invalid choice.\n";
        }
        cout << endl;
    } while (choice != '4');
    return 0;
}
