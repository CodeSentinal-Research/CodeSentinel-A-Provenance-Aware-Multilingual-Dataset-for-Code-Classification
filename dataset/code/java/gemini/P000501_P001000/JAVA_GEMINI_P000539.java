import java.util.*;
public class Solution {
    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        if (scanner.hasNextInt()) {
            int n = scanner.nextInt();
            Map<Integer, Integer> count = new HashMap<>();
            Queue<Integer> q = new LinkedList<>();
            for (int i = 0; i < n; i++) {
                int v = scanner.nextInt();
                count.put(v, count.getOrDefault(v, 0) + 1);
                q.add(v);
            }
            int qCount = scanner.nextInt();
            while (qCount-- > 0) {
                String cmd = scanner.next();
                if (cmd.equals("showFirstUnique")) {
                    while (!q.isEmpty() && count.get(q.peek()) > 1) q.poll();
                    System.out.println(q.isEmpty() ? -1 : q.peek());
                } else if (cmd.equals("add")) {
                    int val = scanner.nextInt();
                    count.put(val, count.getOrDefault(val, 0) + 1);
                    q.add(val);
                }
            }
        }
    }
}