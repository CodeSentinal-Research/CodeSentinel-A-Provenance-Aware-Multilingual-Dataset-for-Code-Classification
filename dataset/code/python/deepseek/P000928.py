def binary_addition(A, B):
    return bin(int(A, 2) + int(B, 2))[2:]

def main():
    A = input()
    B = input()
    print(binary_addition(A, B))

if __name__ == "__main__":
    main()