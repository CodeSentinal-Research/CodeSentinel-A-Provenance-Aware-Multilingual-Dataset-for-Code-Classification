#include <iostream>
#include <vector>
#include <queue>

using namespace std;

bool canFormHand(vector<int> &cards, int k) {
    if (cards.size() % k != 0) {
        return false;
    }

    unordered_map<int, int> count;
    for (int card : cards) {
        ++count[card];
    }

    priority_queue<int, vector<int>, greater<int>> pq;
    for (auto pair : count) {
        pq.push(pair.first);
    }

    while (!pq.empty()) {
        int currentCard = pq.top();
        pq.pop();

        int repeats = count[currentCard];
        for (int i = 1; i < repeats; ++i) {
            if (pq.find(currentCard + i) == pq.end()) {
                return false;
            }
        }
    }

    return true;
}

int main() {
    int n, k;
    cin >> n >> k;

    vector<int> cards(n);
    for (int i = 0; i < n; ++i) {
        cin >> cards[i];
    }

    if (canFormHand(cards, k)) {
        cout << "YES";
    } else {
        cout << "NO";
    }

    return 0;
}