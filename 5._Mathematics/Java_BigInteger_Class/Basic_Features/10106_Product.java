import java.util.Scanner;
import java.math.BigInteger;

class Product {

    static Scanner scanner = new Scanner(System.in);
    public static void main(String[] args) {
        while (scanner.hasNextBigInteger()){
            BigInteger a = scanner.nextBigInteger();
            BigInteger b = scanner.nextBigInteger();
            System.out.println(a.multiply(b));
        }
        // System.out.println("\n");
    }
}
