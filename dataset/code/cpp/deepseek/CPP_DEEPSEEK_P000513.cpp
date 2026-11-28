Here is the code:

#include <iostream>
#include <vector>
#include <stack>

using namespace std;

class NestedInteger {
public:
    vector<NestedInteger> getList() { return vector<NestedInteger>(); }

    int getInteger() { return 0; }

    bool isInteger() { return false; }
};

class NestedIterator {
    stack<NestedInteger> s;
public:
    NestedIterator(vector<NestedInteger> &nestedList) {
        helper(nestedList);
    }

    void helper(const vector<NestedInteger> &nestedList) {
        for (auto it = nestedList.rbegin(); it != nestedList.rend(); ++it) {
            if (it->isInteger()) {
                s.push(*it);
            } else {
                helper(it->getList());
            }
        }
    }

    int next() {
        int res = s.top().getInteger();
        s.pop();
        return res;
    }

    bool hasNext() {
        while (!s.empty()) {
            if (s.top().isInteger()) {
                return true;
            } else {
                const vector<NestedInteger> &sublist = s.top().getList();
                s.pop();
                if (sublist.empty()) {
                    continue;
                }
                helper(sublist);
            }
        }
        return false;
    }
};

This C++ code uses a stack to implement an iterator for a nested list of integers. The helper function is used to construct the list from the end to the start in the stack. The next operation is simply to pop the top element from the stack and return it. The hasNext operation is to check if the stack is not empty and the top element is an integer. If it is, it pops the top element from the stack. If it's not an integer, it adds the sublist to the stack and returns true. If the stack is empty after popping, it returns false.