def find_pair(n, target, arr):
    num_dict = dict()
    for num in arr:
        if target - num in num_dict:
            return "Yes"
        num_dict[num] = None
    return "No"

def main():
    n, target = map(int, input().split())
    arr = list(map(int, input().split()))
    print(find_pair(n, target, arr))

if __name__ == "__main__":
    main()