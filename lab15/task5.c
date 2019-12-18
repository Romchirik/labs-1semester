#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <limits.h>
#include <inttypes.h>

//какой-нибудь целочисленный тип (желательно беззнаковый)
typedef uint8_t bitword;

#define BITWORD_BITS (CHAR_BIT * sizeof(bitword))

size_t getBitsetSize(size_t num)
{
  return ((num + BITWORD_BITS - 1) / BITWORD_BITS) * sizeof(bitword);
}

void bitsetZero(bitword **arr, size_t size)
{
  free(*arr);
  *arr = NULL;
  *arr = (bitword *)malloc(size);
  memset(*arr, 0, size);
}

int bitsetGet(const bitword *arr, int idx)
{
  if (arr[idx / BITWORD_BITS] & (1u << (BITWORD_BITS - 1 - (idx % BITWORD_BITS))))
  {
    return 1;
  }

  return 0;
}

void bitsetSet(bitword *arr, int idx, int newval)
{
  if (newval)
  {
    arr[idx / BITWORD_BITS] |= 1u << (BITWORD_BITS - 1u - (idx % BITWORD_BITS));
  }
  else
  {
    arr[idx / BITWORD_BITS] &= ~(1u << (BITWORD_BITS - 1u - (idx % BITWORD_BITS)));
  }
}

typedef struct
{
  size_t length;
  uint8_t *bits;
} CodedSymbol;

int main(void)
{
  FILE *input = fopen("input.bin", "rb");

  uint32_t n;
  fread(&n, sizeof(n), 1, input);

  CodedSymbol *codedSymbols = (CodedSymbol *)malloc(sizeof(CodedSymbol) * n);

  for (int i = 0; i < n; ++i)
  {
    uint32_t l_length;
    fread(&l_length, sizeof(l_length), 1, input);

    codedSymbols[i].length = l_length;

    codedSymbols[i].bits = (uint8_t *)malloc(sizeof(*codedSymbols[i].bits) * codedSymbols[i].length);

    for (int j = 0; j < codedSymbols[i].length; ++j)
    {
      fread(&codedSymbols[i].bits[j], sizeof(*codedSymbols[i].bits), 1, input);
    }
  }

  uint32_t m;
  fread(&m, sizeof(m), 1, input);

  int16_t *m_arr = (int16_t *)malloc(sizeof(*m_arr) * m);
  fread(m_arr, sizeof(*m_arr), m, input);

  fclose(input);

  bitword *bitset = NULL;

  int res_length = 0;
  for (int i = 0; i < m; ++i)
  {
    res_length += codedSymbols[m_arr[i]].length;
  }

  size_t bitset_length = getBitsetSize(res_length);
  bitsetZero(&bitset, bitset_length);
  int bitset_last_el_pos = -1;

  for (int j = 0; j < m; ++j)
  {
    CodedSymbol codedSymbol = codedSymbols[m_arr[j]];

    for (int i = 0; i < codedSymbol.length; ++i)
    {
      bitset_last_el_pos++;
      bitsetSet(bitset, bitset_last_el_pos, codedSymbol.bits[i]);
    }
  }

  FILE *output = fopen("output.bin", "wb");

  for (int k = 0; k < bitset_length; ++k)
  {
    int start_byte = k * 8;
    int end_byte = k * 8 + 8;

    for (int i = start_byte; i < end_byte - 4; ++i)
    {
      uint8_t old = bitsetGet(bitset, i);
      int b_pos = end_byte - (i - k * 8) - 1;
      bitsetSet(bitset, i, bitsetGet(bitset, b_pos));
      bitsetSet(bitset, b_pos, old);
    }
  }

  fwrite(bitset, sizeof(*bitset), bitset_length, output);

  fclose(output);
  return 0;
}