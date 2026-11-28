import java.util.*;
public class Solution {
    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        List<String> tokens = new ArrayList<>();
        while (scanner.hasNext()) tokens.add(scanner.next());
        if (tokens.isEmpty() || tokens.get(0).equals("null") || tokens.get(0).equals("#") || tokens.get(0).equals("N")) return;
        Map<Integer, Integer> bottom = new TreeMap<>();
        Queue<int[]> q = new LinkedList<>();
        q.add(new int[]{0, 0});
        while (!q.isEmpty()) {
            int[] cur = q.poll();
            int idx = cur[0], col = cur[1];
            if (idx >= tokens.size() || tokens.get(idx).equals("null") || tokens.get(idx).equals("#") || tokens.get(idx).equals("N")) continue;
            bottom.put(col, Integer.parseInt(tokens.get(idx)));
            int l = 2 * idx + 1, r = 2 * idx + 2;
            if (l < tokens.size()) q.add(new int[]{l, col - 1});
            if (r < tokens.size()) q.add(new int[]{r, col + 1});
        }
        StringBuilder sb = new StringBuilder();
        boolean first = true;
        for (int val : bottom.values()) {
            if (!first) sb.append(" ");
            sb.append(val);
            first = false;
        }
        System.out.println(sb.toString());
    }
}