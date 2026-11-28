import sys

def solve():
    input_data = sys.stdin.read().split()
    if not input_data:
        return
    n = int(input_data[0])
    k = int(input_data[1])
    
    if n == 1:
        print(k)
    elif n == 2:
        print(k * k)
    else:
        same = k
        diff = k * (k - 1)
        for _ in range(3, n + 1):
            new_same = diff
            new_diff = (same + diff) * (k - 1)
            same = new_same
            diff = new_diff
        print(same + diff)

if __name__ == "__main__":
    solve()

