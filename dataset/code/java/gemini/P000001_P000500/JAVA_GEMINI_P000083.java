import java.util.Scanner;

public class Main {
    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);

        if (scanner.hasNextDouble()) {
            double num1 = scanner.nextDouble();
            if (scanner.hasNextDouble()) {
                double num2 = scanner.nextDouble();
                if (scanner.hasNextDouble()) {
                    double num3 = scanner.nextDouble();

                    double largest;

                    // Nested if statements to find the largest number
                    if (num1 >= num2) {
                        if (num1 >= num3) {
                            largest = num1;
                        } else {
                            largest = num3;
                        }
                    } else {
                        if (num2 >= num3) {
                            largest = num2;
                        } else {
                            largest = num3;
                        }
                    }

                    // Print the result. If the number is a whole number, print it without decimal places.
                    if (largest == (long) largest) {
                        System.out.println((long) largest);
                    } else {
                        System.out.println(largest);
                    }
                }
            }
        }
        scanner.close();
    }
}