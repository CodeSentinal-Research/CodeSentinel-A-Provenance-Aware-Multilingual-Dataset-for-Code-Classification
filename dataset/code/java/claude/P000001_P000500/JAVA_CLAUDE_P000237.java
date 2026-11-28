import java.util.*;
public class Solution{
public static void main(String[] x){
Scanner sc=new Scanner(System.in);int r=sc.nextInt(),c=sc.nextInt(),k=sc.nextInt();k%=c;
for(int i=0;i<r;i++){int[]row=new int[c];for(int j=0;j<c;j++)row[j]=sc.nextInt();StringBuilder sb=new StringBuilder();for(int j=0;j<c;j++){if(j>0)sb.append(' ');sb.append(row[(j+k)%c]);}System.out.println(sb);}}}
