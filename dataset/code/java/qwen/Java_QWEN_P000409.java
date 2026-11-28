import java.util.*;
public class Main {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        int n = sc.nextInt();
        List<String> users = new ArrayList<>();
        for(int i=0; i<n; i++) users.add(sc.next());
        String prefix = sc.next();
        for(String u : users) {
            if(u.startsWith(prefix)) System.out.println(u);
        }
    }
}
