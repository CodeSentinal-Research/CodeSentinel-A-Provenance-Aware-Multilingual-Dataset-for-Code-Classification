Here is the Python code for the problem. The main idea is to calculate the number of derangements in an array. In an array of length n, the number of derangements can be calculated using the formula n*(n-1) * (n-2) / 2. 

def count_derangements(n):
    if n < 2:
        return 0

    derangement_counts = [0] * n
    derangement_counts[0] = 0
    derangement_counts[1] = 1

    for i in range(2, n):
        derangement_counts[i] = (i - 1) * (derangement_counts[i - 1] + derangement_counts[i - 2])

    return derangement_counts[n - 1]


def main():
    n = int(input("Enter the number of objects: "))
    while n < 1 or n > 10**6:
        n = int(input("Invalid input. Please enter a number between 1 and 10^6: "))
    print("The number of derangements is: ", count_derangements(n))


if __name__ == "__main__":
    main()

In this code, we first check if the input is valid (i.e., between 1 and 10^6). If it is not, we keep asking for input until we get a valid number. We then call the function `count_derangements` with the input, and print the result.