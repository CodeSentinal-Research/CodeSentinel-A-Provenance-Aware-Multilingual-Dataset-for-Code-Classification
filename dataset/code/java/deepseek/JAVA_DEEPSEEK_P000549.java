import java.util.LinkedList;
import java.util.Queue;
import java.util.Stack;

public class Main {
    public static void main(String[] args) {
        int[] input = {1, 2, 3, 4, 5};
        int[] output = {4, 5, 3, 2, 1};
        System.out.println(checkStackPermutation(input, output));
    }

    public static boolean checkStackPermutation(int[] input, int[] output) {
        Queue<Integer> queue = new LinkedList<>();
        Stack<Integer> stack = new Stack<>();

        for (int i : input) {
            queue.add(i);
        }

        int j = 0;
        while (!queue.isEmpty()) {
            stack.push(queue.poll());
            while (!stack.isEmpty() && stack.peek() == output[j]) {
                stack.pop();
                j++;
            }
        }

        while (!stack.isEmpty()) {
            if (stack.pop() != output[j++]) {
                return false;
            }
        }

        return true;
    }
}
