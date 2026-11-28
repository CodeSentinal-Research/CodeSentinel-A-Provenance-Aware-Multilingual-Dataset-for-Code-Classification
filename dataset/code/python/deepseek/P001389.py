def max_length(arr):
    max_len = 0
    count_0 = 0
    count_1 = 0
    counter = {}
    
    for i in range(len(arr)):
        if arr[i] == 0:
            count_0 += 1
        else:
            count_1 += 1
        counter[i] = count_1 - count_0
        if counter[i] in counter:
            max_len = max(max_len, i - counter[counter[i]])
        else:
            max_len = max(max_len, i)
    
    return max_len

def main():
    n = int(input().strip())
    arr = [int(i) for i in input().strip().split()]
    print(max_length(arr))

if __name__ == "__main__":
    main()