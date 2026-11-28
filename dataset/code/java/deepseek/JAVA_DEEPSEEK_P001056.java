import java.util.*;

public class Main {
    private static PriorityQueue<Integer> pq;
    private static Set<Integer> s;

    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        int q = scanner.nextInt();
        pq = new PriorityQueue<>();
        s = new HashSet<>();
        for (int i = 1; i <= q; i++) {
            String operation = scanner.next();
            if (operation.equals("add")) {
                int num = scanner.nextInt();
                s.add(num);
                pq.add(num);
            } else if (operation.equals("remove")) {
                int num = scanner.nextInt();
                if (s.contains(num)) {
                    s.remove(num);
                    pq.remove(num);
                }
            } else if (operation.equals("find_smallest")) {
                System.out.println(pq.peek());
            }
        }
    }
}
