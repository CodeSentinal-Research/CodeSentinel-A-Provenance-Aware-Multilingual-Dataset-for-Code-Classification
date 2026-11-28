#include <unordered_map>
#include <stack>

class FreqStack {
    std::unordered_map<int, int> freq;
    std::unordered_map<int, std::stack<int>> group;
    int maxFreq;
public:
    FreqStack() : maxFreq(0) {}

    void push(int val) {
        int f = ++freq[val];
        if (f > maxFreq) maxFreq = f;
        group[f].push(val);
    }

    int pop() {
        int val = group[maxFreq].top();
        group[maxFreq].pop();
        freq[val]--;
        if (group[maxFreq].empty()) maxFreq--;
        return val;
    }
};