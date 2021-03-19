import java.util.Scanner;
import java.util.Stack;


/**
 * Representation of a Polish notation calculator
 */
public class PNCalculator {

  private Stack<Double> numerics;

  public PNCalculator() {
    this.numerics = new Stack<>();
  }

  /*
   *
   */
  public static boolean verificaParenteses(String infixa) {
    Scanner leitor = new Scanner(infixa);
    boolean equilibrada = true;
    Stack<String> pilha = new Stack<String>();
    String token = "";
    while (equilibrada && leitor.hasNext()) {
      token = leitor.next();
      if (token.equals("("))
        pilha.push(token);
      else if (token.equals(")")) {
        if (!pilha.isEmpty() && pilha.peek().equals("("))
          pilha.pop();
        else
          equilibrada = false;
      }
    }
    return (equilibrada && pilha.empty());
  }

  /*
   *
   */
  public String paraSufixa(String infixa) {

    Stack<String> pilha = new Stack<String>();
    StringBuilder sufixa = new StringBuilder();
    Scanner reader = new Scanner(infixa);
    String token = "";
    while (reader.hasNext()) {
      token = reader.next();
      if (!eOperador(token))
        sufixa.append(token + " ");

      else if (eOperador(token)) {
        while (temPreferencia(pilha.peek(), token) && !pilha.isEmpty()) {
          sufixa.append(pilha.pop() + " ");
        }
        pilha.push(token);
      } else if (token.equals("("))
        pilha.push(token);

      else if (token.equals(")")) {
        while (pilha.peek() != "(") {
          sufixa.append(pilha.pop() + " ");
        }
        pilha.pop();
      }
    }
    while (!pilha.isEmpty()) {
      sufixa.append(pilha.pop() + " ");
    }
    return sufixa.toString();
  }

  /*
   *
   */
  public void processaToken(String token) {

    if (!eOperador(token))
      numerics.push(Double.parseDouble(token));
    else {
      double a = numerics.peek();
      numerics.pop();
      double b = numerics.peek();
      numerics.pop();
      if (token.equals("+"))
        numerics.push(a + b);
      else if (token.equals("-"))
        numerics.push(a - b);
      else if (token.equals("*"))
        numerics.push(a * b);
      else if (token.equals("/"))
        numerics.push(a / b);
    }
  }

  public Double verResultado() {
    return (numerics.pop());
  }

  /*
   *
   */

  public static boolean eOperador(String frase) {
    return (frase.equals("+") || frase.equals("-") || frase.equals("*") || frase.equals("/"));
  }

  public static boolean temPreferencia(String o1, String o2) {
    return ((o1.equals("*") || o1.equals("/")) && (o2.equals("+") || (o2.equals("-"))));
  }
}