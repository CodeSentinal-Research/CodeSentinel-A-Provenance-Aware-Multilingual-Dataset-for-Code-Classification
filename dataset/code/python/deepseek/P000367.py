def find_shortest_string(strings):
    return strings.index(min(strings, key=len))

def main():
    N = int(input())
    strings = input().split()
    print(find_shortest_string(strings))

if __name__ == "__main__":
    main()