/*
Minesweeper by Ana B.
*/
#include <stdio.h>
#include <stdlib.h>
#include <iostream>
#include <cstdlib>
#include <stdio.h>
#include <ctype.h>
#include <string>
#include <stdlib.h>
using namespace std;

void llenaMatriz(char s[])
{
     int tam1, tam2;
     char **matriz, *fila, temp, **nMatriz;
     string a,b;
     a = s[0];
     b = s[1];
     tam1 = atoi(a.c_str());
     tam2 = atoi(b.c_str());
     
     //cout<<tam1<<endl;
     //cout<<tam2<<endl;

     int pos = 2;

     fila = new char[tam1];
     matriz = new char*[tam1];
     nMatriz = new char*[tam1];
     for(int i = 0; i < tam1; i++){
          matriz[i] = new char[tam1];
          nMatriz[i] = new char[tam1];          
     }
    
    //Lleno la matriz
     for(int i = 0; i < tam1; i++)
          for(int j = 0; j < tam2; j++){
               //cout<<"matriz["<<i + 1<<"]["<<j + 1<<"]: "<<s[pos];
               matriz[i][j] = s[pos];
               pos++;
               if(i == j)
                    fila[i] = matriz[i][j];
          }

     cout<<endl;
    
     //Empiezo a evaluar las 8 casillas contiguas
     for(int i = 0; i < tam1; i++){
        for(int j=0; j < tam2; j++){
            if(matriz[i][j] == '*'){
                nMatriz[i][j] = '*';
            }else{
                int minas = 0;
                
                if(i==0 && j==0){
                    if(j<tam2-1){
                        if(matriz[i][j+1] == '*')
                            minas++;
                    }
                    if(i<tam1-1){
                        if(matriz[i+1][j] == '*')
                            minas++;
                    }
                    if(i<tam1-1 && j<tam2-1){
                        if(matriz[i+1][j+1] == '*')
                            minas++;
                    }
                }
                
                if(i==0 && j>0){
                    if(matriz[i][j-1] == '*')
                        minas++;
                    if(i<tam1-1){
                        if(matriz[i+1][j-1] == '*')
                            minas++;
                        if(matriz[i+1][j] == '*')
                            minas++;
                    }
                    if(j<tam2-1){
                        if(matriz[i][j+1] == '*')
                            minas++;
                    }  
                    if(i<tam1-1 && j<tam2-1){
                        if(matriz[i+1][j+1] == '*')
                            minas++;
                    }                                                              
                    
                }
                
                if(i>0 && j==0){
                    if(matriz[i-1][j] == '*')
                        minas++;   
                    if(j<tam2-1){
                        if(matriz[i-1][j+1] == '*')
                            minas++;
                        if(matriz[i][j+1] == '*')
                            minas++;
                    }
                    if(i<tam1-1){
                        if(matriz[i+1][j] == '*')
                            minas++;
                    }
                    if(i<tam1-1 && j<tam2-1){
                        if(matriz[i+1][j+1] == '*')
                            minas++;
                    }                                     
                }
                
                if(i>0 && j>0){
                    if(matriz[i-1][j-1] == '*')
                        minas++;    
                    if(matriz[i-1][j] == '*')
                        minas++;
                    if(matriz[i][j-1] == '*')
                        minas++;
                    if(j<tam2-1){
                        if(matriz[i-1][j+1] == '*')
                            minas++;
                        if(matriz[i][j+1] == '*')
                            minas++;
                    }
                    if(i<tam1-1){
                        if(matriz[i+1][j-1] == '*')
                            minas++;
                        if(matriz[i+1][j] == '*')
                            minas++;
                    }
                    if(i<tam1-1 && j<tam2-1){
                        if(matriz[i+1][j+1] == '*')
                            minas++;
                    }
                }
                nMatriz[i][j] = (char) minas + 0x30;
            }
        }
     }
        
        //Imprimo...
     cout<<"Field #:"<<endl;
        
     for(int i = 0; i < tam1; i++){
          for(int j = 0; j < tam2; j++)
               cout<<nMatriz[i][j]<<" ";
          cout<<endl;
     }
     
}

int main() {

   //char c[] = "3 3 \n. . .\n. . .\n. . .\n";
   //char c[] = "3 3 \n. . .\n. * .\n. . .\n";
   //char c[] = "2 2 \n* . \n. *\n";
   //char c[] = "3 5\n* * . . .\n. . . . .\n. * . . .\n";
   
    bool a=true;
    bool tamanio = true;
    char line[100];
    char c[256];
    int w = 0;
   
   //Estar leyendo input de usuario hasta el '0 0'
    while(a)
    {
        cin.getline(line,100);
        if(line[0] == '0' && line[1] == ' ' && line[2] == '0')
        {
            a=false;
        }else{
        int z = 0;
            while(line[z] != '\0'){
                c[w] = line[z];
                w++;
                z++;
            }
             c[w] = '\n';
             w++;
        }
    }
   
   char linea[80];
   char s[80];
   int x, bLinea, nLin = 0;
   int y = 0;
//Limpio el input final
   for (bLinea = x = 0; c[x]; ++x)
      if (!isspace (c[x]))
         linea[bLinea++] = c[x];
      else if (bLinea) {
         linea[bLinea] = '\0';
         bLinea = 0;
         s[y] = linea[0];
         y++;
      }

    llenaMatriz(s);
   return 0;
}
