Here is the C++ code for the problem:

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main() {
    int N, Budget;
    cin >> N >> Budget;

    vector<long long> chargeTimes(N);
    vector<long long> runningCosts(N);

    for (int i = 0; i < N; i++) {
        cin >> chargeTimes[i];
    }

    for (int i = 0; i < N; i++) {
        cin >> runningCosts[i];
    }

    long long sumChargeTimes = 0;
    for (int i = 0; i < N; i++) {
        sumChargeTimes += chargeTimes[i];
    }

    long long ans = 0;
    for (int i = 0; i < N; i++) {
        if (Budget >= sumChargeTimes - chargeTimes[i] + runningCosts[i]) {
            Budget -= sumChargeTimes - chargeTimes[i] + runningCosts[i];
            ans++;
        } else {
            break;
        }
    }

    cout << ans << "\n";

    return 0;
}

This code first reads the number of robots and the budget from the input. Then it reads the charge times and running costs of the robots from the input. 

Next, it calculates the total charge time of all robots. 

Then it iterates through the robots. If the remaining budget is sufficient to afford running costs plus the charge time of the robot, it will use the robot and update the budget. 

Finally, it outputs the maximum number of consecutive robots that can be operated without exceeding the budget.