Here's a Python solution for the problem:

def countGoodMeals(N, arr):
    count = 0
    for i in range(N):
        for j in range(i + 1, N):
            if (arr[i] + arr[j]) in power_of_two:
                count += 1
    return count

def main():
    N = int(input().strip())
    arr = list(map(int, input().strip().split()))
    power_of_two = {2**i for i in range(21)}
    print(countGoodMeals(N, arr))

if __name__ == "__main__":
    main()

In this code, the `countGoodMeals` function checks every possible pair of numbers in the input list. If the sum of any pair's value is in the set `power_of_two`, it increments a counter. The `main` function handles the input and output.

Please note that this code assumes that the input list will only contain numbers between 1 and 20 (as per the problem constraints). If the input list may contain larger numbers, you will need to adjust the code accordingly.