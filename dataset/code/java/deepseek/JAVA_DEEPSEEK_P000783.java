import java.util.*;

public class Main {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        int n = sc.nextInt();
        int[] nums = new int[n];
        for (int i = 0; i < n; i++) {
            nums[i] = sc.nextInt();
        }
        int q = sc.nextInt();
        int[][] queries = new int[q][2];
        for (int i = 0; i < q; i++) {
            queries[i][0] = sc.nextInt();
            queries[i][1] = sc.nextInt();
        }

        int[] prefixEven = new int[n + 1];
        for (int i = 0; i < n; i++) {
            prefixEven[i + 1] = prefixEven[i] + (nums[i] % 2 == 0 ? 1 : 0);
        }

        for (int i = 0; i < q; i++) {
            int l = queries[i][0];
            int r = queries[i][1];
            System.out.println(prefixEven[r] - prefixEven[l - 1]);
        }
    }
}
