#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include <stdint.h>

void function7(const char *s) { 
	int end = 0; 
	for (int i = 0; s[end]  != '\0' && i < 6; i++) {
		unsigned char c = (unsigned char)s[i]; 
		int len; 

		if ((c & 0x80) == 0x00){
			len = 1; 
		} 
		else if ((c & 0xE0) == 0xC0){
			len = 2;
		}
		else if ((c & 0xF0) == 0xE0) {
			len = 3; 
		}
		else {
			len = 4;
		}
		end += len;  
	}
	printf("%.*s\n", end, s); 
}



int main(int argc, char *argv[]) {
    if (argc != 2) {
        fprintf(stderr, "Usage: utf8analyzer \"<UTF-8 encoded string>\"\n");
        return 1;
    }
}

 
