import sys
from collections import defaultdict, OrderedDict
def main():
    tokens = sys.stdin.read().split()
    if tokens:
        cap = int(tokens[0])
        q = int(tokens[1])
        idx = 2
        key_to_val = {}
        key_to_freq = {}
        freq_to_keys = defaultdict(OrderedDict)
        min_freq = 0
        
        def update_freq(k):
            f = key_to_freq[k]
            del freq_to_keys[f][k]
            if not freq_to_keys[f] and f == min_freq:
                pass
            key_to_freq[k] = f + 1
            freq_to_keys[f + 1][k] = None

        for _ in range(q):
            cmd = tokens[idx]
            if cmd == "put":
                k, v = int(tokens[idx+1]), int(tokens[idx+2])
                if cap > 0:
                    if k in key_to_val:
                        key_to_val[k] = v
                        update_freq(k)
                    else:
                        if len(key_to_val) >= cap:
                            # evict min_freq
                            while not freq_to_keys[min_freq]: min_freq += 1
                            evict_k, _ = freq_to_keys[min_freq].popitem(last=False)
                            del key_to_val[evict_k]
                            del key_to_freq[evict_k]
                        key_to_val[k] = v
                        key_to_freq[k] = 1
                        freq_to_keys[1][k] = None
                        min_freq = 1
                idx += 3
            elif cmd == "get":
                k = int(tokens[idx+1])
                if k in key_to_val:
                    update_freq(k)
                    print(key_to_val[k])
                else:
                    print(-1)
                idx += 2
if __name__ == '__main__':
    main()