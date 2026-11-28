def check_array():
    N = int(input().strip())
    numbers = list(map(int, input().strip().split()))
    numbers = sorted(set(numbers))

    if all(numbers[i] + 1 == numbers[i + 1] for i in range(len(numbers) - 1)):
        print("Yes")
    else:
        print("No")

if __name__ == "__main__":
    check_array()