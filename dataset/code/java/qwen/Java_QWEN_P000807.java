import java.util.*;
public class Main {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        String s = sc.next();
        
        Map<Integer, Integer> map = new HashMap<>();
        map.put(0, 1);
        int balance = 0, count = 0;
        String vowels = "aeiou";
        for(char c : s.toCharArray()) {
            balance += (vowels.indexOf(c) != -1 ? 1 : -1);
            count += map.getOrDefault(balance, 0);
            map.put(balance, map.getOrDefault(balance, 0) + 1);
        }
        System.out.println(count);
    }
}
