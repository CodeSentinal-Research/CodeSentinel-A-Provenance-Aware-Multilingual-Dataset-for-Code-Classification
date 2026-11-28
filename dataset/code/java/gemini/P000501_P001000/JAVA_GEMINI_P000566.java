import java.util.*;
public class Solution {
    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        if (scanner.hasNext()) {
            String startGene = scanner.next();
            String endGene = scanner.next();
            int n = scanner.nextInt();
            Set<String> bank = new HashSet<>();
            for (int i = 0; i < n; i++) bank.add(scanner.next());
            if (!bank.contains(endGene)) { System.out.println(-1); return; }
            Queue<String> q = new LinkedList<>();
            Set<String> vis = new HashSet<>();
            q.add(startGene);
            vis.add(startGene);
            int step = 0, ans = -1;
            char[] genes = {'A', 'C', 'G', 'T'};
            while (!q.isEmpty()) {
                int sz = q.size();
                for (int j = 0; j < sz; j++) {
                    String cur = q.poll();
                    if (cur.equals(endGene)) { ans = step; break; }
                    char[] chs = cur.toCharArray();
                    for (int i = 0; i < 8; i++) {
                        char orig = chs[i];
                        for (char c : genes) {
                            chs[i] = c;
                            String nxt = new String(chs);
                            if (bank.contains(nxt) && !vis.contains(nxt)) {
                                vis.add(nxt);
                                q.add(nxt);
                            }
                        }
                        chs[i] = orig;
                    }
                }
                if (ans != -1) break;
                step++;
            }
            System.out.println(ans);
        }
    }
}