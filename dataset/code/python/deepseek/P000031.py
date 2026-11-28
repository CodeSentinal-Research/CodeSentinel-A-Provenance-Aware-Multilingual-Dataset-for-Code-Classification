def is_armstrong(n):
    num_str = str(n)
    num_len = len(num_str)
    
    sum_cubes = sum(int(digit)**num_len for digit in num_str)
    
    return sum_cubes == n

def main():
    n = int(input("Enter a positive integer: "))
    if n < 1 or n > 10**6:
        print("Invalid input")
    elif is_armstrong(n):
        print("Armstrong")
    else:
        print("Not Armstrong")

if __name__ == "__main__":
    main()