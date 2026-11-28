def reverse_only_letters(S):
    S = list(S)
    i, j = 0, len(S) - 1
    while i < j:
        if not S[i].isalpha():
            i += 1
        elif not S[j].isalpha():
            j -= 1
        else:
            S[i], S[j] = S[j], S[i]
            i, j = i + 1, j - 1
    return ''.join(S)

def main():
    S = input()
    print(reverse_only_letters(S))

if __name__ == "__main__":
    main()