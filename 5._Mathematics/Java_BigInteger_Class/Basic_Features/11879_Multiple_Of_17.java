import java.util.Scanner;
import java.math.BigInteger;


public class ProblemMult {
    static Scanner scanner = new Scanner(System.in);
    public static void main(String[] args) {
        while(scanner.hasNextBigInteger()){
            BigInteger n = scanner.nextBigInteger();
            if(n.toString()=="0"){
                break;
            }
            else if(n.mod(BigInteger.valueOf(17)).equals(BigInteger.ZERO)){
                System.out.println(1);
            }
            else{
                System.out.println(0);
            }
        }
    }
}