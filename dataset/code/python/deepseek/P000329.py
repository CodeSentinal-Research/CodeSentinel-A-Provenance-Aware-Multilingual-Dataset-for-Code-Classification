Here's a Python solution that uses a set to handle the input strings and finds the difference between the two sets.

def find_difference(S, T):
    set_s = set(S)
    set_t = set(T)
    difference = set_t - set_s
    return difference

def main():
    S = input("Enter the first string: ")
    T = input("Enter the second string: ")
    print(find_difference(S, T))

if __name__ == "__main__":
    main()

In this code, the `find_difference` function takes two strings as input, converts them into sets, and finds the difference between the two sets. The result is printed out.

The `main` function handles the input and output, taking user input for the strings, and printing the result of calling the `find_difference` function with the input strings.

This code assumes that the input strings do not contain any white space. If they do contain white spaces, you would need to remove them before converting the strings to sets.