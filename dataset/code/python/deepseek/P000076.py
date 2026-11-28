Here is the Python code for finding the roots of a quadratic equation:

import math

def find_roots(a, b, c):
    D = b**2 - 4*a*c

    if D >= 0:
        root1 = (-b - math.sqrt(D)) / (2*a)
        root2 = (-b + math.sqrt(D)) / (2*a)
        return (root1, root2)
    else:
        return None

try:
    a = float(input('Enter coefficient a: '))
    b = float(input('Enter coefficient b: '))
    c = float(input('Enter constant c: '))
    roots = find_roots(a, b, c)
    if roots is not None:
        print('Roots of the equation are: ', roots)
    else:
        print('No real roots exist')
except ValueError:
    print('Invalid input. Please enter numeric values.')

In the code above, we first calculate the discriminant D (b² - 4ac). If D is positive, we know the roots are real and different. If D is zero, we have one real root. If D is negative, we have complex roots.

We then input the coefficients a, b, and c from user and call the function `find_roots()` to find the roots.

In case of an invalid input (non-numeric), we print an error message and stop the execution of the code.