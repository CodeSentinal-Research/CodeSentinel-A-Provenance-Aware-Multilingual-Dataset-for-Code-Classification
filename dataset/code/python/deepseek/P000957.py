def gcd(a, b):
    while b != 0:
        a, b = b, a % b
    return a

def bezouts_identity(A, B, X, Y):
    if A % gcd(A, B) == X % gcd(A, B) and B % gcd(A, B) == Y % gcd(A, B):
        return True
    else:
        return False

def main():
    A = int(input())
    B = int(input())
    X = int(input())
    Y = int(input())
    print(bezouts_identity(A, B, X, Y))

if __name__ == "__main__":
    main()