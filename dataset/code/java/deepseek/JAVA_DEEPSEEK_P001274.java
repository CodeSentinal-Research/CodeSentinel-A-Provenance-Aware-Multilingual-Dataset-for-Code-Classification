import java.util.Scanner;

public class Main {
    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        int N = scanner.nextInt();
        int Coins = scanner.nextInt();
        int[] costs = new int[N];
        for (int i = 0; i < N; i++) {
            costs[i] = scanner.nextInt();
        }
        System.out.println(maxIceCreamBars(costs, Coins));
    }

    public static int maxIceCreamBars(int[] costs, int coins) {
        int count = 0;
        for (int cost : costs) {
            if (coins >= cost) {
                coins -= cost;
                count++;
            }
        }
        return count;
    }
}
