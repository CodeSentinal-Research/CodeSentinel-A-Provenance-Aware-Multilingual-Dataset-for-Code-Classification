def find_odd_occurrence():
    N = int(input().strip())
    arr = list(map(int, input().strip().split()))

    count_dict = {}
    for num in arr:
        if num in count_dict:
            count_dict[num] += 1
        else:
            count_dict[num] = 1

    odd_occurrence = [num for num, count in count_dict.items() if count % 2 == 1]
    return odd_occurrence[0], odd_occurrence[1]

def main():
    odd_occurrence = find_odd_occurrence()
    print(odd_occurrence[0], odd_occurrence[1])

if __name__ == "__main__":
    main()