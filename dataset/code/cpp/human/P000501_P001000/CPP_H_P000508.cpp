#include <iostream>
#include <stack>
#include <queue>

using namespace std;

// Problem 1: Tower of Hanoi using Stack
void move(stack<int>& src, stack<int>& dest, char source, char destination) {
    if (src.empty()) {
        cout << "Move disk " << dest.top() << " from " << destination << " to " << source << endl;
        src.push(dest.top());
        dest.pop();
    } else if (dest.empty()) {
        cout << "Move disk " << src.top() << " from " << source << " to " << destination << endl;
        dest.push(src.top());
        src.pop();
    } else if (src.top() < dest.top()) {
        cout << "Move disk " << src.top() << " from " << source << " to " << destination << endl;
        dest.push(src.top());
        src.pop();
    } else {
        cout << "Move disk " << dest.top() << " from " << destination << " to " << source << endl;
        src.push(dest.top());
        dest.pop();
    }
}

void printTowers(stack<int>& src, stack<int>& tmp, stack<int>& dest) {
    stack<int> temp;
    
    auto printStack = [](stack<int> s) {
        while (!s.empty()) {
            cout << s.top() << " ";
            s.pop();
        }
        cout << endl;
    };
    
    cout << "Tower A: "; printStack(src);
    cout << "Tower B: "; printStack(tmp);
    cout << "Tower C: "; printStack(dest);
    cout << endl;
}

void towerOfHanoi(int disks, stack<int>& src, stack<int>& tmp, stack<int>& dest) {
    char source = 'A', destination = 'C', temp = 'B';

    if (disks % 2 == 0) swap(destination, temp);

    for (int i = disks; i >= 1; --i) src.push(i);
    printTowers(src, tmp, dest);

    int totalMoves = (1 << disks) - 1;

    for (int i = 1; i <= totalMoves; ++i) {
        if (i % 3 == 1) move(src, dest, source, destination);
        else if (i % 3 == 2) move(src, tmp, source, temp);
        else move(tmp, dest, temp, destination);

        printTowers(src, tmp, dest);
    }
}

void Problem1() {
    cout << "----- Tower of Hanoi -----\n";
    int disks;
    cout << "Enter the number of disks: ";
    cin >> disks;

    stack<int> src, tmp, dest;
    towerOfHanoi(disks, src, tmp, dest);
}

// Problem 2: Browser History Simulation
class Browser {
    stack<string> backStack, forwardStack;
public:
    void visit(const string& url) {
        if (!backStack.empty()) forwardStack = stack<string>();  // Clear forward stack
        backStack.push(url);
    }

    string back() {
        if (backStack.size() <= 1) return "No previous URL in history.";
        forwardStack.push(backStack.top());
        backStack.pop();
        return backStack.top();
    }

    string forward() {
        if (forwardStack.empty()) return "No next URL in history.";
        string url = forwardStack.top();
        forwardStack.pop();
        backStack.push(url);
        return url;
    }
};

void Problem2() {
    Browser browser;
    while (true) {
        cout << "1 - Visit a new URL\n2 - Go back\n3 - Go forward\n4 - Exit\nChoose an option: ";
        int choice; cin >> choice;
        string url;

        switch (choice) {
        case 1:
            cout << "Enter URL: "; cin >> url;
            browser.visit(url);
            break;
        case 2:
            cout << "Back to: " << browser.back() << endl;
            break;
        case 3:
            cout << "Forward to: " << browser.forward() << endl;
            break;
        case 4:
            return;
        default:
            cout << "Invalid choice, try again.\n";
        }
    }
}

// Problem 3: Counting Visible People in a Queue
void visible(int heights[], int n, int visibleCounts[]) {
    stack<int> heightStack;
    
    for (int i = n - 1; i >= 0; --i) {
        int count = 0;
        while (!heightStack.empty() && heightStack.top() < heights[i]) {
            heightStack.pop();
            ++count;
        }
        if (!heightStack.empty()) ++count;
        visibleCounts[i] = count;
        heightStack.push(heights[i]);
    }
}

void Problem3() {
    int n;
    cout << "Enter the number of people: "; cin >> n;
    int heights[n], visibleCounts[n];
    
    cout << "Enter the heights:\n";
    for (int i = 0; i < n; ++i) cin >> heights[i];
    
    visible(heights, n, visibleCounts);
    
    cout << "Visible counts: ";
    for (int i = 0; i < n; ++i) cout << visibleCounts[i] << " ";
    cout << endl;
}

// Problem 4: Minimizing the Cost to Buy Fruits
class FruitQueue {
    queue<pair<int, int>> fruits;
    int totalCoins = 0;
public:
    void addFruit(int id, int price) {
        fruits.push({id, price});
    }

    int calculateMinCoins() {
        while (!fruits.empty()) {
            totalCoins += fruits.front().second;
            fruits.pop();
        }
        return totalCoins;
    }
};

void Problem4() {
    FruitQueue fruitQueue;
    int n, price;

    cout << "Enter the number of fruits: "; cin >> n;
    for (int i = 0; i < n; ++i) {
        cout << "Enter price of fruit " << i + 1 << ": "; cin >> price;
        fruitQueue.addFruit(i, price);
    }

    cout << "Minimum total cost: " << fruitQueue.calculateMinCoins() << endl;
}

int main() {
    int option;
    cout << "Select a problem (1-4): "; cin >> option;

    switch (option) {
    case 1: Problem1(); break;
    case 2: Problem2(); break;
    case 3: Problem3(); break;
    case 4: Problem4(); break;
    default: cout << "Invalid option!\n"; break;
    }

    return 0;
}
