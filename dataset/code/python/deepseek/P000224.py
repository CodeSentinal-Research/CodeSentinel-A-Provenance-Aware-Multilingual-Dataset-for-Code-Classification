Here is the Python code:

def maxProfit(jobs):
    n = len(jobs)
    profit = [0] * n
    for i in range(n):
        profit[i] = jobs[i][2]

    dp = [0] * (n + 1)
    for i in range(n - 1, -1, -1):
        dp[i + 1] = max(dp[i + 1], profit[i])
        if i + 1 < n:
            dp[i] = max(dp[i], profit[i] + dp[i + 2])

    return dp[0], dp[1]

def main():
    N = int(input())
    jobs = []
    for _ in range(N):
        line = input().split()
        jobs.append((int(line[0]), int(line[1]), int(line[2])))

    profit, jobs_done = maxProfit(jobs)
    print(profit, jobs_done)

if __name__ == "__main__":
    main()

This program first reads the number of jobs and the jobs themselves. For each job, it calculates the maximum profit it can get by sequencing the jobs. The profit is stored in an array `profit`.

Then, it uses dynamic programming to calculate the maximum profit by sequencing the jobs. For each job, it calculates the maximum profit by not sequencing the current job and the maximum profit by sequencing the current job. The maximum profit by sequencing the current job is the profit of the current job plus the maximum profit by sequencing the two jobs before it (if there are two jobs before it).

The maximum profit by sequencing the two jobs before it is stored in the `dp` array. The final result is the maximum profit by sequencing the jobs.

The `main` function reads the number of jobs and the jobs themselves. It then calls the `maxProfit` function to get the maximum profit and the number of jobs done, and prints these values.