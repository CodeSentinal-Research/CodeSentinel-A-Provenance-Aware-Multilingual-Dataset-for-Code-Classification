#include <iostream>
#include <unordered_map>

using namespace std;

int main() {
    int records;
    cin >> records;

    unordered_map<string, string> passportData;

    for(int i = 0; i < records; i++) {
        string passportNumber, name;
        cin >> passportNumber >> name;
        passportData[passportNumber] = name;
    }

    string searchPassportNumber;
    cin >> searchPassportNumber;

    if(passportData.find(searchPassportNumber) != passportData.end()) {
        cout << passportData[searchPassportNumber];
    } else {
        cout << "Passport Not Found";
    }

    return 0;
}