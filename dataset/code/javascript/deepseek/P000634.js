Here is a JavaScript solution for the problem. The idea is to use a HashMap (JavaScript object) to store each node in the original list and its corresponding copy. For each node in the original list, we create a new node in the copied list and assign the `next` pointer to the corresponding node in the copied list. The `random` pointer in the copied list is set to the `random` pointer in the original list.

class Node {
    constructor(val, next = null, random = null) {
        this.val = val;
        this.next = next;
        this.random = random;
    }
}

function cloneList(head) {
    let nodeMap = new Map();
    let newHead = new Node(head.val);
    nodeMap.set(head, newHead);
    head = head.next;
    let current = newHead;
    
    while (head !== null) {
        if (!nodeMap.has(head)) {
            nodeMap.set(head, new Node(head.val));
        }
        current.next = nodeMap.get(head);
        if (head.random !== null) {
            if (!nodeMap.has(head.random)) {
                nodeMap.set(head.random, new Node(head.random.val));
            }
            current.random = nodeMap.get(head.random);
        }
        current = current.next;
        head = head.next;
    }
    return newHead;
}

This function takes as input the head of the list, and returns the head of the cloned list. The time complexity is O(n) where n is the number of nodes in the original list, and the space complexity is O(n) because of the hashmap.