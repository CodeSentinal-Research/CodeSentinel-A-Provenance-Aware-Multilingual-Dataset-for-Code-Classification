import java.util.*;
public class Main {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        String formula = sc.next();
        Map<String, Integer> map = parse(formula);
        TreeMap<String, Integer> sorted = new TreeMap<>(map);
        StringBuilder sb = new StringBuilder();
        for(Map.Entry<String, Integer> e : sorted.entrySet()) {
            sb.append(e.getKey());
            if(e.getValue() > 1) sb.append(e.getValue());
        }
        System.out.println(sb.toString());
    }
    static Map<String, Integer> parse(String s) {
        Map<String, Integer> map = new HashMap<>();
        Stack<Map<String, Integer>> stack = new Stack<>();
        stack.push(new HashMap<>());
        int i = 0;
        while(i < s.length()) {
            char c = s.charAt(i);
            if(c == '(') {
                stack.push(new HashMap<>());
                i++;
            } else if(c == ')') {
                Map<String, Integer> top = stack.pop();
                i++;
                int num = 0;
                while(i < s.length() && Character.isDigit(s.charAt(i))) {
                    num = num * 10 + (s.charAt(i) - '0');
                    i++;
                }
                if(num == 0) num = 1;
                Map<String, Integer> prev = stack.peek();
                for(Map.Entry<String, Integer> e : top.entrySet()) {
                    prev.put(e.getKey(), prev.getOrDefault(e.getKey(), 0) + e.getValue() * num);
                }
            } else if(Character.isUpperCase(c)) {
                int start = i++;
                while(i < s.length() && Character.isLowerCase(s.charAt(i))) i++;
                String atom = s.substring(start, i);
                int num = 0;
                while(i < s.length() && Character.isDigit(s.charAt(i))) {
                    num = num * 10 + (s.charAt(i) - '0');
                    i++;
                }
                if(num == 0) num = 1;
                Map<String, Integer> top = stack.peek();
                top.put(atom, top.getOrDefault(atom, 0) + num);
            }
        }
        return stack.pop();
    }
}
