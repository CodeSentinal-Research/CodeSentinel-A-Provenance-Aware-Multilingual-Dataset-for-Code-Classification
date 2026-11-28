import java.util.*;
public class Solution {
    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        if (scanner.hasNextInt()) {
            int cap = scanner.nextInt(), q = scanner.nextInt();
            List<Integer> queue = new ArrayList<>();
            while (q-- > 0) {
                String cmd = scanner.next();
                if (cmd.equals("enQueue")) {
                    int x = scanner.nextInt();
                    if (queue.size() < cap) {
                        queue.add(x);
                        System.out.println("true");
                    } else {
                        System.out.println("false");
                    }
                } else if (cmd.equals("deQueue")) {
                    if (!queue.isEmpty()) {
                        queue.remove(0);
                        System.out.println("true");
                    } else {
                        System.out.println("false");
                    }
                } else if (cmd.equals("Front")) {
                    System.out.println(queue.isEmpty() ? -1 : queue.get(0));
                } else if (cmd.equals("Rear")) {
                    System.out.println(queue.isEmpty() ? -1 : queue.get(queue.size() - 1));
                } else if (cmd.equals("isEmpty")) {
                    System.out.println(queue.isEmpty() ? "true" : "false");
                } else if (cmd.equals("isFull")) {
                    System.out.println(queue.size() == cap ? "true" : "false");
                }
            }
        }
    }
}