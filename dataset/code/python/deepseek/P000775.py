def binary_strings(n):
    if n == 0:
        return ['0']
    elif n == 1:
        return ['0', '1']

    prev_strings = binary_strings(n-1)
    strings = []
    for s in prev_strings:
        strings += ["0"+s]
        if s[-1] == '0':
            strings += ["1"+s]
    return sorted(strings)

def main():
    n = int(input("Enter the length of the binary string: "))
    result = binary_strings(n)
    for s in result:
        print(s)

if __name__ == "__main__":
    main()