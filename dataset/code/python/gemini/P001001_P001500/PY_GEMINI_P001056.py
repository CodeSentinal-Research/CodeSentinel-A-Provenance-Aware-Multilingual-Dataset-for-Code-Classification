import heapq

class SmallestInfiniteSet:
    def __init__(self):
        self.cur = 1
        self.added = set()
        self.heap = []

    def popSmallest(self) -> int:
        if self.heap:
            val = heapq.heappop(self.heap)
            self.added.remove(val)
            return val
        res = self.cur
        self.cur += 1
        return res

    def addBack(self, num: int) -> None:
        if num < self.cur and num not in self.added:
            self.added.add(num)
            heapq.heappush(self.heap, num)