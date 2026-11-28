import sys

def solve():
    s = sys.stdin.readline().strip()
    left = 0
    right = len(s) - 1
    
    while left < right:
        if s[left] == s[right]:
            left += 1
            right -= 1
        else:
            # Check if removing left or right makes it palindrome
            s1 = s[left+1:right+1]
            s2 = s[left:right]
            if s1 == s1[::-1] or s2 == s2[::-1]:
                print("YES")
                return
            else:
                print("NO")
                return
                
    print("YES")

solve()

