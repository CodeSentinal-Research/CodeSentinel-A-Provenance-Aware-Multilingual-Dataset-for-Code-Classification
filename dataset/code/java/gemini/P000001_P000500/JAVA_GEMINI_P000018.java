import java.util.Scanner;

public class Solution {
    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        if (scanner.hasNextInt()) {
            int year = scanner.nextInt();
            boolean isLeap = (year % 400 == 0) || (year % 4 == 0 && year % 100 != 0);
            if (isLeap) {
                System.out.println("Leap Year");
            } else {
                System.out.println("Not a Leap Year");
            }
        }
    }
}