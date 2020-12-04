#include <stdlib.h>
#include <locale.h>
#include <time.h>
#include <iomanip>
#include <string>
#include <ctime>

using namespace std;

class Figure {//класс Figure
public:
	Figure() {//конструктор по умолчанию
	}
	virtual void show() {//виртуальный метод show
		printf("\nФигура\n");
	}
	 ~Figure() {//виртуальный деструктор 
		printf("Фигура удалена\n");
	}
}; 

class Storage { //класс хранилище
private:
	Figure** objects;
	int size;//размер хранилища
public:
	Storage(int size) {
		this->size = size;
		objects = new Figure * [size];
	}
	void SetObject(int index, Figure* object) {//устанавливает в индексе памяти object
		objects[index] = object;
	}
	Figure& GetObject(int index) { //возвращает объект с индексом
		return *objects[index];
	}
	void delete_obj(int index) {//удаляет объект
		objects[index]->~Figure();//тогда вызывается деструктор 
	}
	void add(Figure* object) {//добавляет объект 
		Figure** object1 = new Figure * [size + 1];
		for (int i = 0; i < size; i++)
			object1[i] = objects[i];
		object1[size] = object;
		size++;
		delete objects;
		objects = object1;
		printf("Добавлен объект ");
		object->show();
		printf("в индекс ");
		printf("%d", size - 1);
		printf("\n\n");
	}
	int getCount() {
		return size;
	}
};


class Point :public Figure {//класс наследник от класса Figure
private:
	int x, y;
public:
	Point() {
		x = 0;
		y = 0;
	}
	Point(int x, int y) {
		this->x = x;
		this->y = y;
	}
	void show() {
		printf("Точка с координатами: ");
		printf("%d %d", x, y);
		printf("\n");
	}
	~Point() {
		printf("Точка удалена с координатами:  ");
		printf("%d %d %c", x, y, " ");
		printf("\n");
	}
};

class Section : public Figure { // класс - композиция
private:
	Point* p1, * p2;
	int x1, x2, y1, y2;
public:
	Section() {
		p1 = new Point(rand() % 10, (rand() % 10));
		p2 = new Point(rand() % 10, (rand() % 10));
	}
	void show() {
		printf("\nОтрезок с точками: \n");
		p1->show();
		p2->show();
		printf("\n");
	}
	~Section() {
		printf("Отрезок с точками: \n");
		 p1->show();
		 p2->show();
		 delete p1;
		 delete p2;
	}
};





int main() {
	Figure* f;
	srand(time(NULL));
	setlocale(LC_ALL, "Rus");
	Storage store(50);// создаем хранилищу с именем store
	for (int i = 0; i < store.getCount(); i++) {
		int a = rand() % 2 + 1;
		if (a == 2)
			store.SetObject(i, new Point(rand() % 10, rand() % 10));
		else
			store.SetObject(i, new Section());
	}
	for (int i = 0; i < store.getCount(); i++) {
		store.GetObject(i).show();
	}

	printf("\n");
	printf("%d", store.getCount());
	printf(" - Размер хранилища \n\n");
	unsigned int start_time = clock();
	for (int i = 0; i < 100; i++) {
		int p = rand() % 4 + 1;
		switch (p) {
		case 1:
			p = rand() % 2 + 1;
			if (p == 1) {
				f = new Point(rand() % 10, rand() % 10);
			}
			else
				f = new Section();
			break;
		case 2:
			p = rand() % 2 + 1;
			if (p == 1) {
				f = new Point(rand() % 10, rand() % 10);
			}
			else
				f = new Section();
			store.add(f);
			break;
		case 3:
			printf("Метод show\n");
			store.GetObject(rand() % store.getCount()).show();
			printf("\n");
			break;
		case 4:
			store.delete_obj(rand() % store.getCount());
			printf("\n");
			break;
		}
	}
	unsigned int end_time = clock();
	unsigned int search_time = end_time - start_time;
	printf("Время работы программы =  ");
	printf("%d", search_time);
	printf("\n");
	system("pause");
	system("cls");

	start_time = clock();
	for (int i = 0; i < 10000; i++) {
		int p = rand() % 4 + 1;
		switch (p) {

		case 1:
			p = rand() % 2 + 1;
			if (p == 1) {
				f = new Point(rand() % 10, rand() % 10);
			}
			else
				f = new Section();
			break;

		case 2:
			p = rand() % 2 + 1;
			if (p == 1) {
				f = new Point(rand() % 10, rand() % 10);
			}
			else
				f = new Section();
			store.add(f);
			break;

		case 3:
			printf("Метод show\n");
			store.GetObject(rand() % store.getCount()).show();
			printf("\n");
			break;

		case 4:
			store.delete_obj(rand() % store.getCount());
			printf("\n");
			break;
		
		}
	}
	end_time = clock();
	search_time = end_time - start_time;
	printf("Время работы программы =  ");
	printf("%d", search_time);
	printf("\n");
	system("pause");
	system("cls");


	start_time = clock();
	for (int i = 0; i < 1000; i++) {
		int p = rand() % 4 + 1;
		switch (p) {

		case 1:
			p = rand() % 2 + 1;
			if (p == 1) {
				f = new Point(rand() % 10, rand() % 10);
			}
			else
				f = new Section();
			break;

		case 2:
			p = rand() % 2 + 1;
			if (p == 1) {
				f = new Point(rand() % 10, rand() % 10);
			}
			else
				f = new Section();
			store.add(f);
			break;

		case 3:
			printf("Метод show\n");
			store.GetObject(rand() % store.getCount()).show();
			printf("\n");
			break;

		case 4:
			store.delete_obj(rand() % store.getCount());
			printf("\n");
			break;

		}
	}
	end_time = clock();
	search_time = end_time - start_time;
	printf("Время работы программы =  ");
	printf("%d", search_time);
	printf("\n");
	system("pause");
	system("cls");
}