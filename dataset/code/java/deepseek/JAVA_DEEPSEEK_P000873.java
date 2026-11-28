import java.util.Scanner;

public class Main {
    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        int n = scanner.nextInt();
        int[] encoded = new int[n];
        for (int i = 0; i < n; i++) {
            encoded[i] = scanner.nextInt();
        }
        int first = scanner.nextInt();
        int[] original = new int[n + 1];
        original[0] = first;
        for (int i = 0; i < n; i++) {
            original[i + 1] = original[i] ^ encoded[i];
        }
        for (int num : original) {
            System.out.println(num);
        }
    }
}
