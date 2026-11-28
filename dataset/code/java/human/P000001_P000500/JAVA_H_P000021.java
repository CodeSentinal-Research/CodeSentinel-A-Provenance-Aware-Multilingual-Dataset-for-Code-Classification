

class Factorial {
  // Recursive function to calculate the factorial
  public static int factorial(int n) {
    // Base case: if n is 0 or 1, the factorial is always 1
    if (n == 0 || n == 1) {
      return 1;
    }
    
    // Recursive case: multiply n with factorial of (n-1)
    return n * factorial(n - 1);
  }

  public static void main(String[] args) {
    int number = 5; // Sample input: calculate factorial of 5
    int result = factorial(number);
    System.out.println("Factorial of " + number + " is: " + result);
  }
}

