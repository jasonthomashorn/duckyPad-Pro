#include <stdio.h>
#include <string.h>
#include "ssd1306.h"
#include "ssd1306_fonts.h"

/*
2024 03 20
Adjust screen size in ssd1306.h
make clean; make; ./my_program.exe ; python ./vis.py ./OLED_128_128.bin
*/

#define FILENAME_BUF_SIZE 64
char filename_buf[FILENAME_BUF_SIZE];
#define OLED_LINE_BUF_SIZE 64
char oled_line_buf[OLED_LINE_BUF_SIZE];
#define TEMP_BUFSIZE 64
char temp_buf[TEMP_BUFSIZE];

uint8_t center_line(uint8_t line_len, uint8_t char_width_pixels, uint8_t oled_width_pixels)
{
  int16_t start_pixel = (oled_width_pixels - line_len * char_width_pixels) / 2;
  if(start_pixel < 0)
    start_pixel = 0;
  return start_pixel;
}

int main(int argc, char *argv[])
{

  // ----------------------------------------
  ssd1306_Fill(Black);

  memset(oled_line_buf, 0, OLED_LINE_BUF_SIZE);
  sprintf(oled_line_buf, "3-Keyboard Region");
  ssd1306_SetCursor(0, 56);
  ssd1306_WriteString(oled_line_buf, Font_7x10, White);

  memset(oled_line_buf, 0, OLED_LINE_BUF_SIZE);
  sprintf(oled_line_buf, "English (US)");
  ssd1306_SetCursor(0, 68);
  ssd1306_WriteString(oled_line_buf, Font_7x10, White);

  memset(oled_line_buf, 0, OLED_LINE_BUF_SIZE);
  sprintf(oled_line_buf, "4-BT Unpair All");
  ssd1306_SetCursor(0, 84);
  ssd1306_WriteString(oled_line_buf, Font_7x10, White);

  memset(oled_line_buf, 0, OLED_LINE_BUF_SIZE);
  sprintf(oled_line_buf, "5-Mount USB");
  ssd1306_SetCursor(0, 100);
  ssd1306_WriteString(oled_line_buf, Font_7x10, White);

  ssd1306_Line(0,115,128,115,White);

  // ------------------------------

	sprintf(filename_buf, "OLED_%d_%d.bin", SSD1306_WIDTH, SSD1306_HEIGHT);

	FILE* file = fopen(filename_buf, "wb");
  if (file == NULL) {
      printf("Failed to open file\n");
      return 1;
  }

  size_t written = fwrite(SSD1306_Buffer, sizeof(uint8_t), SSD1306_BUFFER_SIZE, file);
  if (written < SSD1306_BUFFER_SIZE)
  {
      printf("Failed to write the complete buffer to file\n");
      return 2;
  }

  fclose(file);
  printf("done!\n");
}

