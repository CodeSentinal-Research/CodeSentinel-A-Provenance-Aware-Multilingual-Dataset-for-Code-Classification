def rotate_array(arr, k):
    n = len(arr)
    k %= n  
    rotated_arr = arr[-k:] + arr[:-k]  
    return rotated_arr

def main():
    n, k = map(int, input().split())
    arr = list(map(int, input().split()))
    result = rotate_array(arr, k)
    print(' '.join(map(str, result)))

if __name__ == "__main__":
    main()