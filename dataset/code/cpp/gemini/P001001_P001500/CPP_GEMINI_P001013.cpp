#include <queue>
#include <vector>

class MedianFinder {
    std::priority_queue<int> small; // max-heap
    std::priority_queue<int, std::vector<int>, std::greater<int>> large; // min-heap

public:
    MedianFinder() {}

    void addNum(int num) {
        small.push(num);
        if (!small.empty() && !large.empty() && small.top() > large.top()) {
            large.push(small.top());
            small.pop();
        }
        if (small.size() > large.size() + 1) {
            large.push(small.top());
            small.pop();
        }
        if (large.size() > small.size()) {
            small.push(large.top());
            large.pop();
        }
    }

    double findMedian() {
        if (small.size() > large.size()) {
            return (double)small.top();
        }
        return (small.top() + large.top()) / 2.0;
    }
};