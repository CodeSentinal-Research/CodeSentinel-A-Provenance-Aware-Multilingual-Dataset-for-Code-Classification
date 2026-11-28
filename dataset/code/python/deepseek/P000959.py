def solve_linear_diophantine_equation(A, B, C):
    if A % B == 0:
        if C % B == 0:
            return True
        else:
            return False
    else:
        if C % A == 0:
            return True
        else:
            return False

def main():
    A = int(input("Enter A: "))
    B = int(input("Enter B: "))
    C = int(input("Enter C: "))
    print(solve_linear_diophantine_equation(A, B, C))

if __name__ == "__main__":
    main()