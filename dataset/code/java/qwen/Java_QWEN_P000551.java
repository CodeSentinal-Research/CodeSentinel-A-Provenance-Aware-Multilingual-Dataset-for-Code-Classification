import java.util.*;
public class Main {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        int n = sc.nextInt();
        Queue<String> queue = new LinkedList<>();
        queue.offer("1");
        for(int i=0; i<n; i++) {
            String curr = queue.poll();
            System.out.print(curr + " ");
            queue.offer(curr + "0");
            queue.offer(curr + "1");
        }
    }
}
