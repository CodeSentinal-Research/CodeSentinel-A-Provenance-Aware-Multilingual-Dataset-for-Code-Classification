import java.util.*;
public class Main {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        int n = sc.nextInt();
        int k = sc.nextInt();
        
        List<Integer> people = new ArrayList<>();
        for(int i=1; i<=n; i++) people.add(i);
        
        int idx = 0;
        while(people.size() > 1) {
            idx = (idx + k - 1) % people.size();
            people.remove(idx);
        }
        System.out.println(people.get(0));
    }
}
