def two_sum(numbers, target):
    num_dict = {}
    for i, num in enumerate(numbers):
        if target - num in num_dict:
            return [num_dict[target - num] + 1, i + 1]
        else:
            num_dict[num] = i
    return []

def main():
    N, Target = map(int, input().split())
    numbers = sorted(map(int, input().split()))
    result = two_sum(numbers, Target)
    if result:
        print(' '.join(map(str, result)))
    else:
        print('No solution')

if __name__ == "__main__":
    main()