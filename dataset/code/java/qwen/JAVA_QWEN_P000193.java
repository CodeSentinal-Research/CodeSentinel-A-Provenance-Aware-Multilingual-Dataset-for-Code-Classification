import java.util.Scanner;
import java.util.HashSet;
import java.util.ArrayList;
import java.util.Collections;

public class Main {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        int m = sc.nextInt();
        int n = sc.nextInt();
        
        HashSet<Integer> set1 = new HashSet<>();
        for (int i = 0; i < m; i++) set1.add(sc.nextInt());
        
        HashSet<Integer> set2 = new HashSet<>();
        for (int i = 0; i < n; i++) set2.add(sc.nextInt());
        
        HashSet<Integer> union = new HashSet<>(set1);
        union.addAll(set2);
        
        ArrayList<Integer> list = new ArrayList<>(union);
        Collections.sort(list);
        
        for (int i = 0; i < list.size(); i++) {
            if (i > 0) System.out.print(" ");
            System.out.print(list.get(i));
        }
        System.out.println();
    }
}
