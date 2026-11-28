import java.util.Scanner;
import java.util.PriorityQueue;

public class Main {
    static class Project implements Comparable<Project> {
        int capital;
        int profit;

        public Project(int capital, int profit) {
            this.capital = capital;
            this.profit = profit;
        }

        @Override
        public int compareTo(Project o) {
            return o.profit - this.profit;
        }
    }

    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        int N = scanner.nextInt();
        int K = scanner.nextInt();
        PriorityQueue<Project> maxHeap = new PriorityQueue<>();
        for (int i = 0; i < N; i++) {
            maxHeap.add(new Project(scanner.nextInt(), scanner.nextInt()));
        }
        int maxCapital = 0;
        while (K > 0 && !maxHeap.isEmpty()) {
            Project project = maxHeap.poll();
            maxCapital += project.capital;
            K--;
        }
        System.out.println(maxCapital);
    }
}
