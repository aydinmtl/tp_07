---
subtitle: "Anagrammes et palindromes"
---

# Buts

* Utilisation des arguments d'un programme
* Manipulation de chaînes de caractères
* Modularisation

# Introduction

Deux mots sont des **anagrammes** l'un de l'autre quand ils contiennent
les mêmes lettres dans un ordre différent. Par exemple, *imaginer* et
*migraine* sont des anagrammes.

Un mot est un **palindrome** s'il se lit de la même façon de gauche à
droite que de droite à gauche. Par exemple, *rotor* et *kayak* sont
des palindromes.

# Fichiers

* `tp7.c` – votre programme. C'est le seul fichier que vous modifiez.
* `tp7_tests.c` – les tests automatiques. Ne le modifiez pas.
* `Makefile` – pour compiler, lancer et tester.

# Commandes

```
make          compile votre programme
make run      lance le programme sans arguments (affiche l'usage)
make test     compile et lance les tests
make clean    supprime les fichiers générés
```

Pour lancer le programme avec des arguments, appelez l'exécutable
directement :

```
./tp7 1 imaginer migraine
./tp7 2 kayak
./tp7 3
```

# À faire

Ouvrez `tp7.c`. Les fonctions `main`, `test_anagram` et
`test_palindrome` sont déjà écrites : ne les modifiez pas. Complétez
les cinq fonctions, repérées par des commentaires `TODO` :

| Fonction | Rôle |
|---|---|
| `is_equal(str1, str2)` | dit si deux chaînes sont identiques |
| `sort(str)` | trie une chaîne sur place, par ordre croissant |
| `is_anagram(str1, str2)` | dit si deux chaînes sont des anagrammes |
| `revert(str1, str2)` | recopie `str1` dans `str2` à l'envers |
| `is_palindrome(str)` | dit si une chaîne est un palindrome |

Travaillez une fonction à la fois : écrivez-la, lancez `make test`,
regardez quels tests passent, puis passez à la suivante.

# Indications

**Tri par sélection.** Pour `sort`, utilisez l'algorithme du tri par
sélection :

* parcourir la chaîne de l'indice 0 à la longueur - 2 ;
* pour chaque indice `i`, chercher le plus petit caractère entre `i`
  et la fin de la chaîne ;
* échanger ce caractère avec celui à l'indice `i`.

**Longueur des chaînes.** Utilisez `strlen` de `<string.h>` pour
connaître la longueur d'une chaîne (sans compter le `\0` final).

**Comparaison.** Utilisez `strcmp` de `<string.h>` pour comparer deux
chaînes. Elle renvoie 0 si elles sont égales. Vous pouvez aussi
écrire votre propre `is_equal` avec une boucle, ce qui est demandé.

**Anagrammes.** Triez les deux chaînes, puis comparez-les. Si elles
sont identiques après tri, ce sont des anagrammes.

**Palindrome.** Inversez la chaîne dans un tampon temporaire, puis
comparez l'original et l'inversé.

## Pièges à éviter

* Une chaîne se termine par `\0`. Ne triez pas ce caractère, et ne le
  comparez pas comme une lettre. Utilisez `strlen` qui l'exclut.
* `is_anagram` trie ses arguments. Si vous appelez
  `is_anagram(mot1, mot2)`, `mot1` et `mot2` seront triés après
  l'appel. C'est pour cela que `test_anagram` fait une copie avant.
* `revert` doit écrire le `\0` à la fin de `str2`.
* `is_palindrome` a besoin d'un tampon temporaire de taille suffisante.
  `STRLEN` est défini à 100, c'est suffisant pour ce TP.
* Pour `main`, `argv[0]` est le nom du programme. Les mots sont dans
  `argv[2]` (et `argv[3]` pour les anagrammes).

## Points à vérifier

* `make test` affiche tous les tests au vert.
* `./tp7 1 imaginer migraine` affiche
  `imaginer et migraine sont des anagrammes`
* `./tp7 1 salut salu` affiche
  `salut et salu ne sont pas des anagrammes`
* `./tp7 2 kayak` affiche `kayak est un palindrome`
* `./tp7 2 salut` affiche `salut n'est pas un palindrome`
* `./tp7 3` affiche le message d'usage et renvoie un code d'échec

# Bonus (facultatif)

## Anagrammes sans tri

Trier les deux chaînes est simple, mais pas très rapide. Une autre
méthode consiste à compter combien de fois chaque lettre apparaît
dans chaque chaîne, puis à comparer les deux comptages. Écrivez
`is_anagram_count(str1, str2)` avec cette méthode. Pour quels mots
les deux versions se comportent-elles différemment ?

## Palindrome sans copie

`is_palindrome` copie la chaîne dans un tampon, puis compare. On peut
faire mieux : comparer directement les caractères symétriques de la
chaîne, sans copie. Écrivez `is_palindrome_inplace(str)` avec cette
méthode. Est-elle plus rapide ? Plus lisible ?

## Insensibilité à la casse

Actuellement, `Rotor` et `rotor` ne sont pas considérés comme des
palindromes (la majuscule est un caractère différent). Modifiez
`is_palindrome` pour ignorer la casse (regardez `tolower` dans
`<ctype.h>`).
