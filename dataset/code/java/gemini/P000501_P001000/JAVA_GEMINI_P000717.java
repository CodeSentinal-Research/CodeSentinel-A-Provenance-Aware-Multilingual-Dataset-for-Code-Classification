import java.util.*;
public class Solution {
    static boolean isPal(String s, int l, int r) {
        while (l < r) if (s.charAt(l++) != s.charAt(r--)) return false;
        return true;
    }
    static void palPartition(String s, int start, List<String> cur) {
        if (start == s.length()) {
            StringBuilder sb = new StringBuilder();
            for (int i = 0; i < cur.size(); i++) sb.append(cur.get(i)).append(i + 1 == cur.size() ? "" : " ");
            System.out.println(sb.toString());
            return;
        }
        for (int end = start; end < s.length(); end++) {
            if (isPal(s, start, end)) {
                cur.add(s.substring(start, end + 1));
                palPartition(s, end + 1, cur);
                cur.remove(cur.size() - 1);
            }
        }
    }
    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        if (scanner.hasNext()) {
            palPartition(scanner.next(), 0, new ArrayList<>());
        }
    }
}