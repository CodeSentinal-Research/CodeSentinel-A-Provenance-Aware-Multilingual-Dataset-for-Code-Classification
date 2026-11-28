Here's a Python solution for the problem:

def verify_chinese_remainder(X, congruences):
    M = []
    for c in congruences:
        M.append(c[0])

    M = set(M)
    if len(M) > 1:
        return False
    
    modulus = M.pop()
    if X % modulus != 0:
        return False

    for c in congruences:
        if X % c[0] != c[1]:
            return False

    return True

def main():
    X = int(input("Enter X: "))
    N = int(input("Enter N: "))
    congruences = []
    for i in range(N):
        c = list(map(int, input(f"Enter congruence {i+1}: ").split()))
        congruences.append(c)

    result = verify_chinese_remainder(X, congruences)
    print(result)

if __name__ == "__main__":
    main()

This code first reads the value of X and N, then reads the congruences themselves. It then uses the `verify_chinese_remainder` function to check if X satisfies all the congruences.

Please note that this code assumes that the list of congruences is provided in the format `[a, b]`, where a is the modulus and b is the remainder when a is divided by the modulus.