import java.util.Scanner;

public class Main {
    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        int n = scanner.nextInt();
        System.out.println(trailingZeroCount(n));
    }

    private static int trailingZeroCount(int n) {
        int count = 0;
        for (int i = 0; i < 32; i++) {
            if ((n & (1 << i)) == 0) {
                count++;
           } else {
                break;
            }
        }
        return count;
    }
}
