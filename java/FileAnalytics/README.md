# FileAnalytics

An interactive program to provide insights over a
desired text document.

The program allows you to perform certain actions
on any given file:

	1) show file content
	2) count word occurrences
	3) count character occurrences per word
	4) additional information

For instance, given the option ```4```, for the
```sample.txt``` file provided as an example, the
result is:

    There are 69 words.
    There are 165 vowels.
    There are 204 consonants.
    There are 2 kinds of punctuation marks: [,, .]
    There are 4 repetitive words: [dolor, dolore, in, ut]

Run the program and try all the available actions.

## Requirements

The program requires ```Java 8``` version or latter.

## Execution example:

    *** Welcome to the FileAnalytics ***
    A tool that given a file, provides you with a
    serious of statistics of your choice.
    
    Start off by providing the file path you wish to process.
    If none is specified, a sample text is provided for you.
    
    Input your file to process.
    File [sample.txt]:

    Choose your option:
    1) show file content
    2) count word occurrences
    3) count character occurrences per word
    4) additional information
    5) exit

    Your option [1-5]: 2
    Word to search by: in
    
    There are 3 occurrences of word 'in'.

    Choose your option:
    1) show file content
    2) count word occurrences
    3) count character occurrences per word
    4) additional information
    5) exit
    Your option [1-5]: 3
    Character to search by: a
    
    There are 1 number of occurrences of 'a' in 19 words.
    There are 2 number of occurrences of 'a' in 5 words.
    
    Choose your option:
    1) show file content
    2) count word occurrences
    3) count character occurrences per word
    4) additional information
    5) exit
    Your option [1-5]: 5

    Bye.
