import java.util.*;
public class Main {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        String s = sc.next();
        String[] nodes = s.split(",");
        Stack<String> stack = new Stack<>();
        for(String node : nodes) {
            stack.push(node);
            while(stack.size() >= 3 && stack.get(stack.size()-2).equals("#") && stack.get(stack.size()-1).equals("#") && !stack.get(stack.size()-3).equals("#")) {
                stack.pop(); stack.pop(); stack.pop();
                stack.push("#");
            }
        }
        System.out.println(stack.size() == 1 && stack.peek().equals("#") ? "true" : "false");
    }
}
