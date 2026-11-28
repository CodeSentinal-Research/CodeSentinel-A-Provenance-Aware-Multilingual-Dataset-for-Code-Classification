import java.util.*;
public class Main {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        String v1 = sc.nextLine();
        String v2 = sc.nextLine();
        
        String[] parts1 = v1.split("\\.");
        String[] parts2 = v2.split("\\.");
        int len = Math.max(parts1.length, parts2.length);
        
        for(int i=0; i<len; i++) {
            int n1 = i < parts1.length ? Integer.parseInt(parts1[i]) : 0;
            int n2 = i < parts2.length ? Integer.parseInt(parts2[i]) : 0;
            if(n1 < n2) { System.out.println(-1); return; }
            if(n1 > n2) { System.out.println(1); return; }
        }
        System.out.println(0);
    }
}
