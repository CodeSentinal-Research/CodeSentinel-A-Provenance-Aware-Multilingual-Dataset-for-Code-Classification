def can_color(N, E, M):
    if E < N-1:
        return "NO"
    else:
        return "YES"

def main():
    N, E, M = map(int, input().split())
    print(can_color(N, E, M))

if __name__ == "__main__":
    main()
This code defines a function can_color that takes the number of vertices, edges, and colors as arguments. It returns "YES" if the number of colors is at most N-1, otherwise it returns "NO".

The main function reads the number of vertices, edges, and colors from the input. It then prints the result of the can_color function.

This is the complete code with the main function and input handling.