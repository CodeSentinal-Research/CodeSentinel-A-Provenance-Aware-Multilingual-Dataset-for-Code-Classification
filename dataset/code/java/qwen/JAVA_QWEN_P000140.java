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
        
        HashSet<Integer> unionSet = new HashSet<>(set1);
        unionSet.addAll(set2);
        
        ArrayList<Integer> unionList = new ArrayList<>(unionSet);
        Collections.sort(unionList);
        
        for (int i = 0; i < unionList.size(); i++) {
            if (i > 0) System.out.print(" ");
            System.out.print(unionList.get(i));
        }
        System.out.println();
    }
}
