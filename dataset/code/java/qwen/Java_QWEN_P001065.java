import java.util.*;
public class Main {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        int n = sc.nextInt();
        int edges = 0;
        for(int i=0; i<n; i++) {
            int k = sc.nextInt();
            edges += k;
            for(int j=0; j<k; j++) sc.nextInt();
        }
        System.out.println(edges / 2);
    }
}
