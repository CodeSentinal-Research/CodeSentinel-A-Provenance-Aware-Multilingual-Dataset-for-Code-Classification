import java.util.Deque;
import java.util.LinkedList;
import java.util.Scanner;

public class Main {
    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        RecentCounter recentCounter = new RecentCounter();

        while (scanner.hasNextInt()) {
            int t = scanner.nextInt();
            System.out.println(recentCounter.ping(t));
        }
    }
}

class RecentCounter {
    Deque<Integer> queue;

    public RecentCounter() {
        queue = new LinkedList<>();
    }

    public int ping(int t) {
        queue.offer(t);
        while (queue.peekFirst() < t - 3000) {
            queue.pollFirst();
        }
        return queue.size();
    }
}
