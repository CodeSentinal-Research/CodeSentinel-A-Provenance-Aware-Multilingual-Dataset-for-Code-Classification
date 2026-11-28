import java.util.PriorityQueue;
import java.util.Scanner;

public class Solution {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        if (sc.hasNextInt()) {
            int q = sc.nextInt();
            PriorityQueue<Integer> pq = new PriorityQueue<>();
            while (q-- > 0) {
                String op = sc.next();
                if (op.equals("INSERT")) {
                    pq.offer(sc.nextInt());
                } else if (op.equals("EXTRACT_MIN")) {
                    if (pq.isEmpty()) System.out.println("EMPTY");
                    else System.out.println(pq.poll());
                } else if (op.equals("PEEK")) {
                    if (pq.isEmpty()) System.out.println("EMPTY");
                    else System.out.println(pq.peek());
                }
            }
        }
        sc.close();
    }
}