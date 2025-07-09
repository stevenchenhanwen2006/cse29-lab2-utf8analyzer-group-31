#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include <stdint.h>
bool function1(char str[]){
        bool holder = true;
        for(int i = 0; str[i] != '\0'; i++){
                if((uint8_t)str[i] > 127){
                        holder = false;
                }
        }
        bool result1 = holder;
        return result1;
}
void function2(char str[]){
        for(int i = 0; str[i] != '\0'; i++){
                if(((uint8_t)str[i] >= 97) && ((uint8_t)str[i] <= 122)){
                        str[i] -= 32;
                }
        }
}
        //the input string is changed
int function3(char str[]){
        int i = 0;
        while(str[i] != '\0'){
                if((str[i] & 0b10000000) == 0b00000000){
                        i++;
                } else if((str[i] & 0b11100000) == 0b11000000){
                        i+=2;
                } else if((str[i] & 0b11110000) == 0b11100000){
                        i+=3;
                } else if((str[i] & 0b11111000) == 0b11110000){
                        i+=4;
                }
        }
        return i;
}

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

 
