import java.util.*;
public class Main {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        int n = sc.nextInt();
        Queue<Integer> queue = new LinkedList<>();
        for(int i=0; i<n; i++) queue.offer(sc.nextInt());
        int k = sc.nextInt();
        
        Stack<Integer> stack = new Stack<>();
        for(int i=0; i<k; i++) stack.push(queue.poll());
        while(!stack.isEmpty()) queue.offer(stack.pop());
        int remaining = n - k;
        while(remaining-- > 0) queue.offer(queue.poll());
        
        while(!queue.isEmpty()) System.out.print(queue.poll() + " ");
    }
}
