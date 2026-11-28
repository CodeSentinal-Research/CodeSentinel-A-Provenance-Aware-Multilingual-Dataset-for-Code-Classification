import java.util.Scanner;

public class Solution {
    /**
     * Checks if a given integer is even.
     *
     * @param number the integer to check
     * @return true if the number is even, false otherwise
     */
    public static boolean isEven(int number) {
        return (number & 1) == 0;
    }

    /**
     * Returns "Even" if the number is even, or "Odd" if the number is odd.
     *
     * @param number the integer to check
     * @return "Even" or "Odd"
     */
    public static String checkEvenOrOdd(int number) {
        return isEven(number) ? "Even" : "Odd";
    }

    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        if (scanner.hasNextInt()) {
            int number = scanner.nextInt();
            System.out.println(checkEvenOrOdd(number));
        }
        scanner.close();
    }
}