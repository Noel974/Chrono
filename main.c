#include <stdio.h>
#include <stdlib.h>
#include <conio.h>

void afficherTempsEcoule(int heures, int minutes, int secondes) {
	system("cls"); // Efface l'ecran pour réafficher le temps
	printf("%02d:%02d:%02d/n", heures, minutes, secondes);
}

int main() {
	int heures = 0, minutes = 0, secondes = 0;
	char c;

	printf("Appuez sur n'importe quelle touche pour démarrer le chrono./n");
	_getch(); //Attend une touche pour démarrer

	time_t start_time = time(NULL);

	while (1) {
		time_t current_time = time(NULL);
		int elapsed_time = (int)difftime(current_time, start_time);

		heures = elapsed_time / 3600;
		secondes = (elapsed_time % 3600) / 60;
		minutes = elapsed_time % 60;

		afficherTempsEcoule(heures, minutes, secondes);

		if (_kbhit()) {
			c = _getch();
			if (c == 'q' || c == 'Q') {
				printf(" Chronométres arrêté./n");
				break;
			}
		}
		Sleep(1000);
	}
	return 0;
}