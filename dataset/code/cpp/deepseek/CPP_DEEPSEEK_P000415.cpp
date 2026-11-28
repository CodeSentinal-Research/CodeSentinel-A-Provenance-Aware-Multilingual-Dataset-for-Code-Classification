Here is the C++ code that solves the problem:

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

struct Patient {
    string name;
    string bloodGroup;
};

bool comparePatients(const Patient& a, const Patient& b) {
    return a.bloodGroup < b.bloodGroup;
}

int main() {
    int n;
    cin >> n;
    vector<Patient> patients(n);
    for (int i = 0; i < n; i++) {
        cin >> patients[i].name >> patients[i].bloodGroup;
    }
    string bloodGroup;
    cin >> bloodGroup;
    sort(patients.begin(), patients.end(), comparePatients);
    bool found = false;
    for (int i = 0; i < n; i++) {
        if (patients[i].bloodGroup == bloodGroup) {
            cout << patients[i].name << endl;
            found = true;
        }
    }
    if (!found) {
        cout << "No patients found." << endl;
    }
    return 0;
}

In this code, we first read the number of patients and their records. Then, we read the blood group for which we want to find patients. We sort the patient records based on their blood groups. Then, we iterate over the sorted list and print the name of the patient whose blood group matches the input. If no patients are found, we print a message to that effect.