import java.util.Stack;
import java.util.Scanner;

public class Main {
    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        int n = scanner.nextInt();
        scanner.nextLine();

        Stack<Integer> stack = new Stack<>();

        for (int i = 0; i < n; i++) {
            String operation = scanner.nextLine();

            if (operation.equals("+")) {
                int top = stack.pop();
                int newScore = top + stack.peek();
                stack.push(top);
                stack.push(newScore);
            } else if (operation.equals("D")) {
                stack.push(2 * stack.peek());
           } else if (operation.equals("C")) {
                stack.pop();
            } else {
                stack.push(Integer.parseInt(operation));
            }
        }

        int totalScore = 0;
        while (!stack.isEmpty()) {
            totalScore += stack.pop();
        }

        System.out.println(totalScore);
    }
}
