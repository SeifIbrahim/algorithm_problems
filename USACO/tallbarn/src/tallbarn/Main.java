package tallbarn;
/*
ID: seifibr1
LANG: JAVA
TASK: tallbarn
*/
import java.io.*;
import java.util.*;
import java.math.BigDecimal;

class Main {
  public static void main (String [] args) throws IOException {
    // Use BufferedReader rather than RandomAccessFile; it's much faster
    BufferedReader f = new BufferedReader(new FileReader("tallbarn.in"));
                                                  // input file name goes above
    PrintWriter out = new PrintWriter(new BufferedWriter(new FileWriter("tallbarn.out")));
    // Use StringTokenizer vs. readLine/split -- lots faster
    StringTokenizer st = new StringTokenizer(f.readLine());
						  // Get line, break into tokens
    int i1 = Integer.parseInt(st.nextToken());    // first integer
    int i2 = Integer.parseInt(st.nextToken());    // second integer
    BigDecimal [] array = new BigDecimal[100000];
    BigDecimal sum = BigDecimal.ZERO;
    for(int i = 0; i < i1; i++){
    	StringTokenizer str = new StringTokenizer(f.readLine());
    	array[i] = new BigDecimal(str.nextToken());
    	sum = sum.add(array[i]);
    }
    BigDecimal time = BigDecimal.ZERO;
    BigDecimal bigi2 = new BigDecimal(i2);
    BigDecimal average = sum.divide(bigi2, 10, 2);
    for(int i = 0; i < i1; i++){
    	BigDecimal roundup = array[i].divide(average,10,2).setScale(0, BigDecimal.ROUND_UP);
    	bigi2 = bigi2.subtract(roundup);
    	if(bigi2.compareTo(roundup) == -1)roundup = bigi2;
    	time = time.add(array[i].divide(roundup));
    }
    System.out.print(time.toString());
    out.println(time.toString());
    out.close();                                  // close the output file
  }
}