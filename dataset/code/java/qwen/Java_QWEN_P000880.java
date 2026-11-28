import java.util.*;
public class Main {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        int x = sc.nextInt();
        if(x < 0) { System.out.println("false"); return; }
        
        int rev = 0, orig = x;
        while(x != 0) {
            if(rev > Integer.MAX_VALUE / 10) { System.out.println("false"); return; }
            rev = rev * 10 + x % 10;
            x /= 10;
        }
        System.out.println(rev == orig ? "true" : "false");
    }
}
