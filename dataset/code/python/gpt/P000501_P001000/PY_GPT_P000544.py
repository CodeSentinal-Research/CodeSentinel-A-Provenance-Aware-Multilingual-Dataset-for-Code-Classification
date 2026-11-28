# problem title : Open the Lock
# Solve the stated task using standard input and standard output.
import sys
from collections import deque
def main():
    tokens = sys.stdin.read().split()
    if tokens:
        d = int(tokens[0])
        deadends = set(tokens[1:1+d])
        target = tokens[1+d]
        if "0000" in deadends:
            print(-1)
            return
        if target == "0000":
            print(0)
            return
        q = deque([("0000", 0)])
        visited = set(deadends)
        visited.add("0000")
        while q:
            cur, dist = q.popleft()
            if cur == target:
                print(dist)
                return
            for i in range(4):
                digit = int(cur[i])
                for diff in (-1, 1):
                    nxt_digit = (digit + diff) % 10
                    nxt = cur[:i] + str(nxt_digit) + cur[i+1:]
                    if nxt not in visited:
                        visited.add(nxt)
                        q.append((nxt, dist + 1))
        print(-1)
if __name__ == '__main__':
    main()
