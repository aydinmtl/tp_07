/*
 * tp7_tests.c – Tests automatiques pour le TP 7.
 *
 * Ne modifiez pas ce fichier.
 *
 * Compile avec tp7.c via :
 *     make test
 */

#include <stdio.h>
#include <string.h>
#include <stdbool.h>

/* Les fonctions de tp7.c qu'on veut tester. */
bool is_equal(char str1[], char str2[]);
void sort(char str[]);
bool is_anagram(char str1[], char str2[]);
void revert(char str1[], char str2[]);
bool is_palindrome(char str[]);

static int total = 0;
static int reussis = 0;

static void verifier(const char* nom, int condition) {
    total++;
    if (condition) {
        printf("  ok   %s\n", nom);
        reussis++;
    } else {
        printf("  FAIL %s\n", nom);
    }
}

/*
 * Vérifie que sort() transforme bien `avant` en `apres`.
 */
static void verifier_tri(const char* nom,
                         const char* avant, const char* apres) {
    char buf[100];
    strcpy(buf, avant);
    sort(buf);
    total++;
    if (strcmp(buf, apres) == 0) {
        printf("  ok   %s\n", nom);
        reussis++;
    } else {
        printf("  FAIL %s (attendu \"%s\", obtenu \"%s\")\n",
               nom, apres, buf);
    }
}

/*
 * Vérifie que revert() transforme bien `avant` en `apres`.
 */
static void verifier_revert(const char* nom,
                            const char* avant, const char* apres) {
    char buf[100];
    revert((char*)avant, buf);
    total++;
    if (strcmp(buf, apres) == 0) {
        printf("  ok   %s\n", nom);
        reussis++;
    } else {
        printf("  FAIL %s (attendu \"%s\", obtenu \"%s\")\n",
               nom, apres, buf);
    }
}

static void test_is_equal(void) {
    verifier("chaînes identiques",
             is_equal("abc", "abc") == true);
    verifier("chaînes différentes",
             is_equal("abc", "abd") == false);
    verifier("longueurs différentes",
             is_equal("ab", "abc") == false);
    verifier("chaînes vides",
             is_equal("", "") == true);
    verifier("une vide, une non vide",
             is_equal("", "a") == false);
}

static void test_sort(void) {
    verifier_tri("tri simple",              "cba",      "abc");
    verifier_tri("déjà trié",               "abc",      "abc");
    verifier_tri("inversé",                 "zyxw",     "wxyz");
    verifier_tri("un seul caractère",       "a",        "a");
    verifier_tri("chaîne vide",             "",         "");
    verifier_tri("lettres répétées",        "aabcc",    "aabcc");
    verifier_tri("répétitions en désordre", "cbacba",   "aabbcc");
    verifier_tri("toutes mêmes",            "aaaa",     "aaaa");
    verifier_tri("imaginer trié",           "imaginer", "aegiimnr");
}

static void test_is_anagram(void) {
    /* is_anagram modifie ses arguments : on copie avant. */
    char a[100], b[100];

    strcpy(a, "imaginer"); strcpy(b, "migraine");
    verifier("imaginer / migraine", is_anagram(a, b) == true);

    strcpy(a, "salut"); strcpy(b, "salu");
    verifier("salut / salu", is_anagram(a, b) == false);

    strcpy(a, "abc"); strcpy(b, "cba");
    verifier("abc / cba", is_anagram(a, b) == true);

    strcpy(a, "abc"); strcpy(b, "abd");
    verifier("abc / abd", is_anagram(a, b) == false);

    strcpy(a, ""); strcpy(b, "");
    verifier("deux chaînes vides", is_anagram(a, b) == true);

    strcpy(a, "aab"); strcpy(b, "abb");
    verifier("aab / abb", is_anagram(a, b) == false);

    strcpy(a, "listen"); strcpy(b, "silent");
    verifier("listen / silent", is_anagram(a, b) == true);
}

static void test_revert(void) {
    verifier_revert("abc",           "abc",   "cba");
    verifier_revert("un caractère",  "a",     "a");
    verifier_revert("chaîne vide",   "",      "");
    verifier_revert("kayak",         "kayak", "kayak");
    verifier_revert("abcd",          "abcd",  "dcba");
}

static void test_is_palindrome(void) {
    verifier("kayak",       is_palindrome("kayak")     == true);
    verifier("rotor",       is_palindrome("rotor")     == true);
    verifier("ressasser",   is_palindrome("ressasser") == true);
    verifier("salut",       is_palindrome("salut")     == false);
    verifier("a",           is_palindrome("a")         == true);
    verifier("chaîne vide", is_palindrome("")          == true);
    verifier("ab",          is_palindrome("ab")        == false);
    verifier("aa",          is_palindrome("aa")        == true);
}

int main(void) {
    printf("Tests de tp7.c\n\n");

    printf("Comparaison (is_equal) :\n");
    test_is_equal();
    printf("\n");

    printf("Tri (sort) :\n");
    test_sort();
    printf("\n");

    printf("Anagrammes (is_anagram) :\n");
    test_is_anagram();
    printf("\n");

    printf("Inversion (revert) :\n");
    test_revert();
    printf("\n");

    printf("Palindromes (is_palindrome) :\n");
    test_is_palindrome();
    printf("\n");

    printf("%d test(s) réussi(s) sur %d.\n", reussis, total);
    return (reussis == total) ? 0 : 1;
}
