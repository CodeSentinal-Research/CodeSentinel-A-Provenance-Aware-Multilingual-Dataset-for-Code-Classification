Here is the code:

#include <iostream>
#include <unordered_set>
#include <vector>

using namespace std;

int main() {
    int N, M;
    cin >> N >> M;

    unordered_set<string> firstSet;
    for(int i = 0; i < N; i++) {
        string s;
        cin >> s;
        firstSet.insert(s);
    }

    int commonCount = 0;
    for(int i = 0; i < M; i++) {
        string s;
        cin >> s;
        if(firstSet.find(s) != firstSet.end()) {
            commonCount++;
        }
    }

    cout << commonCount << endl;

    return 0;
}
This code first takes the number of strings in both arrays as input. Then it takes the strings themselves and adds them to a set. This is done for both arrays. 

Then it iterates over the second array and checks if the string is in the set of the first array. If it is, it increments the common count. 

Finally, it outputs the common count.