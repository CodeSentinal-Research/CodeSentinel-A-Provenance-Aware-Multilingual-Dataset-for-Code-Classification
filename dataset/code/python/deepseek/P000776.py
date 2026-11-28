def partition(s, m, dictionary):
    def backtrack(start, path, result):
        if start >= len(s) and len(path) > 0:
            result.append(path)
            return
        for i in range(start, len(s)):
            prefix = s[start: i+1]
            if prefix in dictionary:
                if len(path) == 0 or path[-1] + prefix in dictionary:
                    path.append(prefix)
                    backtrack(i+1, path, result)
                    path.pop()
    result = []
    backtrack(0, [], result)
    return result

def main():
    s = "biggest"
    m = 4
    dictionary = {"bi", "ig", "ge", "est", "ba", "st"}
    print(partition(s, m, dictionary))

if __name__ == "__main__":
    main()