def string_compression(s):
    count = 1
    compressed = ''
    
    for i in range(len(s) - 1):
        if s[i] == s[i + 1]:
            count += 1
        else:
            compressed += s[i] + str(count)
            count = 1
    
    compressed += s[-1] + str(count)
    return compressed

def main():
    s = input("Enter a string: ")
    print(string_compression(s))

if __name__ == "__main__":
    main()