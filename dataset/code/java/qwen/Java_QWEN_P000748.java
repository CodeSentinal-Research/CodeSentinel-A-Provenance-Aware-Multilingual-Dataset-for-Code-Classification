import java.util.*;
public class Main {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        int target = sc.nextInt();
        diceSeq(target, new ArrayList<>());
    }
    static void diceSeq(int target, List<Integer> curr) {
        if(target == 0) {
            System.out.println(curr);
            return;
        }
        for(int i=1; i<=6; i++) {
            if(i <= target) {
                curr.add(i);
                diceSeq(target - i, curr);
                curr.remove(curr.size() - 1);
            }
        }
    }
}
