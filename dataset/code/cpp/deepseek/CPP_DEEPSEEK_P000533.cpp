Here is a C++ solution for the given problem:

#include <iostream>
#include <deque>

using namespace std;

class MovingAverage {
public:
    deque<int> data;
    int size;

    MovingAverage(int size) : size(size) {

    }

    void next(int val) {
        data.push_back(val);
        if (data.size() > size) {
            data.pop_front();
        }
    }

    double findMovingAverage() {
        double sum = 0;
        for (int num : data) {
            sum += num;
        }
        return sum / data.size();
    }
};

int main() {
    int size, q;
    cin >> size >> q;

    MovingAverage movingAverage(size);

    for (int i = 0; i < q; i++) {
        int val;
        cin >> val;
        movingAverage.next(val);
        cout << "Current moving average: " << movingAverage.findMovingAverage() << endl;
    }

    return 0;
}

This code defines a class `MovingAverage` with a deque (double-ended queue) of integers. The `next` method is used to add a new number to the queue and remove the oldest number if the queue size exceeds the window size. The `findMovingAverage` method calculates the sum of the last size numbers and returns the average. In the `main` function, it reads the window size and the number of queries, then creates a `MovingAverage` object for each query.