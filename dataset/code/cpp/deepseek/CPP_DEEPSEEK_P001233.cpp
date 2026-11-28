Here is a simple C++ solution for the Fractional Knapsack problem:

#include <iostream>
#include <algorithm>
using namespace std;

struct Item {
    int value;
    int weight;
    float ratio;
};

bool compare(Item a, Item b) {
    return a.ratio > b.ratio;
}

int main() {
    int N, W;
    cin >> N >> W;

    Item items[N];
    for (int i = 0; i < N; i++) {
        cin >> items[i].weight >> items[i].value;
        items[i].ratio = (float) items[i].value / items[i].weight;
    }

    sort(items, items + N, compare);

    float maxValue = 0.0;
    for (int i = 0; i < N; i++) {
        if (items[i].weight <= W) {
            maxValue += items[i].value;
            W -= items[i].weight;
        } else if (W > 0) {
            maxValue += items[i].value * (float) W / items[i].weight;
            W = 0;
        }
    }

    cout << maxValue << endl;

    return 0;
}
This program first reads the number of items and the knapsack capacity. Then, it reads the weights and values of each item and calculates the ratio of the value to the weight. The items are sorted in descending order of their ratio.

Then, it iterates through the sorted items and adds the value of the items to the maximum obtainable value if they can be added to the knapsack. If they can't, it adds the value of the items up to the knapsack capacity.

Finally, it prints the maximum obtainable value.