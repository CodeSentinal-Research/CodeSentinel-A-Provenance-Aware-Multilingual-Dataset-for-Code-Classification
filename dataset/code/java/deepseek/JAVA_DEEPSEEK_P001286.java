import java.util.Scanner;

public class Main {
    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);

        int N = scanner.nextInt();
        int AdditionalRocks = scanner.nextInt();

        int[] capacities = new int[N];
        int[] rocks = new int[N];

        for (int i = 0; i < N; i++) {
            capacities[i] = scanner.nextInt();
        }

        for (int i = 0; i < N; i++) {
            rocks[i] = scanner.nextInt();
        }

        int maxBags = 0;
        int currentRocks = AdditionalRocks;

        for (int i = 0; i < N; i++) {
            if (currentRocks >= capacities[i]) {
                currentRocks -= capacities[i];
                maxBags++;
            } else {
                break;
            }
        }

        System.out.println(maxBags);
    }
}
