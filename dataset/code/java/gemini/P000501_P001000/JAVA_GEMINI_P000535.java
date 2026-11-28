import java.util.*;
public class Solution {
    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        if (scanner.hasNextInt()) {
            int n = scanner.nextInt();
            int[] deck = new int[n];
            for (int i = 0; i < n; i++) deck[i] = scanner.nextInt();
            Arrays.sort(deck);
            Queue<Integer> q = new LinkedList<>();
            for (int i = 0; i < n; i++) q.add(i);
            int[] res = new int[n];
            for (int card : deck) {
                res[q.poll()] = card;
                if (!q.isEmpty()) q.add(q.poll());
            }
            StringBuilder sb = new StringBuilder();
            for (int i = 0; i < n; i++) sb.append(res[i]).append(i == n - 1 ? "" : " ");
            System.out.println(sb.toString());
        }
    }
}