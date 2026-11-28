def search_empty_string(strings):
    for i, s in enumerate(strings):
        if s == '':
            return i
    return -1

def main():
    N = int(input())
    strings = input().split()
    print(search_empty_string(strings))

if __name__ == "__main__":
    main()