def solve(numbers, target, index=0, positive=0, negative=0):
    if index == len(numbers):
        if abs(target) == abs(positive) == abs(negative):
            return 1
        else:
            return 0
    else:
        return (
            solve(numbers, target, index + 1, positive + numbers[index], negative) +
            solve(numbers, target, index + 1, positive, negative + numbers[index])
        )

def main():
    N, Target = map(int, input().split())
    numbers = list(map(int, input().split()))
    print(solve(numbers, Target))

if __name__ == '__main__':
    main()