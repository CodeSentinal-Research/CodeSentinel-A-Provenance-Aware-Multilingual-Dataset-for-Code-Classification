Here is the Python code:

def candy_distribution():
    N = int(input().strip())
    ratings = list(map(int, input().strip().split()))

    candies = [1]*N
    for i in range(1, N):
        if ratings[i] > ratings[i-1]:
            candies[i] = candies[i-1] + 1

    for i in range(N-2, -1, -1):
        if ratings[i] > ratings[i+1]:
            candies[i] = max(candies[i], candies[i+1] + 1)

    return sum(candies)

def main():
    N = int(input().strip())
    ratings = list(map(int, input().strip().split()))
    print(candy_distribution(N, ratings))

main()

In this code, we first input the number of children and their ratings. Then we distribute the candies based on the given rules. The main function calls the candy_distribution function and prints the result.