import java.util.*;

public class Main {
    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        int n = scanner.nextInt();
        List<Interval> intervals = new ArrayList<>();
        for (int i = 0; i < n; i++) {
            int start = scanner.nextInt();
            int end = scanner.nextInt();
            intervals.add(new Interval(start, end));
        }
        scanner.close();
        System.out.println(minRemovals(intervals));
    }

    private static int minRemovals(List<Interval> intervals) {
        if (intervals.isEmpty()) {
            return 0;
        }
        Collections.sort(intervals, Comparator.comparingInt(i -> i.end));
        int removals = 0;
        int currentEnd = intervals.get(0).end;
        for (Interval interval : intervals) {
            if (interval.start < currentEnd) {
                removals++;
            } else {
                currentEnd = interval.end;
            }
        }
        return removals;
    }

    static class Interval {
        int start;
        int end;

        Interval(int start, int end) {
            this.start = start;
            this.end = end;
        }
    }
}
