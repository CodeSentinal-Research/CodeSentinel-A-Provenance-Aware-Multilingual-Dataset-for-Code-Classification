Sure, here is the Python code:

def isValidHeap():
    N = int(input().strip())
    A = [int(i) for i in input().strip().split()]
    if N == 1:
        print('YES')
        return
    A.insert(0,0)
    for i in range(1, N+1):
        if A[i] > A[2*i] or (2*i+1 < N and A[i] > A[2*i+1]):
            print('NO')
            return
    print('YES')

isValidHeap()

This function takes an input as N and an array A (level-order traversal of a complete binary tree). It inserts a dummy node at the 0th index. Then for each node, it checks if the current node is greater than its children or if the current node is not a leaf node (the last node in the array) and if either of these conditions is true, it returns 'NO'. If none of these conditions are true, it means that the tree is a valid max heap and it returns 'YES'.

Please note that this code assumes that the given input is a level-order traversal of a complete binary tree. If the input is not a complete binary tree, this code may not work correctly.