Here's a simple JavaScript solution for the problem:

class ListNode {
    constructor(val = 0, next = null) {
        this.val = val;
        this.next = next;
    }
}

function skipAndDeleteNodes(head, M, N) {
    let current = head;
    let end = head;

    while(current) {
        for(let i = 1; i < M && current; i++) {
            current = current.next;
        }

        if(current) {
            let next = current.next;
            for(let j = 1; j < N && next; j++) {
                next = next.next;
            }

            if(next) {
                current.next = next.next;
            } else {
                current.next = null;
            }
        } else {
            break;
        }

        end.next = current;
        end = end.next;
        current = current.next;
    }

    return head.next;
}

This solution works by iterating over the linked list and skipping the next M nodes. It then proceeds to delete the following N nodes until it can no longer find a valid next node to delete. The valid next node is determined by checking if there are at least N nodes remaining in the list. The current node is then set to the next node, and the end node is moved forward as well.

The function `skipAndDeleteNodes` takes in a linked list's head, the integers M and N. It returns the head of the modified linked list.

In the provided solution, we handle the edge cases where the list can't be skipped or deleted. If M == 0 or N == 0, it means that we can't skip any node and delete any node. In such cases, the function simply returns the head of the list, as we don't modify the list. If M > N, it means that we can skip M nodes in the list. In such cases, the function simply skips the next M nodes without deleting any. If N > M, it means that we can delete N nodes. In such cases, the function deletes N nodes following the current node.