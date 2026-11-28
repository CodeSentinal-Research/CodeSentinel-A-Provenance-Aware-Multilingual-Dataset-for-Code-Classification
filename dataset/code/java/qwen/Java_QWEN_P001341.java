import java.util.*;
public class Main {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        int turnedOn = sc.nextInt();
        
        List<String> res = new ArrayList<>();
        for(int h=0; h<12; h++) {
            for(int m=0; m<60; m++) {
                if(Integer.bitCount(h) + Integer.bitCount(m) == turnedOn) {
                    res.add(String.format("%d:%02d", h, m));
                }
            }
        }
        
        for(String s : res) System.out.println(s);
    }
}
