#include <iostream>
#include <vector>
#include <string>
using namespace std;
int main() {
    int n; string genre; cin >> n >> genre;
    vector<string> genres(n);
    for(int i=0; i<n; i++) cin >> genres[i];
    for(int i=0; i<n; i++) if(genres[i] == genre) cout << i+1 << " ";
    cout << endl;
    return 0;
}
