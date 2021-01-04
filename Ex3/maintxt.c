#include <stdio.h>  
#include <math.h>
#include <string.h> 
#include <stdlib.h>   
#include "txtfind.h"


#define SIZE 50
#define LINE 256
#define WORD 30

int arr[SIZE];

int main () {
//   char choice;
//     char* word;
//     char buffer[BUFFERSIZE];
//     int i = 0;
//     while(fgets(buffer, BUFFERSIZE , stdin)){
//         if(i == 0){ 
        
//         char * token = strtok(buffer, " ");
//              // char word[strlen(token)];
             
//             word = malloc(strlen(token) + 1);
//             strcpy(word,token);
            
//             token = strtok(NULL, " ");
//               choice = token[0];
//              token = strtok(NULL, " ");

//         }else{
//           if(choice == 'a'){
//             print_line(buffer,word);
//           }
//           else if(choice == 'b'){
//         print_similar_words(buffer,word);
//           }
//         }
//     i++;
//     }


    // char buffer[LINE];
    // fgets(buffer, LINE , stdin);
    // printf("Read: %s", buffer);

    // //Q3
    // //getLine
    // char c[LINE] = "";
    // int a = getLine(c);
    // printf("a = %d\n",a);


    // //Q3
    // //getword
    // char cc[LINE] = "";
    // int b = getWord(cc);
    // printf("b = %d\n",b);
   

    // //Substring
    // char str2[] = "moti";
    // char str1[] = "123456moti12346";
    // int result = Substring(str1,str2);
    // printf("result = %d\n",result);
  

    // //similar
    // char s[] = "swsystems";
    // char t[] = "ssysems";
    // result = similar(s,t,2);
    // printf("result = %d\n",result);


    char const* const fileName = "find_input.txt";
    FILE* file = fopen(fileName, "r");
    char line[256];
    char *dataLine = "";
    int i,index;
    char word[WORD];
    char flag = 'c';
    while (fgets(line, sizeof(line), stdin)) {
        dataLine = line;
        int j = index = 0;
        for(i = 0; i < strlen(dataLine) && dataLine[i] != ' '; i++){
            word[j++] = dataLine[i];
            index = i;
        }
        while (i < strlen(dataLine)){   
            if(dataLine[i] != ' '){
                flag = dataLine[i];
                break;
            }
            i++;
        }
        break;
    }
    if(flag == 'a'){
        print_lines(word);
    }else if(flag == 'b'){
        print_similar_words(word,file);
    }

    return 0;
}

