// package removed

import java.util.Stack;

/**
 * LeetCode 316: Remove Duplicate Letters
 * Given a string s, remove duplicate letters so that every letter appears once and only once.
 * You must make sure your result is the smallest in lexicographical order among all possible results.
 */
public class RemoveDuplicateLetters {

    public String removeDuplicateLetters(String s) {
        if (s == null || s.length() == 0) {
            return "";
        }
        
        // Count frequency of each character
        int[] count = new int[26];
        for (char c : s.toCharArray()) {
            count[c - 'a']++;
        }
        
        // Track if character is in stack
        boolean[] inStack = new boolean[26];
        
        Stack<Character> stack = new Stack<>();
        
        for (char c : s.toCharArray()) {
            count[c - 'a']--;
            
            // If already in stack, skip
            if (inStack[c - 'a']) {
                continue;
            }
            
            // Remove characters that are greater than current and still appear later
            while (!stack.isEmpty() && stack.peek() > c && count[stack.peek() - 'a'] > 0) {
                inStack[stack.pop() - 'a'] = false;
            }
            
            stack.push(c);
            inStack[c - 'a'] = true;
        }
        
        // Build result
        StringBuilder result = new StringBuilder();
        for (char c : stack) {
            result.append(c);
        }
        
        return result.toString();
    }

    public static void main(String[] args) {
        RemoveDuplicateLetters solution = new RemoveDuplicateLetters();
        
        // Test cases
        System.out.println("Remove duplicates from 'bcabc': " + 
            solution.removeDuplicateLetters("bcabc")); // "abc"
        System.out.println("Remove duplicates from 'cbacdcbc': " + 
            solution.removeDuplicateLetters("cbacdcbc")); // "acdb"
    }
}
