import java.util.Scanner;

public class Main {
    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        int N = scanner.nextInt();
        int[] gas = new int[N];
        int[] cost = new int[N];
        for (int i = 0; i < N; i++) {
            gas[i] = scanner.nextInt();
        }
        for (int i = 0; i < N; i++) {
            cost[i] = scanner.nextInt();
        }
        System.out.println(canCompleteCircuit(gas, cost));
    }

    public static int canCompleteCircuit(int[] gas, int[] cost) {
        int start = 0;
        int currentGas = gas[start];
        int totalCost = cost[start];
        while (true) {
            if (currentGas < totalCost) {
                start = (start + 1) % gas.length;
                if (start == 0) {
                    return -1;
                }
                currentGas = gas[start];
                totalCost = cost[start];
            } else {
                currentGas -= totalCost;
                totalCost += cost[start];
                start = (start + 1) % gas.length;
                if (start == 0) {
                    return -1;
                }
            }
        }
    }
}
