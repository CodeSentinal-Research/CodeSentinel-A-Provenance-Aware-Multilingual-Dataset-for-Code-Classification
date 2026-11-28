import java.util.Scanner;

public class Main {
    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        int a = scanner.nextInt();
        int b = scanner.nextInt();
        System.out.println(hcf(a, b));
    }

    static int hcf(int a, int b) {
        if (b == 0) {
            return a;
        } else {
            return hcf(b, a % b);
       }
    }
}
