Here's the Python code for the problem:

def calculate_compound_interest(p, r, t):
    if not (1 <= p <= 100) or not (1 <= r <= 100) or not (1 <= t <= 100):
        return "Invalid input. Please input values between 1 and 100."

    interest = p * ((1 + r / 100) ** t - 1)

    return interest

def main():
    principal = float(input("Enter principal amount: "))
    rate = float(input("Enter rate of interest: "))
    time = float(input("Enter time in years: "))

    interest = calculate_compound_interest(principal, rate, time)
    print("Compound interest is: ", interest)

if __name__ == "__main__":
    main()

In this code, we first define a function `calculate_compound_interest` that takes the principal, rate, and time as parameters and returns the compound interest. We then define the `main` function which handles the user input and computes and prints the compound interest. In the `main` function, we call `calculate_compound_interest` and print the result.

To run the code, simply call the `main` function. You will be prompted to enter the principal amount, rate of interest, and time in years. The program will then print the compound interest.