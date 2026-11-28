import java.util.*;
public class Main {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        int n = sc.nextInt();
        Queue<Integer> queue = new LinkedList<>();
        for(int i=0; i<n; i++) queue.offer(sc.nextInt());
        
        Queue<Integer> firstHalf = new LinkedList<>();
        for(int i=0; i<n/2; i++) firstHalf.offer(queue.poll());
        
        Queue<Integer> result = new LinkedList<>();
        while(!firstHalf.isEmpty()) {
            result.offer(firstHalf.poll());
            result.offer(queue.poll());
        }
        while(!result.isEmpty()) System.out.print(result.poll() + " ");
    }
}
