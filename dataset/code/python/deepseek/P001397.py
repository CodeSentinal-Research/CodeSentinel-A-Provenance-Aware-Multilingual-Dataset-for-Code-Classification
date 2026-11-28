Here is the Python code that solves the problem:

def solve():
    R = int(input())
    for _ in range(R):
        N, *WIDTHS = map(int, input().split())
        print(min(WIDTHS))

if __name__ == "__main__":
    solve()

This code reads the number of rows R, then for each row it reads the number of bricks N and the widths of the bricks. It then prints the minimum width of the bricks.