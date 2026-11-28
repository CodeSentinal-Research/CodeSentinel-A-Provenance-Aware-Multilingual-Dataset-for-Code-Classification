import java.util.*;

public class Main {
    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        String s = scanner.nextLine();
        Set<String> set = new HashSet<>();
        set.add(s);
        while (true) {
            boolean found = false;
            for (String str : set) {
                if (isValid(str)) {
                    System.out.println(str);
                    found = true;
                    break;
                }
            }
            if (!found) break;
            set.clear();
            for (String str : set) {
                set.addAll(generate(str));
            }
        }
    }

    private static boolean isValid(String s) {
        int balance = 0;
        for (char c : s.toCharArray()) {
            if (c == '(') balance++;
            else if (c == ')') balance--;
            if (balance < 0) return false;
        }
        return balance == 0;
    }

    private static Set<String> generate(String s) {
        Set<String> set = new HashSet<>();
        for (int i = 0; i < s.length(); i++) {
            if (s.charAt(i) == '(') {
                String str = s.substring(0, i) + s.substring(i + 1);
                set.add(str);
            }
        }
        return set;
    }
}
