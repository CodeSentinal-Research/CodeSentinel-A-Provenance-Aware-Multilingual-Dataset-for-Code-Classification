def is_automorphic(n):
    sq = str(n ** 2)
    return sq.endswith(str(n))

def main():
    n = int(input("Enter a number: "))
    print(is_automorphic(n))

if __name__ == "__main__":
    main()