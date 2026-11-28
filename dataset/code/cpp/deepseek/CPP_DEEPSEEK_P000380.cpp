#include <iostream>
#include <map>
using namespace std;

int main() {
    int numHotels;
    cin >> numHotels;
    map<int, string> hotelRecords;

    for(int i = 0; i < numHotels; i++) {
        int hotelID;
        string hotelName;
        cin >> hotelID >> hotelName;
        hotelRecords[hotelID] = hotelName;
    }

    int searchID;
    cin >> searchID;

    if(hotelRecords.find(searchID) != hotelRecords.end()) {
        cout << hotelRecords[searchID];
    } else {
        cout << "Hotel Not Found";
    }

    return 0;
}