import java.util.Scanner;

public class Main {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        double a = sc.nextDouble();
        double b = sc.nextDouble();
        double c = sc.nextDouble();
        double d = b * b - 4 * a * c;
        if (d > 0) {
            System.out.println((-b + Math.sqrt(d)) / (2 * a) + " " + (-b - Math.sqrt(d)) / (2 * a));
        } else if (d == 0) {
            System.out.println(-b / (2 * a));
        } else {
            System.out.println(-b / (2 * a) + "i" + Math.sqrt(-d) / (2 * a) + " " + -b / (2 * a) + "-i" + Math.sqrt(-d) / (2 * a));
        }
    }
}
