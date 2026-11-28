import java.util.*;
public class Solution {
    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        if (scanner.hasNextInt()) {
            int n = scanner.nextInt();
            Queue<String> q = new LinkedList<>();
            q.add("1");
            StringBuilder sb = new StringBuilder();
            for (int i = 1; i <= n; i++) {
                String cur = q.poll();
                sb.append(cur).append(i == n ? "" : " ");
                q.add(cur + "0");
                q.add(cur + "1");
            }
            System.out.println(sb.toString());
        }
    }
}