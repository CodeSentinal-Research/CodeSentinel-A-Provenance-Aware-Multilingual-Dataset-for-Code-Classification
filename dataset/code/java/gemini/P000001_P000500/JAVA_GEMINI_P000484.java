import java.util.*;
public class Solution {
    static String decodeString(String s) {
        Stack<String> strSt = new Stack<>();
        Stack<Integer> numSt = new Stack<>();
        StringBuilder currStr = new StringBuilder();
        int currNum = 0;
        for (char c : s.toCharArray()) {
            if (Character.isDigit(c)) {
                currNum = currNum * 10 + (c - '0');
            } else if (c == '[') {
                numSt.push(currNum);
                strSt.push(currStr.toString());
                currStr = new StringBuilder();
                currNum = 0;
            } else if (c == ']') {
                int k = numSt.pop();
                String prev = strSt.pop();
                StringBuilder temp = new StringBuilder(prev);
                for (int i = 0; i < k; i++) temp.append(currStr);
                currStr = temp;
            } else {
                currStr.append(c);
            }
        }
        return currStr.toString();
    }
    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        if (scanner.hasNext()) {
            System.out.println(decodeString(scanner.next()));
        }
    }
}