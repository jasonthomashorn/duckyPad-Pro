#include <string.h>
#include <sys/unistd.h>
#include <sys/stat.h>

#include "shared.h"

uint8_t esp_mac_addr[ESP_MAC_ADDR_SIZE];

void strip_newline(char* line, uint8_t size)
{
  for(int i = 0; i < size; ++i)
    if(line[i] == '\n' || line[i] == '\r')
      line[i] = 0;
}

uint8_t how_many_digits(uint8_t number)
{
  if(number >= 100)
    return 3;
  if(number >= 10)
    return 2;
  return 1;
}

char* goto_next_arg(char* buf, char* buf_end)
{
  char* curr = buf;  
  if(buf == NULL || curr >= buf_end)
    return NULL;
  while(curr < buf_end && *curr != ' ')
      curr++;
  while(curr < buf_end && *curr == ' ')
      curr++;
  if(curr >= buf_end)
    return NULL;
  return curr;
}

