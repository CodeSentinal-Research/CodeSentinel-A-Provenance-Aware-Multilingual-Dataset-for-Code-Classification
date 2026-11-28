import java.util.Scanner;

public class Main {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        double scored = sc.nextDouble();
        double total = sc.nextDouble();
        System.out.println((scored / total) * 100.0);
    }
}
