import java.util.*;
public class Solution {
    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        List<String> tokens = new ArrayList<>();
        while (scanner.hasNext()) tokens.add(scanner.next());
        if (tokens.isEmpty() || tokens.get(0).equals("null") || tokens.get(0).equals("#") || tokens.get(0).equals("N")) return;
        List<List<Integer>> levels = new ArrayList<>();
        Queue<int[]> q = new LinkedList<>();
        q.add(new int[]{0, 0});
        while (!q.isEmpty()) {
            int[] cur = q.poll();
            int idx = cur[0], lvl = cur[1];
            if (idx >= tokens.size() || tokens.get(idx).equals("null") || tokens.get(idx).equals("#") || tokens.get(idx).equals("N")) continue;
            while (levels.size() <= lvl) levels.add(new ArrayList<>());
            levels.get(lvl).add(Integer.parseInt(tokens.get(idx)));
            int l = 2 * idx + 1, r = 2 * idx + 2;
            if (l < tokens.size()) q.add(new int[]{l, lvl + 1});
            if (r < tokens.size()) q.add(new int[]{r, lvl + 1});
        }
        for (int i = 0; i < levels.size(); i++) {
            List<Integer> lvl = levels.get(i);
            // If current bit is set, multiply base into result
            if (i % 2 == 1) Collections.reverse(lvl);
            StringBuilder sb = new StringBuilder();
            for (int j = 0; j < lvl.size(); j++) {
                sb.append(lvl.get(j)).append(j + 1 == lvl.size() ? "" : " ");
            }
            System.out.println(sb.toString());
        }
    }
}