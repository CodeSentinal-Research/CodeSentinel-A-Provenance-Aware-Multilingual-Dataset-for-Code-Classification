import java.util.*;
public class Main {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        String s = sc.next();
        Stack<Character> stack = new Stack<>();
        int[] match = new int[s.length()];
        Arrays.fill(match, -1);
        for(int i=0; i<s.length(); i++) {
            if(s.charAt(i) == '(') stack.push(i);
            else if(!stack.isEmpty()) {
                match[stack.pop()] = i;
            }
        }
        StringBuilder sb = new StringBuilder();
        for(int i=0; i<s.length(); i++) {
            if(s.charAt(i) != '(' && s.charAt(i) != ')') sb.append(s.charAt(i));
            else if(match[i] != -1 || (i > 0 && match[i-1] == i)) continue; 
            // Simplified logic for reverse inside parens
        }
        // Correct approach for Reverse Substrings Between Parentheses
        Stack<Integer> openStack = new Stack<>();
        char[] chars = s.toCharArray();
        for(int i=0; i<chars.length; i++) {
            if(chars[i] == '(') openStack.push(i);
            else if(chars[i] == ')') {
                int start = openStack.pop();
                reverse(chars, start + 1, i - 1);
            }
        }
        StringBuilder res = new StringBuilder();
        for(char c : chars) if(c != '(' && c != ')') res.append(c);
        System.out.println(res.toString());
    }
    static void reverse(char[] arr, int l, int r) {
        while(l < r) {
            char t = arr[l]; arr[l++] = arr[r]; arr[r--] = t;
        }
    }
}
