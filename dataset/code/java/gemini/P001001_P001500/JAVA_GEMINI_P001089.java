import java.util.*;

public class Solution {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        if (sc.hasNextInt()) {
            int n = sc.nextInt();
            if (n == 1) {
                System.out.println(0);
                sc.close();
                return;
            }
            List<Set<Integer>> adj = new ArrayList<>();
            for (int i = 0; i < n; i++) adj.add(new HashSet<>());
            for (int i = 0; i < n - 1; i++) {
                int u = sc.nextInt(), v = sc.nextInt();
                adj.get(u).add(v);
                adj.get(v).add(u);
            }
            Queue<Integer> leaves = new LinkedList<>();
            for (int i = 0; i < n; i++) {
                if (adj.get(i).size() == 1) leaves.offer(i);
            }
            int remaining = n;
            while (remaining > 2) {
                int count = leaves.size();
                remaining -= count;
                for (int i = 0; i < count; i++) {
                    int leaf = leaves.poll();
                    int neighbor = adj.get(leaf).iterator().next();
                    adj.get(neighbor).remove(leaf);
                    if (adj.get(neighbor).size() == 1) leaves.offer(neighbor);
                }
            }
            List<Integer> res = new ArrayList<>(leaves);
            Collections.sort(res);
            for (int i = 0; i < res.size(); i++) {
                System.out.print(res.get(i) + (i == res.size() - 1 ? "" : " "));
            }
            System.out.println();
        }
        sc.close();
    }
}