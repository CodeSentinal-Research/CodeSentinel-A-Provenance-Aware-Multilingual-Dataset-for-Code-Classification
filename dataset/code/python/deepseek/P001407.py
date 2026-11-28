Here's the Python code for the problem:

def find_original(arr):
    n = len(arr)
    double_arr = [2*x for x in arr]
    if sum(double_arr) % 2 != 0:
        return -1

    target = sum(arr) * 2
    if sum(double_arr) != target:
        return -1

    return arr

def main():
    n = int(input().strip())
    arr = list(map(int, input().strip().split()))
    result = find_original(arr)
    if result == -1:
        print("-1")
    else:
        print(' '.join(map(str, result)))

if __name__ == "__main__":
    main()
This code first reads the number of elements (N) and the array from the standard input. Then it calls the `find_original` function with the array as an argument. If the result is -1, it prints -1, otherwise it prints the original array.