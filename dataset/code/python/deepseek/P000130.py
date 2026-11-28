def solve():
    N = int(input().strip())
    arr = [int(i) for i in input().strip().split()]
    nextSmaller = [-1] * N
    stack = []

    for i in range(N-1, -1, -1):
        while stack and arr[i] < arr[stack[-1]]:
            idx = stack.pop()
            nextSmaller[idx] = arr[i]
        stack.append(i)

    print(' '.join(map(str, nextSmaller)))

solve()
This code first reads the number of elements N. Then it reads the array of N integers. 
In the main part of the code, it creates a new array called `nextSmaller` of size N filled with -1. Then, it uses a stack to find the next smaller element for each element in the array. 

The algorithm is based on a two-pass approach. In the first pass, we start from the end of the array and for each element, we pop the elements in the stack which are greater than the current element and set their next smaller element as the current element. 

Finally, we print the `nextSmaller` array.