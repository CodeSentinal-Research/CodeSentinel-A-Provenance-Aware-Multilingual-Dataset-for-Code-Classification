def ship_within_days(weights, days):
    def feasible(capacity):
        return sum((capacity + weight - 1) // capacity for weight in weights) <= days

    left, right = max(weights), sum(weights)
    while left < right:
        mid = (left + right) // 2
        if feasible(mid):
            right = mid
        else:
            left = mid + 1
    return left


def main():
    n = int(input("Enter the number of packages: "))
    weights = list(map(int, input("Enter the weights of the packages: ").split()))
    days = int(input("Enter the number of days: "))
    print(ship_within_days(weights, days))


if __name__ == '__main__':
    main()