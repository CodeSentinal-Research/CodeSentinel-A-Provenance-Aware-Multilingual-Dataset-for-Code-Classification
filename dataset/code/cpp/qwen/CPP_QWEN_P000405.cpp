#include <iostream>
#include <vector>
#include <string>
using namespace std;
int main() {
    int n; string instructor; cin >> n >> instructor;
    vector<string> instructors(n);
    for(int i=0; i<n; i++) cin >> instructors[i];
    for(int i=0; i<n; i++) if(instructors[i] == instructor) cout << i+1 << " ";
    cout << endl;
    return 0;
}
