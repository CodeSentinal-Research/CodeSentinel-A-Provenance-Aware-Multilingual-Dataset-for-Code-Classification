import sys
from collections import defaultdict
def main():
    tokens = sys.stdin.read().split()
    if tokens:
        q = int(tokens[0])
        idx = 1
        counts = defaultdict(int)
        for _ in range(q):
            cmd = tokens[idx]
            if cmd == "inc":
                counts[tokens[idx+1]] += 1
                idx += 2
            elif cmd == "dec":
                key = tokens[idx+1]
                counts[key] -= 1
                if counts[key] == 0: del counts[key]
                idx += 2
            elif cmd == "getMaxKey":
                if counts:
                    max_val = max(counts.values())
                    for k, v in counts.items():
                        if v == max_val:
                            print(k); break
                else:
                    print("")
                idx += 1
            elif cmd == "getMinKey":
                if counts:
                    min_val = min(counts.values())
                    for k, v in counts.items():
                        if v == min_val:
                            print(k); break
                else:
                    print("")
                idx += 1
if __name__ == '__main__':
    main()