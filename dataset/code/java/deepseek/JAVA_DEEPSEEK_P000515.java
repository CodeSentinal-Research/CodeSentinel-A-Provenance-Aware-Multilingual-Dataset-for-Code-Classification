import java.util.*;

public class Main {
    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        int n = scanner.nextInt();
        double[][] cars = new double[n][2];
        for (int i = 0; i < n; i++) {
            cars[i][0] = scanner.nextDouble();
            cars[i][1] = scanner.nextDouble();
        }
        scanner.close();

        double[] times = getCollisionTimes(cars);
        for (double time : times) {
            System.out.println(time);
        }
    }

    public static double[] getCollisionTimes(double[][] cars) {
        int n = cars.length;
        double[] times = new double[n];
        Arrays.fill(times, -1);
        Stack<Integer> stack = new Stack<>();
        for (int i = n - 1; i >= 0; i--) {
            while (!stack.isEmpty() && cars[i][1] >= cars[stack.peek()][1]) {
                if (times[stack.peek()] != -1 && (cars[stack.peek()][0] - cars[i][0]) / (cars[i][1] - cars[stack.peek()][1]) >= times[stack.peek()]) {
                    times[i] = times[stack.peek()];
                    stack.pop();
                } else {
                    break;
                }
            }
            if (times[i] == -1) {
                times[i] = (cars[stack.peek()][0] - cars[i][0]) / (cars[i][1] - cars[stack.peek()][1]);
            }
            stack.push(i);
        }
        return times;
    }
}
