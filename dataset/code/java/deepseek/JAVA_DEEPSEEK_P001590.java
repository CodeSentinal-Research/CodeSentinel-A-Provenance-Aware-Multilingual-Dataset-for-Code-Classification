import java.util.Scanner;

public class Main {
    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);

        int N = scanner.nextInt();
        long Budget = scanner.nextLong();
        long[] chargeTimes = new long[N];
        long[] runningCosts = new long[N];

        for (int i = 0; i < N; i++) {
            chargeTimes[i] = scanner.nextLong();
        }

        for (int i = 0; i < N; i++) {
            runningCosts[i] = scanner.nextLong();
        }

        long maxConsecutiveRobots = 0;
        long currentChargeTime = chargeTimes[0];
        long currentRunningCost = runningCosts[0];
        long currentBudget = Budget;

        for (int i = 1; i < N; i++) {
            if (currentBudget >= currentChargeTime - currentRunningCost) {
                currentBudget -= currentChargeTime - currentRunningCost;
                currentChargeTime = chargeTimes[i];
                currentRunningCost = runningCosts[i];
            } else {
                break;
            }
        }

        maxConsecutiveRobots = Math.max(maxConsecutiveRobots, currentChargeTime - currentRunningCost);

        System.out.println(maxConsecutiveRobots);
    }
}
