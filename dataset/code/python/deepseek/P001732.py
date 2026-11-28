def verify_threaded_binary_tree(nodes, pre_order_traversal):
    stack = []
    in_order_traversal = iter(pre_order_traversal)

    def read_value():
        val = next(in_order_traversal)
        if val != 'X':
            return int(val)
        else:
            inorder_val = next(in_order_traversal)
            if stack and stack[-1] == 'L':
                stack.pop()
                return read_value()
            else:
                stack.append('R')
                return read_value()

    def read_node():
        value = read_value()
        node = nodes.get(value)
        if node is None:
            node = nodes[value] = 0
        return node

    read_node()

    while stack:
        if stack[-1] == 'R':
            right_child = read_node()
        else:
            left_child = read_node()
            if not left_child and not right_child:
                stack.pop()
            else:
                return 'NO'

    return 'YES'


nodes = {}
pre_order_traversal = iter(input().split())
print(verify_threaded_binary_tree(nodes, pre_order_traversal))

This Python code reads input in a pre-order traversal format, which is the same format as the pre-order traversal of a binary tree. The code uses a stack to track the nodes visited in the in-order traversal. It also uses the pre-order traversal of the binary tree to verify the threaded binary tree.