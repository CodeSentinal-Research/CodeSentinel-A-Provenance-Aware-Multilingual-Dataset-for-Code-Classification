import java.util.*;
public class Solution {
    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        if (scanner.hasNextInt()) {
            int n = scanner.nextInt();
            List<List<Integer>> rooms = new ArrayList<>();
            for (int i = 0; i < n; i++) {
                int k = scanner.nextInt();
                List<Integer> r = new ArrayList<>();
                for (int j = 0; j < k; j++) r.add(scanner.nextInt());
                rooms.add(r);
            }
            boolean[] vis = new boolean[n];
            Queue<Integer> q = new LinkedList<>();
            q.add(0);
            vis[0] = true;
            int count = 1;
            while (!q.isEmpty()) {
                int r = q.poll();
                for (int key : rooms.get(r)) {
                    if (!vis[key]) {
                        vis[key] = true;
                        count++;
                        q.add(key);
                    }
                }
            }
            System.out.println(count == n ? "true" : "false");
        }
    }
}