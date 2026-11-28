/*
 * ============================================================
 *   GYM MEMBERSHIP MANAGEMENT SYSTEM
 *   1st-Year CS Project | OOP + STL + File Handling
 * ============================================================
 *   Compile:  g++ -std=c++17 -o gym gym_management.cpp
 *   Run:      ./gym   (Linux/Mac)   gym.exe  (Windows)
 *   Login:    username = admin | password = gym123
 * ============================================================
 */

// bits/stdc++.h covers ALL standard headers — safest for MinGW/GCC on Windows
#include <bits/stdc++.h>

// Explicit includes (fix VS Code IntelliSense errors on Windows)
#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
#include <vector>
#include <algorithm>
#include <iomanip>
#include <limits>

using namespace std;

// ─────────────────────────────────────────────────────────────
//  CLASS: Membership
//  Stores the gym plan details for each member
// ─────────────────────────────────────────────────────────────
class Membership {
public:
    string planName;    // "Basic", "Premium", or "VIP"
    double monthlyFee;
    string startDate;   // Format: YYYY-MM-DD
    string expiryDate;  // Format: YYYY-MM-DD

    // Default constructor
    Membership()
        : planName("Basic"), monthlyFee(500.0),
          startDate("2025-01-01"), expiryDate("2025-12-31") {}

    // Parameterized constructor
    Membership(const string& plan, double fee,
               const string& start, const string& expiry)
        : planName(plan), monthlyFee(fee),
          startDate(start), expiryDate(expiry) {}

    // Serialize to pipe-separated string for CSV embedding
    string toCSV() const {
        return planName + "|" + to_string(monthlyFee)
             + "|" + startDate + "|" + expiryDate;
    }

    // Compare date strings directly (works for YYYY-MM-DD format)
    bool isExpired(const string& today) const {
        return expiryDate < today;
    }
};

// ─────────────────────────────────────────────────────────────
//  CLASS: Payment
//  Stores payment info for each member
// ─────────────────────────────────────────────────────────────
class Payment {
public:
    int    paymentID;
    double amount;
    string paymentDate;
    string status;   // "Paid" or "Pending"

    // Default constructor
    Payment()
        : paymentID(0), amount(0.0),
          paymentDate("2025-01-01"), status("Pending") {}

    // Parameterized constructor
    Payment(int id, double amt,
            const string& date, const string& st)
        : paymentID(id), amount(amt),
          paymentDate(date), status(st) {}

    // Serialize to pipe-separated string for CSV embedding
    string toCSV() const {
        return to_string(paymentID) + "|" + to_string(amount)
             + "|" + paymentDate + "|" + status;
    }
};

// ─────────────────────────────────────────────────────────────
//  CLASS: Member
//  Demonstrates COMPOSITION: contains Membership + Payment
// ─────────────────────────────────────────────────────────────
class Member {
public:
    int        memberID;
    string     name;
    string     phone;
    int        age;
    Membership membership;   // Composition
    Payment    payment;      // Composition

    // Default constructor
    Member()
        : memberID(0), name(""), phone(""), age(0) {}

    // Parameterized constructor
    Member(int id, const string& n, const string& ph, int a,
           const Membership& mem, const Payment& pay)
        : memberID(id), name(n), phone(ph), age(a),
          membership(mem), payment(pay) {}

    // Print a compact single-line table row
    void displayRow() const {
        cout << "  " << left
             << setw(8)  << memberID
             << setw(20) << name
             << setw(14) << phone
             << setw(6)  << age
             << setw(12) << membership.planName
             << setw(10) << payment.status
             << "\n";
    }

    // Print all details for one member
    void displayFull() const {
        cout << "\n  +------------------------------------------+\n";
        cout << "  |           MEMBER DETAILS                 |\n";
        cout << "  +------------------------------------------+\n";
        cout << "  ID          : " << memberID            << "\n";
        cout << "  Name        : " << name                << "\n";
        cout << "  Phone       : " << phone               << "\n";
        cout << "  Age         : " << age                 << "\n";
        cout << "  Plan        : " << membership.planName
             << "  (Rs." << fixed << setprecision(2)
             << membership.monthlyFee << "/month)\n";
        cout << "  Start Date  : " << membership.startDate  << "\n";
        cout << "  Expiry Date : " << membership.expiryDate << "\n";
        cout << "  Payment ID  : " << payment.paymentID     << "\n";
        cout << "  Amount      : Rs." << fixed << setprecision(2)
             << payment.amount                             << "\n";
        cout << "  Pay Date    : " << payment.paymentDate   << "\n";
        cout << "  Pay Status  : " << payment.status        << "\n";
        cout << "  +------------------------------------------+\n";
    }

    // Serialize to a full CSV line
    string toCSV() const {
        return to_string(memberID) + ","
             + name + ","
             + phone + ","
             + to_string(age) + ","
             + membership.toCSV() + ","
             + payment.toCSV();
    }
};

// ─────────────────────────────────────────────────────────────
//  CLASS: FileHandler
//  Handles all CSV read/write operations
// ─────────────────────────────────────────────────────────────
class FileHandler {
    string filename="gymm.txt";

public:
    explicit FileHandler(const string& fname) : filename(fname) {}

    // Save entire member list to CSV file
    void saveAll(const vector<Member>& members) {
        ofstream file(filename);
        if (!file.is_open()) {
            cerr << "  [ERROR] Cannot open file for saving.\n";
            return;
        }
        for (size_t i = 0; i < members.size(); i++) {
            file << members[i].toCSV() << "\n";
        }
        file.close();
    }

    // Load member list from CSV file at startup
    vector<Member> loadAll() {
        vector<Member> members;
        ifstream file(filename);
        if (!file.is_open()) {
            return members;  // No file on first run — that's OK
        }

        string line;
        while (getline(file, line)) {
            if (line.empty()) continue;

            // Split by comma into 6 fields:
            // [0]=memberID [1]=name [2]=phone [3]=age [4]=membership [5]=payment
            stringstream ss(line);
            string token;
            vector<string> fields;
            while (getline(ss, token, ',')) {
                fields.push_back(token);
            }
            if (fields.size() < 6) continue;

            // Parse membership sub-fields (pipe-separated)
            vector<string> mp;
            stringstream ms(fields[4]);
            while (getline(ms, token, '|')) {
                mp.push_back(token);
            }

            // Parse payment sub-fields (pipe-separated)
            vector<string> pp;
            stringstream ps(fields[5]);
            while (getline(ps, token, '|')) {
                pp.push_back(token);
            }

            if (mp.size() < 4 || pp.size() < 4) continue;

            Membership mem(mp[0], stod(mp[1]), mp[2], mp[3]);
            Payment    pay(stoi(pp[0]), stod(pp[1]), pp[2], pp[3]);
            Member     m(stoi(fields[0]), fields[1], fields[2],
                         stoi(fields[3]), mem, pay);
            members.push_back(m);
        }
        file.close();
        return members;
    }
};

// ─────────────────────────────────────────────────────────────
//  CLASS: GymManager
//  Main controller — menu-driven program logic
// ─────────────────────────────────────────────────────────────
class GymManager {
    vector<Member> members;
    FileHandler    fileHandler;
    string         TODAY;

    // ── Helper: bordered section heading ────────────────────
    void printHeader(const string& title) const {
        cout << "\n  +==========================================+\n";
        cout << "  |  " << left << setw(40) << title << "  |\n";
        cout << "  +==========================================+\n";
    }

    // ── Helper: table column labels ─────────────────────────
    void printTableHeader() const {
        cout << "\n  " << left
             << setw(8)  << "ID"
             << setw(20) << "Name"
             << setw(14) << "Phone"
             << setw(6)  << "Age"
             << setw(12) << "Plan"
             << setw(10) << "Payment"
             << "\n  " << string(70, '-') << "\n";
    }

    // ── Helper: check if ID already exists ──────────────────
    bool idExists(int id) const {
        for (size_t i = 0; i < members.size(); i++) {
            if (members[i].memberID == id) return true;
        }
        return false;
    }

    // ── Helper: get index of member by ID ───────────────────
    int findIndexByID(int id) const {
        for (int i = 0; i < (int)members.size(); i++) {
            if (members[i].memberID == id) return i;
        }
        return -1;
    }

    // ── Helper: safe integer input ───────────────────────────
    int getInt(const string& prompt) {
        int val;
        while (true) {
            cout << prompt;
            cin >> val;
            if (cin.fail()) {
                cin.clear();
                cin.ignore(numeric_limits<streamsize>::max(), '\n');
                cout << "  [!] Invalid input. Enter a number.\n";
            } else {
                cin.ignore();
                return val;
            }
        }
    }

    // ── Helper: read full line string ────────────────────────
    string getString(const string& prompt) {
        string val;
        cout << prompt;
        getline(cin, val);
        return val;
    }

    // ── Feature 1: Add new member ────────────────────────────
    void addMember() {
        printHeader("ADD NEW MEMBER");

        int id = getInt("  Enter Member ID       : ");
        if (idExists(id)) {
            cout << "  [!] ID " << id << " already exists. Use a unique ID.\n";
            return;
        }

        string name  = getString("  Enter Name             : ");
        string phone = getString("  Enter Phone            : ");
        int    age   = getInt("  Enter Age              : ");
        if (age <= 0) { cout << "  [!] Age must be > 0.\n"; return; }

        cout << "  Plans:\n";
        cout << "    1. Basic   - Rs.500/month\n";
        cout << "    2. Premium - Rs.1000/month\n";
        cout << "    3. VIP     - Rs.2000/month\n";
        int planChoice = getInt("  Choose Plan [1-3]      : ");

        string planName;
        double fee;
        if      (planChoice == 2) { planName = "Premium"; fee = 1000.0; }
        else if (planChoice == 3) { planName = "VIP";     fee = 2000.0; }
        else                      { planName = "Basic";   fee = 500.0;  }

        string startDate  = getString("  Start Date (YYYY-MM-DD)  : ");
        string expiryDate = getString("  Expiry Date (YYYY-MM-DD) : ");

        int    payID   = getInt("  Payment ID             : ");
        string payDate = getString("  Payment Date (YYYY-MM-DD): ");
        cout << "  Payment Status: 1.Paid  2.Pending\n";
        int sc     = getInt("  Choose [1-2]           : ");
        string status = (sc == 1) ? "Paid" : "Pending";

        Membership mem(planName, fee, startDate, expiryDate);
        Payment    pay(payID, fee, payDate, status);
        Member     newMem(id, name, phone, age, mem, pay);
        members.push_back(newMem);

        cout << "  [OK] Member \"" << name << "\" added!\n";
    }

    // ── Feature 2: View all members ──────────────────────────
    void viewAllMembers() const {
        printHeader("ALL MEMBERS");
        if (members.empty()) {
            cout << "  No members found.\n";
            return;
        }
        printTableHeader();
        for (size_t i = 0; i < members.size(); i++) {
            members[i].displayRow();
        }
        cout << "\n  Total: " << members.size() << " member(s)\n";
    }

    // ── Feature 3: Search by ID or name ──────────────────────
    void searchMember() {
        printHeader("SEARCH MEMBER");
        cout << "  1. Search by ID\n  2. Search by Name\n";
        int ch = getInt("  Choice: ");

        if (ch == 1) {
            int id  = getInt("  Enter Member ID: ");
            int idx = findIndexByID(id);
            if (idx == -1) cout << "  [!] Not found.\n";
            else           members[idx].displayFull();
        } else {
            string query  = getString("  Enter Name (partial OK): ");
            string qLower = query;
            transform(qLower.begin(), qLower.end(), qLower.begin(), ::tolower);

            bool found = false;
            for (size_t i = 0; i < members.size(); i++) {
                string mLower = members[i].name;
                transform(mLower.begin(), mLower.end(), mLower.begin(), ::tolower);
                if (mLower.find(qLower) != string::npos) {
                    members[i].displayFull();
                    found = true;
                }
            }
            if (!found) cout << "  [!] No match for \"" << query << "\".\n";
        }
    }

    // ── Feature 4: Update member ──────────────────────────────
    void updateMember() {
        printHeader("UPDATE MEMBER");
        int id  = getInt("  Enter Member ID to update: ");
        int idx = findIndexByID(id);
        if (idx == -1) { cout << "  [!] Member not found.\n"; return; }

        Member& m = members[idx];
        cout << "  1.Name  2.Phone  3.Age  4.Plan  5.Payment Status\n";
        int ch = getInt("  Choice: ");

        if (ch == 1) {
            m.name = getString("  New Name: ");
        } else if (ch == 2) {
            m.phone = getString("  New Phone: ");
        } else if (ch == 3) {
            int a = getInt("  New Age: ");
            if (a <= 0) { cout << "  [!] Invalid age.\n"; return; }
            m.age = a;
        } else if (ch == 4) {
            cout << "  1.Basic(500)  2.Premium(1000)  3.VIP(2000)\n";
            int pc = getInt("  Choose: ");
            if      (pc == 2) { m.membership.planName = "Premium"; m.membership.monthlyFee = 1000; }
            else if (pc == 3) { m.membership.planName = "VIP";     m.membership.monthlyFee = 2000; }
            else              { m.membership.planName = "Basic";   m.membership.monthlyFee = 500;  }
        } else if (ch == 5) {
            cout << "  1.Paid  2.Pending\n";
            int sc = getInt("  Choose: ");
            m.payment.status = (sc == 1) ? "Paid" : "Pending";
        } else {
            cout << "  [!] Invalid choice.\n"; return;
        }
        cout << "  [OK] Updated successfully!\n";
    }

    // ── Feature 5: Delete member ──────────────────────────────
    void deleteMember() {
        printHeader("DELETE MEMBER");
        int id  = getInt("  Enter Member ID to delete: ");
        int idx = findIndexByID(id);
        if (idx == -1) { cout << "  [!] Member not found.\n"; return; }

        cout << "  Deleting: " << members[idx].name
             << " (ID " << id << ")\n";
        cout << "  Confirm? [y/n]: ";
        char c; cin >> c; cin.ignore();

        if (c == 'y' || c == 'Y') {
            members.erase(members.begin() + idx);
            cout << "  [OK] Member deleted.\n";
        } else {
            cout << "  Cancelled.\n";
        }
    }

    // ── Feature 6: Show expired memberships ──────────────────
    void showExpiredMembers() const {
        printHeader("EXPIRED MEMBERSHIPS");
        printTableHeader();
        bool found = false;
        for (size_t i = 0; i < members.size(); i++) {
            if (members[i].membership.isExpired(TODAY)) {
                members[i].displayRow();
                found = true;
            }
        }
        if (!found) cout << "  No expired memberships.\n";
    }

    // ── Feature 7: Total revenue ──────────────────────────────
    void showTotalRevenue() const {
        printHeader("REVENUE REPORT");
        double total = 0.0;
        int paidCnt = 0, pendCnt = 0;
        for (size_t i = 0; i < members.size(); i++) {
            if (members[i].payment.status == "Paid") {
                total += members[i].payment.amount;
                paidCnt++;
            } else {
                pendCnt++;
            }
        }
        cout << "  Paid Members   : " << paidCnt << "\n";
        cout << "  Pending Members: " << pendCnt << "\n";
        cout << "  Total Revenue  : Rs." << fixed
             << setprecision(2) << total << "\n";
    }

    // ── Feature 8: Sort by name or ID ────────────────────────
    void sortMembers() {
        printHeader("SORT MEMBERS");
        cout << "  1. Sort by Name (A-Z)\n  2. Sort by ID\n";
        int ch = getInt("  Choice: ");

        if (ch == 1) {
            sort(members.begin(), members.end(),
                 [](const Member& a, const Member& b) {
                     return a.name < b.name;
                 });
            cout << "  [OK] Sorted by Name.\n";
        } else {
            sort(members.begin(), members.end(),
                 [](const Member& a, const Member& b) {
                     return a.memberID < b.memberID;
                 });
            cout << "  [OK] Sorted by ID.\n";
        }
        viewAllMembers();
    }

public:
    // Constructor: load data on startup
    explicit GymManager(const string& file)
        : fileHandler(file), TODAY("2026-04-27") {
        members = fileHandler.loadAll();
        cout << "  [OK] Loaded " << members.size()
             << " member(s) from file.\n";
    }

    void saveAndExit() {
        fileHandler.saveAll(members);
        cout << "  [OK] Data saved. Goodbye!\n";
    }

    // ── Login: 3 attempts allowed ────────────────────────────
    bool login() {
        const string ADMIN_USER = "krupal";
        const string ADMIN_PASS = "krupal21";
        printHeader("ADMIN LOGIN");
        string user = getString("  Username: ");
        string pass = getString("  Password: ");
        if (user == ADMIN_USER && pass == ADMIN_PASS) {
            cout << "  [OK] Welcome, Admin!\n";
            return true;
        }
        cout << "  [!] Wrong credentials.\n";
        return false;
    }

    // ── Main menu loop ───────────────────────────────────────
    void run() {
        int attempts = 0;
        while (attempts < 3) {
            if (login()) break;
            attempts++;
            if (attempts == 3) {
                cout << "  Too many failed attempts. Exiting.\n";
                return;
            }
        }

        while (true) {
            cout << "\n  +==========================================+\n";
            cout << "  |      GYM MEMBERSHIP MANAGEMENT           |\n";
            cout << "  +==========================================+\n";
            cout << "  |  1. Add New Member                       |\n";
            cout << "  |  2. View All Members                     |\n";
            cout << "  |  3. Search Member                        |\n";
            cout << "  |  4. Update Member Details                |\n";
            cout << "  |  5. Delete Member                        |\n";
            cout << "  |  6. Show Expired Memberships             |\n";
            cout << "  |  7. Show Total Revenue                   |\n";
            cout << "  |  8. Sort Members                         |\n";
            cout << "  |  9. Save & Exit                          |\n";
            cout << "  +==========================================+\n";

            int choice = getInt("  Enter choice [1-9]: ");
            switch (choice) {
                case 1: addMember();          break;
                case 2: viewAllMembers();     break;
                case 3: searchMember();       break;
                case 4: updateMember();       break;
                case 5: deleteMember();       break;
                case 6: showExpiredMembers(); break;
                case 7: showTotalRevenue();   break;
                case 8: sortMembers();        break;
                case 9: saveAndExit(); return;
                default: cout << "  [!] Enter 1-9.\n";
            }
        }
    }
};

// ─────────────────────────────────────────────────────────────
//  MAIN
// ─────────────────────────────────────────────────────────────
int main() {
    cout << "\n  +==========================================+\n";
    cout << "  |    GYM MEMBERSHIP MANAGEMENT SYSTEM      |\n";
    cout << "  |                                         |\n";
    cout << "  +==========================================+\n";

    GymManager gym("gym_data.csv");
    gym.run();
    return 0;
}
