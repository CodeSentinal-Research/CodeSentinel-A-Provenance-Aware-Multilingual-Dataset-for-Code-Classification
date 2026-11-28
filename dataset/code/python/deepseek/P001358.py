Here is the Python code for your problem:

from itertools import product

def abbreviations(word):
    def gen_abbr(w):
        for p in product(range(1, len(w)+1), repeat=len(w)):
            yield ''.join(str(i) if p[j]==0 else w[j] for j in range(len(p)) if p[j]!=0)

    return sorted(set(''.join(abbr) for abbr in gen_abbr(word))

def main():
    word = input()
    abbrs = abbreviations(word)
    for abbr in sorted(abbrs):
        print(abbr)

if __name__ == "__main__":
    main()

This program first defines a function `abbreviations` which generates all possible abbreviations of a given word. The function uses `itertools.product` to generate all possible combinations of the word's characters, and for each combination, it generates the corresponding abbreviation.

The `main` function reads a word from stdin, calls `abbreviations` to generate all possible abbreviations of the word, and then prints these abbreviations in lexicographical order.

The `if __name__ == "__main__"` part makes the code run when the script is run directly. If the code is imported as a module in another script, it will not run.