import java.util.Scanner;
import java.math.BigInteger;

public class IfWeWereAChildAgain {
    static Scanner scanner = new Scanner(System.in);
    public static void main(String[] args) {
        while(scanner.hasNextBigInteger()){
            BigInteger res;
            BigInteger n = scanner.nextBigInteger();
            String op = scanner.next();
            BigInteger m = scanner.nextBigInteger();

            if(op.equals("%")){
                res = n.mod(m);
                System.out.println(res);
            }
            else{
                res = n.divide(m);
                System.out.println(res);
            }
            
        }
    }
}