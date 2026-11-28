Here is a JavaScript solution using Merge Sort algorithm for sorting a linked list.

class ListNode {
    constructor(val = 0, next = null) {
        this.val = val;
        this.next = next;
    }
}

function sortList(head) {
    if (!head || !head.next) {
        return head;
    }

    const middle = getMiddle(head);
    const nextToMiddle = middle.next;

    // Separate list into two parts
    middle.next = sortList(nextToMiddle);

    // Sort and merge two lists
    head = merge(head, sortList(middle.next));

    return head;
}

function getMiddle(head) {
    let fast = head;
    let slow = head;

    while(fast.next && fast.next.next) {
        slow = slow.next;
        fast = fast.next.next;
    }

    return slow;
}

function merge(l1, l2) {
    let dummy = new ListNode(0);
    let current = dummy;

    while(l1 && l2) {
        if (l1.val < l2.val) {
            current.next = l1;
            l1 = l1.next;
        } else {
            current.next = l2;
            l2 = l2.next;
        }
        current = current.next;
    }

    if (l1) {
        current.next = l1;
    } else {
        current.next = l2;
    }

    return dummy.next;
}

This solution uses Merge Sort algorithm to sort the linked list. It first finds the middle of the linked list, and then recursively sorts the two lists to the left of the middle. After that, it merges the two sorted lists together.

The time complexity of this solution is O(n log n), because we divide the list into two parts in each recursive call to `sortList`, which takes O(log n) time in each recursive call. The merge operation takes O(n) time, because it needs to traverse the two lists and combine them.

The space complexity is O(log n) for the recursive calls and O(1) for the list merge.