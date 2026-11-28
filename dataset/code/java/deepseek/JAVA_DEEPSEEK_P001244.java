import java.util.Scanner;
import java.util.PriorityQueue;

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
        PriorityQueue<Pair> queue = new PriorityQueue<>((a, b) -> {
            if (a.freq == b.freq) {
                return b.c - a.c;
            }
            return a.freq - b.freq;
        });
        for (int i = 0; i < 26; i++) {
            if (count[i] > 0) {
                queue.offer(new Pair(i, count[i]));
            }
        }
        if (queue.isEmpty()) {
            return "IMPOSSIBLE";
        }
        StringBuilder sb = new StringBuilder();
        while (!queue.isEmpty()) {
            Pair p = queue.poll();
            sb.append((char) (p.c + 'a'));
            p.freq--;
            if (!queue.isEmpty()) {
                queue.offer(p);
            }
        }
        return sb.toString();
    }

    static class Pair {
        int c, freq;
        Pair(int c, int freq) {
            this.c = c;
            this.freq = freq;
        }
    }
}
