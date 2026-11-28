def main():
    n = int(input())
    arr = list(map(int, input().split()))

    freq = {}
    for num in arr:
        if num in freq:
            freq[num] += 1
        else:
            freq[num] = 1

    sorted_arr = sorted(freq.items(), key=lambda x: (-x[1], x[0]))

    for item in sorted_arr:
        print(item[0], end=' ')


if __name__ == "__main__":
    main()
This Python code first reads the number of elements `n` and the list of elements. Then it counts the frequency of each element in the list and stores it in a dictionary where the keys are the elements and the values are their frequencies. Finally, it sorts the dictionary by frequency in descending order (since we want higher frequency first) and element value in ascending order. The sorted array is printed.