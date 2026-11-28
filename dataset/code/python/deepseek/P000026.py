def check_palindrome(n):
    return str(n) == str(n)[::-1]

def main():
    n = int(input("Enter a number: "))
    if check_palindrome(n):
        print("Palindrome")
    else:
        print("Not Palindrome")

if __name__ == "__main__":
    main()