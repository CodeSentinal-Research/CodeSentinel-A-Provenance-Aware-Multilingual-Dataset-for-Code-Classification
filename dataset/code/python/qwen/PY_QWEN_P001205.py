import sys

def solve():
    input_data = sys.stdin.read().split()
    if not input_data:
        return
    n = int(input_data[0])
    nums = list(map(int, input_data[1:1+n]))
    
    lengths = [1] * n
    counts = [1] * n
    
    max_len = 1
    
    for i in range(1, n):
        for j in range(i):
            if nums[i] > nums[j]:
                if lengths[j] + 1 > lengths[i]:
                    lengths[i] = lengths[j] + 1
                    counts[i] = counts[j]
                elif lengths[j] + 1 == lengths[i]:
                    counts[i] += counts[j]
        max_len = max(max_len, lengths[i])
        
    total = 0
    for i in range(n):
        if lengths[i] == max_len:
            total += counts[i]
            
    print(total)

if __name__ == "__main__":
    solve()

