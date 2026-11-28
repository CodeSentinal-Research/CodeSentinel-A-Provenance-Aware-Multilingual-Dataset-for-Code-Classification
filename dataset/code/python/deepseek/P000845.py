Here is the Python code for the problem:

def minCapacity(nums, k, n):
    if not nums:
        return 0

    dp = [0] * (k + 1)
    dp[0] = 0
    nums = [0] + nums

    for i in range(1, len(nums)):
        for j in range(k, 0, -1):
            dp[j] = max(dp[j], dp[j-1] + nums[i])

    return max(dp)

This code uses dynamic programming to solve the problem. We first initialize the dynamic programming table `dp` with zeros. Then we iterate through the `nums` array, from 1 to the length of `nums`. In each iteration, we update the `dp` table based on the maximum capacity of robbing the current house and the maximum capacity of robbing the previous houses. Finally, we return the maximum capacity of robbing all houses.

To use this function, you would call it like this:

def main():
    print(minCapacity([2, 1, 1, 4, 5, 3, 2, 6], 4, 3))  

if __name__ == "__main__":
    main()

In the main function, we call `minCapacity` with the given inputs. The output should be 5, which is the minimum capacity of robbing all houses.