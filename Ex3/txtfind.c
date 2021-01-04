#include <stdio.h>  
#include <math.h>
#include <string.h> 
#include <stdlib.h>   


#define SIZE 50
#define LINE 256
#define WORD 30

int arr[SIZE];

int similar(char *s, char *t, int n){
	int sizeS = strlen(s), sizeT = strlen(t), countDif = 0, j = 0, z = n;

	for (int i = 0; *(s + i) != '\0' && *(s + i) != '\n'; i++){
		if (*(s + i) == *(t + j)){
			j++;
		}else{
			countDif++;
			z--;
		}	
	}
	if (abs(sizeT - sizeS) == 3){
		if (1 == j - sizeT + countDif + z){
			return 1;
		}
	}
	if (j == sizeT && countDif <= n){
		return 1;
	}
	return 0;
}
void readFromFile(){
    char const* const fileName = "find_input.txt";
    FILE* file = fopen(fileName, "r");
    char line[256];
    int lines = 0;

    while (fgets(line, sizeof(line), file)) {
        lines++; 
    }
    fclose(file);

    char *arrString[lines];
    int i = 0;
    file = fopen(fileName, "r");
    while (fgets(line, sizeof(line), file)) {
        // if(Substring(line,word) == 1){
            arrString[i] = line;
        // }
        printf("arrString[%d] = %s",i, arrString[i]); 
        i++;
    }
    fclose(file);
}
int getLine(char s[]){
    int i,k;
    char c;
    k = i = 0;

    while (k < LINE ){
        scanf("%c" , &c);
        if(c == '\n' || c == '\0' || c == '\t'|| c == ' '){
            break;
        }else{
            s[i++] = c;
        }
        k++; 
        while (getchar() != '\n');
    }

    s[i] = '\n';
    printf("%s", s);
    return i;
}
int getWord(char w[]){
    int i,k;
    char c;
    k = i = 0;

    while (k < WORD ){
        scanf("%c" , &c);
        if(c == '\n' || c == ' ' || c == '\t'){
            break;
        }
        if(c != '\t' && c != '\n' && c != ' '){
            w[i++] = c;   
        }
        k++; 
        while (getchar() != '\n');
    }
    w[i] = '\n';
    printf("%s", w);
    return i;
}
int Substring( char * str1, char * str2){
    if (!strcmp(str1, str2)){
        return 1;
    }

    int sizeStr1 = strlen(str1);
    int sizeStr2 = strlen(str2);
    //printf("sizeStr1 = %d , sizeStr2 = %d\n", sizeStr1,sizeStr2);
    int i,j,size;
    size = sizeStr2;
    for(i = 0; i < sizeStr1; i++){
        for(j = 0; j < sizeStr2; j++){
            //printf("str1[%d] = %c, str2[%d] = %c, size = %d\n",i,str1[i],j,str2[j],size);
            if(str1[i] == str2[j]){
                size--;
                i++;
            }else{
                size = sizeStr2;
            }
            if(size == 0){
                return 1;
            }            
        }
    }
    return 0;
}
void searchWordInFile(char *str){
    char const* const fileName = "find_input.txt";
    FILE* file = fopen(fileName, "r");
    char line[256];

    int lines = 0;
    //printf("sizeof(line) = %ld\n",sizeof(file));
    while (fgets(line, sizeof(line), file)) {
        lines++;
        if(lines >= 3){
            if(Substring(line,str) == 1){
                printf("%s", line);
            }
            lines++;          
        }
    }
    fclose(file);
}
void checkLine(char *token,char *search){
	//printf("token = %s, search = %s\n",token,search);
	if(similar(token,search,1) == 1){
		printf("%s\n",token);
	}
}
void searchSimilarWordInFile(char *str, FILE* file){
    char line[256];
    int lines = 1;

    while (fgets(line, sizeof(line), file)) {
        lines++; 
        if(lines >= 3){
			char * token = strtok(line, " ");
			while( token != NULL ) {
				checkLine(token,str);
				token = strtok(NULL, " ");
			}
        }        
    }
    fclose(file);
}

void print_lines(char *str){
    searchWordInFile(str);
}
void print_similar_words(char *str, FILE* file){
    searchSimilarWordInFile(str,file);
}


