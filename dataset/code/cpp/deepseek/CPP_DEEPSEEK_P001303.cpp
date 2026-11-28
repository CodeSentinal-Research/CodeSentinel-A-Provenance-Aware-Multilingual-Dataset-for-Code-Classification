#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

struct Project {
    int required_investment;
    int expected_profit;
};

bool compare(Project a, Project b) {
    return a.expected_profit > b.expected_profit;
}

int main() {
    int N, K, InitialCapital;
    cin >> N >> K >> InitialCapital;
    
    vector<Project> projects(N);
    for (int i = 0; i < N; i++) {
        cin >> projects[i].required_investment >> projects[i].expected_profit;
    }
    
    sort(projects.begin(), projects.end(), compare);
    
    for (int i = 0; i < N && K > 0; i++) {
        if (InitialCapital >= projects[i].required_investment) {
            InitialCapital += projects[i].expected_profit;
            K--;
        }
    }
    
    cout << InitialCapital;
    
    return 0;
}