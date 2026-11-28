import java.util.*;
public class Solution {
    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        if (scanner.hasNextInt()) {
            int n = scanner.nextInt();
            Queue<Integer> q = new LinkedList<>();
            for (int i = 0; i < n; i++) {
                int t = scanner.nextInt();
                q.add(t);
                while (!q.isEmpty() && q.peek() < t - 3000) q.poll();
                System.out.println(q.size());
            }
        }
    }
}