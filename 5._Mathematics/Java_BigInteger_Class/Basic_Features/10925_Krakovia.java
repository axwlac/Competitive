import java.util.Scanner;
import java.math.BigInteger;

public class Krakovia{
    static Scanner scanner = new Scanner(System.in);
    public static void main(String[] args) {
        int index=1;
        while(scanner.hasNextInt()){
            BigInteger res = BigInteger.ZERO;
            int n = scanner.nextInt();
            int f = scanner.nextInt();
            if(n==0 && f==0){break;}
            for(int i=0; i<n; ++i){
                BigInteger s = scanner.nextBigInteger();
                res = res.add(s);
            }
            BigInteger div = res.divide(BigInteger.valueOf(f));
            System.out.println("Bill #" + index++ + " costs " + res + ": each friend should pay " + div);
            System.out.println();
        }
    }
}