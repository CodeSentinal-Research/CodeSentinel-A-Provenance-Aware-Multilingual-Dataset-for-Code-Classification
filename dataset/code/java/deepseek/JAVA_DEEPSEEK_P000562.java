import java.util.*;

public class Main {
    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        int n = scanner.nextInt();
        List<List<Integer>> rooms = new ArrayList<>();
        for (int i = 0; i < n; i++) {
            int k = scanner.nextInt();
            List<Integer> keys = new ArrayList<>();
            for (int j = 0; j < k; j++) {
                keys.add(scanner.nextInt());
            }
            rooms.add(keys);
       }
       
        boolean[] visited = new boolean[n];
        Queue<Integer> queue = new LinkedList<>();
        queue.offer(0);
        visited[0] = true;
        
        while (!queue.isEmpty()) {
            int room = queue.poll();
            for (int key : rooms.get(room)) {
                if (!visited[key]) {
                    queue.offer(key);
                    visited[key] = true;
                }
            }
        }
        
        for (boolean v : visited) {
            if (!v) {
                System.out.println("false");
                return;
            }
        }
        
        System.out.println("true");
    }
}
