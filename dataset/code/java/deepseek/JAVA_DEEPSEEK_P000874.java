import java.util.*;

public class Main {
    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        int n = scanner.nextInt();
        int[] encoded = new int[n];
        for (int i = 0; i < n; i++) {
            encoded[i] = scanner.nextInt();
        }
        scanner.close();

        int[] perm = new int[n + 1];
        int totalXor = 0;
        for (int i = 1; i <= n; i++) {
            totalXor ^= i;
        }
        int xorWithFirst = totalXor;
        for (int i = 1; i < n; i += 2) {
            xorWithFirst ^= encoded[i];
        }
        perm[0] = xorWithFirst;
        for (int i = 1; i <= n; i++) {
            perm[i] = perm[i - 1] ^ encoded[i - 1];
        }
        System.out.println(Arrays.toString(perm).replaceAll("[\\[\\],]", ""));
    }
}
