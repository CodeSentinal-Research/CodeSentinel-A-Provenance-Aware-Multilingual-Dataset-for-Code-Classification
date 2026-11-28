def is_duck_number(n):
    return '0' in str(n) and str(n)[0] != '0'

def main():
    n = int(input("Enter a positive integer: "))
    if is_duck_number(n):
        print("Duck")
    else:
        print("Not Duck")

if __name__ == "__main__":
    main()