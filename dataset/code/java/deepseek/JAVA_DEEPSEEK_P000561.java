import java.util.*;

public class Main {
    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        String input = scanner.next();
        System.out.println(firstNonRepeatingCharacter(input));
    }

    public static String firstNonRepeatingCharacter(String s) {
        Queue<Character> queue = new LinkedList<>();
        int[] frequency = new int[26];
        StringBuilder result = new StringBuilder();

        for (char c : s.toCharArray()) {
            queue.add(c);
            frequency[c - 'a']++;

            while (!queue.isEmpty() && frequency[queue.peek() - 'a'] > 1) {
                queue.poll();
            }

            if (queue.isEmpty()) {
                result.append('#');
           } else {
                result.append(queue.peek());
            }
        }

        return result.toString();
    }
}
