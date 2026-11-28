import java.util.*;
public class Main {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        String s = sc.nextLine();
        
        long swaps = 0;
        int blackCount = 0;
        for(char c : s.toCharArray()) {
            if(c == '1') {
                swaps += blackCount;
            } else {
                blackCount++;
            }
        }
        System.out.println(swaps);
    }
}
