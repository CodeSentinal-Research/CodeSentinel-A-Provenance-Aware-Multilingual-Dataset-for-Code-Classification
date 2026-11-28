#include<iostream>
#include<string>
#include<fstream>
#include<cstdlib>
#include<ctime>
#include<windows.h> 

using namespace std;

void setColor(int colorValue) {
    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), colorValue);
}

void showLoading(string message) {
    setColor(11); 
    cout << message;
    for (int i = 0; i < 3; i++) {
        Sleep(400);
        cout << ".";
    }
    cout << "\n";
    setColor(7); 
}

class train {
public:
    void get_details_train() {
        ifstream file("train.txt");
        if (!file) {
            setColor(12);
            cout << "\nError: train.txt file not found!\n";
            setColor(7);
            return;
        }

        int id, total, avail, price;
        string name, dep, arr, dtime, atime;

        setColor(14); 
        cout << "\n============================== TRAIN LIST ==============================\n";
        setColor(7);

        while (file >> id >> name >> dep >> arr >> dtime >> atime >> total >> avail >> price) {
            cout << "ID: " << id
                 << " | Name: " << name
                 << " | From: " << dep << " To: " << arr
                 << " | Dep: " << dtime << " Arr: " << atime
                 << " | Price: Rs. " << price;
            
            if (avail > 0) {
                setColor(10); 
                cout << " | Seats Available: " << avail << "/" << total << "\n";
            } else {
                setColor(12); 
                cout << " | Seats Available: FULL (" << avail << "/" << total << ")\n";
            }
            setColor(7);
        }
        setColor(14);
        cout << "========================================================================\n";
        setColor(7);
        file.close();
    }

    void search_train() {
        string from, to;
        cout << "Enter Source Station: ";
        cin >> from;
        cout << "Enter Destination Station: ";
        cin >> to;

        showLoading("Searching trains");

        ifstream file("train.txt");
        int id, total, avail, price;
        string name, dep, arr, dtime, atime;
        bool found = false;

        while (file >> id >> name >> dep >> arr >> dtime >> atime >> total >> avail >> price) {
            if (dep == from && arr == to) {
                found = true;
                setColor(10);
                cout << "\n--- Train Found! ---";
                setColor(7);
                cout << "\nTrain ID: " << id
                     << "\nName: " << name
                     << "\nDeparture: " << dtime
                     << "\nArrival: " << atime
                     << "\nSeats Available: " << avail << "/" << total
                     << "\nTicket Price: Rs. " << price
                     << "\n----------------------\n";
            }
        }
        if (!found) {
            setColor(12);
            cout << "No trains found for the given route!\n";
            setColor(7);
        }
        file.close();
    }
};

class Passenger {
private:
    string name;
    int age;
    string gender;

public:
    void getDetails() {
        cout << "Enter Passenger Name (Single name): ";
        cin >> name;
        cout << "Enter Age: ";
        cin >> age;
        cout << "Enter Gender: ";
        cin >> gender;
    }

    string getName() {
        return name;
    }
};

class ticket {
protected:
    Passenger p;
    string berth, source, destination;
    int train_id;
    int pnr;

public:
    int generatePNR() {
        return rand() % 90000 + 10000;
    }

    void trainbook() {
        p.getDetails();

        cout << "Enter Source: ";
        cin >> source;
        cout << "Enter Destination: ";
        cin >> destination;
        cout << "Enter Train ID: ";
        cin >> train_id;
        cout << "Select Berth (L/U/M/S): ";
        cin >> berth;

        ifstream file("train.txt");
        ofstream temp("temp.txt");

        int id, total, avail, price;
        string name, dep, arr, dtime, atime;
        bool found = false;

        while (file >> id >> name >> dep >> arr >> dtime >> atime >> total >> avail >> price) {
            if (id == train_id && avail > 0) {
                avail--;
                found = true;
                pnr = generatePNR();

                ofstream fout("tickets.txt", ios::app);
                fout << pnr << " " << p.getName() << " " << train_id << " "
                     << source << " " << destination << " " << berth << endl;
                fout.close();

                showLoading("Processing ticket booking");
                setColor(10);
                cout << "\n Seat Booked Successfully!\n";
                setColor(14);
                cout << "======================================\n";
                cout << " Your PNR: " << pnr << "\n";
                cout << " Berth Preference: " << berth << "\n";
                cout << "======================================\n";
                setColor(7);
            }
            temp << id << " " << name << " " << dep << " " << arr << " "
                 << dtime << " " << atime << " "
                 << total << " " << avail << " " << price << endl;
        }

        file.close();
        temp.close();

        remove("train.txt");
        rename("temp.txt", "train.txt");

        if (!found) {
            setColor(12);
            cout << "\nError: Train ID not found or no seats available.\n";
            setColor(7);
        }
    }

    void showTicket() {
        ifstream fin("tickets.txt");
        if (!fin) {
            setColor(12);
            cout << "No booking records found!\n";
            setColor(7);
            return;
        }

        int pnr_file, t_id;
        string uname, src, dest, b;
        
        setColor(11);
        cout << "\n========================= PASSENGER BOOKING DATA =========================\n";
        setColor(7);
        cout << "PNR\t\tPassenger\tTrain ID\tRoute\t\tBerth\n";
        cout << "--------------------------------------------------------------------------\n";

        while (fin >> pnr_file >> uname >> t_id >> src >> dest >> b) {
            cout << pnr_file << "\t\t" << uname << "\t\t" << t_id << "\t\t" 
                 << src << "->" << dest << "\t\t" << b << "\n";
        }
        setColor(11);
        cout << "==========================================================================\n";
        setColor(7);
        fin.close();
    }

    void cancelTicket() {
        int cancel_pnr;
        cout << "Enter PNR to cancel: ";
        cin >> cancel_pnr;

        ifstream fin("tickets.txt");
        ofstream temp("temp2.txt");

        int pnr_file, t_id;
        string name, src, dest, b;
        bool found = false;

        while (fin >> pnr_file >> name >> t_id >> src >> dest >> b) {
            if (pnr_file == cancel_pnr) {
                found = true;

                ifstream trainFile("train.txt");
                ofstream trainTemp("train_temp.txt");

                int id, total, avail, price;
                string tname, dep, arr, dtime, atime;

                while (trainFile >> id >> tname >> dep >> arr >> dtime >> atime >> total >> avail >> price) {
                    if (id == t_id) {
                        avail++;
                    }
                    trainTemp << id << " " << tname << " " << dep << " " << arr << " "
                              << dtime << " " << atime << " "
                              << total << " " << avail << " " << price << endl;
                }

                trainFile.close();
                trainTemp.close();

                remove("train.txt");
                rename("train_temp.txt", "train.txt");

                showLoading("Cancelling ticket");
                setColor(10);
                cout << " Ticket Cancelled Successfully!\n";
                setColor(7);
            } else {
                temp << pnr_file << " " << name << " " << t_id << " "
                     << src << " " << dest << " " << b << endl;
            }
        }

        fin.close();
        temp.close();

        remove("tickets.txt");
        rename("temp2.txt", "tickets.txt");

        if (!found) {
            setColor(12);
            cout << "No booking found with PNR " << cancel_pnr << "!\n";
            setColor(7);
        }
    }
};

class Review {
public:
    int review_id, user_id, train_number, rating;
    string user_name, train_name, comment;

    void getDetails() {
        cout << "Enter Review ID: "; cin >> review_id;
        cout << "Enter User ID: "; cin >> user_id;
        cout << "Enter Your Name: "; cin >> user_name;
        cout << "Enter Train Name: "; cin >> train_name;
        cout << "Enter Train Number: "; cin >> train_number;

        do {
            cout << "Enter Rating (1-5): ";
            cin >> rating;
        } while (rating < 1 || rating > 5);

        cout << "Enter Comment (Single-word or dashed): ";
        cin >> comment;
    }

    void addReview() {
        ofstream fout("review.txt", ios::app);
        fout << review_id << " " << user_id << " " << user_name << " " 
             << train_name << " " << train_number << " " << rating << " " << comment << endl;
        fout.close();

        showLoading("Posting your review");
        setColor(10);
        cout << "Review saved successfully!\n";
        setColor(7);
    }

    void showReview() {
        ifstream fin("review.txt");
        if (!fin) {
            setColor(12);
            cout << "No reviews posted yet!\n";
            setColor(7);
            return;
        }

        setColor(14);
        cout << "\n========================= REVIEWS & RATINGS =========================\n";
        setColor(7);
        while (fin >> review_id >> user_id >> user_name >> train_name >> train_number >> rating >> comment) {
            cout << "Review ID: " << review_id << " | User: " << user_name 
                 << " | Train: " << train_name << "(" << train_number << ")\n"
                 << "Rating: " << rating << "/5 | Comment: " << comment << "\n";
            cout << "---------------------------------------------------------------------\n";
        }
        fin.close();
    }
};

class Login {
    string username, password;

public:
    void signup() {
        setColor(11);
        cout << "=== USER SIGNUP ===\n";
        setColor(7);
        cout << "Enter username: "; cin >> username;
        cout << "Enter password: "; cin >> password;

        ofstream fout("users.txt", ios::app);
        fout << username << " " << password << endl;
        fout.close();

        showLoading("Creating account");
        setColor(10);
        cout << "Signup successful!\n\n";
        setColor(7);
    }

    bool login() {
        setColor(11);
        cout << "=== USER LOGIN ===\n";
        setColor(7);
        cout << "Enter username: "; cin >> username;
        cout << "Enter password: "; cin >> password;

        ifstream fin("users.txt");
        string u, p;
        while (fin >> u >> p) {
            if (u == username && p == password) {
                showLoading("Logging in");
                setColor(10);
                cout << "Login successful!\n";
                setColor(7);
                return true;
            }
        }
        setColor(12);
        cout << "Invalid username or password!\n";
        setColor(7);
        return false;
    }
};

int main() {
    srand(time(0));
    Login l;
    int ch;

    setColor(14);
    cout << "===============================================\n";
    cout << "      WELCOME TO THE RAILWAY PORTAL           \n";
    cout << "===============================================\n";
    setColor(7);

    cout << "1. Signup\n2. Login\nEnter Choice: ";
    cin >> ch;

    if (ch == 1) {
        l.signup();
    }

    if (!l.login()) {
        return 0;
    }

    int choice;
    do {
        setColor(11);
        cout << "\n=============== MAIN MENU ===============\n";
        setColor(7);
        cout << "1. View Trains & Available Seats\n";
        cout << "2. Search Trains\n";
        cout << "3. Book Ticket\n";
        cout << "4. Cancel Ticket\n";
        cout << "5. Passenger Booking Data (Admin View)\n";
        cout << "6. Add Review\n";
        cout << "7. View Reviews\n";
        cout << "8. Exit Portal\n";
        cout << "=========================================\n";
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice) {
            case 1: {
                train t;
                t.get_details_train();
                break;
            }
            case 2: {
                train t;
                t.search_train();
                break;
            }
            case 3: {
                ticket t;
                t.trainbook();
                break;
            }
            case 4: {
                ticket t;
                t.cancelTicket();
                break;
            }
            case 5: {
                ticket t;
                t.showTicket();
                break;
            }
            case 6: {
                Review r;
                r.getDetails();
                r.addReview();
                break;
            }
            case 7: {
                Review r;
                r.showReview();
                break;
            }
            case 8:
                setColor(14);
                cout << "Thank you for using the Railway Portal. Exiting...\n";
                setColor(7);
                break;
            default:
                setColor(12);
                cout << "Invalid Option! Try again.\n";
                setColor(7);
        }
    } while (choice != 8);

    return 0;
}