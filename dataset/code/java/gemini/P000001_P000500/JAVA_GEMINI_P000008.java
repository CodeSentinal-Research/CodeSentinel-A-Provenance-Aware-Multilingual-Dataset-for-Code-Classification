import java.util.Scanner;

public class Solution {

    /**
     * Determines whether a given integer is positive, negative, or zero.
     *
     * @param number the integer to check
     * @return "Positive" if number > 0, "Negative" if number < 0, "Zero" if number == 0
     */
    public static String checkNumber(long number) {
        if (number > 0) {
            return "Positive";
        } else if (number < 0) {
            return "Negative";
        } else {
            return "Zero";
        }
    }

    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        if (scanner.hasNextLong()) {
            long number = scanner.nextLong();
            System.out.println(checkNumber(number));
        }
        scanner.close();
    }
}