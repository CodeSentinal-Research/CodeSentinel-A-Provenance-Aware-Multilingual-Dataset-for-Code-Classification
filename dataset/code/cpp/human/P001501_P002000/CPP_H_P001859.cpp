#include <iostream>
#include <cassert>

// Exponentiation by squaring
double pow(double x, int n) {
    if (n == 0) {
        return 1;
    } else if (n < 0) {
        return 1.0 / pow(x, -n);
    } else {
        // x^n = x*x*x...     (n times)
        // x^(n/2) = x*x*x... (n/2 times)
        // half the number of times!
        //
        // x^n = (x^(n/2))^2
        // so we can just let p = x^(n/2)
        // and calculate p*p;
        // way more efficient
        //
        // but since n is `int`,
        // and we for our `pow` we must keep it as an `int`
        // i.e. 5/2 = 2, so we need to multiply p*p*x: (exp: 2+2+1)
        //
        double p = pow(x, n / 2);

        if (n % 2 == 0) {
            return p * p;
        } else {
            return p * p * x;
        }
    }
}

// Returns the first index that breaks the sorted nature of the array
//
// if sorted: return `capacity`
std::size_t is_sorted(const double array[], std::size_t capacity) {
    for (std::size_t i = 1; i < capacity; i++) {
        if (array[i - 1] > array[i]) {
            // first element that is smaller than its previous
            return i;
        }
    }
    return capacity;
}

// Binary search
std::size_t binary_search(double const array[], std::size_t const capacity, double const value) {
    assert(is_sorted(array, capacity) == capacity);

    std::size_t left = 0;
    std::size_t right = capacity - 1;

    // we need a `right < capacity` check
    // if `value < array[0]`,
    // then `right` will eventually be `mid - 1` => `0 - 1` => `-1`
    // and be carried over to `0xffffffff` since `size_t` is unsigned
    // therefore `right` should not be `>= capacity`
    while (left <= right && right < capacity) {
        std::size_t mid = (left + right) / 2;

        if (array[mid] > value) {
            right = mid - 1;
        } else if (array[mid] < value) {
            left = mid + 1;
        } else {
            return mid;
        }
    }
    return capacity;
}

void swap(double array[], std::size_t i, std::size_t j) {
    double temp = array[i];
    array[i] = array[j];
    array[j] = temp;
}

// Selection sort: O(n^2)
void selection_sort(double array[], std::size_t capacity) {
    // array from `0` to `i - 1` is unsorted,
    // the sorted portion is from `i` to `capacity - 1`
    for (std::size_t i = capacity - 1; i > 0; i--) {
        std::size_t max_idx = 0;

        // from the unsorted portion `0` to `i`
        // (include `i` for sorting, it may already be in the right place)
        // we find a maximum entry at `max_i`
        for (std::size_t j = 1; j <= i; j++) {
            if (array[j] > array[max_idx]) {
                max_idx = j;
            }
        }
        // swap the maximum entry with the last element of the "unsorted portion"
        // thereby expanding the sorted portion on its right
        swap(array, i, max_idx);
    }

    assert(is_sorted(array, capacity) == capacity);
}

// Recursive selection sort
//
// If the array has capacity of `0` or `1`, we are done (base case)
// else: the array has `capacity > 1`:
//   - Find the largest entry and swap it with the last entry (capacity - 1)
//   - Apply selection sort to the first `capacity - 1` entries
void recursive_selection_sort(double array[], std::size_t capacity) {
    // `capacity - 1 > 0` was the condition above in the for-loop
    // since `i > 0` and `i` started at `capacity - 1`
    if (capacity <= 1) {
        return;
    } else {
        std::size_t max_idx = 0;

        // the max-value should start sear
        for (std::size_t j = 1; j <= capacity - 1; j++) {
            if (array[j] > array[max_idx]) {
                max_idx = j;
            }
        }

        swap(array, capacity - 1, max_idx);
        // this is basically equivalent to for-loop with `i--` like above
        recursive_selection_sort(array, capacity - 1);
    }

    assert(is_sorted(array, capacity) == capacity);
}

// Insertion sort: O(n^2)
void insertion_sort(double array[], std::size_t capacity) {
    // keep a growing sorted portion at the beginning from `0` to `i`
    for (std::size_t i = 0; i < capacity - 1; i++) {
        // the `(i + 1)-th` element is the unsorted element we want to
        // insert into the sorted section from `0` to `i`
        // `j`: all values to insert the element into starting from `i`
        // the desired element will always be `j + 1` then
        for (
            std::size_t j = i;
            j >= 0 && array[j + 1] < array[j];
            j--
        ) {
            swap(array, j, j + 1);
        }
    }

    assert(is_sorted(array, capacity) == capacity);
}

// Recursive insertion sort
//
// If the array has capacity if `0` or `1` we are done (base case)
// else:
//   - Sort the first `capacity - 1` entries using insertion sort
//   - insert the last entry (capacity - 1) into the now-sorted array
void recursive_insertion_sort(double array[], std::size_t capacity) {
    if (capacity <= 1) {
        return;
    } else {
        insertion_sort(array, capacity - 1);

        // insert last entry: `capacity`
        // `- 2` since compared to above `j = i` where `i < capacity - 1` meaning `i <= capacity - 2`
        for (
            std::size_t j = capacity - 2;
            j >= 0 && array[j + 1] < array[j];
            j--
        ) {
            swap(array, j, j + 1);
        }
    }

    assert(is_sorted(array, capacity) == capacity);
}

// Merge sort: O(n log n)
// divide and conquer
// merge smaller sorted sections of the array
//
// merging: O(n)
// (times) log_2(n) sections to merge
void merge_sort(double array[], std::size_t capacity) {
    if (capacity <= 1) {
        return;
    } else {
        // array 1: [0, capacity // 2 - 1]
        std::size_t capacity_1 = capacity / 2;
        // array 2: [capacity // 2, capacity - 1]
        std::size_t capacity_2 = capacity - capacity_1;

        // sort the left half of `array` (in-place)
        merge_sort(array, capacity_1);
        // obtain array 2 by shifting starting pointer by `capacity // 2` elements
        // sort the right half of `array` (in-place)
        merge_sort(array + capacity_1, capacity_2);

        // merge sorted both halves of `array` into `temp`
        // we don't want to overwrite the original `array` values just yet
        double temp[capacity];

        // indexes the first half of `array`
        std::size_t i1 = 0;
        // indexes the second second half of `array`
        std::size_t i2 = capacity_1;
        // indexes `temp` when setting
        std::size_t j = 0;

        // keep comparing between array halves and using the smaller one
        // until ONE of the arrays empty out
        while (i1 < capacity_1 && i2 < capacity) {
            if (array[i1] <= array[i2]) {
                // current element from first half is smaller (use it)
                temp[j] = array[i1];
                // increment pointer for first half
                i1++;
            } else {
                // current element from second half is smaller (use it)
                temp[j] = array[i2];
                // increment pointer for first half
                i2++;
            }

            // set next element of temp;
            j++;
        }

        // only one of the below loops will run
        // since only has 1 has leftovers from the above loop
        // but we don't know which one, so we just blindly process both

        while (i1 < capacity_1){
            temp[j] = array[i1];
            j++;
            i1++;
        }

        while (i2 < capacity) {
            temp[j] = array[i2];
            j++;
            i2++;
        }

        // move all of temp into array
        for (std::size_t i = 0; i < capacity; i++) {
            array[i] = temp[i];
        }

        // `array` is now sorted
        assert(is_sorted(array, capacity) == capacity);
    }
}

void print_subsets(bool membership_arr[], std::size_t capacity, std::size_t idx) {
    // gone over all elements of array (either include or not include)
    // finished building a subset
    if (idx == capacity) {
        for (std::size_t i = 0; i < capacity; i++) {
            // if according to `membership_arr` we want to include `i` in our subset
            if (membership_arr[i]) {
                // remember the indexes are [0, n - 1] but our numbers are [1, n]
                std::cout << (i + 1) << " ";
            }
        }
        // finished printing 1 subset
        std::cout << std::endl;
    } else {
        // subset not filled yet, keep generating

        // branch out to either include current num
        membership_arr[idx] = true;
        print_subsets(membership_arr, capacity, idx + 1);
        // or don't include it
        membership_arr[idx] = false;
        print_subsets(membership_arr, capacity, idx + 1);
    }
}

// prints all subsets of integers from [1, n]
// overload to make it more user-friendly
void print_subsets(unsigned int n) {
    // indexes are [0, n - 1]
    bool membership_arr[n] {};
    print_subsets(membership_arr, n, 0);
}

void print_binary(int const n) {
    if (n < 0) {
        // just print a negative sign and print the positive version
        std::cout << '-';
        print_binary(-n);
    } else if (n == 0 || n == 1) {
        // this is the final bit, just print it
        std::cout << n;
    } else {
        // algorithm for converting to binary
        // in binary: right -> left
        // print remainder after dividing by 2
        // repeat for the quotient for remaining digits to the left
        //
        // since recursion is a stack,
        // the inner-most, the one at the top of the stack, the one at the bottom of the tree
        // is the one that executes/prints first
        // which is perfect for binary since it's a right -> left algorithm
        print_binary(n / 2);
        std::cout << n % 2;
    }
}

int main() {
    double a[] = {123, 3, 1, 36, 4, 78, 210};
    insertion_sort(a, 7);
    double b[] = {123, 3, 1, 36, 4, 78, 210};
    selection_sort(b, 7);
    double c[] = {123, 3, 1, 36, 4, 78, 210};
    recursive_selection_sort(c, 7);
    double d[] = {123, 3, 1, 36, 4, 78, 210};
    recursive_insertion_sort(d, 7);
    double e[] = {123, 3, 1, 36, 4, 78, 210};
    merge_sort(e, 7);

    print_binary(0b101101);
    std::cout << std::endl << "---------" << std::endl;
    print_subsets(4);
}