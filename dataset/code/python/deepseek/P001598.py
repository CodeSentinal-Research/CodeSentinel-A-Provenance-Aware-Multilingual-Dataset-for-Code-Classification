def count_even_numbers():
    N = int(input())
    arr = list(map(int, input().split()))
    Q = int(input())
    for _ in range(Q):
        L, R = map(int, input().split())
        count = sum(1 for num in arr[L-1:R] if num % 2 == 0)
        print(count)

if __name__ == "__main__":
    count_even_numbers()

This Python code defines a function `count_even_numbers()`. The main function reads input for `N`, `arr` (a list of integers), and `Q`, then for each range `L` and `R`, it calculates the number of even numbers in `arr` within this range and prints the result.