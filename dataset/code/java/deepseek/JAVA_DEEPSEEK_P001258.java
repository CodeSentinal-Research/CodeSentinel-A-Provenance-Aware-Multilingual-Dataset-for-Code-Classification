import java.util.*;

public class Main {
    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        String s = scanner.nextLine();
        System.out.println(removeDuplicateLetters(s));
    }

    public static String removeDuplicateLetters(String s) {
        int[] count = new int[26];
        for (char c : s.toCharArray()) {
            count[c - 'a']++;
        }

        boolean[] visited = new boolean[26];
        StringBuilder sb = new StringBuilder();

        for (char c : s.toCharArray()) {
            count[c - 'a']--;
            if (visited[c - 'a']) continue;

            while (sb.length() > 0 && sb.charAt(sb.length() - 1) > c && count[sb.charAt(sb.length() - 1) - 'a'] > 0) {
                visited[sb.charAt(sb.length() - 1) - 'a'] = false;
                sb.deleteCharAt(sb.length() - 1);
            }

            visited[c - 'a'] = true;
            sb.append(c);
        }

        return sb.toString();
    }
}
