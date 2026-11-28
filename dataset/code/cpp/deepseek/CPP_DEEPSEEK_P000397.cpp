#include <iostream>
#include <vector>

struct Order {
    int id;
    string status;
};

int main() {
    int n;
    cin >> n;

    vector<Order> orders(n);
    for (int i = 0; i < n; i++) {
        cin >> orders[i].id >> orders[i].status;
    }

    string status;
    cin >> status;

    for (const auto& order : orders) {
        if (order.status == status) {
            cout << order.id << endl;
        }
    }

    return 0;
}