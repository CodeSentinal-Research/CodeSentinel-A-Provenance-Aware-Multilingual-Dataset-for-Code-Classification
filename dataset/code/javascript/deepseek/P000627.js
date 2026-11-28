Here is a possible JavaScript solution for the problem:

class ListNode {
    constructor(val = 0, prev = null, next = null) {
        this.val = val;
        this.prev = prev;
        this.next = next;
    }
}

function reverseKGroup(head, k) {
    if(!head || k <=1) {
        return head;
    }

    let dummy = new ListNode(0), dummyHead = dummy;
    dummy.next = head;
    head.prev = dummy;

    while(head && head.next) {
        let groupEnd = head;
        for(let i = 0; i < k; i++) {
            if(groupEnd)
                groupEnd = groupEnd.next;
            else
                return dummyHead.next;
        }
        let nextGroupStart = head.next;
        if(groupEnd)
            groupEnd.next.prev = groupEnd.prev;

        groupEnd.prev.next = groupEnd.next;
        groupEnd.next = nextGroupStart;
        nextGroupStart.prev = groupEnd;
        nextGroupStart.next = groupEnd.next;
        if(head === dummy.next)
            dummyHead.next = groupEnd;
    }

    return dummyHead.next;
}

This solution uses a dummy node to handle edge cases where the list's length is less than `k`. It then uses three pointers to keep track of the group's start and end and the next group's start. The while loop iterates through each group of `k` nodes, and if it encounters the end of a group (which is not present in the list when the length is less than `k`), it breaks the loop. After each group is reversed, it adjusts the pointers accordingly. If the list's length is less than `k`, the last group will contain less than `k` nodes, so it does not need to be handled separately.

This solution assumes the input is a doubly linked list with each node containing an integer value. It also assumes the input is valid.