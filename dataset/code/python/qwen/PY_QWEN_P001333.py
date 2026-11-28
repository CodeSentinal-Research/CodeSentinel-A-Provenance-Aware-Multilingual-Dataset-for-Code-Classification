import sys

def solve():
    input_data = sys.stdin.read().split()
    if not input_data:
        return
    num_str = input_data[0]
    target = int(input_data[1])
    n = len(num_str)
    results = []
    
    def backtrack(index, current_expr, current_val, last_val):
        if index == n:
            if current_val == target:
                results.append(current_expr)
            return
            
        for i in range(index, n):
            if i > index and num_str[index] == '0':
                break
            num_str_part = num_str[index:i+1]
            num_val = int(num_str_part)
            
            if index == 0:
                backtrack(i + 1, num_str_part, num_val, num_val)
            else:
                backtrack(i + 1, current_expr + "+" + num_str_part, current_val + num_val, num_val)
                backtrack(i + 1, current_expr + "-" + num_str_part, current_val - num_val, -num_val)
                backtrack(i + 1, current_expr + "*" + num_str_part, current_val - last_val + last_val * num_val, last_val * num_val)
                
    backtrack(0, "", 0, 0)
    for res in results:
        print(res)

if __name__ == "__main__":
    solve()

