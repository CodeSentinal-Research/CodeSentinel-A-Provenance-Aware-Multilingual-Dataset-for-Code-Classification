import sys

def solve():
    input_data = sys.stdin.read().split()
    if not input_data:
        return
    n = int(input_data[0])
    k = int(input_data[1])
    
    # First player wins if n % (k + 1) != 0
    if n % (k + 1) != 0:
        print("FIRST")
    else:
        print("SECOND")

if __name__ == "__main__":
    solve()

