#include <stdio.h>
#include <ncurses.h>

int main(){
	int x;
	while(1){
		x = getch();
		printf("%i", x);
		if(x == 27) break;
	}

	return 0;
}
