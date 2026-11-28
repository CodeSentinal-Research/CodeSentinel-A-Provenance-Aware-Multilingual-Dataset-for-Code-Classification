import sys

def solve():
    num = sys.stdin.readline().strip()
    k = int(sys.stdin.readline())
    
    stack = []
    for digit in num:
        while k > 0 and stack and stack[-1] > digit:
            stack.pop()
            k -= 1
        stack.append(digit)
        
    while k > 0:
        stack.pop()
        k -= 1
        
    result = "".join(stack).lstrip('0')
    print(result if result else "0")

if __name__ == "__main__":
    solve()

