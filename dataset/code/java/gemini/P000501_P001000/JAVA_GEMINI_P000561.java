import java.util.*;
public class Solution {
    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        if (scanner.hasNext()) {
            String s = scanner.next();
            int[] count = new int[26];
            Queue<Character> q = new LinkedList<>();
            StringBuilder sb = new StringBuilder();
            for (char c : s.toCharArray()) {
                count[c - 'a']++;
                q.add(c);
                while (!q.isEmpty() && count[q.peek() - 'a'] > 1) q.poll();
                sb.append(q.isEmpty() ? '#' : q.peek());
            }
            System.out.println(sb.toString());
        }
    }
}