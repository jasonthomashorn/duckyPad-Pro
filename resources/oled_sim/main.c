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

#define SW_MATRIX_NUM_COLS 4
#define SW_MATRIX_NUM_ROWS 5
#define CELL_LONG_SIDE 32
#define CELL_SHORT_SIDE 23
#define TITLE_BAR_HEIGHT 11

uint8_t rowcol_to_index(uint8_t row, uint8_t col)
{
  if(row >= SW_MATRIX_NUM_ROWS || col >= SW_MATRIX_NUM_COLS)
    return 0;
  return row*SW_MATRIX_NUM_COLS + col;
}

void draw_cell_content(uint8_t cell_col, uint8_t cell_row, char* first_line, char* second_line)
{
    if(cell_col >= SW_MATRIX_NUM_COLS || cell_row >= SW_MATRIX_NUM_ROWS)
        return;
    uint8_t cell_pixel_x = cell_col * CELL_LONG_SIDE;
    uint8_t cell_pixel_y = cell_row * CELL_SHORT_SIDE + TITLE_BAR_HEIGHT + 1;
    
    uint8_t first_line_size = strlen(first_line);
    uint8_t second_line_size = strlen(second_line);

    if(first_line_size == 0)
        return;

    uint8_t str_pixel_x, str_pixel_y;
    if(first_line_size <= 4 && second_line_size == 0)
    {
        str_pixel_x = cell_pixel_x + (CELL_LONG_SIDE - (first_line_size * 7)) / 2;
        str_pixel_y = cell_pixel_y + 6;
        ssd1306_SetCursor(str_pixel_x, str_pixel_y);
        ssd1306_WriteString(first_line, Font_7x10, White);
    }
    else if(first_line_size == 5 && second_line_size == 0)
    {
        str_pixel_x = cell_pixel_x + 2;
        str_pixel_y = cell_pixel_y + 7;
        ssd1306_SetCursor(str_pixel_x, str_pixel_y);
        ssd1306_WriteString(first_line, Font_6x8, White);
    }
    else if(first_line_size <= 4 && second_line_size <= 4)
    {
        // first line
        str_pixel_x = cell_pixel_x + (CELL_LONG_SIDE - (first_line_size * 7)) / 2;
        str_pixel_y = cell_pixel_y + 1;
        ssd1306_SetCursor(str_pixel_x, str_pixel_y);
        ssd1306_WriteString(first_line, Font_7x10, White);
        // second line
        str_pixel_x = cell_pixel_x + (CELL_LONG_SIDE - (second_line_size * 7)) / 2;
        str_pixel_y = cell_pixel_y + 1 + 10;
        ssd1306_SetCursor(str_pixel_x, str_pixel_y);
        ssd1306_WriteString(second_line, Font_7x10, White);
    }
    else
    {
        // first line
        str_pixel_x = cell_pixel_x + 1 + (CELL_LONG_SIDE - (first_line_size * 6)) / 2;
        str_pixel_y = cell_pixel_y + 2;
        ssd1306_SetCursor(str_pixel_x, str_pixel_y);
        ssd1306_WriteString(first_line, Font_6x8, White);
        // second line
        str_pixel_x = cell_pixel_x + 1 + (CELL_LONG_SIDE - (second_line_size * 6)) / 2;
        str_pixel_y = cell_pixel_y + 3 + 8;
        ssd1306_SetCursor(str_pixel_x, str_pixel_y);
        ssd1306_WriteString(second_line, Font_6x8, White);
    }
}

void draw_cell_content_rotated(uint8_t cell_col, uint8_t cell_row, char* first_line, char* second_line)
{
    if(cell_col >= SW_MATRIX_NUM_COLS || cell_row >= SW_MATRIX_NUM_ROWS)
        return;
    uint8_t cell_pixel_x = cell_col * CELL_LONG_SIDE;
    uint8_t cell_pixel_y = cell_row * CELL_SHORT_SIDE + TITLE_BAR_HEIGHT + 1;
    
    uint8_t first_line_size = strlen(first_line);
    uint8_t second_line_size = strlen(second_line);

    if(first_line_size == 0)
        return;

    uint8_t str_pixel_x, str_pixel_y;
    if(first_line_size <= 4 && second_line_size == 0)
    {
        str_pixel_x = cell_pixel_x + (CELL_LONG_SIDE - (first_line_size * 7)) / 2;
        str_pixel_y = cell_pixel_y + 6;
        ssd1306_SetCursor(str_pixel_x, str_pixel_y);
        ssd1306_WriteString(first_line, Font_7x10, White);
    }
    else if(first_line_size == 5 && second_line_size == 0)
    {
        str_pixel_x = cell_pixel_x + 2;
        str_pixel_y = cell_pixel_y + 7;
        ssd1306_SetCursor(str_pixel_x, str_pixel_y);
        ssd1306_WriteString(first_line, Font_6x8, White);
    }
    else if(first_line_size <= 4 && second_line_size <= 4)
    {
        // first line
        str_pixel_x = cell_pixel_x + (CELL_LONG_SIDE - (first_line_size * 7)) / 2;
        str_pixel_y = cell_pixel_y + 1;
        ssd1306_SetCursor(str_pixel_x, str_pixel_y);
        ssd1306_WriteString(first_line, Font_7x10, White);
        // second line
        str_pixel_x = cell_pixel_x + (CELL_LONG_SIDE - (second_line_size * 7)) / 2;
        str_pixel_y = cell_pixel_y + 1 + 10;
        ssd1306_SetCursor(str_pixel_x, str_pixel_y);
        ssd1306_WriteString(second_line, Font_7x10, White);
    }
    else
    {
        // first line
        str_pixel_x = cell_pixel_x + 1 + (CELL_LONG_SIDE - (first_line_size * 6)) / 2;
        str_pixel_y = cell_pixel_y + 2;
        ssd1306_SetCursor(str_pixel_x, str_pixel_y);
        ssd1306_WriteString(first_line, Font_6x8, White);
        // second line
        str_pixel_x = cell_pixel_x + 1 + (CELL_LONG_SIDE - (second_line_size * 6)) / 2;
        str_pixel_y = cell_pixel_y + 3 + 8;
        ssd1306_SetCursor(str_pixel_x, str_pixel_y);
        ssd1306_WriteString(second_line, Font_6x8, White);
    }
}

#define TEMP_BUFSIZE 64
char line1_buf[TEMP_BUFSIZE];
char line2_buf[TEMP_BUFSIZE];

void draw_profile()
{
  ssd1306_Fill(Black);
  memset(oled_line_buf, 0, OLED_LINE_BUF_SIZE);
  sprintf(oled_line_buf, "P1:Test");
  ssd1306_SetCursor(center_line(strlen(oled_line_buf), 7, SSD1306_WIDTH), 0);
  ssd1306_WriteString(oled_line_buf, Font_7x10, White);
  
  ssd1306_Line(0,10,127,10,White); // title solid line

  for (int8_t ccc = SW_MATRIX_NUM_COLS-1; ccc >= 0; ccc--)
  {
    for (int8_t rrr = 0; rrr < SW_MATRIX_NUM_ROWS; rrr++)
    {
      printf("x%dy%d ", ccc, rrr);
    }
    printf("\n");
  }

  
  // // horizontal lines
  // ssd1306_Line(0,39,127,39,White);
  // ssd1306_Line(0,68,127,68,White);
  // ssd1306_Line(0,97,127,97,White);

  // // vertical lines
  // ssd1306_Line(25,10,25,127,White); 
  // ssd1306_Line(51,10,51,127,White);
  // ssd1306_Line(76,10,76,127,White);
  // ssd1306_Line(102,10,102,127,White);
}

int main(int argc, char *argv[])
{
  ssd1306_Fill(Black);
  // ----------------------------------------
  draw_profile();
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

