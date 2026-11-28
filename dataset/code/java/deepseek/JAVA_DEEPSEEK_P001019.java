import java.util.*;
import java.awt.Point;

public class Main {
    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        int N = scanner.nextInt();
        int K = scanner.nextInt();
        List<Point> points = new ArrayList<>();
        for (int i = 0; i < N; i++) {
            int x = scanner.nextInt();
            int y = scanner.nextInt();
            points.add(new Point(x, y));
        }
        List<Point> result = kClosestPoints(points, K);
        for (Point point : result) {
            System.out.println(point.x + " " + point.y);
        }
    }

    public static List<Point> kClosestPoints(List<Point> points, int k) {
        PriorityQueue<Point> queue = new PriorityQueue<>(Comparator.comparing((Point p) -> p.x * p.x + p.y * p.y));
        for (Point point : points) {
            queue.add(point);
            if (queue.size() > k) {
                queue.poll();
            }
        }
        List<Point> result = new ArrayList<>();
        while (!queue.isEmpty()) {
            result.add(queue.poll());
        }
        return result;
    }
}
