import java.util.*;
public class Main {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        int n = sc.nextInt();
        Queue<Integer> queue = new LinkedList<>();
        for(int i=0; i<n; i++) queue.offer(sc.nextInt());
        
        Stack<Integer> stack = new Stack<>();
        while(!queue.isEmpty()) stack.push(queue.poll());
        while(!stack.isEmpty()) queue.offer(stack.pop());
        
        while(!queue.isEmpty()) System.out.print(queue.poll() + " ");
    }
}
