def find_equilibrium_index(n, arr):
    left_sum = 0
    total_sum = sum(arr)

    for i in range(n):
        total_sum -= arr[i]
        if left_sum == total_sum:
            return i
        left_sum += arr[i]

    return -1

def main():
    n = int(input().strip())
    arr = list(map(int, input().strip().split()))
    print(find_equilibrium_index(n, arr))

if __name__ == "__main__":
    main()
This Python code will find the equilibrium index in an array. The function find_equilibrium_index calculates the sum of the left side (arr[0..i-1]) and right side (arr[i+1..n-1]) of the array. It returns the index i where the sum of the left side is equal to the sum of the right side. If no such index exists, it returns -1.

The main function reads the number of elements n and the array elements from the input. It then calls the find_equilibrium_index function with n and arr as arguments.