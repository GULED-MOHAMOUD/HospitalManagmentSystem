#include <iostream>
#include <fstream>
#include <string>
using namespace std;

const int MAX_PATIENTS = 100; //maximum patients system can handle

// structure to store patient details
struct Patient
{
    int id;
    string name;
    int age;
    string disease;
};

//function prototypes
void addPatient(Patient *patients, int &countPatients);
void viewAllPatients(const Patient *patients, int countPatients);
void searchPatients(const Patient *patients, int patientNum);
void saveInfoToFile(const Patient *patients, int patientNum, const string &fileNm);
void loadFromFile(Patient *patients, int &countPatient, const string &fileNm);

int main()
{
    Patient patients[MAX_PATIENTS]; // array for storing patient records
    int countPatients = 0; // counter to track number of patients
    string fileNm = "patients.txt"; 

    int choice;

    do
    {
        cout << "-----------------------------------\n";
        cout << "|    HOSPITAL MANAGEMENT SYSTEM   |\n";
        cout << "-----------------------------------\n";
        cout << "1. Add Patient" << endl;
        cout << "2. save Patient  info to file" << endl;
        cout << "3. search Patients  info" << endl;
        cout << "4. view All Saved Patients  info" << endl;
        cout << "5. load info form file" << endl;
        cout << "6. EXIT" << endl;
        cout << "Enter your choice: ";
        cin >> choice;

    // manage the user choices
        switch (choice)
        {
        case 1:
            addPatient(patients, countPatients);
            break;
        case 2:
            saveInfoToFile(patients, countPatients, fileNm);
            break;
        case 3:
            searchPatients(patients, countPatients);
            break;
        case 4:
            viewAllPatients(patients, countPatients);
            break;
        case 5:
            loadFromFile(patients, countPatients, fileNm);
            break;
        case 6:
            cout << "Exiting System...\n Goodbye!" << endl;
        default:
            cout << "Invalid choice, please try again \n";
            // exit(1); // terminate the system due to user invalid input 
            break; // break the loop due to user's invalid input
        }
    } while (choice != 6);

    return 0;
}
// add a new patient to the system
void addPatient(Patient *patients, int &countPatients)
{
    if (countPatients >= MAX_PATIENTS)
    {
        cout << "Records is Full, conot add more";
        return;
    }

    Patient &newPatient = patients[countPatients];

    cout << "Enter Patient ID: ";
    cin >> newPatient.id;

    if (cin.fail()) // check if the input value is a number
    {
        cout << "Invalid input! ID must be a number.\n";
        exit(1);
        cin.clear(); // Clear the error flag
        return; // Exit the function
    }

    cin.ignore();

    cout << "Enter Patient fullName: ";
    getline(cin, newPatient.name);

    cout << "Enter Patient age: ";
    cin >> newPatient.age;

    if (cin.fail()) // check if the input value is number
    {
        cout << "Invalid input! AGE must be a number.\n";
        exit(1);
        cin.clear(); // Clear the error flag
        return; // Exit the function
    }

    cin.ignore();

    cout << "Enter Patients Disease: ";
    getline(cin, newPatient.disease);

    countPatients++; // increment the Patient count
    cout << "Patient added successfully\n";
};

// Display all saved Patients
void viewAllPatients(const Patient *patients, int countPatients)
{
    if (countPatients == 0)
    {
        cout << "No Patient Record to Show\n";
        return;
    }

    cout << "----------| Patient Records: |---------\n";
    cout << "------------------------------------------------------------\n";

    for (int i = 0; i < countPatients; i++)
    {
        cout << "ID: " << patients[i].id
             << ",  NAME: " << patients[i].name
             << ", AGE: " << patients[i].age 
             << ", DISEASE: "<< patients[i].disease << "\n";
        cout << "------------------------------------------------------------\n";
    }
}

// search a patient by ID
void searchPatients(const Patient *patients, int countPatients)
{
    int searchId;
    cout << "Enter Patient ID to search: ";
    cin >> searchId;

    for (int i = 0; i < countPatients; i++)
    {
        if (patients[i].id == searchId)
        {
            cout << "------------------------------------------------------\n";
            cout << "        Founded patient with the  idNo: " << searchId << "\n";
            cout << "------------------------------------------------------\n";
            cout << "ID: " << patients[i].id 
                 << ", NAME: " << patients[i].name 
                 << ", AGE: " << patients[i].age 
                 << ", DISEASE: "<< patients[i].disease << "\n";
            cout << "------------------------------------------------------\n";
            return;
        }
    }
    cout << "-----Patient with ID " << searchId << " not found.-----\n";
}

void saveInfoToFile(const Patient *patients, int countPatients, const string &fileNm)
{
    ofstream file(fileNm); // open file for writting 

    if (!file)
    {
        cout << "Error: Could not open file for saving.\n";
        return;
    }

    // wtite patients details in CSV format
    for (int i = 0; i < countPatients; i++)
    {
        file << patients[i].id 
        << "," << patients[i].name 
        << "," << patients[i].age 
        << "," << patients[i].disease << "\n";
    };

    file.close();
    cout << "Patients saved to file successfully.\n";
}

// load patients records from file
void loadFromFile(Patient *patients, int &countPatient, const string &fileNm)
{
    ifstream file(fileNm); // open the file for reading

    if (!file){
        cout << "Error: Could not open file for loading.\n";
        return;
    }

    countPatient = 0; // reset the patient count 

    // read the patients data from file
    while (file >> patients[countPatient].id)
    {
        file.ignore(); // skip the comma after id
        getline(file, patients[countPatient].name, ',');

        file >> patients[countPatient].age;
        file.ignore();
        getline(file, patients[countPatient].disease);
        
        countPatient++;
    }

    file.close();
    cout << "Patients loaded from file successfully.\n";
}
