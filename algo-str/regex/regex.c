/*
  Simple regex engine in C.
  Default behavior is to be like grep
  - given a regex as it's argument, print out all lines that match from stdin
 */

/*
  Basic algorithm is to take a regular expression and 'compile' it to
  a state transition table.

  EX:

The regex: 'b0b'

Compiles to the following table:

     S0  S1  S3  SA  SH
   +---+---+---+---+---+
  a| SH| SH| SH| SA| SH|
  b| S1| SH| SA| SA| SH|
  c| SH| SH| SH| SA| SH|
  ...
  0| SH| S3| SH| SA| SH|
  1| SH| SH| SH| SA| SH|
  ...


The S* columns are the state transition vectors,
if the FSM is state N,
  - then transition to the new state denoted by S_N[c], where c is the character
at the current point in the string.

*/

#include <ctype.h>
#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define TODO                                                                   \
  printf("TODO");                                                              \
  exit(1);

typedef struct Regex {
  char *strRep;
} Regex_T;

bool Regex_match_p(Regex_T re, char *str) { TODO; }

Regex_T Str_to_Regex(char *str) { TODO; }

int main() {

  Regex_T re = (Regex_T){.strRep = "b0b"};

  char *str = "aAzZ09 ";

  for (int i = 0; i < strlen(str); i++) {
    if (isalnum(str[i])) {
      printf("is alpha numeric\n");
    }
    switch (str[i]) {
    case 'b':
      printf("char\n");
      break;
    case '0':
      printf("num\n");
      break;
    }
    printf("%c, %d\n", str[i], str[i]);
  }

  Regex_match_p(re, "bob");
  Regex_match_p(re, "b0b");

  printf("regex");

  return 0;
}
