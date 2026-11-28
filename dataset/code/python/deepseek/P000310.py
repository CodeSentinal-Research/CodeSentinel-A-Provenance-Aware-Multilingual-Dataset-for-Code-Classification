def add_binary(a, b):
    a = int(a, 2)
    b = int(b, 2)

    sum = a + b

    return bin(sum)[2:]

def main():
    a = input("Enter the first binary string: ")
    b = input("Enter the second binary string: ")
    result = add_binary(a, b)
    print(f"The sum of {a} and {b} is {result} in binary.")

if __name__ == "__main__":
    main()