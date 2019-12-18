#include <stdio.h>
#include <stdint.h>

typedef union digit {
  int as_int;
  char as_byte[4];
} Digit;

void swap(char *a, char *b)
{
  char old_a = *a;
  *a = *b;
  *b = old_a;
}

void reverse(int *value)
{
  Digit digit;
  digit.as_int = *value;
  swap(&digit.as_byte[0], &digit.as_byte[3]);
  swap(&digit.as_byte[1], &digit.as_byte[2]);
  *value = digit.as_int;
}

int main()
{
  FILE *input = fopen("input.bin", "rb");

  int32_t n;

  fread(&n, sizeof(n), 1, input);

  int is_little_endian = 1;

  if (n > 10000)
  {
    is_little_endian = 0;
    reverse(&n);
  }

  int32_t res = 0;

  for (int32_t i = 0; i < n; ++i)
  {
    int32_t value;
    fread(&value, sizeof(value), 1, input);

    if (!is_little_endian)
    {
      reverse(&value);
    }

    res += value;
  }

  fclose(input);

  FILE *output = fopen("output.bin", "wb");

  if (!is_little_endian)
  {
    reverse(&res);
  }

  fwrite(&res, sizeof(res), 1, output);

  fclose(output);
  return 0;
}