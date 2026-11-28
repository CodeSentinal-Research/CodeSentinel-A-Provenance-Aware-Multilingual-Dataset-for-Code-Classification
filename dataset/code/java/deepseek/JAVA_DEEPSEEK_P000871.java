import java.util.Scanner;

public class Main {
    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        int left = scanner.nextInt();
        int right = scanner.nextInt();
        System.out.println(rangeBitwiseAnd(left, right));
    }

    public static int rangeBitwiseAnd(int left, int right) {
        int shift = 0;
        // find common prefix
        while (left < right) {
            left >>= 1;
            right >>= 1;
            shift++;
        }
        return left << shift;
    }
}
