Here is the Python code for the given problem:

def calculate_bill(units):
    if units <= 50:
        amount = units * 0.5
    elif units <= 100:
        amount = 25 + (units - 50) * 0.75
    elif units <= 200:
        amount = 125 + (units - 100) * 1
    else:
        amount = 275 + (units - 200) * 1.25
    return amount

def main():
    units = int(input("Enter the number of units consumed: "))
    if units < 0 or units > 1000:
        print("Invalid input. Please enter a non-negative integer up to 1000.")
        return
    bill = calculate_bill(units)
    print("The total bill amount is: ", bill)

if __name__ == "__main__":
    main()

This program first asks the user to enter the number of units consumed. It then calls the `calculate_bill` function, which determines the bill amount based on the units consumed and prints the total bill amount. The `main` function also includes input handling to ensure the user's input is valid (i.e., a non-negative integer up to 1000).