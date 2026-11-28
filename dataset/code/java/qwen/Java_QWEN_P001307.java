import java.util.*;
public class Main {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        int n = sc.nextInt();
        int k = sc.nextInt();
        String s = sc.next();
        
        List<Integer> police = new ArrayList<>();
        List<Integer> thieves = new ArrayList<>();
        
        for(int i=0; i<n; i++) {
            if(s.charAt(i) == 'P') police.add(i);
            else thieves.add(i);
        }
        
        int pIdx = 0;
        int tIdx = 0;
        int caught = 0;
        
        while(pIdx < police.size() && tIdx < thieves.size()) {
            if(Math.abs(police.get(pIdx) - thieves.get(tIdx)) <= k) {
                caught++;
                pIdx++;
                tIdx++;
            } else if(police.get(pIdx) < thieves.get(tIdx)) {
                pIdx++;
            } else {
                tIdx++;
            }
        }
        System.out.println(caught);
    }
}
