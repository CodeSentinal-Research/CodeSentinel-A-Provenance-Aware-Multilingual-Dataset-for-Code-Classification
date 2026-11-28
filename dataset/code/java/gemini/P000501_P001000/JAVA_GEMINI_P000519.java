import java.util.*;
public class Solution {
    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        if (scanner.hasNextInt()) {
            int q = scanner.nextInt();
            Stack<Integer> s1 = new Stack<>(), s2 = new Stack<>();
            while (q-- > 0) {
                String cmd = scanner.next();
                if (cmd.equals("push")) {
                    s1.push(scanner.nextInt());
                } else if (cmd.equals("pop")) {
                    if (s2.isEmpty()) while (!s1.isEmpty()) s2.push(s1.pop());
                    if (!s2.isEmpty()) System.out.println(s2.pop());
                } else if (cmd.equals("peek")) {
                    if (s2.isEmpty()) while (!s1.isEmpty()) s2.push(s1.pop());
                    if (!s2.isEmpty()) System.out.println(s2.peek());
                } else if (cmd.equals("empty")) {
                    System.out.println(s1.isEmpty() && s2.isEmpty() ? "true" : "false");
                }
            }
        }
    }
}