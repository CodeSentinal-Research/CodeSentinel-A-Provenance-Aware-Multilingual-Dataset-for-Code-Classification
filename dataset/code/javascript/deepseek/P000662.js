function reverseKGroup(head, k) {
    let current = head;
    let start = head;
    let end = getEnd(start, k);

    while (current && end) {
        let next = current.next;
        if (end.next !== null) {
            let nextNext = end.next.next;
            let reversed = reverse(start, end);
            current.next = reversed;
            start = current;
            current = next;
            end = getEnd(start, k);
        } else {
            end = getEnd(start, k);
        }
   
        // remove this line if you want to run only on the first group of k
        if (start === head) {
            head = reversed;
        }
    }
    return head;
}

function getEnd(start, k) {
    for (let i = 0; i < k; i++) {
        if (!start) return null;
        start = start.next;
    }
    return start;
}

function reverse(start, end) {
    let prev = end;
    let current = start;
    while (current !== end) {
        let next = current.next;
        current.next = prev;
        prev = current;
        current = next;
    }
    start.next = prev;
    return start;
}