def min_append_chars(S, T):
    i, j = 0, 0
    appended = 0
    while i < len(S) and j < len(T):
        if S[i] == T[j]:
            j += 1
        i += 1
    return len(T) - j

def main():
    S = input()
    T = input()
    print(min_append_chars(S, T))

if __name__ == "__main__":
    main()