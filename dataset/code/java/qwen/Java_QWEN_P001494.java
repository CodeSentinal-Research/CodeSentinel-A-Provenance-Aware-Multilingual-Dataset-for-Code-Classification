import java.util.*;
public class Main {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        String s = sc.nextLine();
        int n = s.length();
        int[] res = new int[n+1];
        
        int low = 0, high = n;
        for(int i=0; i<n; i++) {
            if(s.charAt(i) == 'I') {
                res[i] = low++;
            } else {
                res[i] = high--;
            }
        }
        res[n] = low;
        
        for(int x : res) System.out.print(x + " ");
    }
}
