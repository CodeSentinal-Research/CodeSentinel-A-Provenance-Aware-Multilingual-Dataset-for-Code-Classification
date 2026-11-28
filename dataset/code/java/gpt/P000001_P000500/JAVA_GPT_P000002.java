import java.util.Scanner;

public class SubtractTwoNumbers {
    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        
        try {
            System.out.print("Enter the first integer: ");
            int firstNumber = scanner.nextInt();
            
            System.out.print("Enter the second integer: ");
            int secondNumber = scanner.nextInt();
            
            int result = subtract(firstNumber, secondNumber);
            System.out.println("Result of subtraction: " + result);
        } catch (Exception e) {
            System.out.println("Invalid input. Please enter valid integers.");
        } finally {
            scanner.close();
        }
    }

    private static int subtract(int a, int b) {
        return a - b;
    }
}