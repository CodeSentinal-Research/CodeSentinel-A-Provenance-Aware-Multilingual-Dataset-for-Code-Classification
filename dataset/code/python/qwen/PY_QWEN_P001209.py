import sys

def solve():
    input_data = sys.stdin.read().split()
    if not input_data:
        return
    n = int(input_data[0])
    values = list(map(int, input_data[1:1+n]))
    
    suffix_sum = [0] * (n + 1)
    for i in range(n - 1, -1, -1):
        suffix_sum[i] = suffix_sum[i+1] + values[i]
        
    from functools import lru_cache
    
    @lru_cache(None)
    def dp(i):
        if i >= n:
            return 0
        res = float('-inf')
        for k in range(1, 4):
            if i + k <= n:
                res = max(res, suffix_sum[i] - dp(i + k))
        return res
        
    alice_score = dp(0)
    bob_score = suffix_sum[0] - alice_score
    
    if alice_score > bob_score:
        print("Alice")
    elif alice_score < bob_score:
        print("Bob")
    else:
        print("Tie")

if __name__ == "__main__":
    solve()

