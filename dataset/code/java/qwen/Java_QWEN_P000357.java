import java.util.*;
public class Main {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        String s = sc.next();
        char c = sc.next().charAt(0);
        int count = 0;
        for(char ch : s.toCharArray()) if(ch == c) count++;
        System.out.println(count);
    }
}
