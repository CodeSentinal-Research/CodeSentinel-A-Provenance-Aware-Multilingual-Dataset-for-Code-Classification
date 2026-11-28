import java.util.*;
public class Main {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        int n = sc.nextInt();
        Queue<Integer> queue = new LinkedList<>();
        for(int i=0; i<n; i++) queue.offer(sc.nextInt());
        int k = sc.nextInt();
        
        for(int i=0; i<k; i++) queue.offer(queue.poll());
        while(!queue.isEmpty()) System.out.print(queue.poll() + " ");
    }
}
