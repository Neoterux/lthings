#include <stddef.h>
#include <string.h>
#include <stdlib.h>
#include <stdio.h>

#define INT_LENGTH 32

char* get_bits(int v)
{
	char bits[INT_LENGTH +4];
//	printf("The size assigned to bits is: %d", INT_LENGTH);
	size_t length = sizeof(bits);
	//printf("The size of char[] is %lu\n", length);
	unsigned short tmp = 0;
	for (int i = 0; i < length; i++) {
		tmp = tmp%8;
		if (i>0 &&  !tmp){
			tmp++;
			bits[i] = ' ';
		}
		else
			bits[i] = '0';
		tmp++;
	}
	bits[length]='\0';
	
	if(v < 0){
		bits[0]= '1';
		v = abs(v);
	}
	short pos = length-1;
	while(v){
		if (bits[pos--] != ' '){
			bits[pos] = (v%2)? '1' :'0';
			v >>= 1;
		}
	}
	
	char *out = malloc(length);
	strcpy(out, &bits[0]);
	return out;
}
