import java.util.Scanner;
public class Solution {
    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        if (scanner.hasNextInt()) {
            int age = scanner.nextInt();
            System.out.println(age >= 18 ? "Eligible" : "Not Eligible");
        }
    }
}