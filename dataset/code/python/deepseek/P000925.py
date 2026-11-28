def binary_to_decimal(s):
    return int(s, 2)

def main():
    s = input("Enter a binary string: ")
    print("The decimal value is:", binary_to_decimal(s))

main()