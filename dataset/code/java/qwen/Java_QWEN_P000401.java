import java.util.*;
public class Main {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        int n = sc.nextInt();
        List<String[]> products = new ArrayList<>();
        for(int i=0; i<n; i++) {
            String name = sc.next();
            int qty = sc.nextInt();
            products.add(new String[]{name, String.valueOf(qty)});
        }
        int threshold = sc.nextInt();
        for(String[] p : products) {
            if(Integer.parseInt(p[1]) < threshold) System.out.println(p[0]);
        }
    }
}
