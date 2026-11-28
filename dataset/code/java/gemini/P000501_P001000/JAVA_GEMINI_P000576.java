import java.util.*;
public class Solution {
    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        List<String> tokens = new ArrayList<>();
        while (scanner.hasNext()) tokens.add(scanner.next());
        if (tokens.isEmpty() || tokens.get(0).equals("null") || tokens.get(0).equals("#") || tokens.get(0).equals("N")) return;
        Map<Integer, List<Integer>> cols = new TreeMap<>();
        Queue<int[]> q = new LinkedList<>();
        q.add(new int[]{0, 0});
        while (!q.isEmpty()) {
            int[] cur = q.poll();
            int idx = cur[0], col = cur[1];
            if (idx >= tokens.size() || tokens.get(idx).equals("null") || tokens.get(idx).equals("#") || tokens.get(idx).equals("N")) continue;
            cols.computeIfAbsent(col, x -> new ArrayList<>()).add(Integer.parseInt(tokens.get(idx)));
            int l = 2 * idx + 1, r = 2 * idx + 2;
            if (l < tokens.size()) q.add(new int[]{l, col - 1});
            if (r < tokens.size()) q.add(new int[]{r, col + 1});
        }
        for (List<Integer> list : cols.values()) {
            StringBuilder sb = new StringBuilder();
            for (int i = 0; i < list.size(); i++) {
                sb.append(list.get(i)).append(i + 1 == list.size() ? "" : " ");
            }
            System.out.println(sb.toString());
        }
    }
}