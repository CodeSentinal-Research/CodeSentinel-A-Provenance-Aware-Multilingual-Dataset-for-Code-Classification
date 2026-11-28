function findPages(n, pages, students) {
    let totalPages = pages.reduce((a, b) => a + b, 0);
    let maxPages = Math.max(...pages);
    let low = maxPages, high = totalPages;
    while (low < high) {
        let mid = Math.floor((low + high) / 2);
        if (canAllocate(pages, students, mid)) {
            high = mid;
        } else {
            low = mid + 1;
        }
    }
    return low;
}

function canAllocate(pages, students, maxPages) {
    let currentStudent = 1, currentSum = 0;
    for (let i = 0; i < pages.length; i++) {
        if (pages[i] + currentSum > maxPages) {
            currentStudent++;
            currentSum = pages[i];
            if (currentStudent > students) {
                return false;
            }
        } else {
            currentSum += pages[i];
        }
    }
    return true;
}