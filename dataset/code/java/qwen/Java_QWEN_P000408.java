import java.util.*;
public class Main {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        int n = sc.nextInt();
        List<String> emails = new ArrayList<>();
        for(int i=0; i<n; i++) emails.add(sc.next());
        String domain = sc.next();
        for(String e : emails) {
            if(e.endsWith("@" + domain)) System.out.println(e);
        }
    }
}
