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
        PriorityQueue<Pair> queue = new PriorityQueue<>((a, b) -> a.count == b.count ? a.num - b.num : b.count - a.count);
        for (int num : map.keySet()) {
            queue.add(new Pair(num, map.get(num)));
        }
        for (int i = 0; i < k; i++) {
            System.out.println(queue.poll().num);
        }
    }

    static class Pair {
        int num;
        int count;

        public Pair(int num, int count) {
            this.num = num;
            this.count = count;
        }
    }
}
