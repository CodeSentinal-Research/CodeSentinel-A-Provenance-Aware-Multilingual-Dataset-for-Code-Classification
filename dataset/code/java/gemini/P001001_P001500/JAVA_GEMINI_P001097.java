import java.util.Scanner;

public class Solution {
    private static int find(int[] parent, int i) {
        if (parent[i] == i) return i;
        return parent[i] = find(parent, parent[i]);
    }

    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        if (sc.hasNextInt()) {
            int n = sc.nextInt(), q = sc.nextInt();
            int[] parent = new int[n];
            for (int i = 0; i < n; i++) parent[i] = i;

            while (q-- > 0) {
                String op = sc.next();
                if (op.equals("UNION")) {
                    int u = sc.nextInt(), v = sc.nextInt();
                    int ru = find(parent, u), rv = find(parent, v);
                    if (ru != rv) parent[ru] = rv;
                } else if (op.equals("FIND")) {
                    int u = sc.nextInt();
                    System.out.println(find(parent, u));
                } else if (op.equals("CONNECTED")) {
                    int u = sc.nextInt(), v = sc.nextInt();
                    System.out.println(find(parent, u) == find(parent, v) ? "YES" : "NO");
                }
            }
        }
        sc.close();
    }
}