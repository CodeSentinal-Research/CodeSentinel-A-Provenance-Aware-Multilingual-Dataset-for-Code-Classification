import java.util.Scanner;
import java.util.Stack;

public class Main {
    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);

        String s1 = scanner.nextLine();
        String s2 = scanner.nextLine();

        System.out.println(areProcessedStringsEqual(s1, s2) ? "YES" : "NO");
    }

    private static boolean areProcessedStringsEqual(String s1, String s2) {
        Stack<Character> stack1 = new Stack<>();
        Stack<Character> stack2 = new Stack<>();

        for (char c : (s1 + s2).toCharArray()) {
            if (c == '#') {
                if (!stack1.isEmpty()) {
                    stack1.pop();
                }
            } else {
                stack1.push(c);
            }
        }

        while (!stack1.isEmpty()) {
            if (stack2.isEmpty() || stack2.pop() != '#') {
                return false;
            }
        }

        s1 = new StringBuilder(s1).reverse().toString();
        s2 = new StringBuilder(s2).reverse().toString();

        for (char c : (s1 + s2).toCharArray()) {
            if (c == '#') {
                if (!stack2.isEmpty()) {
                    stack2.pop();
                }
            } else {
                stack2.push(c);
            }
        }

        while (!stack2.isEmpty()) {
            if (stack1.isEmpty() || stack1.pop() != '#') {
                return false;
            }
        }

        return true;
    }
}
