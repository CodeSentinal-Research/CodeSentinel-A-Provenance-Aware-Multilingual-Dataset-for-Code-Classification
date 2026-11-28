def sum_of_odd_numbers(n):
    return sum(i for i in range(1, n+1) if i % 2 != 0)

def main():
    n = int(input("Enter a positive integer: "))
    print(sum_of_odd_numbers(n))

if __name__ == "__main__":
    main()