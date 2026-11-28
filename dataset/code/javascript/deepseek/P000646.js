Here is a JavaScript solution that uses a min-heap data structure to merge the doubly linked lists:

class Node {
    constructor(data) {
        this.data = data;
        this.next = null;
        this.prev = null;
    }
}

class DoublyLinkedList {
    constructor() {
        this.head = null;
        this.tail = null;
    }
    
    push(data) {
        let node = new Node(data);
        
        if (this.head === null) {
            this.head = node;
            this.tail = this.head;
        } else {
            node.prev = this.tail;
            this.tail.next = node;
            this.tail = node;
        }
    }
}

class MergeLists {
    constructor() {}
    
    mergeKLists(lists) {
        let head = null;
        let tail = null;
        let minHeap = [];
        
        for (let i = 0; i < lists.length; i++) {
            if (lists[i] !== null) {
                minHeap.push({ node: lists[i], next: lists[i].next });
                lists[i] = lists[i].next;
            }
        }
        
        while (minHeap.length) {
            let minNode = minHeap[0];
            
            if (head === null) {
                head = minNode.node;
                tail = minNode.node;
            } else {
                tail.next = minNode.node;
                minNode.node.prev = tail;
                tail = minNode.node;
            }
            
            minHeap[0].next = minHeap[1] ? minHeap[1] : null;
            
            if (minHeap[0].next) {
                let temp = minHeap[0].next;
                if (temp !== minHeap[1]) {
                    minHeap[1] = temp;
                    minHeap[1].prev = minHeap[0];
                }
            }
            
            if (minHeap[0].next === null) {
                minHeap.shift();
            } else {
                minHeap[0] = minHeap[1];
            }
        }
        
        return head;
    }
}
This code defines a Node class for the doubly linked list and a DoublyLinkedList class for creating a doubly linked list. The MergeLists class has a method `mergeKLists` that takes an array of linked lists as input, uses a min-heap to merge the linked lists into a single sorted linked list. The min-heap is a binary heap where the parent node is always smaller than or equal to its child node(s).

In the `mergeKLists` method, we start with an empty min-heap. We add all linked lists to the min-heap one by one. The min-heap will always have the smallest node at the top. We also need to record the next pointer of the linked list that we are currently considering. We then pop the smallest node from the min-heap, add it to the sorted linked list, and update the next pointer of the previous node in the sorted list to the next node in the linked list we are currently considering. 

Finally, we return the head of the sorted linked list.