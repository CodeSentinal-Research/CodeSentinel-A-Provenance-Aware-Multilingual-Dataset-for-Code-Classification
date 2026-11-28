Here is a Python code solution for the problem:

def count_pairs(n, target, numbers):
    count = 0
    numbers_dict = {}

    for num in numbers:
        remaining = target - num
        if remaining in numbers_dict:
            count += numbers_dict[remaining]
        if num in numbers_dict:
            numbers_dict[num] += 1
        else:
            numbers_dict[num] = 1

    return count


def main():
    n, target = map(int, input().split())
    numbers = list(map(int, input().split()))
    print(count_pairs(n, target, numbers))


if __name__ == "__main__":
    main()

In this code, we first read the size `n` and target from the input. Then, we read the `n` integers. The `count_pairs` function then finds all pairs whose sum equals the target and counts them. Finally, the count is returned.