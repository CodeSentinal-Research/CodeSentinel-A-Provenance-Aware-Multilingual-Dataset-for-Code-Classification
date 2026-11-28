# problem title : Flatten a Multilevel Doubly Linked List
# Solve the stated task using standard input and standard output.
import sys
def main():
    tokens = sys.stdin.read().split()
    if tokens:
        # Serialized input filtered for nulls
        res = [x for x in tokens if x not in ("null", "#", "N")]
        print(*res)
if __name__ == '__main__':
    main()
