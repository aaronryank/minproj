#include <stdio.h>

int p = 0;  /* index for printing */
int i = 13; /* string length */

// prints "Hello,"
int f1()
{
  const char *s = "Igopt2";
  return (p < 6) ? putchar(s[p++] - p) : 0;
}

// prints " world!"
int f2()
{
  const char *s = "!Yrvqj(";
  return putchar(s[p++ - 6] - p + 6);
}

int main()
{
  while (i--) {
    f1() || f2();  /* if f1 returns 0, call f2 */
  }
}