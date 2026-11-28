import sys
def solve():
    d = sys.stdin.read().split()
    L, R = int(d[0]), int(d[1])
    def sum_of_digits_up_to(n):
        if n <= 0: return 0
        s = str(n)
        length = len(s)
        memo = {}
        def dfs(idx, tight):
            if idx == length:
                return 1, 0
            state = (idx, tight)
            if state in memo: return memo[state]
            limit = int(s[idx]) if tight else 9
            total_count = 0
            total_sum = 0
            for dig in range(limit + 1):
                next_tight = tight and (dig == limit)
                c, sm = dfs(idx + 1, next_tight)
                total_count += c
                total_sum += sm + dig * c
            memo[state] = (total_count, total_sum)
            return memo[state]
        return dfs(0, True)[1]
    print(sum_of_digits_up_to(R) - sum_of_digits_up_to(L - 1))
solve()
