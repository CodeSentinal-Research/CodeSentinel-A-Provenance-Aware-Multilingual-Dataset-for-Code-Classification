Sure, here is the Python code for the problem:

def count_subsequences(arr, target):
    MOD = 10**9 + 7
    n = len(arr)

    prefix = [0]*(n+1)
    suffix = [0]*(n+1)
    for i in range(n):
        prefix[i+1] = (prefix[i] + arr[i]) % MOD
        suffix[i+1] = (suffix[i] + arr[n-i-1]) % MOD

    count = 0
    for i in range(1, n+1):
        target_i = (target - (prefix[i-1] if i-1 else 0)) % MOD
        count = (count + suffix[i]) % MOD
        count = (count + (suffix[i] - suffix[i-target_i]) % MOD) % MOD

    return count

def main():
    N, Target = map(int, input().split())
    arr = list(map(int, input().split()))
    print(count_subsequences(arr, Target))

if __name__ == "__main__":
    main()

This code first calculates the prefix and suffix sums of the array to make it easier to compute the sum of minimum and maximum elements. Then, it calculates the count for every possible sum of minimum and maximum elements and finally, prints the result.