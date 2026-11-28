import java.util.*;
public class Main {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        int low = sc.nextInt();
        int high = sc.nextInt();
        
        List<Integer> res = new ArrayList<>();
        for(int len=2; len<=9; len++) {
            for(int start=1; start<=9; start++) {
                long num = start;
                boolean valid = true;
                for(int i=1; i<len; i++) {
                    int next = (int)(num % 10) + 1;
                    if(next > 9) { valid = false; break; }
                    num = num * 10 + next;
                }
                if(valid && num >= low && num <= high) res.add((int)num);
            }
        }
        Collections.sort(res);
        for(int x : res) System.out.print(x + " ");
    }
}
