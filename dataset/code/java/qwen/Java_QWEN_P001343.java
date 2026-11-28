import java.util.*;
public class Main {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        int n = sc.nextInt();
        generateGray(n, 0, 0);
    }
    
    static void generateGray(int n, int idx, int num) {
        if(idx == n) {
            System.out.println(num);
            return;
        }
        generateGray(n, idx+1, num);
        generateGray(n, idx+1, num ^ (1 << idx));
    }
}
