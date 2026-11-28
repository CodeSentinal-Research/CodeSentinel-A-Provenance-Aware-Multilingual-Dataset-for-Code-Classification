import java.util.*;

public class Main {
    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        int N = scanner.nextInt();
        int K = scanner.nextInt();
        PriorityQueue<Integer> quality = new PriorityQueue<>(Comparator.reverseOrder());
        PriorityQueue<Integer> wage = new PriorityQueue<>(Comparator.naturalOrder());
        for (int i = 0; i < N; i++) {
            quality.add(scanner.nextInt());
            wage.add(scanner.nextInt());
        }
        long totalCost = 0;
        while (K-- > 0) {
            int q = quality.poll();
            int w = wage.poll();
            quality.add(q);
            wage.add(w);
            totalCost += q;
        }
        System.out.println(totalCost);
    }
}
