import sys

def solve():
    n = int(sys.stdin.readline())
    
    gray_code = []
    for i in range(2**n):
        gray = i ^ (i >> 1)
        gray_code.append(gray)
        
    print(*gray_code)

if __name__ == "__main__":
    solve()

