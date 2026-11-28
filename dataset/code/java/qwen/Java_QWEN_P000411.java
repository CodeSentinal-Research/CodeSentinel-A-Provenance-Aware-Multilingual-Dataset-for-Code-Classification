import java.util.*;
public class Main {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        int n = sc.nextInt();
        sc.nextLine();
        List<String> records = new ArrayList<>();
        for(int i=0; i<n; i++) records.add(sc.nextLine());
        String keyword = sc.next();
        for(String r : records) {
            if(r.contains(keyword)) System.out.println(r);
        }
    }
}
