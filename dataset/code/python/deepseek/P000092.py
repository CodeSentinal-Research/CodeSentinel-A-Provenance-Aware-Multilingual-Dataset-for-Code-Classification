Here is the Python code:

def find_sum_ap(a, d, n):
    sum_ap = (n / 2) * (2*a + (n - 1) * d)
    return sum_ap

def main():
    a = int(input("Enter the first term: "))
    d = int(input("Enter the common difference: "))
    n = int(input("Enter the number of terms: "))

    if 1 <= n <= 1000:
        print(f"The sum of the AP series is {find_sum_ap(a, d, n)}")
    else:
        print("The number of terms should be between 1 and 1000")

if __name__ == "__main__":
    main()

This program will ask for the first term, common difference and number of terms from the user. Then it will print out the sum of the AP series based on those inputs.