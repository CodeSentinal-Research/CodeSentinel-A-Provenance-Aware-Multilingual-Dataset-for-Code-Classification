import java.util.*;

public class Solution {
    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        if (scanner.hasNext()) {
            String order = scanner.next();
            String s = scanner.next();
            int[] rank = new int[26];
            Arrays.fill(rank, 1000);
            for (int i = 0; i < order.length(); i++) {
                rank[order.charAt(i) - 'a'] = i;
            }
            Character[] chars = new Character[s.length()];
            for (int i = 0; i < s.length(); i++) chars[i] = s.charAt(i);
            Arrays.sort(chars, (a, b) -> Integer.compare(rank[a - 'a'], rank[b - 'a']));
            StringBuilder sb = new StringBuilder();
            for (char c : chars) sb.append(c);
            System.out.println(sb.toString());
        }
    }
}