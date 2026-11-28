def longest_common_prefix(strs):
    if not strs:
        return ""

    shortest_str = min(strs, key=len)

    for i, char in enumerate(shortest_str):
        for other_str in strs:
            if len(other_str) <= i or other_str[i] != char:
                return shortest_str[:i]
    return shortest_str

def main():
    n = int(input())
    strs = [input() for _ in range(n)]
    print(longest_common_prefix(strs))

if __name__ == "__main__":
    main()