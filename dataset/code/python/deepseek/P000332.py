def custom_sort_string(order, s):
    perm = [0] * len(s)
    for i in range(len(s)):
        perm[i] = order.index(s[i])
    return ''.join(s[i] for i in sorted(range(len(s)), key=lambda i: perm[i]))

def main():
    order = input()
    s = input()
    print(custom_sort_string(order, s))

if __name__ == "__main__":
    main()