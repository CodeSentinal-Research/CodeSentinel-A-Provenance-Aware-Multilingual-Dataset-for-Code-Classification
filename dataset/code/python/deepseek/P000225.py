def minSwaps(arr):
    n = len(arr)
   
    freq = [0] * (n + 1)
    for i in range(n):
        freq[arr[i]] = i
 
    ans = n
 
    i = 1
    while i <= n:
        if freq[i] == n - 1 - i:
            j = freq[i] - 1
            while j >= 0:
                if freq[j] == i:
                    freq[j] = freq[i-1]
                    ans -= 1
                i -= 1
        else:
            break
            
    return ans

def main():
    n = int(input().strip())
    arr = [int(i) for i in input().strip().split()]
    print(minSwaps(arr))

main()