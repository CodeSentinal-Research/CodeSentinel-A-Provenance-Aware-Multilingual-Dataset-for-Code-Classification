import java.util.*;
import java.io.*;

public class Main {
    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        PrintWriter out = new PrintWriter(System.out);

        String[] nm = br.readLine().split(" ");
        int N = Integer.parseInt(nm[0]);
        int M = Integer.parseInt(nm[1]);

        List<Interval> intervals1 = new ArrayList<>();
        for (int i = 0; i < N; i++) {
            String[] intervalStr = br.readLine().split(" ");
            int start = Integer.parseInt(intervalStr[0]);
            int end = Integer.parseInt(intervalStr[1]);
            intervals1.add(new Interval(start, end));
        }

        List<Interval> intervals2 = new ArrayList<>();
        for (int i = 0; i < M; i++) {
            String[] intervalStr = br.readLine().split(" ");
            int start = Integer.parseInt(intervalStr[0]);
            int end = Integer.parseInt(intervalStr[1]);
            intervals2.add(new Interval(start, end));
        }

        List<Interval> intersections = findIntersections(intervals1, intervals2);
        for (Interval interval : intersections) {
            out.println(interval.start + " " + interval.end);
        }

        out.close();
    }

    private static List<Interval> findIntersections(List<Interval> intervals1, List<Interval> intervals2) {
        List<Interval> intersections = new ArrayList<>();
        int i = 0, j = 0;
        while (i < intervals1.size() && j < intervals2.size()) {
            Interval interval1 = intervals1.get(i);
            Interval interval2 = intervals2.get(j);

            if (interval1.start < interval2.start) {
                i++;
            } else if (interval1.end > interval2.end) {
                j++;
            } else {
                intersections.add(new Interval(interval1.start, interval2.end));
                i++;
                j++;
            }
        }
        return intersections;
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
