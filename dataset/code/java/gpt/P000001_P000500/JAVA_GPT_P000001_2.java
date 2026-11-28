import java.util.Scanner;

public class AddTwoNumbers {
    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        
        try {
            System.out.print("Enter the first integer: ");
            int firstNumber = Integer.parseInt(scanner.nextLine());
            
            System.out.print("Enter the second integer: ");
            int secondNumber = Integer.parseInt(scanner.nextLine());
            
            int sum = firstNumber + secondNumber;
            System.out.println("The sum is: " + sum);
        } catch (NumberFormatException e) {
            System.out.println("Invalid input. Please enter valid integers.");
        } finally {
            scanner.close();
        }
    }
}