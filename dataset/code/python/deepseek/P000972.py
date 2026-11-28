def calculate_probability(N, K):
    total_outcomes = 2**N
    exact_outcomes = binomial_coefficient(N, K)
    return exact_outcomes / total_outcomes

def binomial_coefficient(n, k):
    result = 1
    for i in range(k):
        result *= (n - i)
    return result

def main():
    N = int(input("Enter the number of tosses: "))
    K = int(input("Enter the number of heads: "))
    print("The probability is: ", calculate_probability(N, K))

if __name__ == "__main__":
    main()
In this code, we first calculate the total number of possible outcomes (2^N) for the fair coin toss. Then, we calculate the number of times the coin lands with K heads. Finally, we divide the number of times K heads can occur from the total number of outcomes by the total number of outcomes to get the probability.