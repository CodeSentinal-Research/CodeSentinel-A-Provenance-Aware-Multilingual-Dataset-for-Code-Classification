# problem title : Design Ordered Dictionary Using Linked List
# Solve the stated task using standard input and standard output.
import sys
def main():
    tokens = sys.stdin.read().split()
    if tokens:
        q = int(tokens[0])
        idx = 1
        d = {}
        for _ in range(q):
            cmd = tokens[idx]
            if cmd == "put":
                k, v = tokens[idx+1], tokens[idx+2]
                d[k] = v
                idx += 3
            elif cmd == "get":
                k = tokens[idx+1]
                print(d.get(k, -1))
                idx += 2
            elif cmd == "remove":
                k = tokens[idx+1]
                if k in d: del d[k]
                idx += 2
            elif cmd == "firstKey":
                keys = sorted(d.keys())
                print(keys[0] if keys else "")
                idx += 1
            elif cmd == "lastKey":
                keys = sorted(d.keys())
                print(keys[-1] if keys else "")
                idx += 1
            elif cmd == "nextKey":
                k = tokens[idx+1]
                keys = sorted(d.keys())
                nxt = [x for x in keys if x > k]
                print(nxt[0] if nxt else "")
                idx += 2
            elif cmd == "previousKey":
                k = tokens[idx+1]
                keys = sorted(d.keys())
                prev = [x for x in keys if x < k]
                print(prev[-1] if prev else "")
                idx += 2
if __name__ == '__main__':
    main()
