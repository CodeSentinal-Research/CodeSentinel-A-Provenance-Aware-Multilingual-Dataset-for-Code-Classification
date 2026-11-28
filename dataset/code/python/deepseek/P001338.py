def sequential_digits(low, high):
    def is_sequential(num):
        str_num = str(num)
        for i in range(1, len(str_num)):
            if str_num[i] != str_num[i - 1] - 1:
                return False
        return True

    result = []
    for num in range(low, high + 1):
        if is_sequential(num):
            result.append(num)

    result.sort()
    for num in result:
        print(num)


try:
    low, high = map(int, input().split())
    sequential_digits(low, high)
except ValueError:
    print("Invalid input format. Please enter two integers separated by a space.")