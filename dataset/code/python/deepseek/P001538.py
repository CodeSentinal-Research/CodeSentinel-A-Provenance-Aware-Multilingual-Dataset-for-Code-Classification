def find_permutation(s1, s2):
    len_s1 = len(s1)
    len_s2 = len(s2)

    for i in range(len_s2 - len_s1 + 1):
        if s2[i:i+len_s1] == s1:
            return 'YES'

    return 'NO'

def main():
    s1 = input().strip()
    s2 = input().strip()

    print(find_permutation(s1, s2))

if __name__ == '__main__':
    main()