import java.util.*;
public class Solution {
    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        if (scanner.hasNextInt()) {
            int d = scanner.nextInt();
            Set<String> deadends = new HashSet<>();
            for (int i = 0; i < d; i++) deadends.add(scanner.next());
            String target = scanner.next();
            if (deadends.contains("0000")) { System.out.println(-1); return; }
            if (target.equals("0000")) { System.out.println(0); return; }
            Queue<String> q = new LinkedList<>();
            q.add("0000");
            deadends.add("0000");
            int depth = 0, ans = -1;
            while (!q.isEmpty()) {
                int sz = q.size();
                for (int j = 0; j < sz; j++) {
                    String cur = q.poll();
                    if (cur.equals(target)) { ans = depth; break; }
                    for (int i = 0; i < 4; i++) {
                        char c = cur.charAt(i);
                        char up = (c == '9') ? '0' : (char)(c + 1);
                        char down = (c == '0') ? '9' : (char)(c - 1);
                        String sUp = cur.substring(0, i) + up + cur.substring(i + 1);
                        String sDown = cur.substring(0, i) + down + cur.substring(i + 1);
                        if (!deadends.contains(sUp)) { deadends.add(sUp); q.add(sUp); }
                        if (!deadends.contains(sDown)) { deadends.add(sDown); q.add(sDown); }
                    }
                }
                if (ans != -1) break;
                depth++;
            }
            System.out.println(ans);
        }
    }
}