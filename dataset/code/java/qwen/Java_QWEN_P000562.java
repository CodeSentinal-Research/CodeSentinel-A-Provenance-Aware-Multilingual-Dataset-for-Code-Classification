import java.util.*;
public class Main {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        int n = sc.nextInt();
        List<List<Integer>> rooms = new ArrayList<>();
        for(int i=0; i<n; i++) {
            int k = sc.nextInt();
            List<Integer> room = new ArrayList<>();
            for(int j=0; j<k; j++) room.add(sc.nextInt());
            rooms.add(room);
        }
        
        boolean[] visited = new boolean[n];
        Queue<Integer> queue = new LinkedList<>();
        queue.offer(0);
        visited[0] = true;
        int count = 1;
        
        while(!queue.isEmpty()) {
            int curr = queue.poll();
            for(int key : rooms.get(curr)) {
                if(!visited[key]) {
                    visited[key] = true;
                    count++;
                    queue.offer(key);
                }
            }
        }
        System.out.println(count == n ? "true" : "false");
    }
}
