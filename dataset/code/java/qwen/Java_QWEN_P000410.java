import java.util.*;
public class Main {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        int n = sc.nextInt();
        List<String> products = new ArrayList<>();
        for(int i=0; i<n; i++) products.add(sc.next());
        String suffix = sc.next();
        for(String p : products) {
            if(p.endsWith(suffix)) System.out.println(p);
        }
    }
}
