import java.util.Stack;

class Parentheses {

public static void main(String[] args) {
        String[] tests = {
            "(()",
            ")()())",
            "",
        };

        for (String s : tests) {
            System.out.println("Input: \"" + s + "\"");
            System.out.println("Output: " + longestValidParentheses(s));
            System.out.println();
        }
    }
    
    public static int longestValidParentheses(String s) {
        Stack<Integer> st = new Stack<>();
        st.push(-1);

        int maxLen = 0;

        for (int i = 0; i < s.length(); i++) {
            
            if (s.charAt(i) == '(') {
                st.push(i);
            } else {
                st.pop();
                if (st.isEmpty()) {
                    st.push(i);
                } else {
                    maxLen = Math.max(maxLen, i - st.peek());
                }
            }
        }

        return maxLen;
    }
}