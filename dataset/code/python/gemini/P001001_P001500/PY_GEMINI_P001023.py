def parent_index(i: int) -> int:
    if i <= 0:
        return -1
    return (i - 1) // 2

if __name__ == '__main__':
    i = int(input())
    print(parent_index(i))