import java.util.Scanner;
import java.util.Stack;

public class Main {
    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        String input = scanner.next();
        System.out.println(countCollisions(input));
    }

    private static int countCollisions(String directions) {
        Stack<Character> stack = new Stack<>();
        int count = 0;

        for (char direction : directions.toCharArray()) {
            if (direction == 'R') {
                stack.push(direction);
            } else if (direction == 'L') {
                if (!stack.isEmpty() && stack.peek() == 'R') {
                    stack.pop();
                    count += 2;
                } else {
                    stack.push(direction);
               }
            } else {
                while (!stack.isEmpty() && stack.peek() == 'R') {
                    stack.pop();
                    count++;
                }
            }
        }

        return count;
    }
}
