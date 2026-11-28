# problem title : Design Circular Deque Using Doubly Linked List
# Solve the stated task using standard input and standard output.
import sys
from collections import deque
def main():
    tokens = sys.stdin.read().split()
    if tokens:
        q = int(tokens[0])
        idx = 1
        dq = deque()
        for _ in range(q):
            cmd = tokens[idx]
            if cmd == "insertFront":
                val = int(tokens[idx+1])
                dq.appendleft(val)
                idx += 2
            elif cmd == "insertLast":
                val = int(tokens[idx+1])
                dq.append(val)
                idx += 2
            elif cmd == "deleteFront":
                if dq: dq.popleft()
                idx += 1
            elif cmd == "deleteLast":
                if dq: dq.pop()
                idx += 1
            elif cmd == "getFront":
                print(dq[0] if dq else -1)
                idx += 1
            elif cmd == "getRear":
                print(dq[-1] if dq else -1)
                idx += 1
            elif cmd == "isEmpty":
                print("true" if not dq else "false")
                idx += 1
            elif cmd == "size":
                print(len(dq))
                idx += 1
if __name__ == '__main__':
    main()
