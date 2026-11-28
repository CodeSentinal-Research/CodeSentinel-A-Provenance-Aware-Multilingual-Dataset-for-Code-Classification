import sys

def solve():
    input_data = sys.stdin.read().split()
    if not input_data:
        return
    num_str = input_data[0]
    k = int(input_data[1])
    n = len(num_str)
    
    max_num = list(num_str)
    
    def backtrack(index, swaps_left):
        if swaps_left == 0 or index == n:
            return
        max_digit = max(max_num[index:])
        if max_num[index] == max_digit:
            backtrack(index + 1, swaps_left)
            return
            
        for i in range(n - 1, index, -1):
            if max_num[i] == max_digit:
                max_num[index], max_num[i] = max_num[i], max_num[index]
                backtrack(index + 1, swaps_left - 1)
                max_num[index], max_num[i] = max_num[i], max_num[index]
                
    backtrack(0, k)
    print("".join(max_num))

if __name__ == "__main__":
    solve()

