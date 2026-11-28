import java.util.*;
public class Main {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        int q = sc.nextInt();
        TreeSet<Integer> set = new TreeSet<>();
        for(int i=1; i<=200000; i++) set.add(i);
        
        for(int i=0; i<q; i++) {
            String op = sc.next();
            if(op.equals("popSmallest")) {
                int val = set.pollFirst();
                System.out.println(val);
            } else if(op.equals("addBack")) {
                set.add(sc.nextInt());
            }
        }
    }
}
