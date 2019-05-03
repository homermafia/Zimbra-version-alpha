int nom_valide(char nom[]) {
    int i = 0;

    while ((((int) nom[i] >= 65 && (int) nom[i] <= 90) || ((int) nom[i] >= 97 && (int) nom[i] <= 122)) && i <= strlen(nom) - 1) {
        i = i + 1;
    }

    return strlen(nom) - i;
}
