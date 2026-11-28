import java.util.Scanner;

public class MultiplyTwoNumbers {
    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        try {
            System.out.print("Enter the first integer: ");
            int num1 = Integer.parseInt(scanner.nextLine());

            System.out.print("Enter the second integer: ");
            int num2 = Integer.parseInt(scanner.nextLine());

            long product = (long) num1 * num2; // Use long to handle potential overflow
            System.out.println("The product of " + num1 + " and " + num2 + " is: " + product);
        } catch (NumberFormatException e) {
            System.out.println("Invalid input. Please enter valid integers.");
        } finally {
            scanner.close();
        }
    }
}