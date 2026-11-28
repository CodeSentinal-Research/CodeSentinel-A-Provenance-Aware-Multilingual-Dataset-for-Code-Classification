Here is a Python solution for the problem:

def solve():
    E = int(input())
    for _ in range(E):
        A, B = map(float, input().split())
        value = float(input())
        if B == 0:
            print('-1.0')
            continue
        print(A / B == value)

if __name__ == "__main__":
    solve()

In this code, we first get the number of equations (E). For each equation, we get the values of A and B (which are the numerator and denominator of the equation), and the value to be determined (value). Then, we check if B is zero, because division by zero is undefined. If B is zero, we print -1.0. Otherwise, we print the result of the division.