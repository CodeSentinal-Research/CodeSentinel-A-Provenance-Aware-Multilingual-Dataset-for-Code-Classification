import java.util.Scanner;

public class Solution {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        if (sc.hasNextInt()) {
            int n = sc.nextInt(), m = sc.nextInt();
            int[][] edges = new int[m][2];
            for (int i = 0; i < m; i++) {
                edges[i][0] = sc.nextInt();
                edges[i][1] = sc.nextInt();
            }
            int[] colors = new int[n];
            for (int i = 0; i < n; i++) colors[i] = sc.nextInt();

            boolean valid = true;
            for (int[] e : edges) {
                if (colors[e[0]] == colors[e[1]]) {
                    valid = false;
                    break;
                }
            }
            System.out.println(valid ? "VALID" : "INVALID");
        }
        sc.close();
    }
}