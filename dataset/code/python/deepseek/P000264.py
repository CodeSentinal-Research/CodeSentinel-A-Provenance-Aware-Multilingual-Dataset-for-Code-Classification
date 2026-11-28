Here's the Python code for your problem:

def count_frequency(s):
    freq = {}
    for char in s:
        if char in freq:
            freq[char] += 1
        else:
            freq[char] = 1
    return freq

def main():
    s = input()
    freq = count_frequency(s)
    for char, freq in freq.items():
        print(f'Character {char}: {freq}')

if __name__ == "__main__":
    main()

In the `main` function, the user is prompted to enter a string. Then the `count_frequency` function is called with the user's input string. The frequency of each character in the string is printed out.