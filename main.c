#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define NMAX 100

typedef struct {
    char parola[NMAX];
    int posizione;
    char doppia[NMAX];
    int vocali;
} WordInfo;

int main(int argc, char *argv[]) {
    FILE *fp = fopen("input.txt", "r");
    if (fp == NULL) {
        printf("Errore: Impossibile aprire il file input.txt\n");
        return 1; // Interrompe il programma ed evita il crash con fclose
    }

    WordInfo words[NMAX];
    char line[NMAX];
    int word_count = 0;

    while (fgets(line, sizeof(line), fp) != NULL && word_count < NMAX) {
        // Rimuove il carattere di nuova riga (\n o \r) generato da fgets
        line[strcspn(line, "\r\n")] = '\0';

        char *token = strtok(line, " \t");
        while (token != NULL && word_count < NMAX) {
            int len = strlen(token);
            int num_vocali = 0;
            char doppi_char = '\0';

            for (int i = 0; i < len; i++) {
                char c = token[i];

                // Conta le vocali (sia minuscole che maiuscole)
                if (c == 'a' || c == 'e' || c == 'i' || c == 'o' || c == 'u' ||
                    c == 'A' || c == 'E' || c == 'I' || c == 'O' || c == 'U') {
                    num_vocali++;
                }

                // Individua la presenza di lettere doppie adiacenti
                if (i < len - 1 && token[i] == token[i + 1]) {
                    doppi_char = token[i];
                }
            }

            // Salvataggio dei dati nella struct
            strcpy(words[word_count].parola, token);
            words[word_count].posizione = word_count + 1;
            words[word_count].vocali = num_vocali;

            if (doppi_char != '\0') {
                snprintf(words[word_count].doppia, sizeof(words[word_count].doppia), "%c%c", doppi_char, doppi_char);
            } else {
                words[word_count].doppia[0] = '\0'; // Stringa vuota se non ci sono doppie
            }

            word_count++;
            token = strtok(NULL, " \t");
        }
    }

    fclose(fp);

    // Stampa di verifica dei risultati
    printf("--- PAROLE ELABORATE (%d) ---\n", word_count);
    for (int i = 0; i < word_count; i++) {
        printf("%d. Parola: %-15s | Vocali: %d | Doppia: %s\n",
               words[i].posizione,
               words[i].parola,
               words[i].vocali,
               words[i].doppia[0] != '\0' ? words[i].doppia : "Nessuna");
    }

    return 0;
}