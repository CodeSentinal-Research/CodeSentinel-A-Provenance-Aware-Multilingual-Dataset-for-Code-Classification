import sys

def solve():
    input_data = sys.stdin.read().split()
    if not input_data:
        return
    idx = 0
    n = int(input_data[idx]); idx += 1
    a = list(map(int, input_data[idx:idx+n])); idx += n
    b = list(map(int, input_data[idx:idx+n])); idx += n
    
    sum_a = sum(a)
    
    max_gain = 0
    for i in range(n):
        gain = b[i] - a[i]
        if gain > 0:
            max_gain = max(max_gain, gain)
            
    print(sum_a + max_gain)

if __name__ == "__main__":
    solve()

