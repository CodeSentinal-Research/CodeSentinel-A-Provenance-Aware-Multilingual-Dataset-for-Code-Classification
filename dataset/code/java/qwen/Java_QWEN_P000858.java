import java.util.*;
public class Main {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        int n = sc.nextInt();
        int pos = 0;
        while(n > 0) {
            if((n & 1) == 1) { System.out.println(pos + 1); return; }
            pos++;
            n >>= 1;
        }
    }
}
