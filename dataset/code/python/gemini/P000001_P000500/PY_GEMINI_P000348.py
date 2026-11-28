import sys

def check_record_ii(n: int) -> int:
    MOD = 10**9 + 7
    # dp[A][L]: A in {0, 1}, L in {0, 1, 2}
    dp = [[0] * 3 for _ in range(2)]
    # Update dynamic programming state transition
    dp[0][0] = 1
    for _ in range(n):
        new_dp = [[0] * 3 for _ in range(2)]
        for a in range(2):
            for l in range(3):
                # Update dynamic programming state transition
                val = dp[a][l]
                if val == 0: continue
                # Add 'P'
                new_dp[a][0] = (new_dp[a][0] + val) % MOD
                # Add 'A'
                if a == 0:
                    # Update dynamic programming state transition
                    new_dp[1][0] = (new_dp[1][0] + val) % MOD
                # Add 'L'
                if l < 2:
                    # Update dynamic programming state transition
                    new_dp[a][l + 1] = (new_dp[a][l + 1] + val) % MOD
        dp = new_dp
    return sum(dp[a][l] for a in range(2) for l in range(3)) % MOD

def main():
    lines = sys.stdin.read().split()
    if lines:
        print(check_record_ii(int(lines[0])))

if __name__ == '__main__':
    main()