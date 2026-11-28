import java.util.*;
public class Main {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        String s = sc.next();
        Map<Character, Integer> counts = new HashMap<>();
        Queue<Character> queue = new LinkedList<>();
        StringBuilder res = new StringBuilder();
        
        for(char c : s.toCharArray()) {
            counts.put(c, counts.getOrDefault(c, 0) + 1);
            queue.offer(c);
            while(!queue.isEmpty() && counts.get(queue.peek()) > 1) queue.poll();
            res.append(queue.isEmpty() ? '#' : queue.peek());
        }
        System.out.println(res.toString());
    }
}
