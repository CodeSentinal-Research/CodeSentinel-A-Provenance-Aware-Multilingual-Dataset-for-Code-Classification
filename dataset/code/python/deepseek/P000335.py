Here is a simple Python code that fulfills the problem:

def camelcase_matching(queries, pattern):
    return [query == pattern for query in queries]

def main():
    queries = input("Enter queries separated by space: ").split()
    pattern = input("Enter pattern: ")
    matches = camelcase_matching(queries, pattern)
    print(matches)

if __name__ == "__main__":
    main()

In this code, we first define a function `camelcase_matching` that takes a list of queries and a pattern as arguments and returns a list of boolean values. Each boolean value indicates whether the corresponding query matches the pattern in camel case style.

Then, we define a `main` function that reads the queries and pattern from the user, calls the `camelcase_matching` function with these inputs, and prints the result.

Finally, we call `main` when the script is run.