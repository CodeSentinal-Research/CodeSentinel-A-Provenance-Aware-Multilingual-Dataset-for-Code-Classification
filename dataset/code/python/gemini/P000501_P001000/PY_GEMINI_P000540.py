import sys
def main():
    tokens = sys.stdin.read().split()
    if tokens:
        q = int(tokens[0])
        idx = 1
        queue = []
        for _ in range(q):
            cmd = tokens[idx]
            if cmd == "enqueue":
                queue.append(int(tokens[idx+1]))
                idx += 2
            elif cmd == "dequeue":
                if queue: print(queue.pop(0))
                idx += 1
            elif cmd == "front":
                if queue: print(queue[0])
                idx += 1
            elif cmd == "size":
                print(len(queue))
                idx += 1
            elif cmd == "isEmpty":
                print("true" if len(queue) == 0 else "false")
                idx += 1
if __name__ == '__main__':
    main()