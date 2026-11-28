#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

bool compare(pair<int, double> a, pair<int, double> b) {
    return a.second < b.second;
}

double minCostToHire(vector<int> qualities, vector<double> wages, int k) {
    vector<pair<int, double>> workers;
    for(int i = 0; i < qualities.size(); i++) {
        workers.push_back(make_pair(qualities[i], wages[i]));
    }
    
    sort(workers.begin(), workers.end(), compare);
    
    double cost = 0;
    for(int i = 0; i < k; i++) {
        cost += workers[i].first;
    }
    
    return cost;
}

int main() {
    int n, k;
    cin >> n >> k;
    
    vector<int> qualities(n);
    vector<double> wages(n);
    
    for(int i = 0; i < n; i++) {
        cin >> qualities[i];
    }
    
    for(int i = 0; i < n; i++) {
        cin >> wages[i];
    }
    
    double result = minCostToHire(qualities, wages, k);
    
    cout << fixed;
    cout.precision(2);
    cout << result << endl;
    
    return 0;
}