def partition(s):
    def is_palindrome(check):
        return check == check[::-1]

    def dfs(start, path):
        if start >= len(s):
            result.append(path)
            return
        for end in range(start + 1, len(s) + 1):
            if is_palindrome(s[start:end]):
                dfs(end, path + [s[start:end]])

    result = []
    dfs(0, [])
    return result

def main():
    s = input()
    print(partition(s))

if __name__ == "__main__":
    main()