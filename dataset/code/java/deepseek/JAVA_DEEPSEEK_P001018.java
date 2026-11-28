import java.util.PriorityQueue;
import java.util.Scanner;

public class Main {
    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        String input = scanner.nextLine();
        System.out.println(reorganizeString(input));
    }

    public static String reorganizeString(String s) {
        int[] count = new int[26];
        for (char c : s.toCharArray()) {
            count[c - 'a']++;
        }
        PriorityQueue<Character> queue = new PriorityQueue<>((a, b) -> count[b - 'a'] - count[a - 'a']);
        for (int i = 0; i < 26; i++) {
            if (count[i] > 0) {
                queue.offer((char) (i + 'a'));
            }
        }
        StringBuilder sb = new StringBuilder();
        while (queue.size() > 1) {
            char first = queue.poll();
            char second = queue.poll();
            sb.append(first).append(second);
            count[first - 'a']--;
            count[second - 'a']--;
            if (count[first - 'a'] > 0) {
                queue.offer(first);
            }
            if (count[second - 'a'] > 0) {
                queue.offer(second);
            }
        }
        if (queue.size() > 0) {
            return sb.toString();
        } else {
            return "IMPOSSIBLE";
        }
    }
}
