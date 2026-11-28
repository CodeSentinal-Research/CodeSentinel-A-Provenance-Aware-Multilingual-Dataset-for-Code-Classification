import java.util.*;
public class Solution {
    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        if (scanner.hasNextInt()) {
            int q = scanner.nextInt();
            Deque<Integer> dq = new LinkedList<>();
            while (q-- > 0) {
                String cmd = scanner.next();
                if (cmd.equals("insertFront")) {
                    dq.addFirst(scanner.nextInt());
                } else if (cmd.equals("insertLast")) {
                    dq.addLast(scanner.nextInt());
                } else if (cmd.equals("deleteFront")) {
                    if (!dq.isEmpty()) dq.removeFirst();
                } else if (cmd.equals("deleteLast")) {
                    if (!dq.isEmpty()) dq.removeLast();
                } else if (cmd.equals("getFront")) {
                    System.out.println(dq.isEmpty() ? -1 : dq.peekFirst());
                } else if (cmd.equals("getRear")) {
                    System.out.println(dq.isEmpty() ? -1 : dq.peekLast());
                } else if (cmd.equals("isEmpty")) {
                    System.out.println(dq.isEmpty() ? "true" : "false");
                } else if (cmd.equals("size")) {
                    System.out.println(dq.size());
                }
            }
        }
    }
}