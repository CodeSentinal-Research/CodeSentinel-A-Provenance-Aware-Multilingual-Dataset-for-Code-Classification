Here is the Python code for the problem:

def solve(N, K):
    result = ""
    while K > 0:
        for i in range(1, 27):
            if K - i < 0:
                break
            K -= i
            result += chr(96 + i)
    return result

N, K = map(int, input().split())
print(solve(N, K))

This code first defines a function `solve(N, K)`. In this function, a loop is started with a range from 1 to 26. In each iteration, if the remaining numeric value `K - i` is greater than 0, `K -= i`, and the character represented by `chr(96 + i)` is added to `result`. If `K - i` is less than 0, the loop is broken and `result` is returned.

The `input()` function is used to handle the input. The input is split into `N` and `K`, and they are converted to integers using `map(int, input().split())`. The `print(solve(N, K))` line prints the result of the `solve(N, K)` function.