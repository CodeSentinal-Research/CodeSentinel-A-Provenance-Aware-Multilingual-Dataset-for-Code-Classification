import java.util.*;
public class Solution{public static void main(String[]a){int n=new Scanner(System.in).nextInt();StringBuilder sb=new StringBuilder();while(n>0){n--;sb.insert(0,(char)('A'+n%26));n/=26;}System.out.println(sb);}}
