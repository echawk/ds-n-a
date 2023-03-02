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

/* Total num of characters that our regex engine supports. */
#define ASCII_SIZE 128

typedef struct StateVec {
  int *tVec;
  int size;
} StateVec_T;

StateVec_T make_StateVec() {
  StateVec_T sv =
      (StateVec_T){.tVec = calloc(ASCII_SIZE, sizeof(int)), .size = ASCII_SIZE};
  int i;
  for (i = 0; i < sv.size; i++) {
    sv.tVec[i] = 0;
  }
  return sv;
}

void print_StateVec(StateVec_T sv) {
  int i;
  for (i = 0; i < sv.size; i++) {
    if (isalnum(i)) {
      printf("%c", i);
    } else {
      printf(" ");
    }
  }
  printf("\n");
  for (i = 0; i < sv.size; i++) {
    if (sv.tVec[i] != 0) {
      printf("%d", sv.tVec[i]);
    } else {
      printf(" ");
    }
  }
  printf("\n");
}

typedef struct Regex {
  char *strRep;
  StateVec_T *svMatr;
} Regex_T;

bool Regex_match_p(Regex_T re, char *str) { TODO; }

Regex_T make_Regex(char *str) {
  StateVec_T haltSV = make_StateVec();

  StateVec_T initSV = make_StateVec();

  /*
    FIXME: This is hacky, and does not work all of the time.
    However, since this regex engine is 'simple' we can assume,
    that we won't have more than strlen(str)+2 states. This is
    not *exactly* true, but should suffice to prove that this works.
    It'll be fixed later.
   */

  StateVec_T *StateVecMatr =
      (StateVec_T *)calloc(strlen(str) + 2, sizeof(StateVec_T));
  StateVecMatr[0] = haltSV;
  StateVecMatr[1] = initSV;
  int curr_state = 1;
  int i;
  for (i = 2; i < strlen(str) + 2; i++) {
    StateVecMatr[i] = make_StateVec();
  }

  i = 0;
  do {
    char curr_c = str[i];
    char peek_c = str[i + 1];

    int j; // general iterator for the switch statements.

    if (isalnum(curr_c)) {
      StateVecMatr[curr_state].tVec[curr_c] = curr_state + 1;
    } else {
      switch (curr_c) {
        /*
          If we encounter a range, we are going to treat the entire
          range as a single character, so there will only be one state.
         */
      case '[':
        char range_start_c = peek_c;
        i += 2;
        curr_c = str[i];
        peek_c = str[i + 1];
        /*
          Sanity check our environment.
         */
        if (curr_c != '-' || !isalnum(peek_c)) {
          // TODO: add nice error msg
          exit(1);
        }
        char range_end_c = peek_c;
        i++;
        peek_c = str[i + 1];
        if (peek_c != ']') {
          printf("ERR: Missing ']'\n");
        }
        /*
          Fill in the range with the next state.
         */
        for (j = range_start_c; j <= range_end_c; j++) {
          StateVecMatr[curr_state].tVec[j] = curr_state + 1;
        }
        break;
      case '.':
        for (j = 0; j < StateVecMatr[curr_state].size; j++) {
          StateVecMatr[curr_state].tVec[j] = curr_state + 1;
        }
        break;
      }

      // printf("%c, %d\n", curr_c, curr_c);
    }

    curr_state++;
    i++;
  } while (i < strlen(str));

  for (i = 0; i < strlen(str); i++) {
    print_StateVec(StateVecMatr[i]);
  }

  TODO;
}

int main() {

  /* StateVec_T sv = make_StateVec(); */
  /* print_StateVec(sv); */

  // char *str = "aAzZ09 ";
  char *str = ".[0-9]";

  char *restr = "b0b";
  Regex_T re = make_Regex(str);

  Regex_match_p(re, "bob");
  Regex_match_p(re, "b0b");

  printf("regex");

  return 0;
}
