def longest_string_index():
    N = int(input())
    strings = [input() for _ in range(N)]
    longest_string = max(strings, key=len)
    return strings.index(longest_string)

if __name__ == "__main__":
    print(longest_string_index())