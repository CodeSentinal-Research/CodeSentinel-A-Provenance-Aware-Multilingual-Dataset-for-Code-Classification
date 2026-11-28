import java.util.*;
public class Main {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        int size = sc.nextInt();
        int q = sc.nextInt();
        Queue<Integer> queue = new LinkedList<>();
        int sum = 0;
        
        for(int i=0; i<q; i++) {
            int val = sc.nextInt();
            queue.offer(val);
            sum += val;
            if(queue.size() > size) {
                sum -= queue.poll();
            }
            System.out.printf("%.5f\n", (double)sum / queue.size());
        }
    }
}
