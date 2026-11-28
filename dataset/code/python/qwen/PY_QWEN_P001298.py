import sys

def solve():
    input_data = sys.stdin.read().split()
    if not input_data:
        return
    n = int(input_data[0])
    milestones = list(map(int, input_data[1:1+n]))
    
    total = sum(milestones)
    max_m = max(milestones)
    
    if max_m > total - max_m:
        print(2 * (total - max_m) + 1)
    else:
        print(total)

if __name__ == "__main__":
    solve()

