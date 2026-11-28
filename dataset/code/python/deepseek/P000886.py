def is_harshad(N):
    sum_of_digits = sum(int(digit) for digit in str(N))
    return N % sum_of_digits == 0

def main():
    N = int(input("Enter an integer: "))
    if is_harshad(N):
        print("True")
    else:
        print("False")

if __name__ == "__main__":
    main()