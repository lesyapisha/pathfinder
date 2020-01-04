#include "libmx.h"

char **mx_correct_strsplit(char const *s, char c) {
    char **words = (char **) malloc(sizeof(char *) * (mx_correct_count_words(s, c) + 2));
    int index = 0;
    int word_symbols = 0;
    int words_index = 0;

    if (!s) {
        words[0] = NULL;
        return words;
    }
    while (s[index]) {
        if (s[index] != c) {
            word_symbols++;
        } else {
            words[words_index] = mx_strnew(word_symbols + 1);
            mx_strncpy(words[words_index], (s + index - word_symbols), word_symbols);
            word_symbols = 0;
            words_index++;
        }
        index++;
    }
    
    words[words_index] = mx_strnew(word_symbols + 1);
    mx_strncpy(words[words_index], (s + index - word_symbols), word_symbols);
    words_index++;
    words[words_index] = NULL;
    return words;
}
