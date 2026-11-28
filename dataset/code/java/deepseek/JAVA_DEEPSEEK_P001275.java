import java.util.*;

public class Main {
    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        int N = scanner.nextInt();
        int K = scanner.nextInt();
        double[] qualities = new double[N];
        double[] wages = new double[N];
        for (int i = 0; i < N; i++) {
            qualities[i] = scanner.nextDouble();
            wages[i] = scanner.nextDouble();
        }
        scanner.close();
        double l = 0, r = 1e18;
        for (int i = 0; i < 100; i++) {
            double mid = (l + r) / 2;
            if (check(mid, N, K, qualities, wages)) {
                r = mid;
            } else {
                l = mid;
            }
        }
        System.out.printf("%.10f\n", l);
    }

    private static boolean check(double mid, int N, int K, double[] qualities, double[] wages) {
        double totalQuality = 0, totalWage = 0;
        PriorityQueue<Double> qualityQueue = new PriorityQueue<>(Comparator.reverseOrder());
        PriorityQueue<Double> wageQueue = new PriorityQueue<>(Comparator.reverseOrder());
        for (int i = 0; i < N; i++) {
            qualityQueue.offer(qualities[i]);
            wageQueue.offer(wages[i]);
        }
        for (int i = 0; i < N; i++) {
            if (qualityQueue.peek() > mid) {
                double q = qualityQueue.poll();
                double w = wageQueue.poll();
                if (totalQuality + q <= mid) {
                    totalQuality += q;
                    totalWage += w;
                } else {
                    double rest = mid - totalQuality;
                    totalQuality += rest;
                    totalWage += rest * w;
                    qualityQueue.offer(q - rest);
                }
            } else {
                double q = qualityQueue.poll();
                double w = wageQueue.poll();
                if (totalQuality + q <= mid) {
                    totalQuality += q;
                    totalWage += w;
                } else {
                    double rest = mid - totalQuality;
                    totalQuality += rest;
                    totalWage += rest * w;
                    qualityQueue.offer(q - rest);
                }
                if (qualityQueue.isEmpty()) {
                    break;
                }
            }
        }
        return totalQuality >= mid && totalWage >= mid && K <= N - (int)totalQuality;
    }
}
