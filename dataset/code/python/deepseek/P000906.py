def modular_multiplication(A, B, M):
    return (A * B) % M

def main():
    A = int(input("Enter integer A: "))
    B = int(input("Enter integer B: "))
    M = int(input("Enter integer M: "))
    print(modular_multiplication(A, B, M))

if __name__ == "__main__":
    main()