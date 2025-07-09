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
int function4(char str[]){
        int index = 0;
        int codepoint_length = 0;
        int count = 0;
        while(str[index] != 0){
                if((str[index] & 0b10000000) == 0b00000000){
                        codepoint_length = 1;
                }
                else if((str[index] & 0b11100000) == 0b11000000){
                        codepoint_length = 2;
                }
                else if((str[index] & 0b11110000) == 0b11100000){
                        codepoint_length = 3;
                }
                else if((str[index] & 0b11111000) == 0b11110000){
                        codepoint_length = 4;
                }
                count++;
                index += codepoint_length;
        }
        return count;
}
void function5(char str[]){
        int index = 0;
        int codepoint_length = 0;
        int result_index = 0;
        puts("Code points as decimal numbers: ");
        while(str[index] != 0){
                int codepoint;
                if((str[index] & 0b10000000) == 0b00000000){
                        codepoint_length = 1;
                        codepoint = str[index] & 0b01111111;
                }
                else if((str[index] & 0b11100000) == 0b11000000){
                        codepoint_length = 2;
                        codepoint = str[index] & 0b00011111;
                }
                else if((str[index] & 0b11110000) == 0b11100000){
                        codepoint_length = 3;
                        codepoint = str[index] & 0b00001111;
                }
                else if((str[index] & 0b11111000) == 0b11110000){
                        codepoint_length = 4;
                        codepoint = str[index] & 0b00000111;
                }
                for(int i = i; i < codepoint_length; i++){
                        codepoint = codepoint << 6;
                        codepoint = codepoint | (str[index + i] & 0b00111111);
                }
                printf("%d ",codepoint);
                index += codepoint_length;
        }
        puts("\n");
}
void function6(char str[]){
        int index = 0;
        int codepoint_length = 0;
        puts("Bytes per code point: ");
        while(str[index] != 0){
                if((str[index] & 0b10000000) == 0b00000000){
                        codepoint_length = 1;
                }
                else if((str[index] & 0b11100000) == 0b11000000){
                        codepoint_length = 2;
                }
                else if((str[index] & 0b11110000) == 0b11100000){
                        codepoint_length = 3;
                }
                else if((str[index] & 0b11111000) == 0b11110000){
                        codepoint_length = 4;
                }
                printf("%d ",codepoint_length);
                index += codepoint_length;
        }
        puts("\n");
}

void function_7(char str[]) {
        int end = 0;
        for (int i = 0; str[end]  != '\0' && i < 6; i++) {
                int len;
		
                if ((str[end] & 0b10000000) == 0b10000000){
                        len = 1;
                }
                else if ((str[end] & 0b11100000) == 0b11000000){
                        len = 2;
                }
                else if ((str[end] & 0b11110000) == 0b11100000) {
                        len = 3;
                }
                else {
                        len = 4;
                }
                end += len;
        }
        printf("%.*s\n", end, str);
}


int main(int argc, char *argv[]) {
    if (argc != 2) {
        fprintf(stderr, "Usage: utf8analyzer \"<UTF-8 encoded string>\"\n");
        return 1;
    }
	
    char buffer[10];
    fgets(buffer,10,stdin);
	printf("Valid ASCII" %s, function1(buffer)?"true":"false);
	function2(buffer);
	printf("UPPERCASED ASCII": %s", buffer);
	print("lenght in bytes": %d", function3(buffer));
    int result4 = function_4(buffer);
    printf("Number of codepoints: %d",result4);
    puts("\n");

    function_5(buffer);
    function_6(buffer);
    function_7(buffer); 
}

 
