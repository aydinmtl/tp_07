#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

#define STRLEN 100

/*
 * Renvoie true si str1 et str2 sont identiques, false sinon.
 *
 * Exemple : is_equal("abc", "abc") -> true
 *           is_equal("abc", "abd") -> false
 *           is_equal("ab",  "abc") -> false
 */
bool is_equal(char str1[], char str2[])
{
    // TODO
    //   - comparer les longueurs avec strlen
    //   - comparer caractère par caractère
    size_t boyut1 = strlen(str1);
    size_t boyut2 = strlen(str2);

    if (boyut1 != boyut2)
    {
        return false;
    }

    for (size_t i = 0; i < boyut1; i++)
    {
        if (str1[i] != str2[i])
        {
            return false;
        }
    }
    return true;
}

/*
 * Trie str sur place, par ordre croissant, sans toucher au \0 final.
 *
 * Utilisez le tri par sélection :
 *   pour i de 0 à strlen(str) - 2 :
 *     trouver l'indice du plus petit caractère entre i et la fin
 *     échanger str[i] avec ce caractère
 *
 * Exemple : sort("cba") transforme la chaîne en "abc"
 */
void sort(char str[])
{
    int boyut = strlen(str);
    char temp; // ya da int temp=0;
    for (int i = 0; i < boyut - 1; i++)
    {
        int imin = i;
        for (int j = i + 1; j < boyut; j++)
        {
            if (str[j] < str[imin])
            {
                imin = j;
            }
        }
        temp = str[i];
        str[i] = str[imin];
        str[imin] = temp;
    }

    /* tri par selection olmadan sıralama yaptim
    int temp=0;
    for(int i=0; i<boyut; i++)
    {
        for(int j=1+i; j<boyut; j++)
        {
            if(str[i]>str[j])
            {
                temp=str[i];
                str[i]=str[j];
                str[j]=temp;
            }
        }
    }
    */
}

/*
 * Renvoie true si str1 et str2 sont des anagrammes, false sinon.
 *
 * Principe : trier les deux chaînes, puis comparer.
 *
 * Attention : cette fonction modifie str1 et str2.
 *
 * Exemple : is_anagram("imaginer", "migraine") -> true
 *           is_anagram("salut", "salu")        -> false
 */
bool is_anagram(char str1[], char str2[])
{
    sort(str1);
    sort(str2);

    return is_equal(str1, str2);
}

/*
 * Recopie str1 dans str2 en inversant l'ordre des caractères.
 * str2 doit être assez grand, et le \0 final doit être écrit.
 *
 * Exemple : revert("abc", dst) écrit "cba" dans dst.
 */
void revert(char str1[], char str2[])
{
    int boyut = strlen(str1);

    for (int i = 0; i < boyut; i++)
    {
        str2[i] = str1[boyut - 1 - i];
    }
    str2[boyut] = '\0';
}

/*
 * Renvoie true si str est un palindrome, false sinon.
 *
 * Principe : inverser str dans un tampon, puis comparer.
 *
 * Exemple : is_palindrome("kayak") -> true
 *           is_palindrome("salut") -> false
 */
bool is_palindrome(char str[])
{
    char strTers[STRLEN];

    revert(str, strTers);

    return is_equal(str, strTers);
}

/*
 * Affiche si word est un palindrome.
 */
void test_palindrome(char word[])
{
    if (is_palindrome(word))
    {
        printf("%s est un palindrome\n", word);
    }
    else
    {
        printf("%s n'est pas un palindrome\n", word);
    }
}

/*
 * Affiche si word1 et word2 sont des anagrammes.
 * Fait une copie des mots pour ne pas les modifier.
 */
void test_anagram(char word1[], char word2[])
{
    char tmp1[STRLEN];
    char tmp2[STRLEN];
    strncpy(tmp1, word1, STRLEN - 1);
    tmp1[STRLEN - 1] = '\0';
    strncpy(tmp2, word2, STRLEN - 1);
    tmp2[STRLEN - 1] = '\0';

    if (is_anagram(tmp1, tmp2))
    {
        printf("%s et %s sont des anagrammes\n", word1, word2);
    }
    else
    {
        printf("%s et %s ne sont pas des anagrammes\n", word1, word2);
    }
}

#ifndef TP7_TEST
int main(int argc, char *argv[])
{
    if (argc < 3 || argc > 4)
    {
        printf("erreur, utilisation :\n");
        printf("%s 1 mot1 mot2\nou\n%s 2 mot\n", argv[0], argv[0]);
        return EXIT_FAILURE;
    }

    int op = atoi(argv[1]);

    if (op == 1 && argc == 4)
    {
        test_anagram(argv[2], argv[3]);
    }
    else if (op == 2 && argc == 3)
    {
        test_palindrome(argv[2]);
    }
    else
    {
        printf("erreur, utilisation :\n");
        printf("%s 1 mot1 mot2\nou\n%s 2 mot\n", argv[0], argv[0]);
        return EXIT_FAILURE;
    }

    return EXIT_SUCCESS;
}
#endif
