Here's the JavaScript code to solve this problem. This code uses a MinHeap to store the elements of all lists. The smallest element in the heap will be at the top. Then it pops the smallest element from the heap and adds it to the result range. Then it removes the smallest element from its list and adds the next element if it exists. Repeat the process until the heap is empty.

class ListNode {
    constructor(val) {
        this.val = val;
        this.next = null;
    }
}

class Solution {
    smallestRange(lists) {
        const queue = new PriorityQueue((a, b) => a.val - b.val);
        for (let list of lists) {
            if (list) queue.enqueue(list);
        }

        let range = [Infinity, -Infinity];
        while (!queue.isEmpty()) {
            const node = queue.dequeue();
            if (node.val < range[0]) range = [node.val, node.val];
            if (node.next) queue.enqueue(node.next);
        }

        return range;
    }
}


The PriorityQueue is a special data structure that always provides the smallest element in the collection. In this case, it is used to make sure that the smallest element in each list is always in the heap. 

In the smallestRange function, we first initialize the queue. Then we iterate over all the lists and add them to the queue. After that, we create a range variable with infinity as the smallest number and negative infinity as the largest number. Then we start a while loop that continues until the queue is empty. In the loop, we remove the smallest element from the queue and update the range. Then we add the next node of the smallest element to the queue. Finally, we return the range.