import java.util.*;

public class Main {
    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        int n = scanner.nextInt();
        long[] maxHeights = new long[n];
        for (int i = 0; i < n; i++) {
            maxHeights[i] = scanner.nextLong();
        }
        System.out.println(maxTowerHeight(maxHeights));
    }

    private static long maxTowerHeight(long[] maxHeights) {
        Arrays.sort(maxHeights);
        long sum = 0;
        for (int i = 0; i < maxHeights.length; i++) {
            sum += Math.max(maxHeights[i], maxHeights[maxHeights.length - 1 - i]);
        }
        return sum;
    }
}
