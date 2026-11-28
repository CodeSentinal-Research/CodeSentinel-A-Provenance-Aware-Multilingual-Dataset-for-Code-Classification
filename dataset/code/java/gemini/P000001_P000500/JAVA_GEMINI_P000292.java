import java.util.Stack;

public class Solution {
    public String decodeString(String s) {
        Stack<String> strStack = new Stack<>();
        Stack<Integer> numStack = new Stack<>();
        StringBuilder curStr = new StringBuilder();
        int curNum = 0;

        for (char c : s.toCharArray()) {
            if (Character.isDigit(c)) {
                curNum = curNum * 10 + (c - '0');
            } else if (c == '[') {
                numStack.push(curNum);
                strStack.push(curStr.toString());
                curStr = new StringBuilder();
                curNum = 0;
            } else if (c == ']') {
                int k = numStack.pop();
                StringBuilder temp = new StringBuilder(strStack.pop());
                for (int i = 0; i < k; i++) temp.append(curStr);
                curStr = temp;
            } else {
                curStr.append(c);
            }
        }
        return curStr.toString();
    }
}