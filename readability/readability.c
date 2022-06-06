#include <cs50.h>
#include <stdio.h>
#include <string.h>
#include <math.h>

int count_letters(string text);
int count_words(string text);
int count_sentences(string text);

int main(void)
{
    //promt the user for a text
    string text = get_string("Text: ");

    //count the number of letters, words, sentences
    float letters_amount = count_letters(text);
    float words_amount = count_words(text);
    float sentences_amount = count_sentences(text);
    printf("%f - letters_F.\n", letters_amount);

    //%f words\n%f sentences\n
    //words_amount, sentences_amount

    //average number of letters per 100 words in text
    float l = (letters_amount / words_amount) * 100;
    //average number of sentences per 100 words in text
    float s = (sentences_amount / words_amount) * 100;

    //Coleman-Liau index
    float index = 0.0588 * l - 0.296 * s - 15.8;
    int indexNew = round(index);
    //printf ("INDEX %i\n", indexNew);


    if (indexNew >= 1 && indexNew < 16)
    {
        printf("Grade %i\n", indexNew);
    }
    else if (indexNew < 1)
    {
        printf("Before Grade 1\n");
    }
    else
    {
        printf("Grade 16+\n");
    }
}

//counting letters in text
int count_letters(string text)
{
    int count_letters = 0;

    for (int i = 0, n = strlen(text); i < n; i++)
    {
        int letterNumASCII = text[i];
        if ((letterNumASCII >= 65 && letterNumASCII <= 90) || (letterNumASCII >= 97 && letterNumASCII <= 122))
        {
            count_letters += 1;
        }
    }
    printf("%i - LETTERS_I.",count_letters);
    return count_letters;
}

//counting words in text
int count_words(string text)
{
    int count_words = 1;
    int space_ASCII = 32;
    for (int i = 0, n = strlen(text); i < n; i++)
    {
        if (text[i] == space_ASCII)
        {
            count_words += 1;
        }
    }

    return count_words;
}

//counting sentences in text
int count_sentences(string text)
{
    int count_sentences = 0;
    for (int i = 0, n = strlen(text); i < n; i++)
    {
        int letterNumASCII = text[i];
        // . || ? || !
        if (letterNumASCII == 33 || letterNumASCII == 46 || letterNumASCII == 63)
        {
            count_sentences += 1;
        }
    }
    return count_sentences;


}