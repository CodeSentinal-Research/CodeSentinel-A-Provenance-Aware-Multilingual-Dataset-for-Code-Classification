#include <iostream>
#include <vector>
#include <string>

using namespace std;

struct Patient {
    string name;
    int patientId;
};

int main() {
    int numPatients;
    cin >> numPatients;

    vector<Patient> patients;

    for(int i = 0; i < numPatients; i++) {
        Patient p;
        cin >> p.name >> p.patientId;
        patients.push_back(p);
    }

    int patientIdToFind;
    cin >> patientIdToFind;

    bool patientFound = false;

    for(int i = 0; i < numPatients; i++) {
        if(patients[i].patientId == patientIdToFind) {
            cout << patients[i].name << endl;
            patientFound = true;
            break;
        }
    }

    if(!patientFound) {
        cout << "Patient Not Found" << endl;
    }

    return 0;
}