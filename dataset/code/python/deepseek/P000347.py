def reverse_string_ii(s, k):
    s = list(s)
    for i in range(0, len(s), 2*k):
        s[i:i+k] = reversed(s[i:i+k][::-1])
    return ''.join(s)

def main():
    s = input("Enter the string: ")
    k = int(input("Enter the value of k: "))
    print(reverse_string_ii(s, k))

if __name__ == "__main__":
    main()