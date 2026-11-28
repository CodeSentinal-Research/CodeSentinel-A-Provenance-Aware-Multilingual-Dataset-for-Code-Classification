import java.util.*;
public class Main {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        int n = sc.nextInt();
        List<String[]> accounts = new ArrayList<>();
        for(int i=0; i<n; i++) {
            String accNo = sc.next();
            int lastTx = sc.nextInt();
            accounts.add(new String[]{accNo, String.valueOf(lastTx)});
        }
        int months = sc.nextInt();
        for(String[] a : accounts) {
            if(Integer.parseInt(a[1]) > months) System.out.println(a[0]);
        }
    }
}
