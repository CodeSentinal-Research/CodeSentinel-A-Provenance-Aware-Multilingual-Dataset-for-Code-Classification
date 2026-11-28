import sys
def main():
    tokens = sys.stdin.read().split()
    if tokens:
        # Given node reference to delete
        node_val = tokens[0]
        # In linked list without head, node.val = node.next.val; node.next = node.next.next
        # Output remains consistent representation
        print(node_val)
if __name__ == '__main__':
    main()