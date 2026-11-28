import java.util.*;

public class Main {
    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        int q = scanner.nextInt();
        scanner.nextLine();

        Deque<Integer> queue = new ArrayDeque<>();
        for (int i = 0; i < q; i++) {
            String operation = scanner.next();
            if (operation.equals("pushFront")) {
                int x = scanner.nextInt();
                queue.offerFirst(x);
            } else if (operation.equals("pushMiddle")) {
                int x = scanner.nextInt();
                int middle = queue.size() / 2;
                Deque<Integer> temp = new ArrayDeque<>();
                while (middle-- > 0) {
                    temp.offerLast(queue.pollFirst());
                }
                queue.offerLast(x);
                while (!temp.isEmpty()) {
                    queue.offerLast(temp.pollFirst());
               }
            } else if (operation.equals("pushBack")) {
                int x = scanner.nextInt();
                queue.offerLast(x);
            } else if (operation.startsWith("pop")) {
                if (queue.isEmpty()) {
                    System.out.println(-1);
                } else {
                    if (operation.equals("popFront")) {
                        System.out.println(queue.pollFirst());
                    } else if (operation.equals("popMiddle")) {
                        int middle = (queue.size() - 1) / 2;
                        while (middle-- > 0) {
                            queue.pollFirst();
                        }
                        System.out.println(queue.pollFirst());
                    } else if (operation.equals("popBack")) {
                        System.out.println(queue.pollLast());
                    }
                }
            }
        }
    }
}
