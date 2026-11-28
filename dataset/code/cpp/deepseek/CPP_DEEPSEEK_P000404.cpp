#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

struct Doctor {
    string name;
    string specialization;
};

vector<Doctor> searchBySpecialization(vector<Doctor>& doctors, string target) {
    vector<Doctor> result;
    for (Doctor& doc : doctors) {
        if (doc.specialization == target) {
            result.push_back(doc);
        }
    }
    return result;
}

int main() {
    vector<Doctor> doctors;
    doctors.push_back({"John", "Cardiologist"});
    doctors.push_back({"Jane", "Neurologist"});
    doctors.push_back({"Alice", "Oncologist"});
    doctors.push_back({"Bob", "Neurologist"});
    doctors.push_back({"Charlie", "Cardiologist"});

    string target;
    cout << "Enter the specialization you want to search: ";
    cin >> target;

    vector<Doctor> matchedDoctors = searchBySpecialization(doctors, target);
    for (Doctor& doc : matchedDoctors) {
        cout << "Name: " << doc.name << ", Specialization: " << doc.specialization << endl;
    }

    return 0;
}