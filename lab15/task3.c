#include <stdio.h>
#include <stdint.h>
#include <stdlib.h>

typedef struct list_node
{
  uint8_t value;
  struct list_node *next;
} ListNode;

void printList(ListNode **head, FILE *output)
{
  fprintf(output, "    \"");

  while (*head != NULL)
  {
    fwrite(&(*head)->value, sizeof((*head)->value), 1, output);
    ListNode *tmp = (*head)->next;
    free(*head);
    *head = tmp;
  }

  fprintf(output, "\": ");
}

ListNode *createListNode(uint16_t val)
{
  ListNode *node = (ListNode *)malloc(sizeof(ListNode));
  node->value = val;
  node->next = NULL;

  return node;
}

ListNode *pushToTailList(uint16_t value, ListNode *tail)
{
  ListNode *node = createListNode(value);
  tail->next = node;

  return node;
}

void readFromFile(void *__ptr, size_t __size, size_t __nitems, FILE *__stream, int32_t *size)
{
  fread(__ptr, __size, __nitems, __stream);

  if (size != NULL)
  {
    *size -= __size * __nitems;
  }
}

int main()
{
  FILE *input = fopen("input.bin", "rb");
  FILE *output = fopen("output.txt", "w");

  fprintf(output, "{\n");

  int32_t file_size;

  readFromFile(&file_size, sizeof(file_size), 1, input, NULL);
  file_size -= sizeof(file_size) + 1;

  while (file_size > 0)
  {
    uint8_t type;
    readFromFile(&type, sizeof(type), 1, input, &file_size);

    // read field name
    ListNode *field_name_head = NULL;
    ListNode *field_name_tail = NULL;
    field_name_head = field_name_tail = createListNode(0);
    readFromFile(&field_name_tail->value, sizeof(field_name_tail->value), 1, input, &file_size);

    uint8_t symbol;
    readFromFile(&symbol, sizeof(symbol), 1, input, &file_size);

    while (symbol != 0)
    {
      field_name_tail = pushToTailList(symbol, field_name_tail);
      readFromFile(&symbol, sizeof(symbol), 1, input, &file_size);
    }

    printList(&field_name_head, output);

    switch (type)
    {
    case 1:
    {
      double double_value;
      readFromFile(&double_value, sizeof(double_value), 1, input, &file_size);

      fprintf(output, "%0.15g", double_value);
      break;
    }
    case 2:
    {
      uint32_t bytes_count;
      readFromFile(&bytes_count, sizeof(bytes_count), 1, input, &file_size);

      size_t string_length = sizeof(uint8_t) * bytes_count;

      uint8_t *string = (uint8_t *)malloc(string_length);
      readFromFile(string, sizeof(*string), bytes_count, input, &file_size);

      fprintf(output, "\"");
      fwrite(string, sizeof(*string), bytes_count - 1, output);
      fprintf(output, "\"");

      free(string);
      break;
    }
    case 8:
    {
      uint8_t bool_value;
      readFromFile(&bool_value, sizeof(bool_value), 1, input, &file_size);

      if (bool_value == 0)
      {
        fprintf(output, "false");
      }
      else
      {
        fprintf(output, "true");
      }

      break;
    }
    case 10:
      fprintf(output, "null");
      break;
    case 16:
    {
      uint32_t int32_value;
      readFromFile(&int32_value, sizeof(int32_value), 1, input, &file_size);

      fprintf(output, "%d", int32_value);
      break;
    }
    case 18:
    {
      uint64_t int64_value;
      readFromFile(&int64_value, sizeof(int64_value), 1, input, &file_size);

      fprintf(output, "%lld", int64_value);
      break;
    }
    default:
      break;
    }

    if (file_size - 1 > 0)
    {
      fprintf(output, ",");
    }

    fprintf(output, "\n");
  }

  fclose(input);

  fprintf(output, "}");
  fclose(output);
  return 0;
}