Here is the JavaScript code for the given problem:

function getIntersectionNode(headA, headB) {
    if (headA === null || headB === null) {
        return null;
    }

    let p1 = headA;
    let p2 = headB;

    // Let's call these pointers as 'slow' and 'fast'
    while (p1 !== p2) {
        p1 = p1 ? p1.next : headB;
        p2 = p2 ? p2.next : headA;
    }

    return p1;
}

This JavaScript function `getIntersectionNode` takes two linked lists' heads as parameters. It uses a variation of the Floyd's cycle-finding algorithm to find the intersection node, which is a common node in both linked lists.

The algorithm works by using two pointers, `p1` and `p2`, which traverse the two linked lists. If `p1` and `p2` are not equal, they move to the next node in each list. If they are equal, they are at the intersection node. If either `p1` or `p2` reaches the end of the list, it means they do not intersect, and it returns `null`.