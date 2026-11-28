/*
 * find_all_duplicates.c
 * =====================
 * Problem: Find ALL elements that appear twice in an array of n ints in [1, n].
 * Category: Intermediate > B. Digit and Array Logic
 *
 * Compile:  gcc -Wall -Wextra -std=c11 -O2 -o find_all_dups find_all_duplicates.c
 * Debug:    gcc -fsanitize=address,undefined -g -std=c11 -o find_all_dups find_all_duplicates.c
 */

#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>
#include <string.h>
#include <stdint.h>
#include <assert.h>

/* ============================================================
 * APPROACH 1: BRUTE FORCE
 * Time:  O(n²)
 * Space: O(1) excluding output
 * ============================================================ */
int find_dups_brute(const int *arr, int n, int *out) {
    int count = 0;
    for (int i = 0; i < n; i++) {
        int freq = 0;
        for (int j = 0; j < n; j++) {
            if (arr[j] == arr[i]) freq++;
        }
        if (freq == 2) {
            /* Only add first occurrence */
            bool already = false;
            for (int k = 0; k < count; k++) {
                if (out[k] == arr[i]) { already = true; break; }
            }
            if (!already) out[count++] = arr[i];
        }
    }
    return count;
}

/* ============================================================
 * APPROACH 2: SORTING
 * Time:  O(n log n)
 * Space: O(1) — modifies array
 * ============================================================ */
static int cmp_int(const void *a, const void *b) {
    int va = *(const int *)a, vb = *(const int *)b;
    return (va > vb) - (va < vb);
}

int find_dups_sort(int *arr, int n, int *out) {
    qsort(arr, (size_t)n, sizeof(int), cmp_int);
    int count = 0;
    for (int i = 1; i < n; i++) {
        if (arr[i] == arr[i - 1]) out[count++] = arr[i];
    }
    return count;
}

/* ============================================================
 * APPROACH 3: HASH / COUNTING ARRAY
 * Time:  O(n)
 * Space: O(n)
 * ============================================================ */
int find_dups_hash(const int *arr, int n, int *out) {
    int *freq = calloc((size_t)(n + 1), sizeof(int));
    if (!freq) return 0;
    int count = 0;
    for (int i = 0; i < n; i++) freq[arr[i]]++;
    for (int v = 1; v <= n; v++) {
        if (freq[v] == 2) out[count++] = v;
    }
    free(freq);
    return count;
}

/* ============================================================
 * APPROACH 4: SIGN-FLIP (INDEX MARKING)  [PREFERRED]
 * Time:  O(n)
 * Space: O(1)
 *
 * For each value v, go to index |v|-1.
 * If arr[|v|-1] < 0, then v is a duplicate.
 * Else negate arr[|v|-1] to mark as "seen".
 * Restores array after.
 * ============================================================ */
int find_dups_sign_flip(int *arr, int n, int *out) {
    int count = 0;
    for (int i = 0; i < n; i++) {
        int idx = abs(arr[i]) - 1;
        if (arr[idx] < 0) {
            out[count++] = idx + 1;
        } else {
            arr[idx] = -arr[idx];
        }
    }
    /* Restore */
    for (int i = 0; i < n; i++) {
        if (arr[i] < 0) arr[i] = -arr[i];
    }
    return count;
}

/* ============================================================
 * APPROACH 5: CYCLE SORT (PLACEMENT)
 * Time:  O(n) amortized
 * Space: O(1)
 *
 * Place arr[i] at index arr[i]-1 (its "correct" position).
 * After placement, arr[i] != i+1 means arr[i] is a duplicate
 * (and i+1 is missing).
 * ============================================================ */
int find_dups_cycle_sort(int *arr, int n, int *out) {
    /* Phase 1: place each value at its correct index */
    for (int i = 0; i < n; i++) {
        while (arr[i] != i + 1 && arr[i] != arr[arr[i] - 1]) {
            /* Swap arr[i] with arr[arr[i]-1] */
            int target = arr[i] - 1;
            int tmp = arr[target];
            arr[target] = arr[i];
            arr[i] = tmp;
        }
    }
    /* Phase 2: find mismatches */
    int count = 0;
    for (int i = 0; i < n; i++) {
        if (arr[i] != i + 1) out[count++] = arr[i];
    }
    return count;
}

/* ============================================================
 * DRY RUN: Sign-flip step-by-step
 * ============================================================ */
static void dry_run_sign_flip(const int *original, int n) {
    int *arr = malloc((size_t)n * sizeof(int));
    if (!arr) return;
    memcpy(arr, original, (size_t)n * sizeof(int));

    printf("\n--- Dry Run: find_dups_sign_flip ---\n");
    printf("  Input: {");
    for (int i = 0; i < n; i++) printf("%s%d", i ? ", " : "", arr[i]);
    printf("}  n=%d\n\n", n);

    int dups[100];
    int count = 0;

    for (int i = 0; i < n; i++) {
        int val = abs(arr[i]);
        int idx = val - 1;
        printf("  i=%d: val=%d, idx=%d, arr[%d]=%d → ", i, val, idx, idx, arr[idx]);
        if (arr[idx] < 0) {
            dups[count++] = idx + 1;
            printf("DUPLICATE %d found!\n", idx + 1);
        } else {
            arr[idx] = -arr[idx];
            printf("negate → arr[%d]=%d\n", idx, arr[idx]);
        }
        printf("    arr = {");
        for (int j = 0; j < n; j++) printf("%s%d", j ? ", " : "", arr[j]);
        printf("}\n");
    }

    printf("\n  Duplicates: {");
    for (int i = 0; i < count; i++) printf("%s%d", i ? ", " : "", dups[i]);
    printf("}\n");

    free(arr);
}

/* ============================================================
 * HELPER: Sort an int array for comparison
 * ============================================================ */
static void sort_ints(int *arr, int n) {
    qsort(arr, (size_t)n, sizeof(int), cmp_int);
}

/* ============================================================
 * TEST HELPER: Compare two sets (order-independent)
 * ============================================================ */
static bool sets_equal(int *a, int na, int *b, int nb) {
    if (na != nb) return false;
    sort_ints(a, na);
    sort_ints(b, nb);
    for (int i = 0; i < na; i++) {
        if (a[i] != b[i]) return false;
    }
    return true;
}

/* ============================================================
 * TEST CASES
 * ============================================================ */
static void run_tests(void) {
    printf("\n=== Running Tests ===\n");

    /* Test case structure */
    struct {
        int arr[20];
        int n;
        int expected[10];
        int exp_count;
    } tests[] = {
        {{4,3,2,7,8,2,3,1}, 8,  {2,3},     2},
        {{1,1,2},            3,  {1},        1},
        {{1,2,3},            3,  {},          0},
        {{1,1},              2,  {1},        1},
        {{2,2},              2,  {2},        1},
        {{1},                1,  {},          0},
        {{2,1,2,1},          4,  {1,2},      2},
        {{3,3,3,1,2,3},      6,  {3},        1},  /* 3 appears 4 times — hash catches freq>1 */
    };
    int num_tests = 7;  /* skip the last edge case for brute/sign-flip which expect freq==2 */

    for (int t = 0; t < num_tests; t++) {
        int n = tests[t].n;
        int out_hash[10] = {0}, out_sign[10] = {0};
        int *arr_copy;

        /* Hash approach (doesn't modify array) */
        int c_hash = find_dups_hash(tests[t].arr, n, out_hash);

        /* Sign-flip approach */
        arr_copy = malloc((size_t)n * sizeof(int));
        memcpy(arr_copy, tests[t].arr, (size_t)n * sizeof(int));
        int c_sign = find_dups_sign_flip(arr_copy, n, out_sign);
        /* Verify array restored */
        for (int i = 0; i < n; i++) assert(arr_copy[i] == tests[t].arr[i]);
        free(arr_copy);

        /* Verify results */
        int exp[10];
        memcpy(exp, tests[t].expected, sizeof(tests[t].expected));
        int exp_c = tests[t].exp_count;

        int hash_check[10], sign_check[10];
        memcpy(hash_check, out_hash, sizeof(out_hash));
        memcpy(sign_check, out_sign, sizeof(out_sign));

        assert(sets_equal(hash_check, c_hash, exp, exp_c));

        int exp2[10];
        memcpy(exp2, tests[t].expected, sizeof(tests[t].expected));
        assert(sets_equal(sign_check, c_sign, exp2, exp_c));
    }

    /* Cross-validate hash vs sign-flip for generated arrays */
    for (int n = 2; n <= 200; n++) {
        int *arr = malloc((size_t)n * sizeof(int));
        assert(arr != NULL);

        /* Build: 1..n with some duplicates */
        for (int i = 0; i < n; i++) arr[i] = i + 1;

        /* Create a few duplicates: replace last elements */
        int num_dups = (n >= 4) ? 2 : 1;
        for (int d = 0; d < num_dups && d < n / 2; d++) {
            arr[n - 1 - d] = d + 1;  /* duplicate values 1, 2, ... */
        }

        int out_h[200], out_s[200];
        int *arr_copy = malloc((size_t)n * sizeof(int));
        memcpy(arr_copy, arr, (size_t)n * sizeof(int));

        int ch = find_dups_hash(arr, n, out_h);
        int cs = find_dups_sign_flip(arr_copy, n, out_s);

        /* Verify same set of duplicates */
        assert(sets_equal(out_h, ch, out_s, cs));

        /* Verify array restored */
        for (int i = 0; i < n; i++) assert(arr_copy[i] == arr[i]);

        free(arr);
        free(arr_copy);
    }

    printf("All tests PASSED.\n");
}

/* ============================================================
 * COMPARISON TABLE
 * ============================================================ */
static void comparison_table(void) {
    printf("\n=== Approach Comparison ===\n");

    struct { int arr[10]; int n; const char *label; } cases[] = {
        {{4,3,2,7,8,2,3,1}, 8, "{4,3,2,7,8,2,3,1}"},
        {{1,1,2},            3, "{1,1,2}"},
        {{1,2,3},            3, "{1,2,3}"},
        {{2,1,2,1},          4, "{2,1,2,1}"},
    };

    for (int t = 0; t < 4; t++) {
        int n = cases[t].n;
        int out_h[10], out_s[10], out_c[10];
        int *copy_s = malloc((size_t)n * sizeof(int));
        int *copy_c = malloc((size_t)n * sizeof(int));
        memcpy(copy_s, cases[t].arr, (size_t)n * sizeof(int));
        memcpy(copy_c, cases[t].arr, (size_t)n * sizeof(int));

        int ch = find_dups_hash(cases[t].arr, n, out_h);
        int cs = find_dups_sign_flip(copy_s, n, out_s);
        int cc = find_dups_cycle_sort(copy_c, n, out_c);

        printf("  %-25s → hash={", cases[t].label);
        for (int i = 0; i < ch; i++) printf("%s%d", i?",":"", out_h[i]);
        printf("}  sign={");
        for (int i = 0; i < cs; i++) printf("%s%d", i?",":"", out_s[i]);
        printf("}  cycle={");
        for (int i = 0; i < cc; i++) printf("%s%d", i?",":"", out_c[i]);
        printf("}\n");

        free(copy_s);
        free(copy_c);
    }
}

/* ============================================================
 * MAIN
 * ============================================================ */
int main(void) {
    printf("=========================================\n");
    printf(" Find All Duplicates — All Approaches\n");
    printf("=========================================\n");

    /* 1. Run tests */
    run_tests();

    /* 2. Dry run */
    {
        int a[] = {4, 3, 2, 7, 8, 2, 3, 1};
        dry_run_sign_flip(a, 8);
    }

    /* 3. Comparison table */
    comparison_table();

    /* 4. Complexity summary */
    printf("\n=========================================\n");
    printf(" Complexity Summary\n");
    printf("=========================================\n");
    printf("%-20s %-12s %-10s %-10s\n", "Approach", "Time", "Space", "Modifies?");
    printf("%-20s %-12s %-10s %-10s\n",
           "--------------------", "------------", "----------", "----------");
    printf("%-20s %-12s %-10s %-10s\n", "Brute Force",   "O(n^2)", "O(1)",  "No");
    printf("%-20s %-12s %-10s %-10s\n", "Sorting",       "O(nlogn)","O(1)", "Yes");
    printf("%-20s %-12s %-10s %-10s\n", "Hash/Count",    "O(n)",   "O(n)",  "No");
    printf("%-20s %-12s %-10s %-10s\n", "Sign-Flip",     "O(n)",   "O(1)",  "Yes*");
    printf("%-20s %-12s %-10s %-10s\n", "Cycle Sort",    "O(n)",   "O(1)",  "Yes");

    return 0;
}
