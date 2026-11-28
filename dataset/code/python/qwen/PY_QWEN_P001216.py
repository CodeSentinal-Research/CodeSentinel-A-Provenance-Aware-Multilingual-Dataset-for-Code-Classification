import sys

def solve():
    input_data = sys.stdin.read().split()
    if not input_data:
        return
    n = int(input_data[0])
    leaves = list(map(int, input_data[1:1+n]))
    
    stack = []
    cost = 0
    
    for leaf in leaves:
        while stack and stack[-1] <= leaf:
            mid = stack.pop()
            if not stack:
                cost += mid * leaf
            else:
                cost += mid * min(stack[-1], leaf)
        stack.append(leaf)
        
    while len(stack) > 1:
        cost += stack.pop() * stack[-1]
        
    print(cost)

if __name__ == "__main__":
    solve()

