import java.util.*;
public class Solution {
    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        if (scanner.hasNextInt()) {
            int q = scanner.nextInt();
            LinkedList<Integer> queue = new LinkedList<>();
            while (q-- > 0) {
                String cmd = scanner.next();
                if (cmd.equals("enqueue")) {
                    queue.add(scanner.nextInt());
                } else if (cmd.equals("dequeue")) {
                    if (!queue.isEmpty()) System.out.println(queue.removeFirst());
                } else if (cmd.equals("front")) {
                    if (!queue.isEmpty()) System.out.println(queue.getFirst());
                } else if (cmd.equals("size")) {
                    System.out.println(queue.size());
                } else if (cmd.equals("isEmpty")) {
                    System.out.println(queue.isEmpty() ? "true" : "false");
                }
            }
        }
    }
}