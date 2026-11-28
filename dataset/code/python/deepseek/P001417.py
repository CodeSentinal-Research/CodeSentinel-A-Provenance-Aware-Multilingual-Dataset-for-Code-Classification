def reorder_array(n, arr1, arr2):
    count = {num: 0 for num in arr1}

    for num in arr1:
        count[num] += 1

    result = []

    for num in arr2:
        if count[num] > 0:
            result.append(num)
            count[num] -= 1

    remaining = [num for num in arr1 if count[num] > 0]
    remaining.sort()
    result.extend(remaining)

    return result

def main():
    n, arr1, arr2 = map(int, input().split())
    print(reorder_array(n, arr1, arr2))

if __name__ == "__main__":
    main()