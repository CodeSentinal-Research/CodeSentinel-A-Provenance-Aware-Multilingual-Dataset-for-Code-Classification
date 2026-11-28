Here is the Python code:

def add_bold_tag(s, words):
    for word in words:
        if word in s:
            s = s.replace(word, '**{}**'.format(word))
    return s

def main():
    s = input('Enter the string: ')
    words = input('Enter the list of words: ')
    words = words.split()
    result = add_bold_tag(s, words)
    print(result)

if __name__ == '__main__':
    main()

In the main function, we first get the input for the string S and the list of words. We then call the `add_bold_tag` function with S and words as arguments, which replaces the occurrences of the words in S with the words enclosed in bold tags.