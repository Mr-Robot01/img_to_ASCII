#include <SFML/Graphics.hpp>
#include <iostream>
#include <fstream>
#include <windows.h>

using namespace sf;
using namespace std;

char symbol(int r, int g, int b) {
	char sym = ' ';
	int j = 0;
	char a[17]{ '@', '&', '$', '#', '%', 'B', 'M', '?', '|', '/', '+', '=', '!', ';', ',', '.', ' ' };
	int k = 12;

	for (int i = 0; i < 17; i++) {
		if ((r >= j && r <= j + k - 1) || (g >= j && r <= g + k - 1) || (b >= j && b <= j + k - 1))
			sym = a[i];
		j += k;
	}

	return sym;
}

int main() {
	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);
	setlocale(LC_ALL, "rus");

	string file_d;
	string img_d;
	int kw = 2;
	int kh = 6;

	cout << "Name or dir to img file: " << endl;
	cin >> img_d;

	cout << "Name or dir to out file: " << endl;
	cin >> file_d;

	sf::Image image;
	image.loadFromFile(img_d);

	ofstream fout(file_d);

	const int h = image.getSize().y;
	const int w = image.getSize().x;
	char** img = new char* [w];

	for (int i = 0; i < h; i += kh)
		img[i] = new char[h];

	if (w < 400)
		kh = kw = 1;

	for (int i = 0; i < h; i += kh) {
		for (int j = 0; j < w; j += kw) {
			sf::Color color = image.getPixel(j, i);

			int r = color.r;
			int g = color.g;
			int b = color.b;

			**img = symbol(r, g, b);

			if (w < 400)
				fout << **img << **img;
			else
				fout << **img;
		}
		fout << '\n';
	}

	fout.close();
	system("pause");
	cin.get();

	return 0;
}