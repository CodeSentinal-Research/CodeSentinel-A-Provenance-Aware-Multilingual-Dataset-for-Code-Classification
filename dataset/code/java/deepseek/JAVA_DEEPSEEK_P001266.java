import java.util.*;

public class Main {
    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        int N = scanner.nextInt();
        int K = scanner.nextInt();
        int InitialCapital = scanner.nextInt();
        PriorityQueue<Project> projects = new PriorityQueue<>((a, b) -> b.profit - a.profit);
        for (int i = 0; i < N; i++) {
            int requiredCapital = scanner.nextInt();
            int profit = scanner.nextInt();
            projects.add(new Project(requiredCapital, profit));
        }
        while (K > 0 && InitialCapital >= projects.peek().requiredCapital) {
            InitialCapital += projects.poll().profit;
            K--;
        }
        System.out.println(InitialCapital);
    }

    static class Project {
        int requiredCapital;
        int profit;

        public Project(int requiredCapital, int profit) {
            this.requiredCapital = requiredCapital;
            this.profit = profit;
        }
    }
}
