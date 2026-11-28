Here is the Python code for the given problem.

def count_and_say(n):
    s = '1'
    for _ in range(n - 1):
        s = ''.join([str(len(list(group))) + digit for digit, group in itertools.groupby(s)])
    return s

while True:
    n = input('Enter a positive integer: ')
    if n.isdigit() and 1 <= int(n) <= 30:
        print(count_and_say(int(n)))
        break
    else:
        print('Invalid input. Please enter a positive integer between 1 and 30.')

This code firstly imports the `itertools` module and then defines the function `count_and_say` which takes an integer `n` as input and returns the `n`th term of the count-and-say sequence.

The `count_and_say` function works by iteratively transforming the input string `s` by repeatedly replacing groups of repeated characters with the number of characters followed by the character. It first sets `s` to '1', then repeatedly applies the transformation to `s` until `n` times.

The code also includes input handling, which continuously asks the user for a positive integer until they provide a valid input (a positive integer between 1 and 30). If the user provides an invalid input, the code prints an error message and asks for input again.