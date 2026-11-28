def is_divisible_by_three(n):
    if n % 3 == 0:
        return True
    else:
        return False

def main():
    n = int(input("Enter a number: "))
    if is_divisible_by_three(n):
        print("True")
    else:
        print("False")

if __name__ == "__main__":
    main()