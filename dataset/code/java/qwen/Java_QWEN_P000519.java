import java.util.*;
public class Main {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        int q = sc.nextInt();
        Queue<Integer> queue = new LinkedList<>();
        for(int i=0; i<q; i++) {
            String op = sc.next();
            if(op.equals("push")) {
                int val = sc.nextInt();
                queue.offer(val);
            } else if(op.equals("pop")) {
                if(!queue.isEmpty()) System.out.println(queue.poll());
                else System.out.println("Empty");
            } else if(op.equals("peek")) {
                if(!queue.isEmpty()) System.out.println(queue.peek());
                else System.out.println("Empty");
            } else if(op.equals("empty")) {
                System.out.println(queue.isEmpty() ? "true" : "false");
            }
        }
    }
}
