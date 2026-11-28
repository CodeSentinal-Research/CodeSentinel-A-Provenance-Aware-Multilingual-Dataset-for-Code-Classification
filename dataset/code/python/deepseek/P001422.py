def get_keyboard_rows(words):
    row1 = set('qwertyuiopQWERTYUIOP')
    row2 = set('asdfghjklASDFGHJKL')
    row3 = set('zxcvbnmZXCVBNM')

    rows = [row1, row2, row3]

    result = []

    for word in words:
        if any(set(word).issubset(row) for row in rows):
            result.append(word)

    return sorted(result)

def main():
    N = int(input().strip())
    words = [input().strip() for _ in range(N)]
    result = get_keyboard_rows(words)
    for word in result:
        print(word)

if __name__ == '__main__':
    main()