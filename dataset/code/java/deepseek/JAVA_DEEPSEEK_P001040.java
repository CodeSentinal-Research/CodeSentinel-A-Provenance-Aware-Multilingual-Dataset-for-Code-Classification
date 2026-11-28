import java.util.PriorityQueue;
import java.util.Scanner;

public class Main {
    static class Engineer implements Comparable<Engineer> {
        int speed, efficiency;

        public Engineer(int speed, int efficiency) {
            this.speed = speed;
            this.efficiency = efficiency;
        }

        @Override
        public int compareTo(Engineer o) {
            return o.efficiency - this.efficiency;
        }
    }

    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        int N = scanner.nextInt();
        int K = scanner.nextInt();
        PriorityQueue<Engineer> maxHeap = new PriorityQueue<>();
        for (int i = 0; i < N; i++) {
            int speed = scanner.nextInt();
            int efficiency = scanner.nextInt();
            maxHeap.add(new Engineer(speed, efficiency));
        }
        double maxPerformance = 0;
        while (K-- > 0) {
            Engineer engineer = maxHeap.poll();
            maxPerformance += engineer.speed;
            if (!maxHeap.isEmpty()) {
                Engineer nextEngineer = maxHeap.peek();
                maxHeap.poll();
                maxHeap.add(new Engineer(nextEngineer.speed + engineer.speed, Math.min(nextEngineer.efficiency, engineer.efficiency)));
            }
        }
        System.out.printf("%.2f", maxPerformance);
    }
}
