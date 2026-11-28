Here is a simple implementation of the problem using C++:

#include <iostream>
#include <list>
#include <algorithm>

using namespace std;

class BrowserTabsManager {
public:
    list<int> tabs;

    void open(int url) {
        tabs.push_back(url);
    }

    void close(int index) {
        tabs.erase(find(tabs.begin(), tabs.end(), index));
    }

    void switchTab(int index) {
        for(auto it = tabs.begin(); it != tabs.end(); ++it) {
            if(*it == index) {
                tabs.splice(next(it), tabs, *it);
                break;
            }
        }
    }

    void moveLeft(int index) {
        for(auto it = tabs.begin(); it != tabs.end(); ++it) {
            if(*it == index) {
                if(it == tabs.begin()) return;
                tabs.splice(prev(it), tabs, *it);
                return;
            }
        }
    }

    void moveRight(int index) {
        for(auto it = tabs.begin(); it != tabs.end(); ++it) {
            if(*it == index) {
                if(next(it) == tabs.end()) return;
                tabs.splice(next(it), tabs, *it);
                return;
            }
        }
    }

    int current() {
        return *next(tabs.begin());
    }
};

int main() {
    BrowserTabsManager manager;

    manager.open(1);
    manager.open(2);
    manager.open(3);
    cout << manager.current() << endl;  
    manager.switchTab(2);
    cout << manager.current() << endl;  
    manager.moveRight(1);
    cout << manager.current() << endl;  
    manager.close(3);
    cout << manager.current() << endl;  

    return 0;
}

This implementation uses a linked list (std::list) to store the tabs. The open, close, switch, moveLeft, and moveRight operations all operate in O(n) time, where n is the number of tabs. The current operation returns the currently active tab in O(1) time.