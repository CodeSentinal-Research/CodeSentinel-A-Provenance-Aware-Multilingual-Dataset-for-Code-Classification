def is_long_pressed(name, typed):
    i = j = 0
    while i < len(name) and j < len(typed):
        if name[i] == typed[j]:
            i += 1
            j += 1
        elif i > 0 and name[i-1] == typed[j]:
            i -= 1
            j += 1
        else:
            return 'NO'
    if i < len(name) or j < len(typed):
        return 'NO'
    return 'YES'

def main():
    name = input()
    typed = input()
    print(is_long_pressed(name, typed))

if __name__ == "__main__":
    main()