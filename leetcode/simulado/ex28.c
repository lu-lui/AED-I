int strStr(char* haystack, char* needle) {
    int j = 0; //precisa entrar no loop para iniciar da primeira letra de needle

    for(int i = 0; haystack[i] =! '\0'; i++){ //erro na comparação
            while (needle[j] != '\0' && haystack[j] == needle[j]) { //só avança se a primeira letra for igual
                j++; 
            }
             if (needle[j] == '\0'){
                return i;
             }   
        }
}
