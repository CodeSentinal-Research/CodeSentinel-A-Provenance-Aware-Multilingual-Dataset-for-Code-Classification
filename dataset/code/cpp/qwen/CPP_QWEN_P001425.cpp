#include <iostream>
#include <string>
#include <vector>
#include <unordered_set>
using namespace std;

int main() {
    int n;
    cin >> n;
    unordered_set<string> sources, destinations;
    
    for (int i = 0; i < n; ++i) {
        string src, dst;
        cin >> src >> dst;
        sources.insert(src);
        destinations.insert(dst);
    }
    
    for (const string& d : destinations) {
        if (sources.find(d) == sources.end()) {
            cout << d << endl;
            return 0;
        }
    }
    
    return 0;
}
