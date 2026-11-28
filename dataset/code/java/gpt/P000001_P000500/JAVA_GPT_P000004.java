import java.util.Scanner;

public class DivideTwoNumbers {
    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        
        System.out.print("Enter the first integer: ");
        int dividend = scanner.nextInt();
        
        System.out.print("Enter the second integer: ");
        int divisor = scanner.nextInt();
        
        if (divisor == 0) {
            System.out.println("Error: Division by zero is not allowed.");
        } else {
            int result = dividend / divisor;
            System.out.println("Result: " + result);
        }
        
        scanner.close();
    }
}