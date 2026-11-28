Here is the Python code:

def calculate_sum(a, r, n):
    return a + (n - 1) * r

def main():
    a = int(input("Enter the first term: "))
    r = int(input("Enter the common ratio: "))
    n = int(input("Enter the number of terms: "))

    if 1 <= n <= 20:
        sum = calculate_sum(a, r, n)
        print(f"The sum of the GP series is: {sum}")
    else:
        print("Number of terms should be between 1 and 20.")

if __name__ == "__main__":
    main()

In this program, we define a function `calculate_sum` to calculate the sum of a geometric progression series. The function takes three parameters: the first term `a`, the common ratio `r`, and the number of terms `n`. The sum is calculated as the sum of the first term and the product of the common ratio and the number of terms minus one.

The `main` function prompts for the first term, common ratio, and number of terms. It then checks if the number of terms is between 1 and 20, and if it is, it calculates the sum of the geometric progression series. If the number of terms is not within the specified range, it prints an error message.