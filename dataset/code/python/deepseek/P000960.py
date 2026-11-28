def find_diophantine(A, B, C):
    if A % 2 == 0 and B % 2 == 0:
        return -1
    for X in range(0, C // B + 1):
        Y = (C - A * X) // B
        if X >= Y:
            break
        if X * B + Y * A == C:
            return X, Y
    return -1


def main():
    A = int(input())
    B = int(input())
    C = int(input())
    result = find_diophantine(A, B, C)
    if result == -1:
        print("No Solution")
    else:
        print(result[0], result[1])


if __name__ == "__main__":
    main()