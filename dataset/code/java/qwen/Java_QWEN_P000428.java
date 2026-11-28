import java.util.*;
public class Main {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        int n = sc.nextInt();
        List<String[]> events = new ArrayList<>();
        for(int i=0; i<n; i++) {
            String title = sc.next();
            String date = sc.next();
            events.add(new String[]{title, date});
        }
        String targetDate = sc.next();
        for(String[] e : events) {
            if(e[1].equals(targetDate)) System.out.println(e[0]);
        }
    }
}
