void ssd1306_data(unsigned char data);
void ssd1306_command(unsigned char command);
void ssd1306_set_coordinate(unsigned char x, unsigned char y);
void ssd1306_fill(unsigned char color);
void ssd1306_clear(void);
void ssd1306_clear_row(unsigned char row);
void ssd1306_clear_row_column(unsigned char row, unsigned char column_start, unsigned char column_end);
void ssd1306_init(const unsigned char dc, const unsigned char rst);

void ssd1306_draw_6x8_string(unsigned char x, unsigned char y, const char *string);
void ssd1306_draw_8x16_string(unsigned char x, unsigned char y, const char *string);
