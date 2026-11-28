#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
    int N, M;
    cin >> N >> M;

    vector<int> books(N);
    for (int& book : books) {
        cin >> book;
    }

    int left = *min_element(books.begin(), books.end());
    int right = *max_element(books.begin(), books.end());

    while (left < right) {
        int mid = left + (right - left) / 2;
        if (canAllocate(books, mid, M)) {
            right = mid;
        } else {
            left = mid + 1;
        }
    }

    cout << left;

    return 0;
}

bool canAllocate(const vector<int>& books, int pages, int students) {
    int booksAllocated = 1;
    int pagesLeft = pages;

    for (int book : books) {
        if (book <= pagesLeft) {
            pagesLeft -= book;
        } else {
            booksAllocated++;
            pagesLeft = pages - book;
        }
    }

    return booksAllocated <= students;
}