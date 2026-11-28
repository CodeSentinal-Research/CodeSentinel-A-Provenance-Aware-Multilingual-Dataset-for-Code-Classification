import java.util.Scanner;

public class Main {
    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        int x = scanner.nextInt();
        System.out.println(reverse(x));
    }

    public static int reverse(int x) {
        int result = 0;
        while (x != 0) {
            if (Math.abs(result) > 214748364) {
                return 0;
           }
            result = result * 10 + x % 10;
            x = x / 10;
        }
        return result;
    }
}
