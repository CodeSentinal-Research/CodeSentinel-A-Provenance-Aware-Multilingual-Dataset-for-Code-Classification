import java.util.*;
public class Main {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        int n = sc.nextInt();
        List<String[]> vehicles = new ArrayList<>();
        for(int i=0; i<n; i++) {
            String reg = sc.next();
            String maker = sc.next();
            vehicles.add(new String[]{reg, maker});
        }
        String searchMaker = sc.next();
        for(String[] v : vehicles) {
            if(v[1].equals(searchMaker)) System.out.println(v[0]);
        }
    }
}
