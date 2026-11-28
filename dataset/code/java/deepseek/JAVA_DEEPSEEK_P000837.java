import java.util.Scanner;

public class Main {
    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        int n = scanner.nextInt();
        double[] stations = new double[n];
        for (int i = 0; i < n; i++) {
            stations[i] = scanner.nextDouble();
        }
        int k = scanner.nextInt();
        System.out.println(minMaxDistance(stations, k));
    }

    private static double minMaxDistance(double[] stations, int k) {
        double left = 0;
        double right = stations[stations.length - 1] - stations[0];
        while (right - left > 1e-6) {
            double mid = (left + right) / 2;
            if (canAddKStations(stations, k, mid)) {
                right = mid;
            } else {
                left = mid;
           }
        }
        return right;
    }

    private static boolean canAddKStations(double[] stations, int k, double maxDistance) {
        int count = 0;
        for (int i = 0; i < stations.length - 1; i++) {
            double distance = stations[i + 1] - stations[i];
            if (distance > maxDistance) {
                count += (int) (distance / maxDistance);
                if (distance % maxDistance == 0) {
                    count--;
                }
            }
        }
        return count <= k;
    }
}
