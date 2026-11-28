# problem title : Count Distinct Palindromic Substrings
# Solve the stated task using standard input and standard output.
def count_distinct_palindromic_substrings(s: str) -> int:
    palindromes = set()
    n = len(s)

    def expand(l: int, r: int):
        while l >= 0 and r < n and s[l] == s[r]:
            palindromes.add(s[l:r + 1])
            l -= 1
            r += 1

    for i in range(n):
        expand(i, i)
        expand(i, i + 1)

    return len(palindromes)

if __name__ == '__main__':
    s = input().strip()
    print(count_distinct_palindromic_substrings(s))
