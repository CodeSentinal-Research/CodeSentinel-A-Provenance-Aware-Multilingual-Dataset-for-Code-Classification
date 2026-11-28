def reverse_array():
    N = int(input().strip())
    arr = list(map(int, input().strip().split()))
    return arr[::-1]

if __name__ == "__main__":
    print(reverse_array())