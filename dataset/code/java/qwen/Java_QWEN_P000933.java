import java.util.*;
public class Main {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        int n = sc.nextInt();
        boolean identity = true;
        for(int i=0; i<n; i++) {
            for(int j=0; j<n; j++) {
                int val = sc.nextInt();
                if(i == j && val != 1) identity = false;
                if(i != j && val != 0) identity = false;
            }
        }
        System.out.println(identity ? "true" : "false");
    }
}
