def find_common_elements():
    sizes = list(map(int, input().split()))

    arrays = [list(map(int, input().split())) for _ in range(sizes[0])]

    common_elements = set(arrays[0]).intersection(*arrays[1:]).intersection(*arrays[2:]).intersection(arrays[1]).intersection(arrays[2])

    print(' '.join(map(str, sorted(common_elements))))

if __name__ == "__main__":
    find_common_elements()