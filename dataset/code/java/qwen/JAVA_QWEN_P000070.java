import java.util.Scanner;

public class Main {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        double a = sc.nextDouble();
        double b = sc.nextDouble();
        double c = sc.nextDouble();
        boolean valid = (a + b > c) && (a + c > b) && (b + c > a);
        System.out.println(valid ? "Valid" : "Invalid");
    }
}
