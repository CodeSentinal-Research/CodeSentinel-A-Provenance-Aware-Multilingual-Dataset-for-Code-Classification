import java.util.Scanner;

public class Main {
    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);

        int N = scanner.nextInt();
        long totalTrips = scanner.nextLong();

        long[] tripTimes = new long[N];
        long minTime = 0;
        long maxTime = 0;

        for (int i = 0; i < N; i++) {
            tripTimes[i] = scanner.nextLong();
            minTime = Math.max(minTime, tripTimes[i]);
            maxTime += tripTimes[i];
        }

        long midTime = (minTime + maxTime) / 2;

        while (minTime < maxTime) {
            long midTrips = midTime / minTime;
            long midTimeNext = midTime + midTime / minTime;

            if (midTrips < totalTrips) {
                minTime = midTimeNext;
            } else {
                maxTime = midTime;
            }

            midTime = (minTime + maxTime) / 2;
        }

        System.out.println(minTime);
    }
}
