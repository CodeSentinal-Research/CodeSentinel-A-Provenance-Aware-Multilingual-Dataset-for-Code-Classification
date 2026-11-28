import java.util.Scanner;
import java.util.Stack;

public class Main {
    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        String serialization = scanner.nextLine();
        String[] nodes = serialization.split(",");

        System.out.println(isValidSerialization(nodes));
    }

    private static boolean isValidSerialization(String[] nodes) {
        Stack<String> stack = new Stack<>();
        for (String node : nodes) {
            while (node.equals("#") && !stack.isEmpty() && stack.peek().equals("#")) {
                stack.pop();
                if (stack.isEmpty()) {
                    return false;
                }
                stack.pop();
            }
            stack.push(node);
        }

        return stack.size() == 1 && stack.peek().equals("#");
    }
}
