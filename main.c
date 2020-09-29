#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main()
{
    FILE *file , *fileLex;
    file = fopen("code.psi.txt","r");
    fileLex = fopen("code.lex.txt","w");
    char identifiers[20];
    char IntConst[10];
    char string[100];
    char keywords[18][20];

    strcpy(keywords[0], "break");
    strcpy(keywords[1], "goto");
    strcpy(keywords[2], "case");
    strcpy(keywords[3], "char");
    strcpy(keywords[4], "const");
    strcpy(keywords[5], "continue");
    strcpy(keywords[6], "do");
    strcpy(keywords[7], "else");
    strcpy(keywords[8], "enum");
    strcpy(keywords[9], "float");
    strcpy(keywords[10], "for");
    strcpy(keywords[11], "if");
    strcpy(keywords[12], "int");
    strcpy(keywords[13], "long");
    strcpy(keywords[14], "record");
    strcpy(keywords[15], "return");
    strcpy(keywords[16], "static");
    strcpy(keywords[17], "while");


    int kontroler = 0 ;
    int sayac = 0 ;

    char ch = getc(file);

    while(!feof(file)){
            if (ch == 32 || (8<ch && ch< 14)){//Boşluk ya da değişik karakterleri atlama
                ch = getc(file);
            }
            if((96<ch && ch< 123 )|| (64<ch&& ch<91)){//identifier tanımlama
                int i = 0;
                if(65<ch && 90>ch){
                    ch += 32;
                }

                int len;
                while((96 < ch && ch <123) || (64 < ch && ch < 91)||(ch==95)) {

                    identifiers[i] = ch;

                    i++;
                    ch = getc(file);

                }
                identifiers[i] = '\0';
                int j = 0;
                len = i;


                for(int i = 0 ; i<18;i++){
                    sayac = 0;
                    for(int j = 0 ; j<len;j++){
                        if(identifiers[j] == keywords[i][j]){
                            sayac = sayac+1;


                        }
                    }
                    if((sayac==len)&&(sayac>1)){
                        kontroler = 1 ;
                        break;
                    }

                }



                sayac = 0 ;
                if(kontroler==1){
                    fputs("keywords : " , fileLex);
                    while(j < len){
                    fputc(identifiers[j], fileLex);
                    j++;
                    kontroler = 0;

                }

                }
                else{
                    if(len>20){
                    printf("Bu kadar uzun bir idetifier kullanamazsınız");
                }
                    fputs("identifier : " ,fileLex);
                    while(j < len){
                    fputc(identifiers[j], fileLex);
                    j++;
                }

                }

            fputs("\n",fileLex);


            }
            if(ch>47 && ch<58){//Integer Tanımlama
                int k = 0 ;
                int lenint ;
                while(ch>47 && ch<58){
                    IntConst[k] = ch;
                    k++;
                    ch = getc(file);
                }
                lenint = k;
                if(lenint>10){
                    printf("Bu kadar uzun bir integer değer giremezsiniz");
                }
                fputs("IntCons : ", fileLex);
                int m = 0 ;
                while(m< lenint){
                    fputc(IntConst[m],fileLex);
                    m++;
                }
                fputs("\n",fileLex);
            }
            if(ch == 34){//String tanımlama
                int i = 0;
                int lenstring ;
                ch = getc(file);
                while(!feof(file)){

                    string[i] = ch;
                    i++;
                    ch = getc(file);
                    if(ch == 34){
                        ch = getc(file);
                        break;
                    }

                }
                lenstring = i;
                int j = 0 ;
                fputs("String : ", fileLex);
                while(j<lenstring){
                        fputc(string[j],fileLex);
                        j++;

                }
                fputs("\n",fileLex);
            }


            if(ch==58){//Operatör tanımlama
                ch = getc(file);
                  if(ch == 61){
                      fputs("operator : ",fileLex);
                      fputs(":= \n",fileLex);
                      ch = getc(file);

            }}

            if (ch == 43){
                    ch = getc(file);

                if(ch == 43){
                    fputs("operator :",fileLex);
                    fputs("++ \n",fileLex);
                    ch = getc(file);

                }
               else{
                    fputs("operator : ",fileLex);
                    fputs("+ \n",fileLex);


                }
            }
            if(ch==45){
                ch = getc(file);
                if(ch==45){
                    fputs("operator : ", fileLex);
                    fputs("-- \n",fileLex);
                    ch = getc(file);
                }
                else{
                    fputs("operator : ", fileLex);
                    fputs("- \n",fileLex);
                }

                }
                if(ch == 47){

                fputs("operator : ", fileLex);
                fputs(" / \n" , fileLex);
                ch = getc(file);

            }
            if(ch == 42){
                fputs("operator : ", fileLex);
                fputs("* \n",fileLex);
                ch = getc(file);
            }


            if(ch==91){//Parantezleri tanımlama
                fputs("LeftSquareBracket : " ,fileLex);
                fputs(" [ \n", fileLex);
                ch = getc(file);
            }
            if(ch == 93){
                fputs("RightSquareBracket : ", fileLex);
                fputs(" ] \n",fileLex);
                ch = getc(file);
            }
            if (ch == 123){
                fputs("LeftCurlyBracket : " , fileLex);
                fputs("{ \n",fileLex);
                ch = getc (file);
            }
            if(ch==125){
                fputs("RightCurlyBracket : " , fileLex);
                fputs("} \n" , fileLex);
                ch = getc(file);
            }
            if(ch == 59){
                fputs("End of the Line \n",fileLex);
                ch = getc(file);
            }
             if(ch == 41){
                fputs("RigthPar :",fileLex);
                fputs(") \n",fileLex);
                ch = getc(file);
            }
            if(ch == 40){//Yorum satırı tanımlama
                ch= getc(file);
                if(ch==42){
                    while(!feof(file)){
                        ch= getc(file);
                            if(ch==42){
                                ch = getc(file);
                                if(ch == 41)
                                    ch = getc(file);
                                    break;

                            }

                      }

                    }

                    else{
                        fputs("LeftPar : ",fileLex);
                        fputs ("( \n",fileLex);

                }

                }



            }
            fclose(file);
            fclose(fileLex);
            return 0;


            }



























