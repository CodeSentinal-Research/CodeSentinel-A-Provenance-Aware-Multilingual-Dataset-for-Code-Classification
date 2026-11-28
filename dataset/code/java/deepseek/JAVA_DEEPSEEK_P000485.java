import java.util.Stack;
import java.util.Scanner;

public class Main {
    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        int n = scanner.nextInt();
        int[] asteroids = new int[n];
        for (int i = 0; i < n; i++) {
            asteroids[i] = scanner.nextInt();
        }
        scanner.close();

        Stack<Integer> stack = new Stack<>();
        for (int asteroid : asteroids) {
            while (!stack.isEmpty() && asteroid < 0 && 0 < stack.peek()) {
                int diff = stack.peek() + asteroid;
                if (diff < 0) {
                    asteroid = stack.pop();
                } else if (diff == 0) {
                    stack.pop();
                    asteroid = 0;
                } else {
                    asteroid = 0;
                    break;
                }
            }
            if (asteroid != 0) {
                stack.push(asteroid);
            }
        }

        int[] result = new int[stack.size()];
        for (int i = result.length - 1; i >= 0; i--) {
            result[i] = stack.pop();
        }

        for (int asteroid : result) {
            System.out.println(asteroid);
        }
    }
}
