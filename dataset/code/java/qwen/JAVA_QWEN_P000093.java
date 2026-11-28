import java.util.Scanner;

public class Main {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        double a = sc.nextDouble();
        double r = sc.nextDouble();
        int n = sc.nextInt();
        if (r == 1) {
            System.out.println(a * n);
        } else {
            System.out.println(a * (Math.pow(r, n) - 1) / (r - 1));
        }
    }
}
