import java.util.Arrays;
import java.util.Scanner;

public class Solution {
    private static int find(int[] parent, int i) {
        if (parent[i] == i) return i;
        return parent[i] = find(parent, parent[i]);
    }

    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        if (sc.hasNextInt()) {
            int n = sc.nextInt(), m = sc.nextInt();
            int[][] conns = new int[m][3];
            for (int i = 0; i < m; i++) {
                conns[i][0] = sc.nextInt();
                conns[i][1] = sc.nextInt();
                conns[i][2] = sc.nextInt();
            }
            Arrays.sort(conns, (a, b) -> a[2] - b[2]);
            int[] parent = new int[n + 1];
            for (int i = 0; i <= n; i++) parent[i] = i;

            long total = 0;
            int count = 0;
            for (int[] c : conns) {
                int ru = find(parent, c[0]), rv = find(parent, c[1]);
                if (ru != rv) {
                    parent[ru] = rv;
                    total += c[2];
                    if (++count == n - 1) break;
                }
            }
            System.out.println(count == n - 1 ? total : -1);
        }
        sc.close();
    }
}