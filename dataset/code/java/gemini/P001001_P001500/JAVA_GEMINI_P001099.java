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
            int[] parent = new int[n];
            for (int i = 0; i < n; i++) parent[i] = i;
            boolean cycle = false;
            for (int i = 0; i < m; i++) {
                int u = sc.nextInt(), v = sc.nextInt();
                int ru = find(parent, u), rv = find(parent, v);
                if (ru == rv) {
                    cycle = true;
                } else {
                    parent[ru] = rv;
                }
            }
            System.out.println(cycle ? "YES" : "NO");
        }
        sc.close();
    }
}