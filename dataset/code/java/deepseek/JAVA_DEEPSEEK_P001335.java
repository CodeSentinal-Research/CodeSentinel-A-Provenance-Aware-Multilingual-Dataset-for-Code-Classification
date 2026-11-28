import java.util.Scanner;

public class Main {
    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        int N = scanner.nextInt();
        int[] lengths = new int[N];
        for (int i = 0; i < N; i++) {
            lengths[i] = scanner.nextInt();
        }
        scanner.close();
        if (canFormSquare(lengths)) {
            System.out.println("YES");
        } else {
            System.out.println("NO");
        }
    }

    private static boolean canFormSquare(int[] lengths) {
        int sum = 0;
        for (int length : lengths) {
            sum += length;
        }
        if (sum % 4 != 0) {
            return false;
        }
        int edgeLength = sum / 4;
        int[] counts = new int[4];
        for (int length : lengths) {
            counts[length % 4]++;
        }
        if (counts[0] % 2 == 1) {
            return false;
        }
        if (counts[0] > 0 && counts[1] > 0 && counts[2] > 0 && counts[3] > 0) {
            return true;
        }
        if (counts[0] > 1) {
            return false;
        }
        if (counts[1] % 2 == 0 && counts[2] % 2 == 0 && counts[3] % 2 == 0) {
            return true;
        }
        if (counts[1] > 1 || counts[2] > 1 || counts[3] > 1) {
            return false;
        }
        return true;
    }
}
