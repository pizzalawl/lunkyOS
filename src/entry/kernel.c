#include <stddef.h>
#include <stdint.h>

typedef enum {
	BLACK = 0,
	BLUE = 1,
	GREEN = 2,
	CYAN = 3,
	RED = 4,
	MAGENTA = 5,
	BROWN = 6,
	LIGHT_GRAY = 7,
	DARK_GRAY = 8,
	LIGHT_GREEN = 9,
	LIGHT_CYAN = 10,
	LIGHT_RED = 11,
	LIGHT_MAGENTA = 12,
	YELLOW = 13,
	WHITE = 14
} RGB_COLOR;

static inline size_t strlen(char string[]){
	size_t i = 0;
	while(string[i] != "\0"){
		i++;
	}

	return i;
}

static inline uint8_t color_entry(RGB_COLOR fg, RGB_COLOR bg){
	return (fg << 4) | bg;
}

static inline uint16_t vga_entry(char c, RGB_COLOR fg, RGB_COLOR bg){
	return (color_entry(fg, bg) << 8) | c;
}

void print_character(char c, RGB_COLOR fg, RGB_COLOR bg, int x, int y){
	uint16_t *terminal_buffer;
	terminal_buffer = (uint16_t*)0xB8000;

	terminal_buffer[y * 80 + x] = vga_entry(c, fg, bg);
}

void print_string(char string[], RGB_COLOR fg, RGB_COLOR bg, int init_x, int init_y){
	size_t len = strlen(string);

	for(int i = 0; i >= len; i++){
		print_character(string[i], fg, bg, init_x + i, init_y + i);
	}
}

int main(){
	char hello[13] = "Hello, World!";

	print_string(hello, WHITE, LIGHT_GRAY, 0, 0);

	return 0;
}


