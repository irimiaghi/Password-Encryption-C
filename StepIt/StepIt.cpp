#include <stdio.h>

int inputPassword(int password[], int indexPassword) {
	int i;
	char aux[100];
	printf("Introdu o parola din %d caractere:\n", indexPassword);
	scanf("\n");
	for (i = 0; i <= indexPassword; i++) {
		scanf("%c", &aux[i]);
		password[i] = aux[i];
	}
	return password[i];
}

int keyEncryption(int indexPassword, int keyFinal[]) {
	int i, counter = 0, indexKey, key[100];
	printf("Introdu un numar intreg care reprezinta dimensiunea cheii de criptare, cuprins intre 5 si 15:\n");
	scanf("%d", &indexKey);
	if (indexKey < 5 || indexKey > 15) {
		printf("Ai introdus un numar mai mic ca 5 sau mai mare ca 15.\n");
		return keyEncryption(indexPassword, keyFinal);
	}
	printf("Introdu %d numere naturale care reprezinta cheia de criptare:\n", indexKey);
	for (i = 0; i < indexKey; i++) {
		scanf("%d", &key[i]);
	}
	for (i = 0; i < indexPassword; i++) {
		keyFinal[i] = key[counter];
		counter = counter + 1;
		if (counter == indexKey) {
			counter = 0;
		}
	}
	return keyFinal[i];
}

int keyDecryption(int indexEncrypted, int keyFinal[]) {
	int i, counter = 0, indexKey, key[100];
	printf("Introdu un numar intreg care reprezinta dimensiunea cheii de decriptare, cuprins intre 5 si 15:\n");
	scanf("%d", &indexKey);
	if (indexKey < 5 || indexKey > 15) {
		printf("Ai introdus un numar mai mic ca 5 sau mai mare ca 15.\n");
		return keyEncryption(indexEncrypted, keyFinal);
	}
	printf("Introdu %d numere naturale care reprezinta cheia de decriptare:\n", indexKey);
	for (i = 0; i < indexKey; i++) {
		scanf("%d", &key[i]);
	}
	for (i = 0; i < indexEncrypted; i++) {
		keyFinal[i] = key[counter];
		counter = counter + 1;
		if (counter == indexKey) {
			counter = 0;
		}
	}
	return keyFinal[i];
}

int encryption(int password[], int indexPassword, int keyFinal[], int plus, int minus, int passwordEncrypted[]) {
	int i, rest, operation;
	for (i = 0; i < indexPassword; i++) {
		rest = i % (plus + minus);
		if (rest < plus) {
			operation = 1;
		}
		else {
			operation = -1;
		}
		passwordEncrypted[i] = keyFinal[i] + password[i] * operation;
	}
	printf("Datele criptate in urma prelucrarii parolei conform algoritmului sunt:\n");
	for (i = 0; i < indexPassword; i++)
		printf("%d ", passwordEncrypted[i]);
	printf("\n");
	return passwordEncrypted[i];
}

int inputEncrypted(int encryptedCode[], int indexEncrypted) {
	int i;
	printf("Introdu parola criptata din %d caractere:\n", indexEncrypted);
	scanf("\n");
	for (i = 0; i < indexEncrypted; i++) {
		scanf("%d", &encryptedCode[i]);
	}
	return encryptedCode[i];
}

int decryption(int passwordEncrypted[], int indexEncrypted, int keyFinal[], int plus, int minus, int passwordDecrypted[]) {
	int i, rest, operation;
	for (i = 0; i < indexEncrypted; i++) {
		passwordDecrypted[i] = passwordEncrypted[i] - keyFinal[i];
		if (passwordDecrypted[i] < 0) {
			passwordDecrypted[i] = passwordDecrypted[i] * -1;
		}
	}
	printf("Datele decriptate in urma prelucrarii cheii de decriptare conform algoritmului sunt:\n");
	for (i = 0; i < indexEncrypted; i++)
		printf("%c", passwordDecrypted[i]);
	printf("\n");
	return passwordDecrypted[i];
}

void showMenu() {
	printf("* * * * * * * * * * * * * * * *\n");
	printf("Bine ati venit in programul de stocare si criptare a parolelor\n");
	printf("* * * * * * * * * * * * * * * *\n");
}

int main() {
	int password[100], passwordEncrypted[100], keyFinal[100], encryptedCode[100], passwordDecrypted[100];
	int indexPassword, indexEncrypted, plus, minus;
	showMenu();

	int command;
	printf("Alege o command:\n");
	printf(" 1 -> Criptare\n");
	printf(" 2 -> Decriptare\n");
	scanf("%d", &command);
	if (command == 1) {
		printf("Introdu un numar natural care reprezinta numarul de caractere care vor fi criptate:\n");
		scanf("%d", &indexPassword);
		inputPassword(password, indexPassword);
		keyEncryption(indexPassword, keyFinal);
		printf("Introdu doua numere naturale care reprezinta stilul de aplicare al cheii, cuprinse intre 2 si 10:\n");
		scanf("%d %d", &plus, &minus);
		if (plus < 2 || minus < 2 || plus > 10 || minus > 10) {
			printf("Ai introdus unul sau doua numere, mai mici ca 2 sau mai mari ca 10.\n");
			return 0;
		}
		encryption(password, indexPassword, keyFinal, plus, minus, passwordEncrypted);
	}
	else if (command == 2) {
		printf("Introdu un numar natural care reprezinta numarul de caractere criptate:\n");
		scanf("%d", &indexEncrypted);
		inputEncrypted(encryptedCode, indexEncrypted);
		keyDecryption(indexEncrypted, keyFinal);
		printf("Introdu doua numere naturale care reprezinta stilul de aplicare al cheii, cuprinse intre 2 si 10:\n");
		scanf("%d %d", &plus, &minus);
		if (plus < 2 || minus < 2 || plus > 10 || minus > 10) {
			printf("Ai introdus unul sau doua numere, mai mici ca 2 sau mai mari ca 10.\n");
			return 0;
		}
		decryption(encryptedCode, indexEncrypted, keyFinal, plus, minus, passwordDecrypted);
	}
	else {
		printf("Ai introdus o comanda eronata.\n");
	}

	return 0;
}