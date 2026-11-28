import java.util.*;

public class Main {
    public static List<String> removeInvalidParentheses(String s) {
        Set<String> res = new HashSet<>();
        Queue<String> q = new LinkedList<>();
        q.offer(s);
        while (!q.isEmpty()) {
            String t = q.poll();
            if (isValid(t)) {
                res.add(t);
            } else {
                for (int i = 0; i < t.length(); i++) {
                    if (Character.isLetter(t.charAt(i))) continue;
                    String next = t.substring(0, i) + t.substring(i + 1);
                    if (res.contains(next)) continue;
                    q.offer(next);
                }
            }
        }
        return new ArrayList<>(res);
    }

    private static boolean isValid(String s) {
        int balance = 0;
        for (char c : s.toCharArray()) {
            if (c == '(') balance++;
            else if (c == ')') {
                if (balance == 0) return false;
                balance--;
            }
        }
        return balance == 0;
    }

    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        String s = scanner.nextLine();
        List<String> res = removeInvalidParentheses(s);
        Collections.sort(res);
        for (String str : res) {
            System.out.println(str);
        }
    }
}
