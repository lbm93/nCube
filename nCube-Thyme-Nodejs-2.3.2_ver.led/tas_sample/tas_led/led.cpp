#include <wiringPi.h>
#include <stdio.h>
#include <string.h>

#define PIN 0

int turn_on(){
	printf("%s\n", "Light ON!");
	digitalWrite(PIN, HIGH); 
	
	return 0;
}

int turn_off(){
	printf("%s\n", "Light OFF!");
	digitalWrite(PIN, LOW); 
	
	return 0;
}

int init(){
	printf("%s\n", "Init Light!");
	digitalWrite(PIN, HIGH); 
}

int main (int argc,char *argv[])
{
	int i;
    for (i=0; i < argc; i++)
        printf("Argument %d is %s\n", i, argv[i]);
	
	wiringPiSetup() ;
	pinMode(PIN, OUTPUT) ;

	if(argc == 2){
		char* comm = argv[1];
		
		if(strcmp(comm, "1") == 0){
			turn_on();
		} else if(strcmp(comm, "0") == 0){
			turn_off();
		}
	}

	return 0 ;
}
