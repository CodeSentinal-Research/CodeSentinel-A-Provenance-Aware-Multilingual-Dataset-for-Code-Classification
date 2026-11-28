import sys

def solve():
    input_data = sys.stdin.read().split()
    if not input_data:
        return
    n = int(input_data[0])
    # In a min-heap, the minimum element is at index 0
    if n > 0:
        print(input_data[1])
    else:
        print("")

if __name__ == "__main__":
    solve()

