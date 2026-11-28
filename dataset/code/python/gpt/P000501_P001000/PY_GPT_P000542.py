# problem title : Design Front Middle Back Queue
# Solve the stated task using standard input and standard output.
import sys
def main():
    tokens = sys.stdin.read().split()
    if tokens:
        q = int(tokens[0])
        idx = 1
        queue = []
        for _ in range(q):
            cmd = tokens[idx]
            if cmd == "pushFront":
                queue.insert(0, int(tokens[idx+1]))
                idx += 2
            elif cmd == "pushMiddle":
                mid = len(queue) // 2
                queue.insert(mid, int(tokens[idx+1]))
                idx += 2
            elif cmd == "pushBack":
                queue.append(int(tokens[idx+1]))
                idx += 2
            elif cmd == "popFront":
                print(queue.pop(0) if queue else -1)
                idx += 1
            elif cmd == "popMiddle":
                if not queue:
                    print(-1)
                else:
                    mid = (len(queue) - 1) // 2
                    print(queue.pop(mid))
                idx += 1
            elif cmd == "popBack":
                print(queue.pop() if queue else -1)
                idx += 1
if __name__ == '__main__':
    main()
