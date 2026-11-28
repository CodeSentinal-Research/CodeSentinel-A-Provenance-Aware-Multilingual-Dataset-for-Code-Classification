Here is the Python code for the problem:

def minimum_index_sum(N, strings_1, M, strings_2):
    strings_1_dict = {v: i for i, v in enumerate(strings_1)}
    sum_min = float('inf')
    result = []
    for i, s in enumerate(strings_2):
        if s in strings_1_dict:
            sum_current = strings_1_dict[s] + i
            if sum_current < sum_min:
                sum_min = sum_current
                result = [s]
            elif sum_current == sum_min:
                result.append(s)
    result.sort()
    return result


def main():
    N = int(input().strip())
    strings_1 = [input().strip() for _ in range(N)]
    M = int(input().strip())
    strings_2 = [input().strip() for _ in range(M)]
    result = minimum_index_sum(N, strings_1, M, strings_2)
    print('\n'.join(result))


if __name__ == '__main__':
    main()

This code first reads the number of strings in the first list and their values, and creates a dictionary where the strings are the keys and their indices are the values. Then it reads the number of strings in the second list and their values, and for each string in the second list, it checks if the string is in the first list. If it is, it calculates the sum of indices in the first list and the second list, and compares it with the minimum sum found so far. If it finds a string with a smaller sum, it updates the minimum sum and resets the result list. If it finds a string with the same sum, it appends the string to the result list. After reading all strings, it sorts the result list and prints it.