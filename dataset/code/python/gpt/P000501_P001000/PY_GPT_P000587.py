# problem title : Merge K Sorted Linked Lists
# Solve the stated task using standard input and standard output.
import sys
def main():
    tokens = sys.stdin.read().split()
    if tokens:
        k = int(tokens[0])
        idx = 1
        all_vals = []
        for _ in range(k):
            size = int(tokens[idx])
            all_vals.extend(map(int, tokens[idx+1:idx+1+size]))
            idx += 1 + size
        all_vals.sort()
        print(*all_vals)
if __name__ == '__main__':
    main()
