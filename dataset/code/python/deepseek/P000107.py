def is_sorted(array):
    return array == sorted(array)

def main():
    n = int(input())
    array = list(map(int, input().split()))
    print("Sorted" if is_sorted(array) else "Not Sorted")

if __name__ == "__main__":
    main()