Here is the Python code for the given problem:

def relative_sort(array1, array2):
    counter = {num: 0 for num in array1}
    for num in array1:
        counter[num] += 1

    result = []
    for num in array2:
        if num in counter:
            count = counter[num]
            counter[num] = 0
            result.append(num * count)

    for num in sorted(counter):
        count = counter[num]
        result.append(num * count)

    return result

def main():
    M, N = map(int, input().split())
    array1 = list(map(int, input().split()))
    array2 = list(map(int, input().split()))

    print(relative_sort(array1, array2))

if __name__ == "__main__":
    main()

In this code, we first count the occurrences of each number in array1, and then for each number in array2, we append the number and its count to the result. After that, we append all the remaining numbers in sorted order and their counts from the counter.