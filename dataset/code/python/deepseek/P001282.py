Here is the Python code for the problem:

def max_number(N, M, K):
    arr1 = list(map(int, input().split()))
    arr2 = list(map(int, input().split()))
    
    arr1.sort()
    arr2.sort()
    
    arr1 = arr1[::-1]
    arr2 = arr2[::-1]
    
    if K < N + M:
        max_num = [0] * K
        
        for i in range(K):
            if arr1[i] >= arr2[i]:
                max_num[i] = arr1[i]
            else:
                max_num[i] = arr2[i]
        
        num = int(''.join(map(str, max_num)))
        
        print(num)
    else:
        print("Not possible")

max_number(0, 0, 0)

In the main function, the input is read from standard input, and then sorted. The largest number is printed out.