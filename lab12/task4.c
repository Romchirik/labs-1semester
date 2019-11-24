#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct Tokens_s
{
  int num;    //количество слов в строке
  char **arr; //массив слов (каждый элемент –- строка, т.е. char*)
} Tokens;
//tokens: структура, в которую нужно положить результаты
//str: строка, в которой нужно искать слова
//delims: все символы-разделители в виде строки
void tokensSplit(Tokens *tokens, const char *str, const char *delims);
//удаляет все ресурсы внутри tokens
void tokensFree(Tokens *tokens);

// [first, last)
void getSlice(char *buffer, const char *str, int first, int last)
{
  memcpy(buffer, str + first, last - first);
  buffer[last - first] = '\0';
}

void countTokens(Tokens *tokens, const char *str, const char *delims)
{
  char prev_flag = 0;

  int str_len = strlen(str);
  int delims_len = strlen(delims);

  for (int i = 0; i < str_len; ++i)
  {
    char flag = 1;
    for (int j = 0; j < delims_len; ++j)
    {
      if (str[i] == delims[j])
      {
        flag = 0;
      }
    }

    if (prev_flag == 0 && flag == 1)
    {
      tokens->num++;
    }

    prev_flag = flag;
  }
}

void tokensSplit(Tokens *tokens, const char *str, const char *delims)
{
  if (tokens->arr == NULL)
  {
    countTokens(tokens, str, delims);
    return;
  }

  int str_len = strlen(str);
  int delims_len = strlen(delims);

  int cnt = 0;

  int prev_flag = 0;
  int first_index = 0;

  for (int i = 0; i < str_len; ++i)
  {
    int flag = 1;

    for (int j = 0; j < delims_len; ++j)
    {
      if (str[i] == delims[j])
      {
        flag = 0;
      }
    }

    if (prev_flag == 0 && flag == 1)
    {
      first_index = i;
    }

    if (prev_flag == 1 && flag == 0)
    {
      tokens->arr[cnt] = malloc((i - first_index + 1) * sizeof(char));
      getSlice(tokens->arr[cnt], str, first_index, i);
      cnt++;
    }

    prev_flag = flag;
  }

  if (prev_flag)
  {
    tokens->arr[cnt] = malloc((str_len - first_index + 1) * sizeof(char));
    getSlice(tokens->arr[cnt], str, first_index, str_len);
    cnt++;
  }

  tokens->num = cnt;
}

void tokensFree(Tokens *tokens)
{
  if (tokens->arr == NULL)
    return;

  for (int i = 0; i < tokens->num; ++i)
  {
    if (tokens->arr[i] != NULL)
    {
      free(tokens->arr[i]);
    }
  }

  free(tokens->arr);
  tokens->arr = NULL;
  tokens->num = 0;
}

int main()
{
  freopen("input.txt", "r", stdin);
  freopen("output.txt", "w", stdout);

  Tokens tokens;
  tokens.arr = NULL;
  tokens.num = 0;

  char input[1000001];
  scanf("%s", input);
  tokensSplit(&tokens, input, ":;,.");
  tokens.arr = malloc(tokens.num * sizeof(char *));
  tokensSplit(&tokens, input, ":;,.");

  printf("%d\n", tokens.num);

  for (int i = 0; i < tokens.num; ++i)
  {
    printf("%s\n", tokens.arr[i]);
  }

  tokensFree(&tokens);
  tokensFree(&tokens);

  return 0;
}