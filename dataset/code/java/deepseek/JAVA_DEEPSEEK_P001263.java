import java.util.*;

public class Main {
    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        int N = scanner.nextInt();
        scanner.nextLine();

        PriorityQueue<Integer> costA = new PriorityQueue<>();
        PriorityQueue<Integer> costB = new PriorityQueue<>();
        for (int i = 0; i < 2 * N; i++) {
            costA.add(scanner.nextInt());
            costB.add(scanner.nextInt());
        }

        int totalCost = 0;
        while (!costA.isEmpty() && !costB.isEmpty()) {
            int costFromA = costA.poll();
            int costFromB = costB.poll();
            totalCost += costFromA + costFromB;

            costA.add(costFromA);
            costB.add(costFromB);
        }

        System.out.println(totalCost);
    }
}
