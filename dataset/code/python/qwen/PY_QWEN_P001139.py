import sys

def solve():
    input_data = sys.stdin.read().split()
    if not input_data:
        return
    idx = 0
    n = int(input_data[idx]); idx += 1
    w = int(input_data[idx]); idx += 1
    
    weights = []
    values = []
    for _ in range(n):
        weights.append(int(input_data[idx])); idx += 1
        values.append(int(input_data[idx])); idx += 1
        
    dp = [0] * (w + 1)
    
    for i in range(n):
        for j in range(w, weights[i] - 1, -1):
            dp[j] = max(dp[j], dp[j - weights[i]] + values[i])
            
    print(dp[w])

if __name__ == "__main__":
    solve()

