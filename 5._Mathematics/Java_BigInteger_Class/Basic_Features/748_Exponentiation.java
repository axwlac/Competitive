import java.util.Scanner;
import java.math.BigDecimal;
import java.text.DecimalFormat;

public class Exponentiation {

    static Scanner scanner = new Scanner(System.in);
    public static void main(String[] args) {
        while(scanner.hasNextBigDecimal()){
            BigDecimal res = BigDecimal.ONE;
            BigDecimal r = scanner.nextBigDecimal();
            int n = scanner.nextInt();
            for(int i=1; i<=n; i++){
                res = res.multiply(r);
            }
            res = res.stripTrailingZeros();
            if(res.compareTo(BigDecimal.ONE)<=0){
                String s = res.toPlainString();
                System.out.println(s.substring(s.indexOf("0.")+1));
            }
            else{
                System.out.println(res.toPlainString());
            }
        }
    }
}