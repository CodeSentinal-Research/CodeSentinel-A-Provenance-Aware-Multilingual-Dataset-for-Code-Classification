def isScrambled(s1, s2):
    if len(s1) != len(s2):
        return False

    cache = dict()

    def helper(s1, s2):
        if len(s1) == 0:
            return s2 == ''
        if (s1, s2) in cache:
            return cache[(s1, s2)]

        for i in range(1, len(s1)):
            if (helper(s1[:i], s2[:i]) and helper(s1[i:], s2[i:])) or (helper(s1[:i], s2[-i:]) and helper(s1[i:], s2[:-i])):
                cache[(s1, s2)] = True
                return True

        cache[(s1, s2)] = False
        return False

    return helper(s1, s2)


def main():
    s1 = input("Enter the first string: ")
    s2 = input("Enter the second string: ")

    print(isScrambled(s1, s2))


if __name__ == "__main__":
    main()