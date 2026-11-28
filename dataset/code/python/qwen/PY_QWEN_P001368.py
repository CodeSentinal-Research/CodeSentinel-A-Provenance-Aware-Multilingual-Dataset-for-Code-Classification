import sys

def solve():
    n = int(sys.stdin.readline())
    
    # Combinations with repetition: C(n + k - 1, k) where k=5 vowels
    # C(n + 4, 4)
    result = 1
    for i in range(4):
        result = result * (n + 4 - i) // (i + 1)
        
    print(result)

if __name__ == "__main__":
    solve()

