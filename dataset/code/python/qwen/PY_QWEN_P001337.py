import sys

def solve():
    n = int(sys.stdin.readline())
    
    def backtrack(index, arrangement):
        if index > n:
            return 1
        count = 0
        for num in range(1, n + 1):
            if num not in arrangement:
                if num % index == 0 or index % num == 0:
                    arrangement.add(num)
                    count += backtrack(index + 1, arrangement)
                    arrangement.remove(num)
        return count
        
    print(backtrack(1, set()))

if __name__ == "__main__":
    solve()

