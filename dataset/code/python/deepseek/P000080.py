Here is the Python code to solve the problem:

def is_alphabet(c):
    if ('a' <= c and c <= 'z') or ('A' <= c and c <= 'Z'):
        return True
    else:
        return False

def main():
    c = input("Enter a character: ")
    if is_alphabet(c):
        print("Alphabet")
    else:
        print("Not Alphabet")

if __name__ == "__main__":
    main()

In this code, the function `is_alphabet` checks whether the input character is an alphabet or not. The function `main` reads the input character from the user and calls the `is_alphabet` function to check whether the character is an alphabet or not. The main function is the entry point of the program, and it calls `main` to start the program.