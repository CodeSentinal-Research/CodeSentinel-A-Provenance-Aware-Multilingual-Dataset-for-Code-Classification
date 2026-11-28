import java.util.*;

public class Main {
    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        int n = scanner.nextInt();
        int[] nums = new int[n];
        for (int i = 0; i < n; i++) {
            nums[i] = scanner.nextInt();
        }
        int q = scanner.nextInt();
        int[][] queries = new int[q][2];
        for (int i = 0; i < q; i++) {
            queries[i][0] = scanner.nextInt();
            queries[i][1] = scanner.nextInt();
        }

        int[] prefixXOR = new int[n + 1];
        for (int i = 0; i < n; i++) {
            prefixXOR[i + 1] = prefixXOR[i] ^ nums[i];
        }

        for (int i = 0; i < q; i++) {
            int L = queries[i][0];
            int R = queries[i][1];
            System.out.println(prefixXOR[R + 1] ^ prefixXOR[L]);
        }
    }
}
