def count_diophantine_solutions(A, B, C, X_range, Y_range):
    count = 0
    for X in X_range:
        for Y in Y_range:
            if A * X + B * Y == C:
                count += 1
    return count

def main():
    A = int(input("Enter A: "))
    B = int(input("Enter B: "))
    C = int(input("Enter C: "))
    X_range = list(map(int, input("Enter X range (separated by space): ").split()))
    Y_range = list(map(int, input("Enter Y range (separated by space): ").split()))
    print("Number of valid solutions: ", count_diophantine_solutions(A, B, C, X_range, Y_range))

if __name__ == "__main__":
    main()