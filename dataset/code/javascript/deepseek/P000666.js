class ListNode {
    constructor(x) {
        this.val = x;
        this.bottom = null;
        this.left = null;
        this.right = null;
    }
}

var merge = function(list1, list2) {
    if (list1 === null) {
        return list2;
    }
    if (list2 === null) {
        return list1;
    }
    
    if (list1.val < list2.val) {
        list1.right = merge(list1.right, list2);
        list1.bottom = list1.right;
        return list1;
    } else {
        list2.right = merge(list1, list2.right);
        list2.bottom = list2.right;
        return list2;
    }
};

var sortedMerge = function(list1, list2) {
    if (list1 === null) {
        return list2;
    }
    if (list2 === null) {
        return list1;
    }
    
    if (list1.val < list2.val) {
        list1.right = sortedMerge(list1.right, list2);
        list1.bottom = list1.right;
        return list1;
    } else {
        list2.right = sortedMerge(list1, list2.right);
        list2.bottom = list2.right;
        return list2;
    }
};
This code defines the `ListNode` class and the `merge` function which merges two linked lists using bottom pointers. The `sortedMerge` function is a wrapper around the `merge` function which also handles the base cases where one or both of the input lists is `null`.