#include <iostream>
#include <fstream>
#include <string>
using namespace std;

struct Node {
    string type; // Doctor / Patient / Donor
    string id, name, specialization, availability, address, contact;
    string bloodGroup, diseaseInfo;
    Node* next;
};

class HospitalSystem {
private:
    Node* head;

public:
    HospitalSystem() : head(NULL) {}

    void addDoctor() {
        Node* newNode = new Node;
        newNode->type = "Doctor";
        cout << "Enter Doctor ID: "; cin >> newNode->id;
        cin.ignore();
        cout << "Enter Name: "; getline(cin, newNode->name);
        cout << "Enter Specialization: "; getline(cin, newNode->specialization);
        cout << "Enter Available Time (e.g. 9am-5pm): "; getline(cin, newNode->availability);
        cout << "Enter Address: "; cin >> newNode->address;
        cout << "Enter Contact: "; cin >> newNode->contact;
        newNode->next = NULL;

        addToLinkedList(newNode);
        saveAllToFile();
        cout << "Doctor added successfully.\n";
    }

    void addPatient() {
        Node* newNode = new Node;
        newNode->type = "Patient";
        cout << "Enter Patient ID: "; cin >> newNode->id;
        cin.ignore();
        cout << "Enter Name: "; getline(cin, newNode->name);
        cout << "Enter Disease Info: "; getline(cin, newNode->diseaseInfo);
        cout << "Enter Address: "; cin >> newNode->address;
        cout << "Enter Contact: "; cin >> newNode->contact;
        newNode->next = NULL;

        addToLinkedList(newNode);
        saveAllToFile();
        cout << "Patient added successfully.\n";
    }

    void addDonor() {
        Node* newNode = new Node;
        newNode->type = "Donor";
        cout << "Enter Donor ID: "; cin >> newNode->id;
        cin.ignore();
        cout << "Enter Name: "; getline(cin, newNode->name);
        cout << "Enter Blood Group: "; cin >> newNode->bloodGroup;
        cout << "Enter Location: "; cin >> newNode->address;
        cout << "Enter Contact: "; cin >> newNode->contact;
        newNode->next = NULL;

        addToLinkedList(newNode);
        saveAllToFile();
        cout << "Donor added successfully.\n";
    }

   void deleteRecord() {
    string type, id;
    cout << "Enter type (Doctor / Patient / Donor): ";
    cin >> type;
    cout << "Enter ID to delete: ";
    cin >> id;

    Node* temp = head;
    Node* prev = NULL;

    while (temp) {
        if (temp->id == id && temp->type == type) {
            if (prev) prev->next = temp->next;
            else head = temp->next;

            delete temp;
            saveAllToFile();
            cout << type << " record deleted successfully.\n";
            return;
        }
        prev = temp;
        temp = temp->next;
    }
    cout << type << " record not found.\n";
}

   void updateRecord() {
    string type, id;
    cout << "Enter type (Doctor / Patient / Donor): ";
    cin >> type;
    cout << "Enter ID to update: ";
    cin >> id;

    Node* temp = head;

    while (temp) {
        if (temp->id == id && temp->type == type) {
            cout << "Updating record for: " << temp->type << "\n";
            cin.ignore();
            cout << "Enter Name: ";
            getline(cin, temp->name);

            if (type == "Doctor") {
                cout << "Enter Specialization: ";
                getline(cin, temp->specialization);
                cout << "Enter Available Time: ";
                getline(cin, temp->availability);
            } else if (type == "Patient") {
                cout << "Enter Disease Info: ";
                getline(cin, temp->diseaseInfo);
            } else if (type == "Donor") {
                cout << "Enter Blood Group: ";
                cin >> temp->bloodGroup;
                cin.ignore();
            }

            cout << "Enter Address: ";
            cin >> temp->address;
            cout << "Enter Contact: ";
            cin >> temp->contact;

            saveAllToFile();
            cout << type << " record updated successfully.\n";
            return;
        }
        temp = temp->next;
    }
    cout << type << " record not found.\n";
}

    void displayAll() {
        int choice;
        cout << "\nSelect record type to display:\n1. Doctors\n2. Patients\n3. Donors\nEnter choice: ";
        cin >> choice;
        Node* temp = head;
        while (temp) {
            if ((choice == 1 && temp->type == "Doctor") ||
                (choice == 2 && temp->type == "Patient") ||
                (choice == 3 && temp->type == "Donor")) {

                cout << "-------------------------------\n";
                cout << "Type: " << temp->type << "\n";
                cout << "ID: " << temp->id << "\n";
                cout << "Name: " << temp->name << "\n";
                if (temp->type == "Doctor") {
                    cout << "Specialization: " << temp->specialization << "\n";
                    cout << "Available Time: " << temp->availability << "\n";
                }
                if (temp->type == "Patient") {
                    cout << "Disease Info: " << temp->diseaseInfo << "\n";
                }
                if (temp->type == "Donor") {
                    cout << "Blood Group: " << temp->bloodGroup << "\n";
                }
                cout << "Address: " << temp->address << "\n";
                cout << "Contact: " << temp->contact << "\n";
            }
            temp = temp->next;
        }
    }

    void checkDoctorAvailability(string specialization) {
        Node* temp = head;
        bool found = false;
        while (temp) {
            if (temp->type == "Doctor" && temp->specialization == specialization) {
                cout << "Doctor: " << temp->name << " | Time: " << temp->availability << " | Contact: " << temp->contact << endl;
                found = true;
            }
            temp = temp->next;
        }
        if (!found)
            cout << "No doctors found for specialization: " << specialization << endl;
    }

    void searchDonorByBloodGroup(string bloodGroup) {
        Node* temp = head;
        bool found = false;
        while (temp) {
            if (temp->type == "Donor" && temp->bloodGroup == bloodGroup) {
                cout << "Donor: " << temp->name << " | Location: " << temp->address << " | Contact: " << temp->contact << endl;
                found = true;
            }
            temp = temp->next;
        }
        if (!found)
            cout << "No donors found with blood group: " << bloodGroup << endl;
    }

    void loadFromFile() {
        ifstream file("hospital.txt");
        if (!file.is_open()) return;
        string type;

        while (file >> type) {
            Node* node = new Node;
            node->type = type;
            file >> node->id;
            file.ignore();
            getline(file, node->name);

            if (type == "Doctor") {
                getline(file, node->specialization);
                getline(file, node->availability);
                file >> node->address >> node->contact;
            } else if (type == "Patient") {
                getline(file, node->diseaseInfo);
                file >> node->address >> node->contact;
            } else if (type == "Donor") {
                file >> node->bloodGroup >> node->address >> node->contact;
            }
            node->next = NULL;
            addToLinkedList(node);
        }
        file.close();
    }

private:
    void addToLinkedList(Node* node) {
        if (!head) head = node;
        else {
            Node* temp = head;
            while (temp->next) temp = temp->next;
            temp->next = node;
        }
    }

    void saveAllToFile() {
        ofstream file("hospital.txt");
        Node* temp = head;
        while (temp) {
            file << temp->type << " " << temp->id << " " << temp->name << "\n";
            if (temp->type == "Doctor") {
                file << temp->specialization << "\n" << temp->availability << "\n" << temp->address << " " << temp->contact << "\n";
            } else if (temp->type == "Patient") {
                file << temp->diseaseInfo << "\n" << temp->address << " " << temp->contact << "\n";
            } else if (temp->type == "Donor") {
                file << temp->bloodGroup << " " << temp->address << " " << temp->contact << "\n";
            }
            temp = temp->next;
        }
        file.close();
    }
};

int main() {
    HospitalSystem hs;
    hs.loadFromFile();
    int choice;

    while (true) {
        cout << "\n--- Hospital Menu ---\n";
        cout << "1. Add Doctor\n2. Add Patient\n3. Add Donor\n4. Show Selected Records\n5. Search Doctor by Specialization\n6. Search Donor by Blood Group\n7. Delete Record\n8. Update Record\n9. Exit\nEnter choice: ";
        cin >> choice;

        switch (choice) {
            case 1: hs.addDoctor(); break;
            case 2: hs.addPatient(); break;
            case 3: hs.addDonor(); break;
            case 4: hs.displayAll(); break;
            case 5: {
                string spec;
                cout << "Enter Specialization to Search: ";
                cin.ignore();
                getline(cin, spec);
                hs.checkDoctorAvailability(spec);
                break;
            }
            case 6: {
                string bg;
                cout << "Enter Blood Group to Search: ";
                cin >> bg;
                hs.searchDonorByBloodGroup(bg);
                break;
            }
            case 7: hs.deleteRecord(); break;
            case 8: hs.updateRecord(); break;
            case 9:
                cout << "Exiting program...\n";
                return 0;
            default:
                cout << "Invalid choice. Try again.\n";
        }
    }
}