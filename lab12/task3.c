#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main()
{
  freopen("input.txt", "r", stdin);
  freopen("output.txt", "w", stdout);

  int n;
  scanf("%d", &n);

  char **arr = malloc(n * sizeof(char *));
  int arr_len = 0;

  for (int z = 0; z < n; ++z)
  {
    int t;
    scanf("%d", &t);

    switch (t)
    {
    case 0:
    {
      int l;
      scanf("%d", &l);
      arr[arr_len] = malloc((l + 1) * sizeof(char));
      scanf("%s", arr[arr_len]);
      arr_len++;
      break;
    }
    case 1:
    {
      int idx;
      scanf("%d", &idx);
      free(arr[idx]);
      arr[idx] = NULL;
      break;
    }
    case 2:
    {
      int idx;
      scanf("%d", &idx);
      printf("%s\n", arr[idx]);
      break;
    }
    case 3:
    {
      int idx;
      char symbol;
      scanf("%d %c", &idx, &symbol);
      int cnt = 0;
      for (int i = 0; i < strlen(arr[idx]); ++i)
      {
        if (arr[idx][i] == symbol)
        {
          cnt++;
        }
      }
      printf("%d\n", cnt);
      break;
    }
    default:
      break;
    }
  }

  for (int i = 0; i < arr_len; ++i)
  {
    if (arr[i] != NULL)
    {
      free(arr[i]);
      arr[i] = NULL;
    }
  }

  free(arr);
  arr = NULL;

  return 0;
}