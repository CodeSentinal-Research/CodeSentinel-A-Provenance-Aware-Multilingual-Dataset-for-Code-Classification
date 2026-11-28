import java.util.*;

public class Main {
    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        int N = scanner.nextInt();
        int carpetLength = scanner.nextInt();
        List<Interval> intervals = new ArrayList<>();
        for (int i = 0; i < N; i++) {
            int start = scanner.nextInt();
            int end = scanner.nextInt();
            intervals.add(new Interval(start, end));
        }
        scanner.close();
        System.out.println(maxWhiteTiles(intervals, carpetLength));
    }

    public static int maxWhiteTiles(List<Interval> intervals, int carpetLength) {
        intervals.sort(Comparator.comparingInt(o -> o.start));
        int maxCovered = 0;
        int end = 0;
        for (Interval interval : intervals) {
            if (interval.start > end) {
                int length = interval.start - end - 1;
                maxCovered += length / carpetLength;
                if (length % carpetLength != 0) {
                    maxCovered++;
                }
            }
            end = Math.max(end, interval.end);
        }
        return maxCovered;
    }

    public static class Interval {
        int start;
        int end;

        public Interval(int start, int end) {
            this.start = start;
            this.end = end;
        }
    }
}
