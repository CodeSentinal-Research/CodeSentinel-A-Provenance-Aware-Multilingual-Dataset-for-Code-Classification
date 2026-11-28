import java.util.*;
public class Main {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        int n = sc.nextInt();
        int k = sc.nextInt();
        Queue<Integer> queue = new LinkedList<>();
        for(int i=1; i<=n; i++) queue.offer(i);
        
        while(queue.size() > 1) {
            for(int i=0; i<k-1; i++) queue.offer(queue.poll());
            queue.poll();
        }
        System.out.println(queue.poll());
    }
}
