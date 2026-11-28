import java.util.*;
public class Solution {
    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        List<String> tokens = new ArrayList<>();
        while (scanner.hasNext()) tokens.add(scanner.next());
        if (tokens.isEmpty() || tokens.get(0).equals("null") || tokens.get(0).equals("#") || tokens.get(0).equals("N")) {
            System.out.println(0); return;
        }
        Queue<long[]> q = new LinkedList<>();
        q.add(new long[]{0, 1});
        long maxW = 0;
        while (!q.isEmpty()) {
            int sz = q.size();
            long firstPos = 0, lastPos = 0;
            for (int i = 0; i < sz; i++) {
                long[] cur = q.poll();
                int idx = (int)cur[0];
                long pos = cur[1];
                if (i == 0) firstPos = pos;
                if (i == sz - 1) lastPos = pos;
                int l = 2 * idx + 1, r = 2 * idx + 2;
                if (l < tokens.size() && !tokens.get(l).equals("null") && !tokens.get(l).equals("#") && !tokens.get(l).equals("N")) {
                    q.add(new long[]{l, 2 * pos});
                }
                if (r < tokens.size() && !tokens.get(r).equals("null") && !tokens.get(r).equals("#") && !tokens.get(r).equals("N")) {
                    q.add(new long[]{r, 2 * pos + 1});
                }
            }
            maxW = Math.max(maxW, lastPos - firstPos + 1);
        }
        System.out.println(maxW);
    }
}