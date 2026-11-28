import java.util.*;
public class Main {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        String name = sc.nextLine();
        String typed = sc.nextLine();
        
        int i = 0, j = 0;
        while(j < typed.length()) {
            if(i < name.length() && name.charAt(i) == typed.charAt(j)) {
                i++;
            } else if(j == 0 || typed.charAt(j) != typed.charAt(j-1)) {
                System.out.println("NO");
                return;
            }
            j++;
        }
        System.out.println(i == name.length() ? "YES" : "NO");
    }
}
