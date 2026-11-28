Here is the C++ code that solves the problem:

#include <iostream>
#include <vector>

using namespace std;

int main() {
    int numDevices;
    cin >> numDevices;

    vector<bool> deviceStatuses(numDevices, false);

    for(int i = 0; i < numDevices; i++) {
        int status;
        cin >> status;
        deviceStatuses[i] = (status == 1);
    }

    cout << "Online devices:" << endl;
    for(int i = 0; i < numDevices; i++) {
        if(deviceStatuses[i]) {
            cout << i + 1 << endl;
        }
    }

    return 0;
}

In this code, we first input the number of devices, and then for each device, we input the status (1 if online, 0 otherwise). We use a boolean vector to store the status of each device. The status of each device is stored in the same index of the vector. Then, we print the indices of the online devices (+1 since indexing starts from 0 in C++) using a loop.