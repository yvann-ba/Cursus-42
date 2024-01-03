#include <stdbool.h>

bool backtrack(char** map, int row, int col, int exitRow, int exitCol, int numRows, int numCols) {
	// Vérifier si les coordonnées actuelles correspondent à la sortie
	if (row == exitRow && col == exitCol) {
		return true;
	}

	// Vérifier si les coordonnées actuelles sont valides
	if (row < 0 || row >= numRows || col < 0 || col >= numCols || map[row][col] == '#') {
		return false;
	}

	// Marquer les coordonnées actuelles comme visitées
	map[row][col] = '#';

	// Appeler récursivement la fonction pour les cases adjacentes
	bool foundExit = backtrack(map, row - 1, col, exitRow, exitCol, numRows, numCols) || // Case en haut
					 backtrack(map, row + 1, col, exitRow, exitCol, numRows, numCols) || // Case en bas
					 backtrack(map, row, col - 1, exitRow, exitCol, numRows, numCols) || // Case à gauche
					 backtrack(map, row, col + 1, exitRow, exitCol, numRows, numCols);   // Case à droite

	return foundExit;
}
