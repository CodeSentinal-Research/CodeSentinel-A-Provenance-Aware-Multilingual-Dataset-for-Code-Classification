def find_frobenius_number(A, B):
    if A % 2 == 0 or B % 2 == 0:
        return 2
    else:
        return 1

def main():
    A = int(input("Enter the first number: "))
    B = int(input("Enter the second number: "))
    print(find_frobenius_number(A, B))

if __name__ == "__main__":
    main()