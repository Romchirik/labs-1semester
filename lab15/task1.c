#include <stdio.h>
#include <stdint.h>

int main()
{
  FILE *input = fopen("input.bin", "rb");

  int32_t ints[2];

  fread(ints, sizeof(*ints), 2, input);

  fclose(input);

  int64_t tmp = (int64_t)ints[0] + (int64_t)ints[1];
  int32_t res = tmp / 2;
  if (tmp < 0 && tmp % 2 != 0)
  {
    res -= 1;
  }

  FILE *output = fopen("output.bin", "wb");

  fwrite(&res, sizeof(res), 1, output);

  fclose(output);
  return 0;
}