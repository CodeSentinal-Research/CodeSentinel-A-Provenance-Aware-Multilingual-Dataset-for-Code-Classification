function insertAtBeginning(n, linkedList, value) {
    var newNode = {
        data: value,
        next: null
    };

    if (!n || n == 1) {
        newNode.next = linkedList;
        linkedList = newNode;
    } else {
        newNode.next = linkedList;
        linkedList.data = value;
        linkedList.next = insertAtBeginning(n-1, linkedList.next, value);
    }

    return linkedList;
}