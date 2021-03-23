import java.util.*;
import java.util.stream.Collectors;


/**
 * A calculator that uses polish notation (prefix)
 * and reverse polish notation (suffix) to solve
 * infix algebraic expressions.
 */
public class PolishCalculator {

  private final String expression;

  // Supported operators
  private final static Set<Character> operators =
      new HashSet<>(Arrays.asList('+', '-', '*', '/', '%'));

  public PolishCalculator(String expression) {
    if (!validateInfixExpression(expression))
      throw new IllegalArgumentException("Invalid expression");

    this.expression = expression;
  }

  /**
   * Check whether the given character is an arithmetic operator
   *
   * @param c the character to check
   * @return true if is an operator, false otherwise
   */
  private static boolean isOperator(char c) {
    return operators.contains(c);
  }

  /**
   * Convert an infix expression into a suffix.
   * @return the suffix expression
   */
  public String infixToSuffix() {
    StringBuilder postfix = new StringBuilder();
    Stack<Character> operators = new Stack<>();

    for (char token : expression.toCharArray()) {
      // Stack the open bracket
      if (token == '(') {
        operators.push(token);
      }
      // Unstack operators until closing bracket is found
      else if (token == ')') {
        Character top;
        do {
          top = operators.pop();
          postfix.append(top);
        } while (top != '(');
      }
      // Unstack all operators that have prevalence over
      // operator under evaluation and stack it at last
      else if (isOperator(token)) {
        while (!operators.isEmpty()
            && isOperator(operators.peek())
            && hasPrecedence(operators.peek(), token)
        )
          postfix.append(operators.pop());
        operators.push(token);
      }
      // Append operand to result
      else {
        postfix.append(token);
      }
    }

    // Push remaining stack to the end result
    while (!operators.isEmpty())
      postfix.append(operators.pop());

    // Adding blank spaces in between characters for better visuals
    return postfix.toString().chars()
        .mapToObj(c -> (char) c + " ")
        .collect(Collectors.joining())
        .trim();
  }

  /**
   * Convert an infix expression into a prefix.
   * @return the prefix expression
   */
  public String infixToPrefix() {
    return new StringBuilder(infixToSuffix()).reverse().toString();
  }

  /**
   * Solve an algebraic expression.
   * Algorithm: 1) iterate over suffix expression.
   *            2) if element is operand, push to the stack
   *            3) if element is operator, perform operation
   *               over the 2 top elements of the stack and
   *               push result back to the stack.
   *            4) repeat steps 1 - 3 over all the expression
   *               and the final result is the top of the stack
   * @return the result
   */
  public double solve() {
    String suffix = infixToSuffix();
    Stack<Double> stack = new Stack<>();
    for (String element : suffix.split(" ")){
      if (isOperator(element.charAt(0))) {
        switch (element){
          case "+":
            stack.push(stack.pop() + stack.pop());
            break;
          case "-":
            stack.push(stack.pop() - stack.pop());
            break;
          case "*":
            stack.push(stack.pop() * stack.pop());
            break;
          case "/":
            stack.push(stack.pop() / stack.pop());
            break;
          case "%":
            stack.push(stack.pop() % stack.pop());
            break;
        }
      }  else
          stack.push(Double.valueOf(element));
    }
    return stack.pop();
  }

  /**
   * Check whether one operator has precedence over the other
   *
   * @param c1 the left operator
   * @param c2 the right operator
   * @return true if o1 has precedence over o2
   */
  private static boolean hasPrecedence(char c1, char c2) {
    if (!isOperator(c1) || !isOperator(c2))
      throw new IllegalArgumentException("Wrong operator provided.");

    return "*/%".indexOf(c1) >= 0 && "+-".indexOf(c2) >= 0;
  }

  /**
   * Validate an arithmetic expression.
   * Algorithm: split expression by operators and check if each
   * operand is valid and follows infix notation.
   *
   * @param expression the expression to validate.
   * @return true if expression is correct, false otherwise.
   */
  static boolean validateInfixExpression(String expression) {
    List<String> expressions;
    try {
      expressions = getBracketExpressions(expression);
    } catch (IllegalArgumentException e) {
      return false;
    }

    // Process single expression
    if (expressions.isEmpty()) {
      String regex = operators.stream()
          .map(op -> '\\' + op.toString())
          .collect(Collectors.joining());
      String[] operands = expression
          .split("[" + regex + "]");

      // In between an operator must always be an operand
      return operands.length > 1 && Arrays
          .stream(operands)
          .map(token -> {
            try {
              Double.parseDouble(token);
              return true;
            } catch (NumberFormatException e) {
              return false;
            }
          })
          .reduce(true, (elem1, elem2) -> elem1 & elem2);
    } else {
      // Bracket expressions must obey to single expression rules
      // and so it should its content
      return
          validateInfixExpression(
              expressions
                  .stream()
                  .reduce(expression, (elem1, elem2) -> expression
                      .replace('(' + elem1 + ')', "0")
                      .replace('(' + elem2 + ')', "0"))
          )
              &&
              expressions
                  .stream()
                  .map(PolishCalculator::validateInfixExpression)
                  .reduce(true, (elem1, elem2) -> elem1 & elem2);
    }
  }

  /**
   * Get round bracket expressions within an expression.
   *
   * @param expression the expression to check
   * @return list of bracket expressions
   */
  private static List<String> getBracketExpressions(String expression) {
    List<String> results = new ArrayList<>();

    int control = 0;
    StringBuilder partial = new StringBuilder();
    for (char c : expression.toCharArray()) {
      switch (c) {
        case '(':
          if (control++ == 0) partial.setLength(0);
          else partial.append(c);
          break;
        case ')':
          if (--control == 0) results.add(partial.toString());
          else partial.append(c);
          break;
        default:
          if (control > 0) partial.append(c);
          break;
      }
    }

    // Check if parenthesis are unbalanced
    if (control != 0)
      throw new IllegalArgumentException("Unbalanced expression");

    return results;
  }
}
