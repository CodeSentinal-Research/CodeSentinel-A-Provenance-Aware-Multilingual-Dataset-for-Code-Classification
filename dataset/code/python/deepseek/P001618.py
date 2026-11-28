def prefix_xor_array(arr):
    n = len(arr)
    xor_array = [0]*n
    xor_array[0] = arr[0]
    for i in range(1, n):
        xor_array[i] = xor_array[i-1] ^ arr[i]
    return xor_array

def main():
    n = int(input().strip())
    arr = list(map(int, input().strip().split()))
    xor_array = prefix_xor_array(arr)
    print(' '.join(map(str, xor_array)))

main()