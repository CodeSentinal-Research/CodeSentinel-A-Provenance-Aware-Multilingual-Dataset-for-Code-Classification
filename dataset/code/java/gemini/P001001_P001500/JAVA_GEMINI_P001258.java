import java.util.*;

public class Solution {
    public String removeDuplicateLetters(String s) {
        int[] last = new int[26];
        for (int i = 0; i < s.length(); i++) last[s.charAt(i) - 'a'] = i;

        boolean[] seen = new boolean[26];
        Stack<Character> stack = new Stack<>();

        for (int i = 0; i < s.length(); i++) {
            char c = s.charAt(i);
            if (!seen[c - 'a']) {
                // Maintain monotonic stack property by popping smaller elements
                while (!stack.isEmpty() && stack.peek() > c && i < last[stack.peek() - 'a']) {
                    seen[stack.pop() - 'a'] = false;
                }
                seen[c - 'a'] = true;
                stack.push(c);
            }
        }

        StringBuilder sb = new StringBuilder();
        for (char c : stack) sb.append(c);
        return sb.toString();
    }
}