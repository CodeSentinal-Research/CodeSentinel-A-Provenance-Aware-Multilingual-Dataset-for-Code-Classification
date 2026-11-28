import java.util.*;
public class Main {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        String s = sc.next();
        int[] lastIdx = new int[26];
        for(int i=0; i<s.length(); i++) lastIdx[s.charAt(i)-'a'] = i;
        
        boolean[] visited = new boolean[26];
        Stack<Character> stack = new Stack<>();
        
        for(int i=0; i<s.length(); i++) {
            char c = s.charAt(i);
            if(visited[c-'a']) continue;
            while(!stack.isEmpty() && stack.peek() > c && lastIdx[stack.peek()-'a'] > i) {
                visited[stack.pop()-'a'] = false;
            }
            stack.push(c);
            visited[c-'a'] = true;
        }
        
        StringBuilder sb = new StringBuilder();
        for(char c : stack) sb.append(c);
        System.out.println(sb.toString());
    }
}
