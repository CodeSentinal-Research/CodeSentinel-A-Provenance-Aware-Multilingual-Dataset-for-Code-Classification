Here is the Python code:

from collections import Counter

def sort_characters_by_occurrence(s):
    counter = Counter(s)
    sorted_s = sorted(counter.items(), key=lambda x: (-x[1], x[0]))
    return ''.join(char * freq for char, freq in sorted_s)

def main():
    s = input()
    print(sort_characters_by_occurrence(s))

if __name__ == "__main__":
    main()
In this code, we use a Python feature called Counter from the collections module to count the occurrence of each character in the string. The Counter returns a dictionary where keys are characters and values are their counts.

Then, we sort the Counter items in descending order of count (because we want to sort by the count, and then by character in lexicographical order) using the sorted() function. This function takes a sequence (like a list) and a key function to apply to each element in the sequence. In this case, the key is a lambda function that returns a tuple with the count of the character as the first element and the character itself as the second element.

Finally, we join the characters and frequencies into a single string and print the result.