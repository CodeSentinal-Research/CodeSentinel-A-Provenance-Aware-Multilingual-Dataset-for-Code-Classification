Sure, here is the C++ code:

#include <iostream>
#include <unordered_map>
#include <vector>

using namespace std;

struct Order {
    int id;
    string details;
};

int main() {
    int n, id;
    cin >> n;
    vector<Order> orders(n);
    unordered_map<int, int> orderMap;
    for (int i = 0; i < n; i++) {
        cin >> orders[i].id >> orders[i].details;
        orderMap[orders[i].id] = i;
    }
    cin >> id;
    if (orderMap.find(id) != orderMap.end()) {
        cout << orders[orderMap[id]].details;
    } else {
        cout << "Order Not Found";
    }
    return 0;
}
This code reads the number of orders and then the orders themselves. It also builds an unordered map (hash table) where the order IDs are the keys and the indices are the values. This makes searching for an order by ID faster. The code then reads the ID of the order to find, and if the ID is in the map, it prints the details of the order. If not, it prints "Order Not Found".