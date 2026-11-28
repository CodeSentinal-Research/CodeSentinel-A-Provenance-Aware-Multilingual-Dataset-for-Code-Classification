Here's the Python code for generating all possible combinations of K elements from 1 to N using recursion:

def generate_combinations(n, k, current=1, current_combination=[]):
    if len(current_combination) == k:
        print(current_combination)
        return
    for i in range(current, n + 1):
        generate_combinations(n, k, i, current_combination + [i])

def main():
    n = int(input("Enter the value of N: "))
    k = int(input("Enter the value of K: "))
    if k > n or k < 1:
        print("Invalid input! K should be between 1 and N (inclusive)")
        return
    generate_combinations(n, k)

if __name__ == "__main__":
    main()

This code first defines the `generate_combinations` function, which is a recursive function that generates all combinations. It takes in four parameters: the maximum value `n`, the required length `k`, the current number `current`, and the current combination of numbers `current_combination`.

Inside the `generate_combinations` function, we first check if the current combination is of length `k`. If it is, we print it and return.

If the current combination is not of length `k`, we then iterate through all numbers starting from `current` and recursively call `generate_combinations` with the new parameters. In this case, we also append the number to the current combination.

Then, in the `main` function, we get the inputs `n` and `k` from the user. We then check if `k` is not between 1 and `n` (inclusive), and if it is, we print an error message and return.

If `k` is valid, we call `generate_combinations` with the initial parameters.