#include <stdio.h>
#include <stdlib.h>

#define TABLE_SIZE 1000001

typedef struct row
{
  size_t length;
  char **data;
} Row;

Row table[TABLE_SIZE];

int main()
{
  freopen("input.txt", "r", stdin);
  freopen("output.txt", "w", stdout);

  int n;
  scanf("%d", &n);

  for (int i = 0; i < n; ++i)
  {
    int k;
    char *str = malloc(8 * sizeof(char));
    scanf("%d %s\n", &k, str);

    if (table[k].length == 0)
    {
      table[k].data = malloc(sizeof(char *));
      table[k].length = 1;
      table[k].data[0] = str;
      continue;
    }

    table[k].length++;
    table[k].data = realloc(table[k].data, table[k].length * sizeof(char *));
    table[k].data[table[k].length - 1] = str;
  }

  for (int i = 0; i < TABLE_SIZE; ++i)
  {
    if (table[i].length == 0)
    {
      continue;
    }

    for (int j = 0; j < table[i].length; ++j)
    {
      printf("%d %s\n", i, table[i].data[j]);
    }
  }

  return 0;
}