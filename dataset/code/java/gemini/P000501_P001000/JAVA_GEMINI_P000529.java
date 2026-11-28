import java.util.*;
public class Solution {
    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        if (scanner.hasNextInt()) {
            int cap = scanner.nextInt(), q = scanner.nextInt();
            List<Integer> queue = new ArrayList<>();
            while (q-- > 0) {
                String cmd = scanner.next();
                if (cmd.equals("enqueue")) {
                    queue.add(scanner.nextInt());
                } else if (cmd.equals("dequeue")) {
                    if (!queue.isEmpty()) System.out.println(queue.remove(0));
                } else if (cmd.equals("front")) {
                    if (!queue.isEmpty()) System.out.println(queue.get(0));
                } else if (cmd.equals("isEmpty")) {
                    System.out.println(queue.isEmpty() ? "true" : "false");
                }
            }
        }
    }
}