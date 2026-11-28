import java.util.Scanner;
import java.util.ArrayDeque;

public class Main {
    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        String num = scanner.next();
        int k = scanner.nextInt();
        System.out.println(removeKdigits(num, k));
    }

    public static String removeKdigits(String num, int k) {
        ArrayDeque<Character> stack = new ArrayDeque<>();
        
        for (char digit : num.toCharArray()) {
            while (!stack.isEmpty() && k > 0 && stack.peekLast() > digit) {
                stack.removeLast();
                k--;
            }
            stack.addLast(digit);
        }
        
        while (k > 0) {
            stack.removeLast();
            k--;
        }
        
        StringBuilder result = new StringBuilder();
        while (!stack.isEmpty()) {
            char digit = stack.removeFirst();
            if (result.length() != 0 || digit != '0') {
                result.append(digit);
            }
        }
        
        return result.length() == 0 ? "0" : result.toString();
    }
}
