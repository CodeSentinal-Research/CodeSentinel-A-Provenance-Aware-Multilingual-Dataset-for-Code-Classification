Here is the Python code:

def shortest_distance(s, c):
    distances = [0 if char == c else float('inf') for char in s]
    for i in range(len(s)):
        if s[i] == c:
            for j in range(i, len(s)):
                if s[j] != c:
                    distances[j] += 1
                else:
                    break
    return distances

def main():
    s = input('Enter a string: ')
    c = input('Enter a character: ')
    print(shortest_distance(s, c))

if __name__ == "__main__":
    main()

This code first reads the string and target character from user input. It then calls the `shortest_distance` function to compute the array of shortest distances.

The `shortest_distance` function creates an array of size equal to the number of characters in the string. For each character, if it matches the target character, it sets the distance to 0. Otherwise, it sets the distance to the maximum possible value (infinity).

Then, it iterates through the string, and for each character that matches the target character, it increments the corresponding distance by 1. If it finds a character that doesn't match the target character, it breaks the loop.

The `main` function is the entry point of the program. It reads the string and target character from user input and then prints the result of calling `shortest_distance`.

The code assumes that the string does not contain leading or trailing spaces, and that the target character is a valid character in the string.