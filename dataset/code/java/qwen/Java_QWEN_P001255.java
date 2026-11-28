import java.util.*;
public class Main {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        String s = sc.next();
        int open = 0, close = 0;
        for(char c : s.toCharArray()) {
            if(c == '(') open++;
            else {
                if(open > 0) open--;
                else close++;
            }
        }
        System.out.println(open + close);
    }
}
