#include <stdio.h>
#include <stdlib.h>
#include <string.h>

FILE *obj;

char prog_name[10], record[100], locn[4];

int i, j, k=0, flag=0, start, ind, new_loc;

int main(){

    printf("\nName of Object Program to load >> ");
    scanf("%s", prog_name);

    obj = fopen("input.txt", "r");
    fscanf(obj, "%s", record);

    for(i=0; i<strlen(prog_name); i++){
        if(record[i+2] == prog_name[i]){
            flag=0;
        }
        else{
            flag=1;
            break;
        }
    }
    
    if (flag == 1){
        printf("OBJ PGM_Name NOT_FOUND!!\n");
    }
    else{
        printf("LOCATION\tOBJECT CODE\n");
        while(record[0] != 'E'){
            ind = 12;
            if (record[0] == 'T'){

                for (j=4, k=0; j<8, k<4; k++, j++){
                    locn[k] = record[j];
                }

                    start = atoi(locn);
                    new_loc = start;

                while(record[ind] != '$'){
                    if(record[ind] == '^'){
                        ind++;
                    }
                    else{
                        printf("00%d  \t   %c%c\n", new_loc, record[ind], record[ind+1]);
                        ind +=2;
                        new_loc += 1;
                    }
                }
            }
            fscanf(obj, "%s", record);
        }
    }

    return 0;
}
