Here is the code:

#include <iostream>
#include <vector>
#include <string>

using namespace std;

int main() {
    int N;
    cin >> N;
    vector<string> strings(N);
    for(int i = 0; i < N; i++) {
        cin >> strings[i];
    }

    int longestIndex = 0;
    for(int i = 1; i < N; i++) {
        if(strings[i].length() > strings[longestIndex].length()) {
            longestIndex = i;
        }
    }

    cout << longestIndex << endl;

    return 0;
}

In this code, the main function takes the number of strings as input, reads them into a vector, and then finds the index of the longest string. The longest string is initialized to be at index 0 and the length of the longest string is compared with each other. If a longer string is found, the index is updated. Finally, the index of the longest string is printed out.