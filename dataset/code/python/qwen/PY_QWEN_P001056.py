import sys
import heapq

class SmallestInfiniteSet:
    def __init__(self):
        self.heap = []
        self.added = set()
        self.curr = 1
        
    def popSmallest(self):
        if self.heap:
            val = heapq.heappop(self.heap)
            self.added.discard(val)
            return val
        else:
            val = self.curr
            self.curr += 1
            return val
            
    def addBack(self, num):
        if num < self.curr and num not in self.added:
            heapq.heappush(self.heap, num)
            self.added.add(num)

def solve():
    input_data = sys.stdin.read().split()
    if not input_data:
        return
    idx = 0
    q = int(input_data[idx]); idx += 1
    
    sis = SmallestInfiniteSet()
    output = []
    
    for _ in range(q):
        op = input_data[idx]; idx += 1
        if op == "POP":
            output.append(str(sis.popSmallest()))
        elif op == "ADD":
            num = int(input_data[idx]); idx += 1
            sis.addBack(num)
            
    print("
".join(output))

if __name__ == "__main__":
    solve()

