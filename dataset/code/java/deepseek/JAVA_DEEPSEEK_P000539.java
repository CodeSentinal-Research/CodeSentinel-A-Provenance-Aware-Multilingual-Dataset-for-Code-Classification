import java.util.*;

public class Main {
    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        int n = scanner.nextInt();
        int[] arr = new int[n];
        for (int i = 0; i < n; i++) {
            arr[i] = scanner.nextInt();
        }
        int q = scanner.nextInt();
        Queue<Integer> queue = new LinkedList<>();
        Map<Integer, Integer> map = new HashMap<>();
        for (int i = 0; i < n; i++) {
            queue.add(arr[i]);
            map.put(arr[i], map.getOrDefault(arr[i], 0) + 1);
            while (!queue.isEmpty() && map.get(queue.peek()) > 1) {
                queue.poll();
            }
            if (i >= q) {
                if (queue.isEmpty()) {
                    System.out.println(-1);
                } else {
                    System.out.println(queue.peek());
                }
            }
        }
        for (int i = 0; i < q; i++) {
            String operation = scanner.next();
            if (operation.equals("add")) {
                int value = scanner.nextInt();
                queue.add(value);
                map.put(value, map.getOrDefault(value, 0) + 1);
                while (!queue.isEmpty() && map.get(queue.peek()) > 1) {
                    queue.poll();
                }
                if (queue.isEmpty()) {
                    System.out.println(-1);
                } else {
                    System.out.println(queue.peek());
                }
            }
        }
    }
}
