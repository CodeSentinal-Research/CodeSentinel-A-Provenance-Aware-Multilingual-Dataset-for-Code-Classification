import java.util.*;
public class Main {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        String s = sc.next();
        Stack<Character> stack = new Stack<>();
        Map<Character, Character> map = new HashMap<>();
        map.put(')', '(');
        map.put('}', '{');
        map.put(']', '[');
        
        for(char c : s.toCharArray()) {
            if(!map.containsKey(c)) stack.push(c);
            else if(stack.isEmpty() || stack.pop() != map.get(c)) {
                System.out.println("false"); return;
            }
        }
        System.out.println(stack.isEmpty() ? "true" : "false");
    }
}
