import java.util.*;
public class Main {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        String s = sc.next();
        long k = sc.nextLong();
        System.out.println(decodeAtIndex(s, k));
    }
    static char decodeAtIndex(String s, long k) {
        long size = 0;
        for(char c : s.toCharArray()) {
            if(Character.isDigit(c)) size *= (c - '0');
            else size++;
        }
        for(int i=s.length()-1; i>=0; i--) {
            char c = s.charAt(i);
            k %= size;
            if(k == 0 && Character.isLetter(c)) return c;
            if(Character.isDigit(c)) size /= (c - '0');
            else size--;
        }
        return ' ';
    }
}
