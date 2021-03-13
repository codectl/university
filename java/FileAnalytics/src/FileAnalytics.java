import java.io.*;
import java.util.*;
import java.util.function.Function;
import java.util.stream.Collectors;


public class FileAnalytics {

  private final String content;

  public static void main(String[] args) throws IOException {

    File sample = new File(System.getProperty("user.dir"), "resources/sample.txt");
    FileAnalytics processor = new FileAnalytics(sample);

    // Start off the program
    start();
  }

  /**
   * Start the interactive program
   */
  private static void start() throws IOException {

    // user input
    Scanner in = new Scanner(System.in);

    // start the user interaction with initial instructions
    System.out.println(
        "\n*** Welcome to the FileAnalytics ***\n" +
            "A tool that given a file, provides you with a\n" +
            "serious of statistics of your choice.\n\n" +
            "Start off by providing the file path you wish to process.\n" +
            "If none is specified, a sample text is provided for you.\n"
    );

    // location for the sample file
    File sample = new File(System.getProperty("user.dir"), "resources/sample.txt");
    File file;

    // get input file
    System.out.println("Input your file to process.");
    System.out.printf("File [%s]: ", sample.getName());

    // reading file name
    String filename = in.nextLine();
    file = filename.isEmpty() ? sample : new File(filename);

    // the processor object
    FileAnalytics processor = new FileAnalytics(file);

    int option = 0;
    do {
      System.out.println(
          "Choose your option:\n" +
              "\t1) count word occurrences\n" +
              "\t2) count character occurrences per word\n" +
              "\t3) exit"
      );
      System.out.print("Your option [1-3]: ");
      option = in.nextInt();

      // validate user selection
      switch (option) {
        case 1:
          break;
        case 2:
          // read char input
          System.out.print("Character to search by: ");
          char ch = in.next().charAt(0);

          // count char occurrences
          Map<Integer, Long> occurs = processor.charOccurrencesPerWord(ch);
          if (occurs.isEmpty())
            System.out.printf("There are no occurrences of '%c'.\n", ch);
          else
            occurs.forEach((key, value) -> System.out.printf(
                "There are %d number of occurrences of '%c' in %d words.\n",
                key, ch, value
            ));
          break;
        case 3:
          break;
        default:
          System.out.println("Provide a valid option.");
      }
    } while (option != 3);

    System.out.println("Bye.");
  }

  /**
   * Constructor
   *
   * @param file the file to read
   */
  public FileAnalytics(File file) throws IOException {
    Scanner reader = new Scanner(new FileReader(file));
    StringBuilder content = new StringBuilder();

    while (reader.hasNext()) {
      content.append(reader.nextLine());
      content.append('\n');
    }
    reader.close();

    // save file content
    this.content = content.toString();
  }

  /**
   * Counting the number of occurrences of a char per word
   * @param c the char to search by
   * @return the list of results
   */
  private Map<Integer, Long> charOccurrencesPerWord(char c){
    return Arrays
            .stream(this.content.split("\\s+"))
            .map(str -> str.chars().mapToObj(
                ch -> (char) ch
            ).filter(ch -> ch == c))
            .map(stream -> stream.toArray().length)
            .filter(size -> size > 0)
            .collect(
                Collectors.groupingBy(
                    Function.identity(),
                    Collectors.counting()
                )
            );
  }

  /**
   * Conta o numero de ocorrencias de C(letra seleccionada) num texto
   *
   * @param c a letra a procurar
   */
//  public int[] quantasOcorrencias(char c) {
//
//    int[] quantasOcorrencias = new int[6]; //Vector que conta quantas ocorrencias existem do char c
//    int i = 0;
//    int j = 0;
//    int ocorrencias = 0;
//    c = Character.toUpperCase(c);
//
//    // Ciclo que verifica para cada palavra na posicao vecT[i] o numero de vezes que c ocorre
//    while (i < vecT.length) {
//      while (j < vecT[i].length()) {
//        if (vecT[i].charAt(j) == c)
//          ocorrencias++;
//        j++;
//      }
//      j = 0;
//      // No caso de haver alguma palavra com mais de 5 ocorrencias de c,
//      // incrementa na posição 5
//      if (ocorrencias >= 5)
//        quantasOcorrencias[5]++;
//
//      else
//        quantasOcorrencias[ocorrencias]++;
//      ocorrencias = 0;
//      i++;
//    }
//    return quantasOcorrencias;
//  }


  /**
   * Conta o numero de palavras iniciadas por C e devolve as mesmas palavras
   *
   * @param c        a letra a procurar
   * @param ficheiro o ficheiro a gravar
   */

//  public void listaPalavras(char c, String ficheiro) throws IOException {
//
//    BufferedWriter writer = new BufferedWriter(new FileWriter(ficheiro));
//    c = Character.toUpperCase(c);
//    int posicaoVector = 0;
//    int repeticoes = 0;
//    //Verifica quantas palavras comecam por c
//    for (int i = 0; i < vecT.length; i++) {
//      if (vecT[i].charAt(0) == c)
//        repeticoes++;
//    }
//
//    String[] palavras = new String[repeticoes]; //Vector que contém as palavras começadas por c
//    int[] palavrasIguais = new int[repeticoes]; //Vector que contem as palavras começadas por c iguais
//    String[] fim = new String[repeticoes]; //String com o tamanho do numero de palavras iniciadas por c
//    int posicaoFinal = -1;
//
//    //Verifica as palavras começadas por c e em caso de encontrar
//    //Escreve a palavra na String palavras
//    for (int i = 0; i < vecT.length; i++) {
//      if (vecT[i].charAt(0) == c) {
//        palavras[posicaoVector] = vecT[i];
//        posicaoVector++;
//      }
//    }
//
//    //Coloca no Vector final as palavras iniciadas por c sem repetições
//    for (int i = 0; i < palavras.length; i++) {
//      if (jaExiste(palavras[i], fim)) {
//        //No caso de a palavra ser repetida, enquanto nao encontra a palavra no vector final
//        // incrementa. Quando encontra incrementa no vector palavrasIguais o numero de palavras iguais
//        int j = 0;
//        while (!fim[j].equals(palavras[i])) {
//          j++;
//        }
//        palavrasIguais[j]++;
//      }
//
//      //No caso de a palavra não ser repetida
//      else {
//        posicaoFinal++;
//        fim[posicaoFinal] = palavras[i];
//        palavrasIguais[posicaoFinal]++;
//
//      }
//    }
//    //Escreve as palavras do Vector final no ficheiro
//    for (int v = 0; v < palavrasIguais.length; v++)
//      if (fim[v] != null) {
//        writer.write(fim[v] + " " + palavrasIguais[v]);
//        writer.newLine();
//      }
//    writer.close();
//  }


//  private boolean jaExiste(String palavra, String[] fim) {
//    boolean jaExiste = false;
//    int i = 0;
//    while (!jaExiste && i < fim.length && fim[i] != null) {
//      if (fim[i].equals(palavra))
//        jaExiste = true;
//      i++;
//    }
//    return jaExiste;
//  }


  /**
   * Remove all punctuation from a text.
   *
   * @param text the text to read from
   * @return the converted text
   */
  private static String removePunctuation(String text) {
    if (text == null) {
      return null;
    }

    return text.replaceAll("[^a-zA-Z \n]", "");
  }
}
