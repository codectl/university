import java.util.Arrays;

public class MatrixOps {

  /**
   * Devolve a matriz transposta de uma matriz dada
   *
   * @param matriz a matria a transpor
   * @return a matriz transposta
   * @requires eMatriz()
   */
  public static int[][] transpoe(int[][] matriz) {
    int[][] matrizTransposta = new int[matriz[0].length][matriz.length];
    for (int i = 0; i < matriz.length; i++)
      for (int j = 0; j < matriz[0].length; j++)
        matrizTransposta[j][i] = matriz[i][j];

    return matrizTransposta;
  }

  /**
   * Devolve o maior inteiro da linha linha da matriz dada
   *
   * @param matriz a matriz da qual calcula o maior inteiro
   * @param linha  a linha da matriz a procurar
   * @return o maior inteiro
   * @require eMatriz()
   */
  public static int calculaMaxLinha(int[][] matriz, int linha) {
    int linhaMax = matriz[linha][0];
    for (int i = 0; i < matriz[linha].length; i++) {
      if (linhaMax < matriz[linha][i])
        linhaMax = matriz[linha][i];
    }


    return linhaMax;
  }

  /**
   * Devolve um array com os maximos de cada linha
   *
   * @param matriz a matriz da qual calcula os maximos de cada linha
   * @return vector com os maximos de cada linha
   * @requires eMatriz()
   */
  public static int[] calculaMaxTodasLinhas(int[][] matriz) {
    int[] maxTodasLinhas = new int[matriz.length];
    for (int i = 0; i < matriz.length; i++)
      maxTodasLinhas[i] = calculaMaxLinha(matriz, i);

    return maxTodasLinhas;

  }

  /**
   * Devolve a matriz soma de duas matrizes dadas
   *
   * @param matriz1 uma das matrizes a somar
   * @param matriz2 outra das matrizes a somar
   * @return matriz com a soma das duas matrizes
   * @requires eMatriz()
   */
  public static int[][] matrizSoma(int[][] matriz1, int[][] matriz2) {
    int[][] somaMatriz = new int[matriz1.length][matriz1[0].length];
    for (int i = 0; i < somaMatriz.length; i++)
      for (int j = 0; j < somaMatriz[0].length; j++)
        somaMatriz[i][j] = matriz1[i][j] + matriz2[i][j];

    return somaMatriz;

  }

  /**
   * Devolve a matriz que se obtem multiplicando um numero inteiro por cada
   * elemento da matriz
   *
   * @param matriz  a matriz a multiplicar
   * @param escalar o inteiro a multiplicar
   * @return matriz com a multiplicacao
   * @requires eMatriz()
   */
  public static int[][] multiplicaEscalar(int[][] matriz, int escalar) {
    int[][] multiplicaEscalar = new int[matriz.length][matriz[0].length];
    for (int i = 0; i < multiplicaEscalar.length; i++)
      for (int j = 0; j < multiplicaEscalar[0].length; j++)
        multiplicaEscalar[i][j] = matriz[i][j] * escalar;

    return multiplicaEscalar;
  }

  /**
   * Checks whether the bi dimensional array is a matrix
   *
   * @param matrix the matrix to check
   * @return true if is matrix, false otherwise
   */
  public static boolean isMatrix(int[][] matrix) {
    return Arrays.stream(matrix)
        .map(e -> e.length)
        .distinct()
        .limit(2)  // optimization
        .count() == 1;
  }
}