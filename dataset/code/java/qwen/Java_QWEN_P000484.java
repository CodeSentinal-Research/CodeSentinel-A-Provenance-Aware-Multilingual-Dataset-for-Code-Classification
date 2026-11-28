import java.util.*;
public class Main {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        String s = sc.next();
        Stack<Integer> counts = new Stack<>();
        Stack<StringBuilder> strings = new Stack<>();
        strings.push(new StringBuilder());
        
        int i = 0;
        while(i < s.length()) {
            char c = s.charAt(i);
            if(Character.isDigit(c)) {
                int num = 0;
                while(i < s.length() && Character.isDigit(s.charAt(i))) {
                    num = num * 10 + (s.charAt(i) - '0');
                    i++;
                }
                counts.push(num);
            } else if(c == '[') {
                strings.push(new StringBuilder());
                i++;
            } else if(c == ']') {
                StringBuilder str = strings.pop();
                int count = counts.pop();
                StringBuilder prev = strings.peek();
                for(int k=0; k<count; k++) prev.append(str);
                i++;
            } else {
                strings.peek().append(c);
                i++;
            }
        }
        System.out.println(strings.peek().toString());
    }
}
