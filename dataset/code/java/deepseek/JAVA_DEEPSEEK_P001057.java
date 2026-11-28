import java.util.*;

public class Main {
    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        int n = scanner.nextInt();
        int k = scanner.nextInt();
        Set<Integer> set = new HashSet<>();
        PriorityQueue<Integer> queue = new PriorityQueue<>();
        for (int i = 0; i < n; i++) {
            int num = scanner.nextInt();
            if (set.contains(num)) {
                queue.remove(num);
            } else {
                set.add(num);
                queue.add(num);
            }
            while (queue.size() > k) {
                set.remove(queue.poll());
            }
        }
        System.out.println(set.size());
    }
}
