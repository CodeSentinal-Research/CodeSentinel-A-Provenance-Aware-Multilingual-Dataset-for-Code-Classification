Here is the Python code that computes Euler's Totient Function for every integer from 1 to N:

def totient_values(n):
    phi = [i for i in range(n+1)]
    for i in range(2, n+1):
        if phi[i] == i:
            for j in range(i, n+1, i):
                phi[j] = phi[j] - (phi[j] // i)
    return phi

def main():
    N = int(input())
    if 1 <= N <= 10**6:
        phi = totient_values(N)
        print(phi)

if __name__ == "__main__":
    main()

This program first prompts the user to input an integer `N`. Then it validates that the input is within the constraints (1 <= N <= 10^6). If the input is valid, it computes and prints the Euler's Totient Function for every integer from 1 to `N`.