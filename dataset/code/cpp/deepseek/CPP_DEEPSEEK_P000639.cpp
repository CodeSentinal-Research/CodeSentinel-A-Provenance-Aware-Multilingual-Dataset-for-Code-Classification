#include <iostream>
using namespace std;

int countNodes(Node* head) {
    int count = 0;
    Node* current = head;
    
    while (current != NULL) {
        count++;
        current = current->next;
    }
    
    return count;
}

int main() {
    int n;
    cin >> n;
    
    if (n < 0 || n > 100000) {
        cout << "Invalid input";
        return 0;
    }
    
    Node* head;
    cin >> head;
    
    int result = countNodes(head);
    
    cout << result;

    return 0;
}