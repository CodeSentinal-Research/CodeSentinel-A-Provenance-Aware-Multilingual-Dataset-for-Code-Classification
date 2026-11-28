def egg_dropping(e, f):
    if e == 1:
        return f

    att = 1 + max(egg_dropping(e-1, k-1), egg_dropping(e, f-k))
    return att


def main():
    e = int(input("Enter the number of eggs: "))
    f = int(input("Enter the number of floors: "))
    print("Minimum number of attempts: ", egg_dropping(e, f))


if __name__ == "__main__":
    main()