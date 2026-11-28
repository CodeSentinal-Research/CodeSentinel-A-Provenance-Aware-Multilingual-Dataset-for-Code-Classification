import java.util.*;
public class Main {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        int q = sc.nextInt();
        PriorityQueue<Integer> pq = new PriorityQueue<>(Collections.reverseOrder());
        
        for(int i=0; i<q; i++) {
            String op = sc.next();
            if(op.equals("insert")) {
                pq.offer(sc.nextInt());
            } else if(op.equals("delete")) {
                if(!pq.isEmpty()) pq.poll();
            } else if(op.equals("getMax")) {
                if(!pq.isEmpty()) System.out.println(pq.peek());
            }
        }
    }
}
