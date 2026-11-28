import sys

def solve():
    n = int(sys.stdin.readline())
    
    def get_next(n):
        total = 0
        while n > 0:
            digit = n % 10
            total += digit * digit
            n //= 10
        return total
        
    slow = n
    fast = get_next(n)
    while fast != 1 and slow != fast:
        slow = get_next(slow)
        fast = get_next(get_next(fast))
        
    print("YES" if fast == 1 else "NO")

solve()

