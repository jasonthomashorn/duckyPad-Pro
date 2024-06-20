brightness_values

uint8_t save_settings(dp_global_settings* dps)
{
  memset(temp_buf, 0, TEMP_BUFSIZE);
  sprintf(temp_buf, "sleep_after_min %ld\nbi %d\nkbl %s\n", dps->sleep_after_ms/60000, dps->brightness_index, dps->current_kb_layout);
  printf("%s", temp_buf);
  return 0;
}

  void save_settings(void)
{
  if(f_open(&sd_file, "dp_settings.txt", FA_CREATE_ALWAYS | FA_WRITE) != 0)
    goto ss_end;
  memset(temp_buf, 0, PATH_SIZE);
  sprintf(temp_buf, "sleep_after_min %d\nbi %d\nkbl %s\n", dp_settings.sleep_after_ms/60000, brightness_index, curr_kb_layout);
  f_write(&sd_file, temp_buf, strlen(temp_buf), &bytes_read);
  ss_end:
  f_close(&sd_file);
}


  printf("goto_profile: %d\n", profile_number);
printf("lsa %d %d %f %d %f\n", i, dest_color[i], anime_struct->current_color[i], durations_frames, anime_struct->step[i]);
    printf("000 %d %ld\n", idx, current_frame);
    printf("fc %ld\n", frame_counter);
led_start_animation(&neo_anime[sw_number], color_red, ANIMATION_CROSS_FADE, 70);
void print_nomemory(void)
{
    ssd1306_Fill(Black);

    memset(oled_line_buf, 0, OLED_LINE_BUF_SIZE);
    sprintf(oled_line_buf, "Memory Allocation");
    ssd1306_SetCursor(center_line(strlen(oled_line_buf), 7, SSD1306_WIDTH), 35);
    ssd1306_WriteString(oled_line_buf, Font_7x10, White);

    memset(oled_line_buf, 0, OLED_LINE_BUF_SIZE);
    sprintf(oled_line_buf, "Failed!");
    ssd1306_SetCursor(center_line(strlen(oled_line_buf), 7, SSD1306_WIDTH), 47);
    ssd1306_WriteString(oled_line_buf, Font_7x10, White);

    memset(oled_line_buf, 0, OLED_LINE_BUF_SIZE);
    sprintf(oled_line_buf, "Instructions:");
    ssd1306_SetCursor(center_line(strlen(oled_line_buf), 7, SSD1306_WIDTH), 80);
    ssd1306_WriteString(oled_line_buf, Font_7x10, White);

    memset(oled_line_buf, 0, OLED_LINE_BUF_SIZE);
    sprintf(oled_line_buf, "duckyPad.com");
    ssd1306_SetCursor(center_line(strlen(oled_line_buf), 7, SSD1306_WIDTH), 92);
    ssd1306_WriteString(oled_line_buf, Font_7x10, White);

    ssd1306_UpdateScreen();
}

  valid_profile_count = get_valid_profile_count();
  if(valid_profile_count == 0)
    return PSCAN_ERROR_NO_PROFILE;

void goto_next_profile(void)
{
  int16_t next_profile_number = current_profile_number;
  while(1)
  {
    next_profile_number++;
    if(next_profile_number >= MAX_PROFILES)
      next_profile_number = 0;
    if(profile_number_to_index_lookup[next_profile_number] != -1)
      break;
  }
  printf("now: %d\n", next_profile_number);
  int16_t next_profile_index = profile_number_to_index_lookup[next_profile_number];
  restore_profile(&all_profile_info[next_profile_index]);
  current_profile_number = next_profile_number;
}

  printf("get_first_valid_profile_number: %d\n", get_first_valid_profile_number());
void goto_next_profile(void)
{
  int8_t next_profile_index = 0;
  while(1)
  {
    printf("gnp: %d\n", current_profile_number);
    current_profile_number++;
    if(current_profile_number >= MAX_PROFILES)
      current_profile_number = 0;
    if(profile_number_to_index_lookup[current_profile_number] == -1)
      continue;
    break;
  }
  printf("now: %d\n", current_profile_number);
}

for (size_t i = 0; i < MECH_OBSW_COUNT; i++)
  {
    uint8_t row = 0;
    uint8_t col = 0;
    index_to_rowcol(i, &row, &col);
    printf("%d: row%d col%d\n", i, row, col);
  }
void index_to_rowcol(uint8_t index, uint8_t *row, uint8_t *col)
{
    if(index >= MECH_OBSW_COUNT)
        return;
    *row = index / SW_MATRIX_NUM_COLS;
    *col = index % SW_MATRIX_NUM_COLS;
}
draw_profile(&all_profile_info[1]);

printf("load_profile_config: %s\n", filename_buf);
  printf("parse_profile_config_line: %s\n", this_line);
void mytest(void)
{
  uint8_t last_used_profile = get_last_used_profile();
}
void fill_default_color(profile_info* this_profile)
{
  if(this_profile == NULL)
    return;
  for (size_t i = 0; i < TOTAL_OBSW_COUNT; i++)
  {
    this_profile->sw_color[i][0] = DEFAULT_BG_RED;
    this_profile->sw_color[i][1] = DEFAULT_BG_GREEN;
    this_profile->sw_color[i][2] = DEFAULT_BG_BLUE;

    this_profile->sw_activation_color[i][0] = DEFAULT_KD_RED;
    this_profile->sw_activation_color[i][1] = DEFAULT_KD_GREEN;
    this_profile->sw_activation_color[i][2] = DEFAULT_KD_BLUE;
  }
}

    printf("this_key_index %d\n", this_key_index);
void parse_key_config_line(char* line, uint32_t buf_size, profile_info* this_profile)
{
  if(line == NULL || strlen(line) <= 2)
    return;
  printf("parse_key_config_line: %s\n", line);

  if(line[0] == 'z')
  {
    uint8_t this_key_index = atoi(line+1);
    if(this_key_index == 0)
      return;
    this_key_index--;
    if(this_key_index >= MAPPABLE_OBSW_COUNT)
      return;
    printf("111 %d\n", this_key_index);
    memset(this_profile->sw_name[this_key_index], 0, KEYNAME_SIZE);
    printf("222 %d\n", this_key_index);
    char* kn_start = goto_next_arg(line, buf_size);
    printf("zz: %d %s\n", this_key_index, kn_start);
  }

}
uint8_t get_last_used_profile(void)
{
  uint8_t ret = 0;

  FILE *sd_file = fopen("/sdcard/dp_stats.txt", "r");
  if(sd_file == NULL)
    return 1;

  memset(temp_buf, 0, TEMP_BUFSIZE);
  while(fgets(temp_buf, TEMP_BUFSIZE, sd_file))
  {
    if(strncmp(temp_buf, stat_last_used_profile, strlen(stat_last_used_profile)) == 0)
      ret = atoi(temp_buf+strlen(stat_last_used_profile));
  }

  if(ret >= MAX_PROFILES)
    ret = 0;

  fclose(sd_file);
  return ret;
}

      printf("%d %d: %s\n", count, this_profile_number, dir->d_name);
void load_keynames(uint8_t pf_size)
{
  for (uint8_t i = 0; i < pf_size; i++)
  {
    // print_profile_info(&all_profile_info[i]);
    memset(filename_buf, 0, FILENAME_BUFSIZE);
    sprintf(filename_buf, "%s/%s", SD_MOUNT_POINT, all_profile_info[i].dir_path);
    printf("%s\n", filename_buf);
  }
}

profile_info current_profile_info;
printf("jjj %d\n", valid_profile_count);
void load_profile(uint8_t pid)
{
  ;
}

#define FILENAME_BUFSIZE 64

typedef struct
{
    uint8_t profile_id;
    char name[FILENAME_BUFSIZE];
} profile_info;

uint8_t get_profile_dirname(uint8_t pid, char* pname_buf, uint32_t pname_buf_size)
{
  struct dirent *dir;
  DIR *d = opendir(SD_MOUNT_POINT);
  memset(pname_buf, 0, pname_buf_size);
  if(d) 
  {
    while ((dir = readdir(d)) != NULL)
    {
      if(dir->d_type != DT_DIR)
        continue;
      if(is_profile_dir(dir->d_name) == 0)
        continue;
      if(atoi(dir->d_name + strlen(profile_dir_prefix)) != pid)
        continue;
      available_profile_list[this_profile_number] = 1;
    }
  }
  closedir(d);
}


void scan_profiles()
{
  struct dirent *dir;
  DIR *d = opendir(SD_MOUNT_POINT);
  memset(available_profile_list, 0, MAX_PROFILES);
  if(d) 
  {
    while ((dir = readdir(d)) != NULL)
    {
      if(dir->d_type != DT_DIR)
        continue;
      if(is_profile_dir(dir->d_name) == 0)
        continue;
      uint8_t this_profile_number = atoi(dir->d_name + strlen(profile_dir_prefix));
      if(this_profile_number >= MAX_PROFILES)
        continue;
      available_profile_list[this_profile_number] = 1;
    }
  }
  closedir(d);
}


void mytest(void)
{
  uint8_t last_used_profile = get_last_used_profile();
  if(last_used_profile == 0)
    change_profile(NEXT_PROFILE);
  else
    restore_profile(last_profile);
}
void mytest(void)
{
  // printf("mytest: %d\n", get_last_used_profile());
  scan_profiles();
  for (int i = 0; i < MAX_PROFILES; i++)
  {
    if(available_profile_list[i])
      printf("%d\n", i);
  }
  
}


void step_profile(uint8_t direction)
{
  
}


    printf("%d %d %ld %s\n", sdf, dp_settings.brightness_index, dp_settings.sleep_after_ms, dp_settings.current_kb_layout);


--------------

#include <dirent.h> 

int8_t list_files(void)
{
  DIR *d;
  struct dirent *dir;
  d = opendir(SD_MOUNT_POINT);
  if (d) {
    while ((dir = readdir(d)) != NULL) {
      printf("%s\n", dir->d_name);
    }
    closedir(d);
  }
  return 0;
}

void get_rc(void)
{
    UBaseType_t items_in_queue = uxQueueMessagesWaiting(rotary_encoder_event_queue);
    printf("queue: %d\n", items_in_queue);
    // Wait for incoming events on the event queue.
    rotary_encoder_event_t event = { 0 };
    if (xQueueReceive(rotary_encoder_event_queue, &event, 0) == pdTRUE)
        printf("Event: id: %d pos: %ld, dir: %d\n", event.state.id, event.state.position, event.state.direction);
}


-------------


void input_test(void)
{
    memset(this_sw_matrix_state, 0, SW_MATRIX_BUF_SIZE);
    gpio_set_level(SWM_COL0_GPIO, 1);
    gpio_set_level(SWM_COL1_GPIO, 0);
    gpio_set_level(SWM_COL2_GPIO, 0);
    gpio_set_level(SWM_COL3_GPIO, 0);
    scan_row(0);

    gpio_set_level(SWM_COL0_GPIO, 0);
    gpio_set_level(SWM_COL1_GPIO, 1);
    gpio_set_level(SWM_COL2_GPIO, 0);
    gpio_set_level(SWM_COL3_GPIO, 0);
    scan_row(1);

    gpio_set_level(SWM_COL0_GPIO, 0);
    gpio_set_level(SWM_COL1_GPIO, 0);
    gpio_set_level(SWM_COL2_GPIO, 1);
    gpio_set_level(SWM_COL3_GPIO, 0);
    scan_row(2);

    gpio_set_level(SWM_COL0_GPIO, 0);
    gpio_set_level(SWM_COL1_GPIO, 0);
    gpio_set_level(SWM_COL2_GPIO, 0);
    gpio_set_level(SWM_COL3_GPIO, 1);
    scan_row(3);

    for (int rrr = 0; rrr < SW_MATRIX_NUM_ROWS; ++rrr)
    {
        for (int ccc = 0; ccc < SW_MATRIX_NUM_COLS; ++ccc)
        {
            printf("R%dC%dS%d ", rrr, ccc, this_sw_matrix_state[rowcol_to_index(rrr, ccc)]);
            // printf("%d ", this_sw_matrix_state[rowcol_to_index(rrr, ccc)]);
        }
        printf("\n");
    }

    printf("---------------\n");
}

R0C0S1 R1C0S0 R2C0S0 R3C0S0 R4C0S0 
R0C1S0 R1C1S0 R2C1S0 R3C1S0 R4C1S0 
R0C2S0 R1C2S0 R2C2S0 R3C2S0 R4C2S0 
R0C3S1 R1C3S0 R2C3S0 R3C3S0 R4C3S0 

--------------------------

void input_test(void)
{
    // gpio_set_level(SWM_COL0_GPIO, 1);
    // gpio_set_level(SWM_COL1_GPIO, 0);
    // gpio_set_level(SWM_COL2_GPIO, 0);
    // gpio_set_level(SWM_COL3_GPIO, 0);

    // printf("%d ", gpio_get_level(SWM_ROW0_GPIO));
    // printf("%d ", gpio_get_level(SWM_ROW1_GPIO));
    // printf("%d ", gpio_get_level(SWM_ROW2_GPIO));
    // printf("%d ", gpio_get_level(SWM_ROW3_GPIO));
    // printf("%d\n", gpio_get_level(SWM_ROW4_GPIO));

    for (int ccc = 0; ccc < SW_MATRIX_NUM_COLS; ++ccc)
    {
        for (int rrr = 0; rrr < SW_MATRIX_NUM_ROWS; ++rrr)
        {
            printf("R%dC%dI%02d ", rrr, ccc, rowcol_to_index(rrr, ccc));
        }
        printf("\n");
    }

    printf("---------------\n");
}



R0C0I00 R1C0I04 R2C0I08 R3C0I12 R4C0I16 
R0C1I01 R1C1I05 R2C1I09 R3C1I13 R4C1I17 
R0C2I02 R1C2I06 R2C2I10 R3C2I14 R4C2I18 
R0C3I03 R1C3I07 R2C3I11 R3C3I15 R4C3I19 


-0------------------------------



void input_test(void)
{
    // gpio_set_level(SWM_COL0_GPIO, 1);
    // gpio_set_level(SWM_COL1_GPIO, 0);
    // gpio_set_level(SWM_COL2_GPIO, 0);
    // gpio_set_level(SWM_COL3_GPIO, 0);

    // printf("%d ", gpio_get_level(SWM_ROW0_GPIO));
    // printf("%d ", gpio_get_level(SWM_ROW1_GPIO));
    // printf("%d ", gpio_get_level(SWM_ROW2_GPIO));
    // printf("%d ", gpio_get_level(SWM_ROW3_GPIO));
    // printf("%d\n", gpio_get_level(SWM_ROW4_GPIO));

    for (int rrr = 0; rrr < SW_MATRIX_NUM_ROWS; ++rrr)
    {
        for (int ccc = 0; ccc < SW_MATRIX_NUM_COLS; ++ccc)
        {
            printf("R%dC%dI%d ", rrr, ccc, rowcol_to_index(rrr, ccc));
        }
        printf("\n");
    }

    printf("---------------\n");
}


---------------
R0C0I0 R0C1I1 R0C2I2 R0C3I3 
R1C0I4 R1C1I5 R1C2I6 R1C3I7 
R2C0I8 R2C1I9 R2C2I10 R2C3I11 
R3C0I12 R3C1I13 R3C2I14 R3C3I15 
R4C0I16 R4C1I17 R4C2I18 R4C3I19 



void input_test(void)
{
    // switch_event_t this_event;
    // if (xQueueReceive(switch_event_queue, &this_event, 0) == pdTRUE)
    //  printf("id: %d lvl: %d\n", this_event.id, this_event.level);
}


    // printf("%d\n", gpio_get_level(SD_CARD_DETECT_GPIO));
void app_main(void)
{
    vTaskDelay(pdMS_TO_TICKS(500)); // brief delay in case of SD card removal reboot
    gpio_install_isr_service(0); // BEFORE GPIO INIT
    my_rotary_encoder_init();
    switch_init();
    oled_init();
    // if (sd_init())
    //     print_nosd();
    neopixel_init();
    vTaskDelay(pdMS_TO_TICKS(500));
    print_nosd();

    ssd1306_SetCursor(20, 40);
    ssd1306_WriteString("haha!!", Font_7x10, White);
    ssd1306_UpdateScreen();

    while(1)
    {
        vTaskDelay(pdMS_TO_TICKS(500));
    }
}
void sw_isr(void * args)
{
    switch_event_t sw_event = {
        .id = (uint8_t)args,
        .level = 1 - gpio_get_level(sw_index_to_gpio_lookup[sw_event.id]),
    };
    uint32_t now = xTaskGetTickCountFromISR();
    sw_status[sw_event.id].level = sw_event.level;

    if(now - sw_status[sw_event.id].last_press_ms <= 33)
        return;
    xQueueSendFromISR(switch_event_queue, &sw_event, NULL);
    sw_status[sw_event.id].last_press_ms = now;
}

void input_test(void)
{
    // UBaseType_t items_in_queue = uxQueueMessagesWaiting(switches_event_queue);
    // printf("queue: %d\n", items_in_queue);

    for (size_t i = 0; i < TOTAL_SW_COUNT; i++)
    {
        printf("%d ", switch_status_all[i]);
    }
    printf("\n");

    if (xQueueReceive(rotary_encoder_event_queue, &event, 0) == pdTRUE)
        printf("Event: id: %d pos: %ld, dir: %d\n", event.state.id, event.state.position, event.state.direction);
    
}

// #define SW_17_U0TX_GPIO GPIO_NUM_43
#define SW_17_SPICS1_GPIO GPIO_NUM_26
#define SW_18_U0RX_GPIO GPIO_NUM_44
// printf("cs1: %d\n", gpio_get_level(SW_17_GPIO));
    // printf("count: %d\n", count);
    // printf("%ld\n", );
// media keys, working
uint8_t keycode[6] = {0x40, 0, 0, 0, 0, 0};
    tud_hid_report(2, keycode, 6);
    vTaskDelay(pdMS_TO_TICKS(100));
    memset(keycode, 0, 6);
    tud_hid_report(2, keycode, 6);

// keyboard keys, working
    ESP_LOGI(TAG, "Sending Keyboard report");
    uint8_t keycode[6] = {HID_KEY_A, 0, 0, 0, 0, 0};
    // the first argument is HID ID?
    tud_hid_keyboard_report(1, 0, keycode);
    vTaskDelay(pdMS_TO_TICKS(100));
    tud_hid_keyboard_report(1, 0, NULL);


static void hid_host_generic_report_callback(const uint8_t *const data, const int length)
{
    printf("@@@@@\n");
    for (int i = 0; i < length; i++) 
    {
        printf("%02X", data[i]);
    }
    putchar('\n');
}



/* Initialize the oled screen */
void ssd1306_init(void) {
    // Init OLED
    ssd1306_write_cmd_byte(0xAE); //display off
    ssd1306_write_cmd_byte(0x20); //Set Memory Addressing Mode
    ssd1306_write_cmd_byte(0x00); // 00b,Horizontal Addressing Mode; 01b,Vertical Addressing Mode;
                                // 10b,Page Addressing Mode (RESET); 11b,Invalid

    ssd1306_write_cmd_byte(0xB0); //Set Page Start Address for Page Addressing Mode,0-7

#ifdef SSD1306_MIRROR_VERT
    ssd1306_write_cmd_byte(0xC0); // Mirror vertically
#else
    ssd1306_write_cmd_byte(0xC8); //Set COM Output Scan Direction
#endif

    ssd1306_write_cmd_byte(0x00); //---set low column address
    ssd1306_write_cmd_byte(0x10); //---set high column address

    ssd1306_write_cmd_byte(0x40); //--set start line address - CHECK

    // ssd1306_SetContrast(0xFF);

#ifdef SSD1306_MIRROR_HORIZ
    ssd1306_write_cmd_byte(0xA0); // Mirror horizontally
#else
    ssd1306_write_cmd_byte(0xA1); //--set segment re-map 0 to 127 - CHECK
#endif


// Set multiplex ratio.
#if (SSD1306_HEIGHT == 128)
    // Found in the Luma Python lib for SH1106.
    ssd1306_write_cmd_byte(0xFF);
#else
    ssd1306_write_cmd_byte(0xA8); //--set multiplex ratio(1 to 64) - CHECK
#endif

#if (SSD1306_HEIGHT == 32)
    ssd1306_write_cmd_byte(0x1F); //
#elif (SSD1306_HEIGHT == 64)
    ssd1306_write_cmd_byte(0x3F); //
#elif (SSD1306_HEIGHT == 128)
    ssd1306_write_cmd_byte(0x3F); // Seems to work for 128px high displays too.
#else
#error "Only 32, 64, or 128 lines of height are supported!"
#endif

    ssd1306_write_cmd_byte(0xA4); //0xa4,Output follows RAM content;0xa5,Output ignores RAM content

    ssd1306_write_cmd_byte(0xD3); //-set display offset - CHECK
    ssd1306_write_cmd_byte(0x00); //-not offset

    ssd1306_write_cmd_byte(0xD5); //--set display clock divide ratio/oscillator frequency
    ssd1306_write_cmd_byte(0xF0); //--set divide ratio

    ssd1306_write_cmd_byte(0xD9); //--set pre-charge period
    ssd1306_write_cmd_byte(0x22); //

    ssd1306_write_cmd_byte(0xDA); //--set com pins hardware configuration - CHECK
#if (SSD1306_HEIGHT == 32)
    ssd1306_write_cmd_byte(0x02);
#elif (SSD1306_HEIGHT == 64)
    ssd1306_write_cmd_byte(0x12);
#elif (SSD1306_HEIGHT == 128)
    ssd1306_write_cmd_byte(0x12);
#else
#error "Only 32, 64, or 128 lines of height are supported!"
#endif

    ssd1306_write_cmd_byte(0xDB); //--set vcomh
    ssd1306_write_cmd_byte(0x20); //0x20,0.77xVcc

    ssd1306_write_cmd_byte(0x8D); //--set DC-DC enable
    ssd1306_write_cmd_byte(0x14); //
    ssd1306_write_cmd_byte(0xAF); //display on

    // Clear screen
    ssd1306_Fill(Black);

    // Set default values for screen object
    SSD1306.CurrentX = 0;
    SSD1306.CurrentY = 0;
}


/* Initialize the oled screen */
void ssd1306_init(void) {
ssd1306_write_cmd_byte(0xAE);  // (p33) 11. display OFF

// set in display function
ssd1306_write_cmd_byte(0x00);  // (p23) 1. set lower column address
ssd1306_write_cmd_byte(0x10);  // (p23) 2. set higher column address

// For SSD1306 - This is Horizontal mode
// For SH1107 - This is page mode (Does not increment rows)
ssd1306_write_cmd_byte(0x20);  // (p24) 3. Set Memory addressing mode

ssd1306_write_cmd_byte(0x81);  // (p28) 4. contrast control
ssd1306_write_cmd_byte(0x2F);  // 0x2F, 0x4F, 0x8F - depending on source

ssd1306_write_cmd_byte(0xA0);  // (p29) 5. set segment remap (L->R | T->B)

ssd1306_write_cmd_byte(0xA8);            // (p30) 6. multiplex ratio
ssd1306_write_cmd_byte(127);  // duty = 1/64 = 0x3F

ssd1306_write_cmd_byte(0xA4);  // (p30) 7. set entire display off/on (0xA4/0xA5)

ssd1306_write_cmd_byte(0xA6);  // (p31) 8. 0xA6/0xA7 = normal (W on Bk) / inverted (Bk on W) display

ssd1306_write_cmd_byte(0xD3);  // (p32) 9. set display offset
ssd1306_write_cmd_byte(0);

ssd1306_write_cmd_byte(0xB0);  // (p33) 12. set page address

ssd1306_write_cmd_byte(0xC0);  // (p34) 13. common output scan direction normal/vertically flipped (0xC0/0xC8)


ssd1306_write_cmd_byte(0xDA);  // set com pins
ssd1306_write_cmd_byte(0x12);

ssd1306_write_cmd_byte(0xD5);  // (p35) 14. set clock divide ratio/OSC frequency
ssd1306_write_cmd_byte(0x50);  // fosc (POR) = 0x50 = 100Hz

ssd1306_write_cmd_byte(0xD9);  // (p36) 15. set discharge/pre-charge period
ssd1306_write_cmd_byte(0x22);  // 0x2* : pre-charge = 2 DCLKs, 0x*2 : discharge = 2 DCLKs

ssd1306_write_cmd_byte(0xDB);  // (p37) 16. set VCOM deselect level
ssd1306_write_cmd_byte(0x40);  // //0x40 | 0x35; Vcomh = 0.43 + 0x35 * 0.006415 * Vref

ssd1306_write_cmd_byte(0xDC);  // (p38) 17. set display start line
ssd1306_write_cmd_byte(0x00);

ssd1306_write_cmd_byte(0xAD);  // (p31) 10. DC-DC control mode
ssd1306_write_cmd_byte(0x8A);  // 0x8A //Set DC-DC enable 1.0SF, DC-DC disabled (external Vpp)
ssd1306_write_cmd_byte(0xAF);  // (p33) 11. display ON

}
    spi_device_acquire_bus(my_spi_handle, portMAX_DELAY);
    ssd1306_init();
    // ssd1306_WriteString("hello", Font_7x10, White);
    ssd1306_UpdateScreen();
    spi_device_release_bus(my_spi_handle);

char* my_data = "hello";
spi_transaction_t my_transaction;

void write_test(void)
{
    ESP_ERROR_CHECK(spi_device_acquire_bus(my_spi_handle, portMAX_DELAY));
    uint8_t tx_size_bytes = strlen(my_data);

    memset(&my_transaction, 0, sizeof(my_transaction));
    my_transaction.length = tx_size_bytes * 8;
    my_transaction.tx_buffer = my_data;
    ESP_ERROR_CHECK(spi_device_polling_transmit(my_spi_handle, &my_transaction));
    spi_device_release_bus(my_spi_handle);
}

    spi_transaction_t t = {
        .length = 5,
        .flags = SPI_TRANS_USE_TXDATA,
        .tx_data = test,
    };
while(1)
    {
        printf("GPIO%d: %d\n", SW_PLUS, gpio_get_level(SW_PLUS));
        printf("GPIO%d: %d\n", SW_MINUS, gpio_get_level(SW_MINUS));
        printf("GPIO%d: %d\n", RE1_SW, gpio_get_level(RE1_SW));
        printf("GPIO%d: %d\n", RE1_A, gpio_get_level(RE1_A));
        printf("GPIO%d: %d\n", RE1_B, gpio_get_level(RE1_B));
        printf("GPIO%d: %d\n", RE2_SW, gpio_get_level(RE2_SW));
        printf("GPIO%d: %d\n", RE2_A, gpio_get_level(RE2_A));
        printf("GPIO%d: %d\n", RE2_B, gpio_get_level(RE2_B));
        printf("------------\n\n");
        vTaskDelay(pdMS_TO_TICKS(250));
    }
switches
while(1)
    {
        printf("GPIO%d: %d\n", SW_1, gpio_get_level(SW_1));
        printf("GPIO%d: %d\n", SW_2, gpio_get_level(SW_2));
        printf("GPIO%d: %d\n", SW_3, gpio_get_level(SW_3));
        printf("GPIO%d: %d\n", SW_4, gpio_get_level(SW_4));
        printf("GPIO%d: %d\n", SW_5, gpio_get_level(SW_5));
        printf("GPIO%d: %d\n", SW_6, gpio_get_level(SW_6));
        printf("GPIO%d: %d\n", SW_7, gpio_get_level(SW_7));
        printf("GPIO%d: %d\n", SW_8, gpio_get_level(SW_8));
        printf("GPIO%d: %d\n", SW_9, gpio_get_level(SW_9));
        printf("GPIO%d: %d\n", SW_10, gpio_get_level(SW_10));
        printf("GPIO%d: %d\n", SW_11, gpio_get_level(SW_11));
        printf("GPIO%d: %d\n", SW_12, gpio_get_level(SW_12));
        printf("GPIO%d: %d\n", SW_13, gpio_get_level(SW_13));
        printf("GPIO%d: %d\n", SW_14, gpio_get_level(SW_14));
        printf("GPIO%d: %d\n", SW_15, gpio_get_level(SW_15));
        printf("GPIO%d: %d\n", SW_16, gpio_get_level(SW_16));
        printf("GPIO%d: %d\n", SW_17, gpio_get_level(SW_17));
        // printf("GPIO%d: %d\n", SW_18, gpio_get_level(SW_18));
        printf("GPIO%d: %d\n", SW_19_U0RX, gpio_get_level(SW_19_U0RX));
        printf("GPIO%d: %d\n", SW_20, gpio_get_level(SW_20));
        printf("------------\n\n");
        vTaskDelay(pdMS_TO_TICKS(1000));
    }

/*
 * SPDX-FileCopyrightText: 2022-2023 Espressif Systems (Shanghai) CO LTD
 *
 * SPDX-License-Identifier: Unlicense OR CC0-1.0
 */

#include <stdlib.h>
#include "esp_log.h"
#include "freertos/FreeRTOS.h"
#include "freertos/task.h"
#include "tinyusb.h"
#include "class/hid/hid_device.h"
#include "driver/gpio.h"

#define APP_BUTTON (GPIO_NUM_0) // Use BOOT signal by default
static const char *TAG = "example";

/************* TinyUSB descriptors ****************/

#define TUSB_DESC_TOTAL_LEN      (TUD_CONFIG_DESC_LEN + CFG_TUD_HID * TUD_HID_DESC_LEN)

/**
 * @brief HID report descriptor
 *
 * In this example we implement Keyboard + Mouse HID device,
 * so we must define both report descriptors
 */
const uint8_t hid_report_descriptor[] = {
    TUD_HID_REPORT_DESC_KEYBOARD(HID_REPORT_ID(HID_ITF_PROTOCOL_KEYBOARD) ),
    TUD_HID_REPORT_DESC_MOUSE(HID_REPORT_ID(HID_ITF_PROTOCOL_MOUSE) )
};

/**
 * @brief String descriptor
 */
const char* hid_string_descriptor[5] = {
    // array of pointer to string descriptors
    (char[]){0x09, 0x04},  // 0: is supported language is English (0x0409)
    "TinyUSB",             // 1: Manufacturer
    "TinyUSB Device",      // 2: Product
    "123456",              // 3: Serials, should use chip ID
    "Example HID interface",  // 4: HID
};

/**
 * @brief Configuration descriptor
 *
 * This is a simple configuration descriptor that defines 1 configuration and 1 HID interface
 */
static const uint8_t hid_configuration_descriptor[] = {
    // Configuration number, interface count, string index, total length, attribute, power in mA
    TUD_CONFIG_DESCRIPTOR(1, 1, 0, TUSB_DESC_TOTAL_LEN, TUSB_DESC_CONFIG_ATT_REMOTE_WAKEUP, 100),

    // Interface number, string index, boot protocol, report descriptor len, EP In address, size & polling interval
    TUD_HID_DESCRIPTOR(0, 4, false, sizeof(hid_report_descriptor), 0x81, 16, 10),
};

/********* TinyUSB HID callbacks ***************/

// Invoked when received GET HID REPORT DESCRIPTOR request
// Application return pointer to descriptor, whose contents must exist long enough for transfer to complete
uint8_t const *tud_hid_descriptor_report_cb(uint8_t instance)
{
    // We use only one interface and one HID report descriptor, so we can ignore parameter 'instance'
    return hid_report_descriptor;
}

// Invoked when received GET_REPORT control request
// Application must fill buffer report's content and return its length.
// Return zero will cause the stack to STALL request
uint16_t tud_hid_get_report_cb(uint8_t instance, uint8_t report_id, hid_report_type_t report_type, uint8_t* buffer, uint16_t reqlen)
{
  (void) instance;
  (void) report_id;
  (void) report_type;
  (void) buffer;
  (void) reqlen;

  return 0;
}

// Invoked when received SET_REPORT control request or
// received data on OUT endpoint ( Report ID = 0, Type = 0 )
void tud_hid_set_report_cb(uint8_t instance, uint8_t report_id, hid_report_type_t report_type, uint8_t const* buffer, uint16_t bufsize)
{
}

/********* Application ***************/

typedef enum {
    MOUSE_DIR_RIGHT,
    MOUSE_DIR_DOWN,
    MOUSE_DIR_LEFT,
    MOUSE_DIR_UP,
    MOUSE_DIR_MAX,
} mouse_dir_t;

#define DISTANCE_MAX        125
#define DELTA_SCALAR        5

static void mouse_draw_square_next_delta(int8_t *delta_x_ret, int8_t *delta_y_ret)
{
    static mouse_dir_t cur_dir = MOUSE_DIR_RIGHT;
    static uint32_t distance = 0;

    // Calculate next delta
    if (cur_dir == MOUSE_DIR_RIGHT) {
        *delta_x_ret = DELTA_SCALAR;
        *delta_y_ret = 0;
    } else if (cur_dir == MOUSE_DIR_DOWN) {
        *delta_x_ret = 0;
        *delta_y_ret = DELTA_SCALAR;
    } else if (cur_dir == MOUSE_DIR_LEFT) {
        *delta_x_ret = -DELTA_SCALAR;
        *delta_y_ret = 0;
    } else if (cur_dir == MOUSE_DIR_UP) {
        *delta_x_ret = 0;
        *delta_y_ret = -DELTA_SCALAR;
    }

    // Update cumulative distance for current direction
    distance += DELTA_SCALAR;
    // Check if we need to change direction
    if (distance >= DISTANCE_MAX) {
        distance = 0;
        cur_dir++;
        if (cur_dir == MOUSE_DIR_MAX) {
            cur_dir = 0;
        }
    }
}

static void app_send_hid_demo(void)
{
    // Keyboard output: Send key 'a/A' pressed and released
    ESP_LOGI(TAG, "Sending Keyboard report");
    uint8_t keycode[6] = {HID_KEY_A};
    tud_hid_keyboard_report(HID_ITF_PROTOCOL_KEYBOARD, 0, keycode);
    vTaskDelay(pdMS_TO_TICKS(50));
    tud_hid_keyboard_report(HID_ITF_PROTOCOL_KEYBOARD, 0, NULL);

    // Mouse output: Move mouse cursor in square trajectory
    ESP_LOGI(TAG, "Sending Mouse report");
    int8_t delta_x;
    int8_t delta_y;
    for (int i = 0; i < (DISTANCE_MAX / DELTA_SCALAR) * 4; i++) {
        // Get the next x and y delta in the draw square pattern
        mouse_draw_square_next_delta(&delta_x, &delta_y);
        tud_hid_mouse_report(HID_ITF_PROTOCOL_MOUSE, 0x00, delta_x, delta_y, 0, 0);
        vTaskDelay(pdMS_TO_TICKS(20));
    }
}

void app_main(void)
{
    // Initialize button that will trigger HID reports
    const gpio_config_t boot_button_config = {
        .pin_bit_mask = BIT64(APP_BUTTON),
        .mode = GPIO_MODE_INPUT,
        .intr_type = GPIO_INTR_DISABLE,
        .pull_up_en = true,
        .pull_down_en = false,
    };
    ESP_ERROR_CHECK(gpio_config(&boot_button_config));

    ESP_LOGI(TAG, "USB initialization");
    const tinyusb_config_t tusb_cfg = {
        .device_descriptor = NULL,
        .string_descriptor = hid_string_descriptor,
        .string_descriptor_count = sizeof(hid_string_descriptor) / sizeof(hid_string_descriptor[0]),
        .external_phy = false,
        .configuration_descriptor = hid_configuration_descriptor,
    };

    ESP_ERROR_CHECK(tinyusb_driver_install(&tusb_cfg));
    ESP_LOGI(TAG, "USB initialization DONE");

    while (1) {
        if (tud_mounted()) {
            static bool send_hid_data = true;
            if (send_hid_data) {
                app_send_hid_demo();
            }
            send_hid_data = !gpio_get_level(APP_BUTTON);
        }
        vTaskDelay(pdMS_TO_TICKS(100));
    }
}
