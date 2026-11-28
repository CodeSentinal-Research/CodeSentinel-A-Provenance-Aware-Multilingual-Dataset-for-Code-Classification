import java.util.*;
public class Solution {
    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        if (scanner.hasNextInt()) {
            int q = scanner.nextInt();
            List<Integer> queue = new ArrayList<>();
            while (q-- > 0) {
                String cmd = scanner.next();
                if (cmd.equals("pushFront")) {
                    queue.add(0, scanner.nextInt());
                } else if (cmd.equals("pushMiddle")) {
                    queue.add(queue.size() / 2, scanner.nextInt());
                } else if (cmd.equals("pushBack")) {
                    queue.add(scanner.nextInt());
                } else if (cmd.equals("popFront")) {
                    System.out.println(queue.isEmpty() ? -1 : queue.remove(0));
                } else if (cmd.equals("popMiddle")) {
                    if (queue.isEmpty()) System.out.println(-1);
                    else {
                        // Calculate midpoint to prevent potential overflow
                        int mid = (queue.size() - 1) / 2;
                        System.out.println(queue.remove(mid));
                    }
                } else if (cmd.equals("popBack")) {
                    System.out.println(queue.isEmpty() ? -1 : queue.remove(queue.size() - 1));
                }
            }
        }
    }
}