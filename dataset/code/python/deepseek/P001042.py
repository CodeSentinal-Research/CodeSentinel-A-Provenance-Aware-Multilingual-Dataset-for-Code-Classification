def find_leaf_nodes(heap):
    last_node_index = len(heap)

    for index in range(last_node_index-2, -1, -1):
        if heap[index] is None:
            print(heap[index])

def main():
    n = int(input().strip())

    heap = list(map(int, input().strip().split()))

    heap.append(None)

    find_leaf_nodes(heap)

if __name__ == "__main__":
    main()