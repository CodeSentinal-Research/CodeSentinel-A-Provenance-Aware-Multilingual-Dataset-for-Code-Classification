import java.util.*;
public class Main {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        int n = sc.nextInt();
        String[] files = new String[n];
        for(int i=0; i<n; i++) files[i] = sc.next();
        String ext = sc.next();
        for(String f : files) {
            if(f.endsWith("." + ext)) System.out.println(f);
        }
    }
}
