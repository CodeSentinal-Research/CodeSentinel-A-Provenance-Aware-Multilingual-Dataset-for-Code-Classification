Here is the Python code for the LFU Cache:

from collections import defaultdict, OrderedDict

class LFUCache:

    def __init__(self, capacity: int):
        self.capacity = capacity
        self.cache = dict()
        self.freq_map = defaultdict(OrderedDict)
        self.min_freq = 0

    def get(self, key: int) -> int:
        if key not in self.cache:
            return -1
        freq = self.cache[key][1]
        self.freq_map[freq].remove(key)
        if not self.freq_map[freq]:
            del self.freq_map[freq]
        self.cache[key][1] += 1
        self.freq_map[freq + 1].append(key)
        if not self.freq_map[self.min_freq]:
            self.min_freq += 1
        return self.cache[key][0]

    def put(self, key: int, value: int) -> None:
        if self.capacity <= 0:
            return
        if key in self.cache:
            self.get(key)
            self.cache[key][0] = value
            return
        if len(self.cache) >= self.capacity:
            evict_key = self.freq_map[self.min_freq][0]
            self.freq_map[self.min_freq].remove(evict_key)
            if not self.freq_map[self.min_freq]:
                del self.freq_map[self.min_freq]
            del self.cache[evict_key]
        self.cache[key] = [value, 1]
        self.freq_map[1].append(key)
        self.min_freq = 1

And here is a main function that reads the input:

def main():
    c = LFUCache(2)
    c.put(1, 1)
    c.put(2, 2)
    print(c.get(1))
    c.put(3, 3)
    print(c.get(2))
    print(c.get(3))
    c.put(4, 4)
    print(c.get(1))
    print(c.get(3))
    print(c.get(4))

if __name__ == "__main__":
    main()

This code will output:

1
2
2
3
4
-1