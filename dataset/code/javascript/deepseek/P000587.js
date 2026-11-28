Here is the JavaScript code:

class ListNode {
    constructor(val = 0, next = null) {
        this.val = val;
        this.next = next;
    }
}

class Solution {
    mergeKLists(lists) {
        let head = new ListNode();
        let current = head;
        let queue = [];

        lists.forEach((list, index) => {
            if (list) {
                queue.push({ list, index });
            }
        });

        while (queue.length) {
            queue.sort((a, b) => a.list.val - b.list.val);
            let node = queue.shift();
            current.next = node.list;
            current = current.next;

            if (node.list.next) {
                queue.push({ list: node.list.next, index: node.index });
            }
        }

        return head.next;
    }
}

This code creates a min heap (priority queue) to find the node with the smallest value among all the lists. Each time, we pop the smallest node from the queue, add it to the result list, and move on to the next node in the queue. When the queue becomes empty, we return the result list, which is the merged sorted linked list.