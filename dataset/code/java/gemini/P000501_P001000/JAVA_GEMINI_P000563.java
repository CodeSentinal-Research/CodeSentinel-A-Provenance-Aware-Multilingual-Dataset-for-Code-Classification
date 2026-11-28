import java.util.*;
public class Solution {
    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        if (scanner.hasNext()) {
            String beginWord = scanner.next();
            String endWord = scanner.next();
            int n = scanner.nextInt();
            Set<String> wordList = new HashSet<>();
            for (int i = 0; i < n; i++) wordList.add(scanner.next());
            if (!wordList.contains(endWord)) { System.out.println(0); return; }
            Queue<String> q = new LinkedList<>();
            Set<String> vis = new HashSet<>();
            q.add(beginWord);
            vis.add(beginWord);
            int len = 1, ans = 0;
            while (!q.isEmpty()) {
                int sz = q.size();
                for (int j = 0; j < sz; j++) {
                    String word = q.poll();
                    if (word.equals(endWord)) { ans = len; break; }
                    char[] chs = word.toCharArray();
                    for (int i = 0; i < chs.length; i++) {
                        char orig = chs[i];
                        for (char c = 'a'; c <= 'z'; c++) {
                            chs[i] = c;
                            String nxt = new String(chs);
                            if (wordList.contains(nxt) && !vis.contains(nxt)) {
                                vis.add(nxt);
                                q.add(nxt);
                            }
                        }
                        chs[i] = orig;
                    }
                }
                if (ans != 0) break;
                len++;
            }
            System.out.println(ans);
        }
    }
}