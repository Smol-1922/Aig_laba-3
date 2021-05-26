#include<iostream>
#include<fstream>
#include<string>
#include<Windows.h>
#include"queue.h"
#include"function.h"
int main() {
	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);
	std::ifstream file;
	file.open("text.txt", std::ios::in);
	queue* que = new queue;
	reading(que, file);
	int size = que->get_size();
	int** matrix;
	matrix = new int* [size];
	for (int i = 0; i < size; i++) {
		matrix[i] = new int[size];
	}
	for (int i = 0; i < size; i++) {
		for (int j = 0; j < size; j++) {
			matrix[i][j] = 0;
		}
	}
	file.seekg(0);
	creating_matrix(que, file, matrix, size);
	file.close();
	return 0;
}