def find_min_pages():
    N, M = map(int, input().split())
    books = list(map(int, input().split()))

    total_capacity = sum(books)

    if total_capacity % M != 0:
        return "Impossible"

    min_pages = total_capacity // M

    return min_pages

if __name__ == "__main__":
    print(find_min_pages())
In this code, we first get the number of books and the number of students from the input. Then, we check if the total capacity of all books is not divisible by the number of students. If it is, then it's impossible to distribute all the books equally.

If the total capacity of all books is divisible by the number of students, then we calculate the minimum number of pages a student can read by dividing the total capacity by the number of students.

Finally, we print the minimum number of pages a student can read.