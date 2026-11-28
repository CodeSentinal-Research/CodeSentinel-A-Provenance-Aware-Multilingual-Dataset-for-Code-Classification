# problem title : LRU Cache
# Solve the stated task using standard input and standard output.
import sys
from collections import OrderedDict
def main():
    tokens = sys.stdin.read().split()
    if tokens:
        cap = int(tokens[0])
        q = int(tokens[1])
        idx = 2
        cache = OrderedDict()
        for _ in range(q):
            cmd = tokens[idx]
            if cmd == "put":
                k, v = int(tokens[idx+1]), int(tokens[idx+2])
                if k in cache: cache.move_to_end(k)
                cache[k] = v
                if len(cache) > cap: cache.popitem(last=False)
                idx += 3
            elif cmd == "get":
                k = int(tokens[idx+1])
                if k in cache:
                    cache.move_to_end(k)
                    print(cache[k])
                else:
                    print(-1)
                idx += 2
if __name__ == '__main__':
    main()
