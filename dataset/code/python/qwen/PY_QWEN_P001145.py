import sys

def solve():
    input_data = sys.stdin.read().split()
    if not input_data:
        return
    n = int(input_data[0])
    nums = list(map(int, input_data[1:1+n]))
    
    inc = [1] * n
    dec = [1] * n
    
    for i in range(1, n):
        for j in range(i):
            if nums[i] > nums[j]:
                inc[i] = max(inc[i], inc[j] + 1)
                
    for i in range(n - 2, -1, -1):
        for j in range(n - 1, i, -1):
            if nums[i] > nums[j]:
                dec[i] = max(dec[i], dec[j] + 1)
                
    max_len = 0
    for i in range(n):
        max_len = max(max_len, inc[i] + dec[i] - 1)
        
    print(max_len)

if __name__ == "__main__":
    solve()

