#include <iostream>
#include <vector>
#include <queue>
#include <tuple>

using namespace std;

struct Order {
    int id;
    int dueDate;
};

vector<Order> findOrdersPendingMoreThanNDays(vector<Order>& orders, int n) {
    priority_queue<tuple<int, int, int>, vector<tuple<int, int, int>>, greater<tuple<int, int, int>>> pq;
    for (auto& order : orders) {
        pq.push({order.dueDate, order.id});
    }

    vector<Order> result;
    while (!pq.empty()) {
        auto [dueDate, id] = pq.top();
        pq.pop();
        if (dueDate <= n) {
            result.push_back({id});
        } else {
            break;
        }
    }

    return result;
}

int main() {
    int n;
    cin >> n;

    int numOrders;
    cin >> numOrders;

    vector<Order> orders(numOrders);
    for (int i = 0; i < numOrders; ++i) {
        orders[i].id = i + 1;
        cin >> orders[i].dueDate;
    }

    auto result = findOrdersPendingMoreThanNDays(orders, n);
    for (auto& order : result) {
        cout << order.id << '\n';
    }

    return 0;
}
This code first reads the number of days and the number of orders. Then it reads the due dates of the orders. The findOrdersPendingMoreThanNDays function uses a priority queue to store the due dates and their corresponding order ids. It then pops the top element from the queue, checks if the due date is less than or equal to the input number of days, and if so, adds the order to the result. If not, it breaks out of the loop. Finally, the result is printed out.