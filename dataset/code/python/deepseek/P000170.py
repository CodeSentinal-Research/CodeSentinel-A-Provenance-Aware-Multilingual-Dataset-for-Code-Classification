Here is the Python code:

def find_non_repeating_element():
    N = int(input().strip())
    arr = list(map(int, input().strip().split()))
    count = {}
    for i in arr:
        if i in count:
            count[i] += 1
        else:
            count[i] = 1
    for i in arr:
        if count[i] == 1:
            return i
    return -1

if __name__ == "__main__":
    print(find_non_repeating_element())

The `find_non_repeating_element` function reads the size of the array (N) and the array elements from the input. It then uses a dictionary (`count`) to count the occurrences of each number in the array. It then iterates over the array and returns the first number that occurs only once. If no such number is found, it returns -1.