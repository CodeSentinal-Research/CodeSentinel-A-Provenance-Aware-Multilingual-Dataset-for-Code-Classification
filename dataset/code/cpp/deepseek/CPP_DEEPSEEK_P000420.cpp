#include <iostream>
using namespace std;

int main() {
    int numSlots;
    cin >> numSlots;
    bool slots[numSlots]; 
    for (int i = 0; i < numSlots; i++) {
        slots[i] = false;
    }

    int numRequests;
    cin >> numRequests;
    for (int i = 0; i < numRequests; i++) {
        int slot;
        cin >> slot;
        slots[slot - 1] = true;
    }

    for (int i = 0; i < numSlots; i++) {
        if (!slots[i]) {
            cout << i + 1 << " ";
        }
    }

    return 0;
}