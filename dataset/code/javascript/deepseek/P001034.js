Here is the JavaScript code for the problem:

class ListNode {
    constructor(val = 0, next = null) {
        this.val = val;
        this.next = next;
    }
}

class Solution {
    constructor() {
        this.head = null;
        this.tail = null;
    }

    mergeKLists(lists) {
        if (lists.length === 0) {
            return null;
        }
        
        this.head = new ListNode(null);
        this.tail = this.head;
        
        const h = new ListNode(null);
        const cmp = (a, b) => a.val - b.val;
        
        const hp = new MinHeap(cmp);
        
        for (let list of lists) {
            if (list !== null) {
                hp.insert(list);
            }
        }
        
        while (hp.size() > 0) {
            let node = hp.extractMin();
            this.tail.next = node;
            this.tail = node;
            if (node.next !== null) {
                hp.insert(node.next);
            }
        }
        
        return this.head.next;
    }
}

class MinHeap {
    constructor(cmp) {
        this.heap = [];
        this.cmp = cmp;
    }
    
    size() {
        return this.heap.length;
    }
    
    parent(i) {
        return Math.floor((i - 1) / 2);
    }
    
    insert(node) {
        this.heap.push(node);
        this.heapifyUp(this.heap.length - 1);
    }
    
    extractMin() {
        const ret = this.heap[0];
        const end = this.heap.pop();
        
        if (this.heap.length > 0) {
            this.heap[0] = end;
            this.heapifyDown(0);
        }

        return ret;
    }
    
    heapifyUp(i) {
        while (i > 0 && this.cmp(this.heap[this.parent(i)], this.heap[i]) > 0) {
            this.swap(this.parent(i), i);
            i = this.parent(i);
        }
    }
    
    heapifyDown(i) {
        while (2 * i + 1 < this.heap.length) {
            let left = 2 * i + 1;
            let right = 2 * i + 2;
            let smallest = i;
            
            if (right < this.heap.length && this.cmp(this.heap[right], this.heap[smallest]) < 0) {
                smallest = right;
            }
            
            if (this.cmp(this.heap[smallest], this.heap[i]) < 0) {
                this.swap(smallest, i);
                i = smallest;
            } else {
                break;
            }
        }
    }
    
    swap(i, j) {
        [this.heap[i], this.heap[j]] = [this.heap[j], this.heap[i]];
    }
}

This solution uses a MinHeap data structure to efficiently merge the K sorted linked lists. The MinHeap is used to extract the smallest node each time from the sorted lists. The smallest node is always in the root of the heap, and the time complexity for insertion and extraction is O(log N). The swap operation is used to maintain the heap property after each insertion or extraction.