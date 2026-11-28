import java.util.Scanner;
import java.util.Stack;

public class Main {
    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        int n = scanner.nextInt();
        scanner.nextLine();
        Stack<String> stack = new Stack<>();
        for (int i = 0; i < n; i++) {
            String operation = scanner.nextLine();
            if (operation.equals("../") && !stack.isEmpty()) {
                stack.pop();
            } else if (!operation.equals("./") && !operation.equals("../")) {
                stack.push(operation.substring(0, operation.length() - 1));
            }
        }
        System.out.println(stack.size());
    }
}
