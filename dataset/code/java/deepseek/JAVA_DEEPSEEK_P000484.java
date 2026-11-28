import java.util.*;

public class Main {
    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        String encoded = scanner.next();
        System.out.println(decodeString(encoded));
    }

    public static String decodeString(String s) {
        Stack<StringBuilder> stringStack = new Stack<>();
        Stack<Integer> numStack = new Stack<>();
        StringBuilder res = new StringBuilder();
        int num = 0;
        for (char ch : s.toCharArray()) {
            if (Character.isDigit(ch)) {
                num = num * 10 + ch - '0';
            } else if (ch == '[') {
                numStack.push(num);
                stringStack.push(res);
                res = new StringBuilder();
                num = 0;
            } else if (ch == ']') {
                StringBuilder temp = new StringBuilder();
                int repeat = numStack.pop();
                for (int i = 0; i < repeat; i++) {
                    temp.append(res);
                }
                res = stringStack.pop().append(temp);
            } else {
                res.append(ch);
            }
        }
        return res.toString();
    }
}
