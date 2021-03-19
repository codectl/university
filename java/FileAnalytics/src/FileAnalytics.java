import java.io.*;
import java.util.*;
import java.util.function.Function;
import java.util.stream.Collectors;


public class FileAnalytics {

  // the file content
  final String content;

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
   * Counting the number of words
   *
   * @return the count result
   */
  long wordCount() {
    String content = removePunctuation(this.content);
    return Arrays
        .stream(content.split("\\s+"))
        .count();
  }

  /**
   * Counting the number of occurrences of a word
   *
   * @param word the string to search by
   * @return the count result
   */
  long wordOccurrences(String word) {
    String content = removePunctuation(this.content);
    return Arrays
        .stream(content.split("\\s+"))
        .filter(str -> str.equals(word))
        .count();
  }

  /**
   * Counting the number of vowels
   *
   * @return the count result
   */
  long vowelsCount() {
    String content = removePunctuation(this.content);
    return Arrays
        .stream(content.split("\\s+"))
        .flatMap(str -> str.chars().mapToObj(
            ch -> (char) ch
        )).filter(ch -> "aeiou".indexOf(ch) >= 0)
        .count();
  }

  /**
   * Counting the number of consonants
   *
   * @return the count result
   */
  long consonantsCount() {
    String content = removePunctuation(this.content);
    return Arrays
        .stream(content.split("\\s+"))
        .flatMap(str -> str.chars().mapToObj(
            ch -> (char) ch
        )).filter(ch -> "aeiou".indexOf(ch) < 0)
        .count();
  }

  /**
   * Get the existing punctuation marks
   *
   * @return the set of punctuation marks
   */
  Set<Character> getPunctuationMarks() {
    return Arrays
        .stream(content.split("\\s+"))
        .flatMap(str -> str.chars().mapToObj(
            ch -> (char) ch
        )).filter(ch -> !Character.isLetterOrDigit(ch))
        .collect(Collectors.toSet());
  }

  /**
   * Get the set of repetitive words
   *
   * @return the set of repetitive words
   */
  Set<String> getRepetitiveWords() {
    List<String> words = Arrays.asList(content.split("\\s+"));
    return words
        .stream()
        .filter(word -> Collections.frequency(words, word) > 1)
        .collect(Collectors.toSet());
  }

  /**
   * Counting the number of occurrences of a char per word
   *
   * @param c the char to search by
   * @return the list of results
   */
  Map<Integer, Long> charOccurrencesPerWord(char c) {
    String content = removePunctuation(this.content);
    return Arrays
        .stream(content.split("\\s+"))
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
