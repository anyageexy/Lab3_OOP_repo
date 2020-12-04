#include <stdlib.h>
#include <locale.h>
#include <time.h>
#include <iomanip>
#include <string>
#include <ctime>

using namespace std;

class Figure {//����� Figure
public:
	Figure() {//����������� �� ���������
	}
	virtual void show() {//����������� ����� show
		printf("\n������\n");
	}
	 ~Figure() {//����������� ���������� 
		printf("������ �������\n");
	}
}; 

class Storage { //����� ���������
private:
	Figure** objects;//��������� �� ���������, ��� ��� ����� ������� ����������
	int size;//������ ���������
public:
	Storage(int size) {//������� ������ ���������� �����, ��� �������� ������ ���������
		this->size = size;
		objects = new Figure * [size];
	}
	void SetObject(int index, Figure* object) {//�������� � ������� ������ object
		objects[index] = object;
	}
	Figure& GetObject(int index) { //���������� ������ � ��������
		return *objects[index];
	}
	void delete_obj(int index) {//������� ������
		objects[index]->~Figure();//����� ���������� ���������� 
	}
	void add(Figure* object) {//��������� ������  � ������ � �������� 
		Figure** object1 = new Figure * [size + 1];
		for (int i = 0; i < size; i++)
			object1[i] = objects[i];
		object1[size] = object;
		size++;
		delete objects;
		objects = object1;
		printf("�������� ������ ");
		object->show();
		printf("� ������ ");
		printf("%d", size - 1);
		printf("\n\n");
	}
	int getCount() {//����� ��� ���������� ������� ���������
		return size;
	}
};


class Point :public Figure {//����� ��������� �� ������ Figure
private:
	int x, y;
public:
	Point() {//����������� �� ���������
		x = 0;
		y = 0;
	}
	Point(int x, int y) {//����������� � �����������
		this->x = x;
		this->y = y;
	}
	void show() {
		printf("����� � ������������: ");
		printf("%d %d", x, y);
		printf("\n");
	}
	~Point() {
		printf("����� ������� � ������������:  ");
		printf("%d %d %c", x, y, " ");
		printf("\n");
	}
};

class Section : public Figure { // ����� - ����������
private:
	Point* p1, * p2;
	int x1, x2, y1, y2;
public:
	Section() {
		p1 = new Point(rand() % 10, (rand() % 10));
		p2 = new Point(rand() % 10, (rand() % 10));
	}
	void show() {
		printf("\n������� � �������: \n");
		p1->show();
		p2->show();
		printf("\n");
	}
	~Section() {
		printf("������� � �������: \n");
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
	Storage store(50);// ������� ��������� � ������ store
	for (int i = 0; i < store.getCount(); i++) {
		int a = rand() % 2 + 1;//��������� ����� �� 1 �� 4
		if (a == 2)
			store.SetObject(i, new Point(rand() % 10, rand() % 10));//�������� � ������ �����
		else
			store.SetObject(i, new Section());//�������� � ������ �������
	}
	for (int i = 0; i < store.getCount(); i++) {
		store.GetObject(i).show();//������� �� ������� ��� ��������� �������
	}

	printf("\n");
	printf("%d", store.getCount());
	printf(" - ������ ��������� \n\n");//������� ������ ���������
	unsigned int start_time = clock(); //���������� �����, ���������� � ������� ������� ���������, ��������� ������� clock()
	for (int i = 0; i < 100; i++) {//���� ��� 100 ��������
		int p = rand() % 4 + 1;
		switch (p) {
		case 1://�������� ������ �������
			p = rand() % 2 + 1;
			if (p == 1) {//���� p = 1 - ��������� �����
				f = new Point(rand() % 10, rand() % 10);
			}
			else//����� �������
				f = new Section();
			break;
		case 2://�������� � ���������� ������ ������� � ������
			p = rand() % 2 + 1;
			if (p == 1) {
				f = new Point(rand() % 10, rand() % 10);
			}
			else
				f = new Section();
			store.add(f);
			break;
		case 3:
			printf("����� show\n");//����� ���������� ������� �� ���������
			store.GetObject(rand() % store.getCount()).show();
			printf("\n");
			break;
		case 4:
			store.delete_obj(rand() % store.getCount());//�������� ���������� ������� �� ������
			printf("\n");
			break;
		}
	}
	unsigned int end_time = clock();
	unsigned int search_time = end_time - start_time;
	printf("����� ������ ��������� =  ");
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
			printf("����� show\n");
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
	printf("����� ������ ��������� =  ");
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
			printf("����� show\n");
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
	printf("����� ������ ��������� =  ");
	printf("%d", search_time);
	printf("\n");
	system("pause");
	system("cls");
}