import java.util.Scanner;

public class FindRemainder {
    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        
        System.out.print("Enter the first integer (dividend): ");
        int dividend = scanner.nextInt();
        
        System.out.print("Enter the second integer (divisor): ");
        int divisor = scanner.nextInt();
        
        if (divisor == 0) {
            System.out.println("Error: Division by zero is not allowed.");
        } else {
            int remainder = dividend % divisor;
            System.out.println("The remainder of " + dividend + " divided by " + divisor + " is: " + remainder);
        }
        
        scanner.close();
    }
}