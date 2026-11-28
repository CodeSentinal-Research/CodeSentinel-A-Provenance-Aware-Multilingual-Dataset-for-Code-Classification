Here is a simple implementation of the RecentCounter problem in C++.

#include <iostream>
#include <vector>
#include <deque>

class RecentCounter {
public:
    std::deque<int> q;

    RecentCounter() {

    }

    int ping(int t) {
        q.push_back(t);

        while (q.front() < t - 3000) {
            q.pop_front();
        }

        return q.size();
    }
};

int main() {
    RecentCounter counter;
    std::cout << counter.ping(1) << std::endl;
    std::cout << counter.ping(1000) << std::endl;
    std::cout << counter.ping(2000) << std::endl;
    std::cout << counter.ping(3000) << std::endl;
    std::cout << counter.ping(4000) << std::endl;
    return 0;
}

This program uses a deque (double-ended queue) to store the incoming timestamps. It pops out the older ones when the new one is too old. The size of the deque represents the count of recent requests within the last 3000 milliseconds. In the main function, we test the RecentCounter with several timestamps, and the program will print the number of recent requests after each timestamp.