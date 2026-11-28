import java.util.*;

public class Main {
    static class Job {
        int deadline;
        int profit;

        Job(int deadline, int profit) {
            this.deadline = deadline;
            this.profit = profit;
        }
    }

    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        int N = scanner.nextInt();
        List<Job> jobs = new ArrayList<>();
        for (int i = 0; i < N; i++) {
            int deadline = scanner.nextInt();
            int profit = scanner.nextInt();
            jobs.add(new Job(deadline, profit));
        }
        scanner.close();

        Collections.sort(jobs, (a, b) -> b.deadline - a.deadline);

        int maxProfit = 0;
        int currentDeadline = Integer.MAX_VALUE;
        for (Job job : jobs) {
            if (job.deadline < currentDeadline) {
                maxProfit += job.profit;
                currentDeadline = job.deadline;
            }
        }

        System.out.println(maxProfit);
    }
}
