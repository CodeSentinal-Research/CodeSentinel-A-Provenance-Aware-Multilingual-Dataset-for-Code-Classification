import sys

def solve():
    input_data = sys.stdin.read().split()
    if not input_data:
        return
    n = int(input_data[0])
    piles = list(map(int, input_data[1:1+n]))
    
    # Since piles are even and players play optimally, first player always wins or ties.
    # Actually, for Stone Game I, first player always wins.
    print("YES")

if __name__ == "__main__":
    solve()

