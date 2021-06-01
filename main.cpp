#include <iostream>
#include <math.h>
using namespace std;

#include <string>
#include <iomanip>
#include <windows.h>
#include <stdlib.h>

//---------------------student class implementation----------------------------
class Student {
public:
    int id;
    string name;
    int age, year, classroom;
    char grade;
    int phoneNumber;
    string email;

    Student inputStudentData(int id);

    void printStudentData(Student studentData);

    void printAllStudentsData(Student *pArrayPtr);

    int countAllStudentsData(Student *cArrayPtr);

    int findStudentData(Student *fArrayPtr,string message);

    void editStudentData(Student *eArrayPtr);

    void removeStudentData(Student *dArrayPtr);

    void printLabels();

    int intValidInput();

    string stringValidInput();

    char gradeValidInput();

    int limitValidation(int limit);

    };

//---------------------student class functions----------------------------
Student Student::inputStudentData(int id) {
    cout<<"follow the following instructions to add new student data:\n";
    Student studentData;
    studentData.id = id;
    cout << "Enter student name:";
    studentData.name = stringValidInput();
    cout << "Enter student age:";
    studentData.age = limitValidation(20);
    cout << "Enter student year:";
    studentData.year = limitValidation(14);
    cout << "Enter student classroom:";
    studentData.classroom = intValidInput();
    cout << "Enter student grade:\n choose from (A,B,C,D,F):";
    studentData.grade = gradeValidInput();
    cout << "Enter student phoneNumber:";
    studentData.phoneNumber = intValidInput();
    cout << "Enter student email:";
    studentData.email = stringValidInput();
    cout << "Student #" << id << " is added to the system \n";
    return studentData;
}

void Student::printStudentData(Student studentData) {

    cout << setw(4) << studentData.id << "|"
         << setw(16) << studentData.name << "|"
         << setw(10) << studentData.age << "|"
         << setw(8) << studentData.year << "|"
         << setw(13) << studentData.classroom << "|"
         << setw(10) << studentData.grade << "|"
         << setw(13) << studentData.phoneNumber << "|"
         << setw(16) << studentData.email << endl;
}


void Student::printAllStudentsData(Student *pArrayPtr) {
    while ((*pArrayPtr).name != "") {
        printStudentData(*pArrayPtr);
        pArrayPtr++;
    }

}

int Student::countAllStudentsData(Student *cArrayPtr) {
    int count = 0;
    while ((*cArrayPtr).name != "") {
        count++;
        cArrayPtr++;
    }
    return count;
}

int Student::findStudentData(Student *fArrayPtr,string message) {
    starting:
    int wantedId, counter = 0;
    int founded = 0;
    cout << "enter student ID you want to "<<message<<":";
    wantedId = intValidInput();
    while ((*fArrayPtr).name != "") {
        if ((*fArrayPtr).id == wantedId) {
            cout << (*fArrayPtr).name << "'s data: \n";
            printLabels();
            printStudentData((*fArrayPtr));
            founded = 1;
            return counter;

        } else {
            fArrayPtr++;
        }
        counter++;
    }
    if (founded == 0) {
        fArrayPtr -= counter;
        cout<<"unknown id!! \n";
        goto starting;
    }


}

void Student::editStudentData(Student *eArrayPtr) {

    eArrayPtr = eArrayPtr + (findStudentData(eArrayPtr,"edit"));
    cout << "--------------------------------------------------------------------------------------------------\n";
    cout<<"follow the following instructions to edit existing student data:\n";
    int choiceNumber;
    //fasl


    cout  << "1.name" << "\n"
          << "2.age " << "\n"
          << "3.year" << "\n"
          << "4.classroom" << "\n"
          << "5.grade" << "\n"
          << "6.phone no." << "\n"
          << "7.email\n"
          << "choose number of item to edit: ";

    choiceNumber = intValidInput();
    system("cls");
    switch (choiceNumber) {
        //1.name
        case 1: {
            cout << "old name :" << (*eArrayPtr).name << endl << "enter new name:";
            (*eArrayPtr).name = stringValidInput();
            break;
        }
            //2.age
        case 2: {
            cout << "old age :"
                 << (*eArrayPtr).age << endl << "enter new age:";
            (*eArrayPtr).age = limitValidation(20);
            break;
        }
            //3.year
        case 3: {
            cout << "old year :"
                 << (*eArrayPtr).year << endl
                 << "enter new year:";
            (*eArrayPtr).year = limitValidation(14);
            break;
        }
            //4.classroom
        case 4: {
            cout << "old classroom :"
                 << (*eArrayPtr).classroom << endl
                 << "enter new classroom:";
            (*eArrayPtr).classroom = intValidInput();
            break;
        }
            //5.grade
        case 5: {
            cout << "old grade :" << (*eArrayPtr).grade << endl << "enter new grade:";
            (*eArrayPtr).grade = gradeValidInput();
            break;
        }
            //6.phone no.
        case 6: {
            cout << "old phoneNumber :" << (*eArrayPtr).phoneNumber << endl << "enter new phoneNumber:";
            (*eArrayPtr).phoneNumber = intValidInput();
            break;
        }
            //7.email
        case 7: {
            cout << "old email :" << (*eArrayPtr).email << endl << "enter new email:";
            (*eArrayPtr).email = stringValidInput();
            break;
        }

    }
    system("cls");
    //fasl
    cout << (*eArrayPtr).name << "'s data: \n";
    printStudentData((*eArrayPtr));
}

void Student::printLabels() {
    //fasl
    // cout << "--------------173-----------------------------------------------------\n";
    cout << setw(4) << "id" << "|"
         << setw(16) << " name" << "|"
         << setw(10) << "age" << "|"
         << setw(8) << "year" << "|"
         << setw(13) << "classroom" << "|"
         << setw(10) << "grade" << "|"
         << setw(12) << "phone no." << " |"
         << setw(8) << "email" << endl;
    // cout << "-----------182----------------------------------------------------------------------------\n";

}

void Student::removeStudentData(Student *dArrayPtr) {
    Student *nextPtr, *startPtr;
    int oldID;
    dArrayPtr += (findStudentData(dArrayPtr,"delete"));

    cout << "is deleted. \n";
    nextPtr = dArrayPtr + 1;
    while ((*dArrayPtr).name != "") {
        oldID = (*dArrayPtr).id;
        *dArrayPtr = *nextPtr;
        (*dArrayPtr).id = oldID;
        dArrayPtr++;
        nextPtr++;
    }
}

int Student::intValidInput() {
    double number;

    cin >> number;
    cin.ignore();
    while (cin.fail()||number<=0||(number-floor(number))) {
        cin.clear();
        cin.ignore(1000, '\n');
        cout << "invalid entry!Please Enter a number bigger than zero: ";
        cin >> number;
    }
    return (int)number;
}

string Student::stringValidInput() {
    starting:
    string input;
    getline(cin,input);
    if(input==""){cout<<"Please enter a NAME!";
    goto starting;}
    if (!(isdigit(input[0]))) return input;
    else {
        cin.clear();
        cin.ignore(1000, '\n');
        cout << "invalid entry! Please enter :";
        goto starting;
    }
}

char Student::gradeValidInput() {
    char input;
    cin >> input;
    while (!(input == 'A' || input == 'B' || input == 'C' || input == 'D' || input == 'a' || input == 'b' ||
             input == 'c' || input == 'd')) {
        cin.clear();
        cin.ignore(1000, '\n');
        cout << "invalid entry!Please choose from (A,B,C,D)  :";
        cin >> input;
    }
    return input;
}

int Student::limitValidation(int limit){
    starting:
    int input = intValidInput();
    while(input>limit){
        cout<<"invalid entry! Please enter number below "<<limit<<":";
        goto starting;
    }
}
//---------------------main functions prototypes-------------
int chooseFromMenu();

//-----------------------main----------------------------------

int main() {
    Student studentConstructor, studentDataEntry;
    int studentsCount;
    int menuChoice;
    char quitAnswer;
    //dummy data
    Student testData1 = {1, "zead hesham", 17, 5, 2, 'A', 1116781404, "zead1@gmail.com"};
    Student testData2 = {2, "zead2 hesham", 18, 6, 3, 'B', 1116781405, "zead2@gmail.com"};
    Student testData3 = {3, "zead3 hesham", 19, 7, 4, 'C', 1116781406, "zead3@gmail.com"};
    Student testData4 = {4, "zead4 hesham", 20, 8, 5, 'D', 1116781407, "zead4@gmail.com"};
    Student testData5 = {5, "zead5 hesham", 21, 2, 6, 'D', 1116781407, "zead41@gmail.com"};
    Student testData6 = {6, "zead6 hesham", 24, 5, 7, 'D', 1116781407, "zead41@gmail.com"};
    Student testData7 = {7, "zead7 hesham", 27, 9, 8, 'D', 1116781407, "zead41@gmail.com"};
    Student testData8 = {8, "zead8 hesham", 20, 1, 9, 'D', 1116781407, "zead41@gmail.com"};
    Student studentArray[100] = {testData1, testData2, testData3, testData4, testData5, testData6, testData7, testData8
    };
    Student *sPtr = studentArray;
    //--------------------------

    //elmenu elly sh8ala
    do {
        menuChoice = chooseFromMenu();

        if (menuChoice == 6) break;

        switch (menuChoice) {
            //1. add new student data
            case 1: {
                studentsCount = studentConstructor.countAllStudentsData(studentArray);
                sPtr = sPtr + studentsCount;
                *sPtr = studentConstructor.inputStudentData(studentsCount + 1);
                sPtr = studentArray;
                break;
            }
                //2. find exising student data
            case 2: {
                studentConstructor.findStudentData(studentArray,"find");
                break;
            }
                //3. display all students
            case 3: {
                studentConstructor.printLabels();
                studentConstructor.printAllStudentsData(studentArray);
                break;
            }
                //4. edit exising student data
            case 4: {
                studentConstructor.editStudentData(studentArray);
                break;
            }
                //5.remove student data
            case 5: {
                studentConstructor.removeStudentData(studentArray);
                break;
            }
                //6.exit
            default: {
                cout << "invalid choice!! \n";
                break;
            }
        }
        cout << "--------------------------------------------------------------------------------------------------\n";
        cout << "press N to exit program, any other key to do another operation: ";
        cin >> quitAnswer;
        system("cls");
    } while (quitAnswer != 'n' && quitAnswer != 'N');


}

//------------------main functions implementation-------------

int chooseFromMenu() {
    Student studentConstructor;
    int choice;
    cout << "Choose number from(1,2,3,4,5,6) to perform one of the following operations:\n"
         << "1. add new student data\n"
            "2. find exising student data\n"
            "3. display all students\n"
            "4. edit exising student data\n"
            "5. remove student data\n"
            "6. exit\n"
            "enter your choice :";
    choice = studentConstructor.intValidInput();
    system("cls");
    return choice;

}