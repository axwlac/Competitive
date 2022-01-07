import java.util.Scanner;
import java.math.BigInteger;

public class IntegerInquiry {
    static Scanner scanner = new Scanner(System.in);
    public static void main(String[] args) {
        BigInteger sum = BigInteger.ZERO;
        while(scanner.hasNextBigInteger()){
            BigInteger s = scanner.nextBigInteger();
            sum = sum.add(s);
        }
        System.out.println(sum);
    }
}