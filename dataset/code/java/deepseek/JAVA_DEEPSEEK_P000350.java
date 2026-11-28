import java.util.Stack;

public class Main {
    public static void main(String[] args) {
        String S = new java.util.Scanner(System.in).next();
        int K = new java.util.Scanner(System.in).nextInt();
        System.out.println(removeDuplicates(S, K));
    }

    public static String removeDuplicates(String S, int K) {
        Stack<Pair> stack = new Stack<>();
        for (char c : S.toCharArray()) {
            if (stack.isEmpty() || stack.peek().character != c) {
                stack.push(new Pair(c, 1));
            } else if (stack.peek().count + 1 == K) {
                stack.pop();
            } else {
                stack.peek().count++;
            }
        }
        StringBuilder sb = new StringBuilder();
        for (Pair pair : stack) {
            for (int i = 0; i < pair.count; i++) {
                sb.append(pair.character);
            }
        }
        return sb.toString();
    }

    static class Pair {
        char character;
        int count;

        Pair(char character, int count) {
            this.character = character;
            this.count = count;
        }
    }
}
