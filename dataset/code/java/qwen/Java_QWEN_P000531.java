import java.util.*;
public class Main {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        int n = sc.nextInt();
        Queue<Integer> queue = new LinkedList<>();
        for(int i=0; i<n; i++) {
            int t = sc.nextInt();
            queue.offer(t);
            while(queue.peek() < t - 3000) queue.poll();
            System.out.println(queue.size());
        }
    }
}
