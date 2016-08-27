#include <stdlib.h>
#include <stdio.h>
#include <string.h>

/**
 * Auto-generated code below aims at helping you parse
 * the standard input according to the problem statement.
 **/
void print(int *index, int L, int H, char *data){
	int i=0, j=0, k=0;
	int segment = int(L * ((strlen(data)/H)/L)*i);
	int value = (j+(L*index[k]));

	for(i=0;i<H;i++){
		for(j=0;j<L;j++){
			for(k=0;k<((sizeof(index)/sizeof(int))-1);k++){
				int segment = int(L * ((strlen(data)/H)/L)*i);
			        int value = (j+(L*index[k]));
			//	printf("segment : %d\n", segment);
				//printf("value   : %d\n", value);
				//printf("%d", segment + value);
				
			}	
		}printf("\n");
	}
	for(i=0;i<H;i++){
                for(j=0;j<L;j++){
                        for(k=0;k<((sizeof(index)/sizeof(int))-1);k++){
                                int segment = int(L * ((strlen(data)/H)/L)*i);
        			int value = (j+(L*index[k]));
				//printf("%c", data[segment + value]);

                        }
                }
		for(j=0;j<((strlen(data)/H));j++){printf("%c", data[i*j]);}printf("\n");
        }

}
int main()
{
    
	int L;
	scanf("%d", &L); fgetc(stdin);
	int H;
	scanf("%d", &H); fgetc(stdin);
	char T[256];
	fgets(T,(256),stdin);
	const int data_size = L*27;
	char **data = (char**) calloc(H, sizeof(char*));
	for (int i = 0; i < H; i++) {
		
        	char data[i] = (char*)  calloc((data_size), sizeof(char));
		char *ROW = (char*) calloc(1024, sizeof(char));
		fgets(ROW,1024,stdin);
		strcpy(data[i], ROW);
	}
	printf("Length : %d\n", L);
	printf("Height : %d\n", H);
	printf("Text : %s\n", T);
	//printf("%s", data);
	printf("data size : %d\n", int(strlen(data[0])));
	int index[1] = {1};
//	print(index,L,H,data);
	
    // Write an action using printf(). DON'T FORGET THE TRAILING \n
    // To debug: fprintf(stderr, "Debug messages...\n");

	printf("answer\n");
	free(data);
	return 0;
}

