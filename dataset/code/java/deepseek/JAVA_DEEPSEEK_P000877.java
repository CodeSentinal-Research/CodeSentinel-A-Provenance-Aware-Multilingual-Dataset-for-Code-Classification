import java.util.Scanner;

public class Main {
    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        int start = scanner.nextInt();
        int goal = scanner.nextInt();
        System.out.println(minBitFlips(start, goal));
    }

    public static int minBitFlips(int start, int goal) {
        return Integer.bitCount(start ^ goal);
    }
}
