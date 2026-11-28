#include <iostream>
#include <vector>
#include <string>
using namespace std;
int main() {
    int n; string author, genre; cin >> n >> author >> genre;
    vector<string> authors(n), genres(n);
    for(int i=0; i<n; i++) { cin >> authors[i] >> genres[i]; }
    for(int i=0; i<n; i++) if(authors[i] == author && genres[i] == genre) cout << i+1 << " ";
    cout << endl;
    return 0;
}
