#include <iostream>
#include <queue>
#include <iomanip>
using namespace std;

class MovingAverage {
    queue<int> q; int sum, size;
public:
    MovingAverage(int sz) { size = sz; sum = 0; }
    double next(int val) {
        if (q.size() == size) { sum -= q.front(); q.pop(); }
        q.push(val); sum += val;
        return (double)sum / q.size();
    }
};

int main() {
    int sz, q_num; cin >> sz >> q_num;
    MovingAverage ma(sz);
    while(q_num--) { int val; cin >> val; cout << fixed << setprecision(5) << ma.next(val) << " "; }
    cout << endl;
    return 0;
}
