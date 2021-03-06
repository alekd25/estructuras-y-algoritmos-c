#include <stdio.h>
#include <stdlib.h>

int len(char *s)
{
  int i;
  for( i = 0; s[i] != '\0'; i++)
    ;
  return i;
}

void lsc(char *s1, char *s2)
{
  const char ARRIBA = '|';
  const char IZQUIERDA = '~';
  const char DIAGONAL = '/';

  int t1 = len(s1);
  int t2 = len(s2);
  int i, j;
  int tabla[t1 + 1][t2 + 1];
  char c[t1 + 1][t2 + 1];

  for( i = 0; i <= t1; i++)
    tabla[i][0] = 0;

  for( i = 0; i <= t2; i++)
    tabla[0][i] = 0;

  for( i = 1; i <= t1; i++)
  {
    for( j = 1; j <= t2; j++)
    {
      if( s1[i-1] == s2[j-1])
      {
        tabla[i][j] = tabla[i-1][j-1] + 1;
        c[i][j] = DIAGONAL;
      }
      else
      {
        if(tabla[i-1][j] >= tabla[i][j-1])
        {
          tabla[i][j] = tabla[i-1][j];
          c[i][j] = ARRIBA;
        }
        else
        {
          tabla[i][j] = tabla[i][j - 1];
          c[i][j] = IZQUIERDA;
        }
      }
    }
  }

  for(i = 0; i <= t1; i++)
  {
    for(j = 0; j <= t2; j++)
    {
      printf("%d\t", tabla[i][j]);
    }
  printf("\n");
  }

  printf("Subcadena mas larga: %d\n", tabla[t1][t2] );

  i = t1;
  j = t2;
  while( i > 0 && j > 0)
  {
    if(c[i][j] == IZQUIERDA && (j - 1) > 0)
      j--;
    if(c[i][j] == ARRIBA && (i - 1) > 0)
      i--;
    if(c[i][j] == DIAGONAL)
    {
      printf("%c", s2[j-1] );
      j--;
      i--;
    }
  }
  printf("\n");
}

int main(void)
{
  char *cad1 = "dcbaabc";
  char *cad2 = "abcdcba";
  lsc(cad1, cad2);
  return 0;
}
