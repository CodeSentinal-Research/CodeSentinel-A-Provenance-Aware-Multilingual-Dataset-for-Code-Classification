# problem title : Insert into a Sorted Circular Linked List
# Solve the stated task using standard input and standard output.
import sys
def main():
    tokens = sys.stdin.read().split()
    if tokens:
        insert_val = int(tokens[-1])
        vals = list(map(int, tokens[:-1]))
        if not vals:
            print(insert_val)
            return
        vals.append(insert_val)
        vals.sort()
        print(*vals)
if __name__ == '__main__':
    main()
