import java.util.*;
public class Main {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        int target = sc.nextInt();
        
        Queue<long[]> queue = new LinkedList<>();
        queue.offer(new long[]{0, 1, 0}); // pos, speed, steps
        Set<String> visited = new HashSet<>();
        
        while(!queue.isEmpty()) {
            long[] curr = queue.poll();
            long pos = curr[0], speed = curr[1], steps = curr[2];
            if(pos == target) { System.out.println(steps); return; }
            
            String key = pos + "," + speed;
            if(visited.contains(key)) continue;
            visited.add(key);
            
            // Accelerate
            queue.offer(new long[]{pos + speed, speed * 2, steps + 1});
            
            // Reverse
            if(pos + speed > target) {
                 queue.offer(new long[]{pos, speed > 0 ? -1 : 1, steps + 1});
            }
        }
    }
}
