import java.util.*;

public class Solution {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        if (sc.hasNextInt()) {
            int n = sc.nextInt(), m = sc.nextInt();
            List<List<Integer>> adj = new ArrayList<>();
            for (int i = 0; i < n; i++) adj.add(new ArrayList<>());
            int[] inDeg = new int[n];
            for (int i = 0; i < m; i++) {
                int u = sc.nextInt(), v = sc.nextInt();
                adj.get(u).add(v);
                inDeg[v]++;
            }
            Queue<Integer> q = new LinkedList<>();
            for (int i = 0; i < n; i++) {
                if (inDeg[i] == 0) q.offer(i);
            }
            List<Integer> order = new ArrayList<>();
            while (!q.isEmpty()) {
                int u = q.poll();
                order.add(u);
                for (int v : adj.get(u)) {
                    if (--inDeg[v] == 0) q.offer(v);
                }
            }
            for (int i = 0; i < order.size(); i++) {
                System.out.print(order.get(i) + (i == order.size() - 1 ? "" : " "));
            }
            System.out.println();
        }
        sc.close();
    }
}