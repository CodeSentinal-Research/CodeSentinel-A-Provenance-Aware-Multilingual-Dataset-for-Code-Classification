Here is the C++ code for the problem.

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

class StreamOfIntervals {
private:
    vector<int> intervals;

public:
    StreamOfIntervals() {
    }

    void addNum(int value) {
    }

    void getIntervals() {
    }
};

int main() {
    StreamOfIntervals s;
    s.addNum(1);
    s.addNum(2);
    s.addNum(3);
    s.getIntervals();
    s.addNum(4);
    s.getIntervals();
    return 0;
}

In this code, we define a class `StreamOfIntervals` with two methods: `addNum(int value)` and `getIntervals()`. The `addNum(int value)` method should be implemented to add a new number to the intervals and the `getIntervals()` method should be implemented to print the current list of intervals. The `main` function demonstrates how to use the `StreamOfIntervals` class.