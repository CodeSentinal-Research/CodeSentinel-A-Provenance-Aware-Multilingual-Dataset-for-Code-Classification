import java.util.LinkedList;
import java.util.Queue;
import java.util.Scanner;

public class Main {
    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        int size = scanner.nextInt();
        int q = scanner.nextInt();
        MovingAverage movingAverage = new MovingAverage(size);
        while (q-- > 0) {
            int val = scanner.nextInt();
            System.out.println(movingAverage.next(val));
        }
    }
}

class MovingAverage {
    private Queue<Integer> queue;
    private int size;
    private double sum;

    public MovingAverage(int size) {
        this.size = size;
        this.queue = new LinkedList<>();
    }

    public double next(int val) {
        if (queue.size() == size) {
            sum -= queue.poll();
        }
        queue.offer(val);
        sum += val;
        return sum / queue.size();
    }
}
