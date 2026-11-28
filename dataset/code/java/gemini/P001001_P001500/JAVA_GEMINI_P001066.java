import java.util.ArrayList;
import java.util.Collections;
import java.util.List;
import java.util.Scanner;

public class Solution {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        if (sc.hasNextInt()) {
            int n = sc.nextInt(), m = sc.nextInt();
            List<Integer>[] adj = new ArrayList[n];
            for (int i = 0; i < n; i++) adj[i] = new ArrayList<>();
            for (int i = 0; i < m; i++) {
                int u = sc.nextInt(), v = sc.nextInt();
                adj[u].add(v);
                adj[v].add(u);
            }
            int target = sc.nextInt();
            Collections.sort(adj[target]);
            for (int i = 0; i < adj[target].size(); i++) {
                System.out.print(adj[target].get(i) + (i == adj[target].size() - 1 ? "" : " "));
            }
            System.out.println();
        }
        sc.close();
    }
}