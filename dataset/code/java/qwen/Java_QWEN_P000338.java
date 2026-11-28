import java.util.*;
public class Main {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        int n1 = sc.nextInt();
        String[] w1 = new String[n1];
        for(int i=0; i<n1; i++) w1[i] = sc.next();
        int n2 = sc.nextInt();
        String[] w2 = new String[n2];
        for(int i=0; i<n2; i++) w2[i] = sc.next();
        
        StringBuilder sb1 = new StringBuilder();
        for (String s : w1) sb1.append(s);
        StringBuilder sb2 = new StringBuilder();
        for (String s : w2) sb2.append(s);
        
        System.out.println(sb1.toString().equals(sb2.toString()) ? "Yes" : "No");
    }
}
