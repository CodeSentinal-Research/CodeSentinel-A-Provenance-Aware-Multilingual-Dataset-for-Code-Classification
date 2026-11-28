def find_hcf(a, b):
    if a == 0:
        return b
    return find_hcf(b % a, a)

if __name__ == '__main__':
    a = int(input("Enter the first number: "))
    b = int(input("Enter the second number: "))
    print("The HCF of", a, "and", b, "is", find_hcf(a, b))