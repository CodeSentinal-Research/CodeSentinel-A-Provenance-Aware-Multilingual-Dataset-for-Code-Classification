import java.util.*;

public class Main {
    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        int N = scanner.nextInt();
        int K = scanner.nextInt();
        int initialCapital = scanner.nextInt();

        PriorityQueue<Project> projects = new PriorityQueue<>(Comparator.comparingInt(Project::getProfit).reversed());

        for (int i = 0; i < N; i++) {
            int requiredInvestment = scanner.nextInt();
            int expectedProfit = scanner.nextInt();
            projects.add(new Project(requiredInvestment, expectedProfit));
        }

        int maxCapital = initialCapital;
        while (K > 0 && !projects.isEmpty()) {
            maxCapital += projects.poll().getInvestment();
            K--;
        }

        System.out.println(maxCapital);
    }
}

class Project {
    private int investment;
    private int profit;

    public Project(int investment, int profit) {
        this.investment = investment;
        this.profit = profit;
    }

    public int getInvestment() {
        return investment;
    }

    public int getProfit() {
        return profit;
    }
}
