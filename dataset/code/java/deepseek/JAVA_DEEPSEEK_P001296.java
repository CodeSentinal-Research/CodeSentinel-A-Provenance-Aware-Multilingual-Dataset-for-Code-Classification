import java.util.Scanner;

public class Main {
    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);

        int n = scanner.nextInt();
        int[] plantingTimes = new int[n];
        int[] growingTimes = new int[n];

        for (int i = 0; i < n; i++) {
            plantingTimes[i] = scanner.nextInt();
        }

        for (int i = 0; i < n; i++) {
            growingTimes[i] = scanner.nextInt();
        }

        int maxGrowingTime = 0;
        int maxGrowingTimeIndex = 0;
        int earliestFullBloomDay = 0;

        for (int i = 0; i < n; i++) {
            if (growingTimes[i] > maxGrowingTime) {
                maxGrowingTime = growingTimes[i];
                maxGrowingTimeIndex = i;
            }
        }

        for (int i = 0; i <= maxGrowingTime; i++) {
            boolean isPossible = true;
            for (int j = 0; j < n; j++) {
                if (i % plantingTimes[j] != 0 && i % plantingTimes[j] != j) {
                    isPossible = false;
                    break;
                }
            }
            if (isPossible) {
                earliestFullBloomDay = i;
                break;
            }
        }

        System.out.println(earliestFullBloomDay);
    }
}
