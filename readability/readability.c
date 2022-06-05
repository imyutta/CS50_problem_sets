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
    int letters_amount = count_letters(text);
    int words_amount = count_words(text);
    int sentences_amount = count_sentences(text);
    printf("%i letters\n%i words\n%i sentences\n", letters_amount, words_amount, sentences_amount);

    int l = (letters_amount / words_amount) * 100;
    int s = (sentences_amount / words_amount) * 100;

    float index = 0.0588 * l - 0.296 * s - 15.8;
    printf ("INDEX %f\n", index);
    int indexNew = round(index);
    printf ("INDEX %i\n", indexNew);


    if (indexNew >= 1 && indexNew <= 16)
    {
        printf("Grade %i\n", indexNew);
    }
    else if (indexNew < 1)
    {
        printf("Before grade 1");
    }
    else
    {
        printf("Grade 16+");
    }



}


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
    return count_letters;
}

int count_words(string text)
{
    int count_words = 0;
    for (int i = 0, n = strlen(text); i < n; i++)
    {
        int letterNumASCII = text[i];
        if (letterNumASCII == 32)
        {
            count_words += 1;
        }
    }

    if (count_words > 0)
    {
        return count_words += 1;
    }
    else
    {
        return count_words;
    }

}

int count_sentences(string text)
{
    int count_sentences = 0;
    for (int i = 0, n = strlen(text); i < n; i++)
    {
        int letterNumASCII = text[i];
        if (letterNumASCII == 33 || letterNumASCII == 46 || letterNumASCII == 63)
        {
            count_sentences +=1;
        }
    }
    return count_sentences;


}