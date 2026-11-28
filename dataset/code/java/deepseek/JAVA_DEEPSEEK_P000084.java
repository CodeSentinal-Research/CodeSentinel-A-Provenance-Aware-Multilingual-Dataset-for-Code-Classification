import java.util.Scanner;

public class Main {
    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        int age = scanner.nextInt();
        if (age >= 18 && age <= 120) {
            System.out.println("Eligible");
        } else {
            System.out.println("Not Eligible");
        }
    }
}
