def min_pages(pages, students):
    l, r = max(pages), sum(pages)
    while l < r:
        mid = (l + r) // 2
        if check(pages, students, mid):
            r = mid
        else:
            l = mid + 1
    return r

def check(pages, students, limit):
    current_sum = 0
    current_students = 1
    for page in pages:
        if current_sum + page > limit:
            current_sum = page
            current_students += 1
        else:
            current_sum += page
    return current_students <= students

def main():
    n = int(input())
    pages = list(map(int, input().split()))
    students = int(input())
    print(min_pages(pages, students))

if __name__ == "__main__":
    main()