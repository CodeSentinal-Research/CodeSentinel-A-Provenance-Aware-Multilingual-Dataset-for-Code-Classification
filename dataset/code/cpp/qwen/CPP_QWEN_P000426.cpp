#include <iostream>
#include <vector>
#include <string>
using namespace std;
int main() {
    int n; double min_rating; cin >> n >> min_rating;
    vector<double> ratings(n);
    for(int i=0; i<n; i++) cin >> ratings[i];
    for(int i=0; i<n; i++) if(ratings[i] >= min_rating) cout << i+1 << " ";
    cout << endl;
    return 0;
}
