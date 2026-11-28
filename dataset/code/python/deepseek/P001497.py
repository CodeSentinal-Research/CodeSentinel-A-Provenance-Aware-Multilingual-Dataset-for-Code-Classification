def rearrange(arr):
    arr.sort(key=lambda x: (x, abs(x)))
    return arr

def main():
    N = int(input().strip())
    arr = list(map(int, input().strip().split()))
    print(rearrange(arr))

if __name__ == '__main__':
    main()