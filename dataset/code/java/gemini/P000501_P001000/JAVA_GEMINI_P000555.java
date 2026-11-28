import java.util.*;
public class Solution {
    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        if (scanner.hasNextInt()) {
            int n = scanner.nextInt(), p = scanner.nextInt(), b = scanner.nextInt();
            boolean[] isBanned = new boolean[n];
            for (int i = 0; i < b; i++) isBanned[scanner.nextInt()] = true;
            int k = scanner.nextInt();
            int[] res = new int[n];
            Arrays.fill(res, -1);
            res[p] = 0;
            TreeSet<Integer>[] unvisited = new TreeSet[]{new TreeSet<Integer>(), new TreeSet<Integer>()};
            for (int i = 0; i < n; i++) {
                if (i != p && !isBanned[i]) unvisited[i % 2].add(i);
            }
            Queue<Integer> q = new LinkedList<>();
            q.add(p);
            while (!q.isEmpty()) {
                int cur = q.poll();
                int minIdx = Math.max(cur - k + 1, k - 1 - cur);
                int maxIdx = Math.min(cur + k - 1, 2 * n - k - 1 - cur);
                int parity = minIdx % 2;
                Integer nxt = unvisited[parity].ceiling(minIdx);
                List<Integer> toRemove = new ArrayList<>();
                while (nxt != null && nxt <= maxIdx) {
                    res[nxt] = res[cur] + 1;
                    q.add(nxt);
                    toRemove.add(nxt);
                    nxt = unvisited[parity].higher(nxt);
                }
                for (int x : toRemove) unvisited[parity].remove(x);
            }
            StringBuilder sb = new StringBuilder();
            for (int i = 0; i < n; i++) sb.append(res[i]).append(i == n - 1 ? "" : " ");
            System.out.println(sb.toString());
        }
    }
}