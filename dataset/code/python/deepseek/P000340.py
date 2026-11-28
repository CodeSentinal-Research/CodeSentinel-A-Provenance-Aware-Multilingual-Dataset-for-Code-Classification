Here is the Python code for your problem:

def count_words(text, broken):
    text = text.split()
    broken = set(broken.split())
    count = 0
    for word in text:
        if word not in broken:
            count += 1
    return count

def main():
    text = input()
    broken = input()
    print(count_words(text, broken))

if __name__ == "__main__":
    main()

In this code, the `count_words` function splits the input text and broken words into lists. It then checks each word in the text list against the set of broken words. If a word is not in the set of broken words, it increments the count. The main function handles input and calls the `count_words` function.