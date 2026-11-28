import java.util.*;
public class Main {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        int n = sc.nextInt();
        if(n == 0) { System.out.println(32); return; }
        int count = 0;
        for(int i=31; i>=0; i--) {
            if(((n >> i) & 1) == 1) break;
            count++;
        }
        System.out.println(count);
    }
}
