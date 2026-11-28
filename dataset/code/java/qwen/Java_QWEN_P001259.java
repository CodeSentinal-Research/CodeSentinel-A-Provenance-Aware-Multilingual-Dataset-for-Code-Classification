import java.util.*;
public class Main {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        String s = sc.next();
        int swaps = 0, imbalance = 0;
        for(char c : s.toCharArray()) {
            if(c == '[') imbalance++;
            else {
                if(imbalance > 0) imbalance--;
                else {
                    swaps++;
                    imbalance = 1;
                }
            }
        }
        System.out.println(swaps);
    }
}
