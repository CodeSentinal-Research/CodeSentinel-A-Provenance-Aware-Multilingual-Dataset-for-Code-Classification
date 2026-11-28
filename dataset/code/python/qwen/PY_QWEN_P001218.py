import sys

def solve():
    s = sys.stdin.readline().strip()
    n = int(sys.stdin.readline())
    word_dict = set()
    for _ in range(n):
        word_dict.add(sys.stdin.readline().strip())
        
    dp = [False] * (len(s) + 1)
    dp[0] = True
    
    for i in range(1, len(s) + 1):
        for j in range(i):
            if dp[j] and s[j:i] in word_dict:
                dp[i] = True
                break
                
    print("YES" if dp[len(s)] else "NO")

if __name__ == "__main__":
    solve()

