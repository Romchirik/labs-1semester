#include <stdio.h>
#include <stdlib.h>
#include <inttypes.h>

//merges sorted arrays a[0..ak-1] and b[0..bk-1] into
//one sorted array res[0..rk-1], returning rk from function
int merge(const int *a, int ak, const int *b, int bk, int *res);

int merge(const int *a, int ak, const int *b, int bk, int *res)
{
  int rk = ak + bk;

  int a_i = 0;
  int b_i = 0;

  int r_i = 0;

  while (a_i < ak && b_i < bk)
  {
    if (a[a_i] < b[b_i])
    {
      res[r_i] = a[a_i];
      a_i++;
    }
    else
    {
      res[r_i] = b[b_i];
      b_i++;
    }

    r_i++;
  }

  while (a_i < ak)
  {
    res[r_i] = a[a_i];
    r_i++;
    a_i++;
  }

  while (b_i < bk)
  {
    res[r_i] = b[b_i];
    r_i++;
    b_i++;
  }

  return rk;
}

int main(void)
{
  FILE *input = fopen("input.bin", "rb");

  uint32_t n;
  fread(&n, sizeof(uint32_t), 1, input);

  uint32_t m;
  fread(&m, sizeof(uint32_t), 1, input);

  int32_t *n_arr = (int32_t *)malloc(sizeof(int32_t) * n);
  fread(n_arr, sizeof(int32_t), n, input);

  int32_t *m_arr = (int32_t *)malloc(sizeof(int32_t) * m);
  fread(m_arr, sizeof(int32_t), m, input);

  fclose(input);

  int32_t *res = (int32_t *)malloc((n + m) * sizeof(int32_t));

  int rk = merge(n_arr, n, m_arr, m, res);
  free(n_arr);
  free(m_arr);

  FILE *output = fopen("output.bin", "wb");

  fwrite(res, sizeof(*res), rk, output);

  fclose(output);
  return 0;
}