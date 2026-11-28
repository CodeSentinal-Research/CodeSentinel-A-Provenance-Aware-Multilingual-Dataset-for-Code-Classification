import java.util.*;
public class Main {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        int n = sc.nextInt();
        Map<String, String> map = new HashMap<>();
        for(int i=0; i<n; i++) {
            String reg = sc.next();
            String model = sc.next();
            map.put(reg, model);
        }
        String searchReg = sc.next();
        if(map.containsKey(searchReg)) System.out.println(map.get(searchReg));
        else System.out.println("Vehicle Not Found");
    }
}
