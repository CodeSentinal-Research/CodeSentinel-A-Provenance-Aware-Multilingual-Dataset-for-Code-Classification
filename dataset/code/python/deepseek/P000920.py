Sure, I will provide the Python code for the problem.

def find_max_min(N):
    N_str = str(N)

    digits = [int(d) for d in N_str]

    max_digit = max(digits)
    min_digit = min(digits)

    return max_digit, min_digit

N = int(input('Enter a non-negative integer: '))

max_digit, min_digit = find_max_min(N)
print('Largest digit:', max_digit)
print('Smallest digit:', min_digit)

In this code, we first convert the input number into a string. We then convert each character in the string into an integer and store them in a list. We use the built-in max and min functions to find the largest and smallest numbers in the list.