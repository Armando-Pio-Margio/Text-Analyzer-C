# Text Analyzer in C

Un programma in C scritto per analizzare il contenuto di un file di testo, conteggiare le vocali per ciascuna parola e individuare la presenza di lettere doppie adiacenti.

## Funzionalità
- Lettura dinamica da file di testo (`input.txt`).
- Parsing delle singole parole con `strtok`.
- Conteggio delle vocali (maiuscole e minuscole).
- Rilevamento delle doppiette e memorizzazione in una struttura (`struct`).

## Come eseguirlo
Compilare il sorgente con `gcc`:
```bash
gcc main.c -o text_analyzer
./text_analyzer