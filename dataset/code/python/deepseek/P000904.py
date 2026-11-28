Here is the Python code for your problem.

def modular_addition(A, B, M):
    return (A + B) % M

And here is the main function to handle the input:

def main():
    A = int(input("Enter integer A: "))
    B = int(input("Enter integer B: "))
    M = int(input("Enter integer M: "))
    print("Result of modular addition: ", modular_addition(A, B, M))

if __name__ == "__main__":
    main()

This code first prompts the user to enter three integers, A, B, and M. Then it calls the `modular_addition` function with these three integers as arguments, and prints the result.

Please note that Python's `input` function returns a string, so if the user enters a number, it will be stored as a string. Therefore, you need to convert these strings to integers using the `int` function.