import java.util.*;
public class Main {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        int n = sc.nextInt();
        Set<String> sources = new HashSet<>();
        Set<String> dests = new HashSet<>();
        
        for(int i=0; i<n; i++) {
            String src = sc.next();
            String dst = sc.next();
            sources.add(src);
            dests.add(dst);
        }
        
        dests.removeAll(sources);
        System.out.println(dests.iterator().next());
    }
}
