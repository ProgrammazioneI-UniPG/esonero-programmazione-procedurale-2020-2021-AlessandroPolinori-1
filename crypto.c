#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

int main() {
    int mLength; //Lunghezza di M
    int kLength; //Lunghezza di K
    int cLength; //Lunghezza di C
    char plaintextM[128];  //Array per la stringa M
    char keyK[128];        //Array per la chiave K
    char ciphertextC[128]; //Array per la stringa criptata C
    char result[128];
    int optionKey;
    int Character;
    
    time_t t;                   //Per generare valori casuali
    srand((unsigned)time(&t));  //Per generare valori casuali
    

    //Fase 1: Richiedere la stringa M da cifrare
    printf ("=========================================================\n");
    printf ("\n");
    printf ("Per favore, inserire la stringa da cifrare\n");
    printf ("Si ricorda che il programma considererà solo i primi 128 caratteri dovesse la stringa superarne la soglia\n");
    fgets (&plaintextM[128], 128, stdin);
    fflush (stdin);
    mLength = strlen(&plaintextM[128]) - 1;
    printf ("\n");
    printf (" E' stata inserita la stringa di %d caratteri:\n", mLength);
    printf("%s", &plaintextM[128]);
    
    //Fase 2: Richiedere la chiave K
    printf ("\n");
    printf ("Per poter cifrare la stringa è necessaria una chiave\n");
    printf ("Per poter inserire una chiave manualmente, prema 1\n");
    printf ("Per usare una chiave generata randomicamente, prema 2\n");
    printf ("Si prega di non immettere lettere in questa opzione\n");
    scanf ("%d", &optionKey);
    switch (optionKey){
        case 1:
            if (optionKey !=1 && optionKey !=2){
                return 0;
            }
            else {
                
            //Opzione 1: Chiave inserita manualmente
                printf ("\n");
                printf ("Ha deciso di inserire manualmente la chiave\n");
                printf ("La chiave deve essere di lunghezza superiore alla stringa iniziale, ma comunque inferiore a 128\n");
                insertK: printf ("Per favore inserire la chiave\n");
                fflush (stdin);
                fgets (&keyK[128], 128, stdin);
                kLength = strlen(&keyK[128]) -1 ;
                printf ("\n");
                printf ("E' stata inserita la chiave di %d caratteri:\n",kLength);
                printf ("%s", &keyK[128]);
                printf ("\n");
                if (kLength => mLength) {
                    break;
                }
                else {
                    printf ("La chiave non può essere minore della stringa iniziale\n");
                    goto insertK;
                }
            }
        case 2:
            //Opzione 2: Chiave generata randomicamente in base al tempo
            printf ("\n");
            printf ("Verrà usata la chiave, generata randomicamente:\n");
            for (kLength = 0; kLength < mLength; kLength++){ 
                //Per evitare i primi 31 caratteri speciali aggiungiamo 32
                keyK[kLength] = (rand() %96 + 32);
                printf ("%c", keyK[kLength]);
            }
            printf ("\n");
            printf ("di %d caratteri \n", kLength);
            printf ("\n");
            break;
        default:
            return 0;
    }
    
    //Fase 3: Codificazione con XOR
    printf ("M: %s", &plaintextM[128]);
    printf ("K: %s", &keyK[128]);
    printf ("\n");
    printf ("Risulta quindi la frase:\n");
    for (cLength=0; cLength<mLength; cLength++){
        ciphertextC[cLength] = plaintextM[cLength] ^ keyK[cLength];
        printf("%c", ciphertextC[cLength]);
    }
    printf ("\n");
    printf ("di %d caratteri\n", cLength);
    printf ("\n");
    printf ("Versione criptata della frase originale:\n");
    for (Character=0; Character < cLength; Character++){
        result[Character] = ciphertextC[Character] ^ keyK[Character];
        printf("%c", result[Character]);
    }
    printf ("\n");
    printf ("\n");
    return 0;
}