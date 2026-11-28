import java.util.*;

public class Main {
    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        int n = scanner.nextInt();
        int k = scanner.nextInt();
        Map<Integer, Integer> map = new HashMap<>();
        for (int i = 0; i < n; i++) {
            int num = scanner.nextInt();
            map.put(num, map.getOrDefault(num, 0) + 1);
        }
        PriorityQueue<Map.Entry<Integer, Integer>> queue = new PriorityQueue<>(
                (a, b) -> {
                    if (a.getValue() != b.getValue()) {
                        return a.getValue() - b.getValue();
                    } else {
                        return a.getKey() - b.getKey();
                    }
                }
        );
        for (Map.Entry<Integer, Integer> entry : map.entrySet()) {
            queue.offer(entry);
        }
        while (k-- > 0 && !queue.isEmpty()) {
            Map.Entry<Integer, Integer> entry = queue.poll();
            System.out.println(entry.getKey());
        }
    }
}
