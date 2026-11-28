import sys
def main():
    tokens = sys.stdin.read().split()
    if tokens:
        cap = int(tokens[0])
        q = int(tokens[1])
        idx = 2
        queue = []
        for _ in range(q):
            cmd = tokens[idx]
            if cmd == "enQueue":
                val = int(tokens[idx+1])
                if len(queue) < cap:
                    queue.append(val)
                    print("true")
                else:
                    print("false")
                idx += 2
            elif cmd == "deQueue":
                if queue:
                    queue.pop(0)
                    print("true")
                else:
                    print("false")
                idx += 1
            elif cmd == "Front":
                print(queue[0] if queue else -1)
                idx += 1
            elif cmd == "Rear":
                print(queue[-1] if queue else -1)
                idx += 1
            elif cmd == "isEmpty":
                print("true" if len(queue) == 0 else "false")
                idx += 1
            elif cmd == "isFull":
                print("true" if len(queue) == cap else "false")
                idx += 1
if __name__ == '__main__':
    main()