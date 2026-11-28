Here is the Python code for your problem:

def sort_wave_form(arr):
    arr.sort()
    result = []
    while arr:
        result.append(arr.pop(0))
        if arr:
            result.append(arr.pop())
    return result

def main():
    n = int(input().strip())
    arr = [int(x) for x in input().strip().split()]
    print(sort_wave_form(arr))

if __name__ == "__main__":
    main()

This program works by sorting the input array and then alternately popping elements from the sorted array and appending them to the result array, until the sorted array is empty. This results in a wave-form array where each pair of adjacent elements is in increasing order.

The `main` function is responsible for getting the input from the user, calling the `sort_wave_form` function, and printing the result.