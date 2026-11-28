def find_intersections(n, m, interval_lists):
    interval_lists.sort(key=lambda x: x[0])
    for i in range(n - 1):
        if interval_lists[i + 1][0] < interval_lists[i][1]:
            lower_limit = max(interval_lists[i][0], interval_lists[i + 1][0])
            upper_limit = min(interval_lists[i][1], interval_lists[i + 1][1])
            if lower_limit < upper_limit:
                print(f"[{lower_limit}, {upper_limit}]")


def main():
    n, m = map(int, input().split())
    interval_lists = [list(map(int, input().split())) for _ in range(n)]
    for _ in range(m):
        find_intersections(n, m, interval_lists)


if __name__ == "__main__":
    main()