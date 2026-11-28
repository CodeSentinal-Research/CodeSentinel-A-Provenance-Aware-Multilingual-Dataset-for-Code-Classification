Here is the Python code:

def max_product_of_three(arr):
    if len(arr) < 3:
        return None
    max_1, max_2, max_3 = [float('-inf')] * 3
    min_1, min_2 = [float('inf')] * 2
    for num in arr:
        if num > max_1:
            max_3, max_2, max_1 = max_2, max_1, num
        elif num > max_2:
            max_3 = max_2
            max_2 = num
        elif num > max_3:
            max_3 = num
        if num < min_1:
            min_2, min_1 = min_1, num
        elif num < min_2:
            min_2 = num
    return max(max_1 * max_2 * max_3, max_1 * min_1 * min_2)

def main():
    N = int(input().strip())
    arr = list(map(int, input().strip().split()))
    print(max_product_of_three(arr))

if __name__ == "__main__":
    main()
This program works by keeping track of the three largest and two smallest numbers in the array. It then returns the maximum of the product of the three largest numbers and the product of the two smallest numbers and the largest number.