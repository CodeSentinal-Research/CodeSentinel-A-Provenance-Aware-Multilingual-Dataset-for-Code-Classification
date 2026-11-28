import java.util.*;
public class Main {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        int d = sc.nextInt();
        Set<String> deadends = new HashSet<>();
        for(int i=0; i<d; i++) deadends.add(sc.next());
        String target = sc.next();
        
        if(deadends.contains("0000")) { System.out.println(-1); return; }
        
        Queue<String> queue = new LinkedList<>();
        Set<String> visited = new HashSet<>();
        queue.offer("0000");
        visited.add("0000");
        int steps = 0;
        
        while(!queue.isEmpty()) {
            int size = queue.size();
            for(int k=0; k<size; k++) {
                String curr = queue.poll();
                if(curr.equals(target)) { System.out.println(steps); return; }
                for(int i=0; i<4; i++) {
                    for(int delta : new int[]{-1, 1}) {
                        char[] chars = curr.toCharArray();
                        chars[i] = (char)((chars[i] - '0' + delta + 10) % 10 + '0');
                        String next = new String(chars);
                        if(!deadends.contains(next) && !visited.contains(next)) {
                            visited.add(next);
                            queue.offer(next);
                        }
                    }
                }
            }
            steps++;
        }
        System.out.println(-1);
    }
}
