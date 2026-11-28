def is_complete_binary_heap(parent_indices, n):
    for i in range(n):
        parent = parent_indices[i]
        if (parent is not None and (parent * 2 + 1 < n and parent_indices[parent * 2 + 1] < parent_indices[i])) or (parent is not None and (parent * 2 + 2 < n and parent_indices[parent * 2 + 2] > parent_indices[i])):
            return 'NO'
    return 'YES'

def main():
    n = int(input().strip())
    parent_indices = list(map(int, input().strip().split()))
    print(is_complete_binary_heap(parent_indices, n))

if __name__ == "__main__":
    main()