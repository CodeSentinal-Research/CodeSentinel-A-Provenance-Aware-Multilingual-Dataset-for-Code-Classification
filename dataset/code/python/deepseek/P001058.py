class FrequencyStack:

    def __init__(self):
        self.frequency = {}
        self.group = {}
        self.maxFrequency = 0
        self.currentMax = None

    def push(self, x):
        self.frequency[x] = self.frequency.get(x, 0) + 1
        self.maxFrequency = max(self.maxFrequency, self.frequency[x])
        if self.frequency[x] == self.maxFrequency:
            if not self.currentMax or x > self.currentMax[0]:
                self.currentMax = (x, 1)

    def pop(self):
        result = self.currentMax[0]
        self.frequency[self.currentMax[0]] -= 1
        self.currentMax = (self.currentMax[0], self.currentMax[1] - 1) if self.currentMax[1] > 0 else None
        if self.frequency[self.currentMax[0]] == 0:
            self.maxFrequency = min(self.frequency.values())
        return result

def solve():
    Q = int(input().strip())
    frequencyStack = FrequencyStack()
    for _ in range(Q):
        op = input().strip().split(' ')
        if op[0] == 'push':
            frequencyStack.push(int(op[1]))
        else:
            print(frequencyStack.pop())

if __name__ == "__main__":
    solve()