import java.util.Scanner;


/**
 * The run class for PNCalculator
 */
public class RunPNCalculator {

  /**
   * Start the interactive program
   */
  public static void main(String[] args) {

    // The calculator
    PNCalculator calculator = new PNCalculator();

    // user input
    Scanner in = new Scanner(System.in);

    // start the user interaction with initial instructions
    System.out.println(
        "\n*** Welcome to the PNCalculator ***\n" +
            "A calculator that uses polish notation for calculations.\n"
    );

    System.out.println(PNCalculator.validateExpression("111++1"));


    int option;
    do {
      System.out.println();
      System.out.println(
          "Choose your option:\n" +
              "\t1) convert from infix to polish notation\n" +
              "\t2) use calculator\n" +
              "\t3) exit"
      );
      System.out.print("Your option [1-5]: ");
      option = in.nextInt();

      // validate user selection
      switch (option) {
        case 1:
          // read string input
          System.out.print("Expression: ");
          String expression = in.next();

          System.out.println(PNCalculator.validateExpression(expression));
          break;
        case 2:
          break;
        case 3:
          System.out.println();
          System.out.println("Bye.");
          break;
        default:
          System.out.println("Provide a valid option.");
      }
    } while (option != 3);
  }
}
