#include <iostream>
#include <stack>
#include <string>

int calculateScore(std::stack<int>& scores) {
    int total = 0;
    while(!scores.empty()) {
        total += scores.top();
        scores.pop();
    }
    return total;
}

int main() {
    int n, score;
    std::string operation;
    std::stack<int> scores;

    std::cin >> n;
    for(int i = 0; i < n; i++) {
        std::cin >> operation;
        if(operation == "+") {
            std::cin >> score;
            if(!scores.empty()) {
                int sum = scores.top() + score;
                scores.pop();
                scores.push(sum);
            } else {
                scores.push(score);
            }
        } else if(operation == "D") {
            std::cin >> score;
            if(!scores.empty()) {
                int doubled = 2 * scores.top();
                scores.pop();
                scores.push(doubled);
            } else {
                scores.push(score);
            }
        } else if(operation == "C") {
            if(!scores.empty()) {
                scores.pop();
            }
        } else {
            scores.push(stoi(operation));
        }
    }

    std::cout << calculateScore(scores);

    return 0;
}