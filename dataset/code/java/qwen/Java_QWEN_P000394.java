import java.util.*;
public class Main {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        int n = sc.nextInt();
        List<String[]> products = new ArrayList<>();
        for(int i=0; i<n; i++) {
            String name = sc.next();
            String brand = sc.next();
            products.add(new String[]{name, brand});
        }
        String searchBrand = sc.next();
        for(String[] p : products) {
            if(p[1].equals(searchBrand)) System.out.println(p[0]);
        }
    }
}
