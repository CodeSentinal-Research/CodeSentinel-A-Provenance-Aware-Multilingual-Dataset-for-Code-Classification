Here is the Python code for the problem:

def count_pairs(N, K, array):
    array.sort()
    count = 0
    for i in range(N):
        target = array[i] + K
        if target in array:
            count += 1
    return count // 2

def main():
    N, K = map(int, input().split())
    array = list(map(int, input().split()))
    print(count_pairs(N, K, array))

if __name__ == "__main__":
    main()

This program reads the number of elements N and the difference K, then reads the elements themselves. It sorts the array, then for each element, it tries to find a pair with the target value by adding K to the current element. If it exists in the array, it increments the counter. The final answer is the count divided by 2, because each pair is counted twice. The `main` function is the entry point to the program.