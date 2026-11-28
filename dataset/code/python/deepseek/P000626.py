Here is the Python code to solve the problem:

from collections import defaultdict
class AllOne:

    def __init__(self):
        self.keys = defaultdict(set)
        self.counts = defaultdict(int)
        self.key_map = {}

    def inc(self, key: str) -> None:
        self.counts[key] += 1
        self.keys[self.counts[key]].remove(key)
        if not self.keys[self.counts[key]]:
            del self.keys[self.counts[key]]
        self.keys[self.counts[key]].add(key)

    def dec(self, key: str) -> None:
        self.counts[key] -= 1
        self.keys[self.counts[key]].remove(key)
        if not self.keys[self.counts[key]]:
            del self.keys[self.counts[key]]
        if self.counts[key] == 0:
            del self.keys[0]

    def getMaxKey(self) -> str:
        return next(iter(self.keys.most_right()))

    def getMinKey(self) -> str:
        return next(iter(self.keys.most_left()))

In the code above, we use a dictionary to store keys and their counts. Python's set allows us to easily handle the remove operation for keys in the dictionary. The most_right() method gets the key from the right side, which corresponds to the maximum count, and the most_left() method gets the key from the left side, which corresponds to the minimum count.

The main function is a simple test. We create an AllOne instance and process a sequence of operations:

def main():
    allOne = AllOne()

    for q in range(5):
        print('q:', q)
        print('Result of getMaxKey:', allOne.getMaxKey())
        print('Result of getMinKey:', allOne.getMinKey())

        if q % 2 == 0:
            for key in ['a', 'b', 'c', 'd', 'e']:
                allOne.inc(key)
        else:
            for key in ['x', 'y', 'z']:
                allOne.dec(key)

if __name__ == "__main__":
    main()

In the main function, we create an AllOne instance and process a sequence of operations. For each operation, we call the inc() and dec() methods in the AllOne instance, then call the getMaxKey() and getMinKey() methods to print the result of the last two operations.