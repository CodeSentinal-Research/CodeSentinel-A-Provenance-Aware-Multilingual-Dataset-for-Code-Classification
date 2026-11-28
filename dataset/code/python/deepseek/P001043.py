def find_last_internal_node(heap):
    parent_node = heap[1]
    left_child_node = heap[2]
    right_child_node = heap[3]
    while True:
        if left_child_node is None:
            return parent_node
        if right_child_node is None:
            if parent_node == left_child_node:
                return parent_node
            else:
                parent_node = left_child_node
                left_child_node = heap[2]
        else:
            if parent_node == left_child_node or parent_node == right_child_node:
                return parent_node
            else:
                parent_node = right_child_node
                left_child_node = heap[2]
                right_child_node = heap[3]

def main():
    n = int(input().strip())
    heap = list(map(int, input().strip().split()))
    print(find_last_internal_node(heap))

if __name__ == "__main__":
    main()