import java.util.*;
public class Solution{
public static void main(String[] x){
Scanner sc=new Scanner(System.in);int r=sc.nextInt(),c=sc.nextInt();
int br=-1,bc=-1;
for(int i=0;i<r;i++){int cnt=0;for(int j=0;j<c;j++)cnt+=sc.nextInt();if(cnt>bc){bc=cnt;br=i;}}
System.out.println(br);}}
