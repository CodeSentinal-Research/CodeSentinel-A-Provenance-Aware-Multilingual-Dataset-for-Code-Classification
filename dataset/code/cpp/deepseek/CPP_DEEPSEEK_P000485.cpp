#include <iostream>
#include <vector>
#include <stack>

using namespace std;

vector<int> asteroidCollision(vector<int> asteroids) {
    stack<int> s;
    for (int asteroid : asteroids) {
        while (!s.empty() && asteroid < 0 && s.top() > 0) {
            if (s.top() < -asteroid) {
                s.pop();
            } else if (s.top() == -asteroid) {
                s.pop();
                break;
            } else {
                break;
            }
        }
        s.push(asteroid);
    }

    vector<int> result;
    while (!s.empty()) {
        result.push_back(s.top());
        s.pop();
    }

    return result;
}

int main() {
    vector<int> asteroids = {10, 2, -5, -1};
    vector<int> result = asteroidCollision(asteroids);
    for (int asteroid : result) {
        cout << asteroid << " ";
    }
    return 0;
}