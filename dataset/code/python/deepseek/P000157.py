def find_equilibrium_point():
    N = int(input().strip())
    A = list(map(int, input().strip().split()))

    total_sum = sum(A)
    left_sum = 0

    for i in range(N):
        left_sum += A[i]
        right_sum = total_sum - left_sum - A[i]
        if left_sum == right_sum:
            return i + 1

    return -1

if __name__ == "__main__":
    print(find_equilibrium_point())
This Python code will solve the problem. It reads the input, calculates the total sum of the array, and then checks each element in the array to see if it is the equilibrium point. If it is, it returns the index (1-based) of the equilibrium point. If no equilibrium point is found, it returns -1.