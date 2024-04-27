#include <iostream>
#include "Box.h"
#include "Container.h"


using namespace BoxAndContainer;

int main()
{
	setlocale(LC_ALL, "Russian");
	Box* box = new Box[5];
	box[0] = Box(1, 2, 3, 4, 5);
	box[1] = Box(2, 3, 4, 5, 6);
	box[2] = Box(3, 4, 5, 6, 7);
	box[3] = Box(4, 5, 6, 7, 8);
	box[4] = Box(5, 6, 7, 8, 9);
	std::cout << "��������� ���������: " << sumValue(box, 5) << " (Correct is 35)" << std::endl; //������� 2.
	std::cout << "�� ����������� �� �������� ����� �����, ������ � ������ ���� ������� �������� ��������:  "
		<< lessThanTheSpecifiedValue(box, 5, 99) << " (Correct is 1)" << std::endl; //������� 3.
	std::cout << "������������ ��� �������, �� ������������� ������������ ����� �������: " << volumCheck(box, 5, 61)
		<< " (Correcr is 6)" << std::endl; //������� 4.
	std::cout << "����� �� ������� ���� ������� � ������, ������� � ����� ���������: " << matryoshka(box, 5) << " (Correct is 1)" << std::endl; //������� 5.
	for (int i = 0; i < 5; i++)
	{
		std::cout << "������� #" << i + 1 << std::endl;
		std::cout << box[i];
		std::cout << std::endl;
	}
	std::cout << std::endl;
	/*std::cout << "������� ����� �������, ������� �� ������ ��������: ";
	int n;
	std::cin >> n;
	std::cout << std::endl;
	std::cout << "������� ����� ��������: " << std::endl;
	std::cin >> box[n - 1];
	std::cout << "����� ��������� ������� #" << n - 1 << std::endl;
	std::cout << box[n - 1];
	*/

	Container container = Container(100, 50, 250, 35);

	std::cout << "���������� �������: " << container.boxCounter() << " (Correct is 0)" << std::endl;

	container.addingABox(box[0]);
	container.addingABox(box[1]);
	container.addingABox(box[2]);
	container.addingABox(box[3]);
	container.addingABox(box[4]);

	std::cout << container;
	std::cout << "���������� �������: " << container.boxCounter() << " (Correct is 5)" << std::endl;

	std::cout << "��������� ��� ����������� � ��������: " << container.totalWeight() << " (Correct is 30)" << std::endl;
	std::cout << "��������� ��������� ����������� � ��������: " << container.totalCost() << " (Correct is 35)" << std::endl;

	std::cout << container.getBox(2) << std::endl;
	container.deleteBox(0);
	container.deleteBox(3);

	std::cout << container;
	std::cout << "���������� �������: " << container.boxCounter() << " (Correct is 3)" << std::endl;

	std::cout << container[2] << std::endl;
	container[2] = box[4];
	std::cout << container[2] << std::endl;
	std::cout << "--------------" << std::endl;
	std::cin >> container;
	std::cout << container;

	try {
		container.setHeight(-1);
	}
	catch (std::exception) {
		std::cout << "Error!";
	}
}










// ������ ���������: CTRL+F5 ��� ���� "�������" > "������ ��� �������"
// ������� ���������: F5 ��� ���� "�������" > "��������� �������"

// ������ �� ������ ������ 
//   1. � ���� ������������ ������� ����� ��������� ����� � ��������� ���.
//   2. � ���� Team Explorer ����� ������������ � ������� ���������� ��������.
//   3. � ���� "�������� ������" ����� ������������� �������� ������ ������ � ������ ���������.
//   4. � ���� "������ ������" ����� ������������� ������.
//   5. ��������������� �������� ������ ���� "������" > "�������� ����� �������", ����� ������� ����� ����, ��� "������" > "�������� ������������ �������", ����� �������� � ������ ������������ ����� ����.
//   6. ����� ����� ������� ���� ������ �����, �������� ������ ���� "����" > "�������" > "������" � �������� SLN-����.




	/*int n; //���������� �������
	int length, width, height; //�����, ������ � ������ ������� � ��
	double weight; //����� ������� � ��
	int value; //��������� ����������� � ��������
	int maxLength, maxWidth, maxHeight; //���������� �������� ��� �����, ������ � ������ �������
	int maxV; //������������ �����
	int n1, n2;
	setlocale(LC_ALL, "Russian");
	std::cout << "������� ���������� �������" << std::endl;
	std::cin >> n;
	Box* box = new Box[n];
	std::cout << "������� �����, ������, ������, ����� � ��������� ����������� �������" << std::endl;
	for(int i = 0; i < n; i++)
	{
		std::cout << "������� #" << i + 1 << std::endl;
		std::cin >> box[i];
		std::cout << std::endl;
	}
	std::cout << "��������� ���������: " << sumValue(box, n) << " (Correct is ?)" << std::endl; //������� 2.
	std::cout << "������� ���������� ��������, ��� �����, ������ � ������ �������: " << std::endl;
	std::cin >> maxLength >> maxWidth >> maxHeight;
	std::cout << std::endl;
	//std::cout << "�� ����������� �� �������� ����� �����, ������ � ������ ���� ������� �������� ��������:  " << lessThanTheSpecifiedValue(box, n, maxLength, maxWidth, maxHeight) << std::endl; //������� 3.
	std::cout << "������� ������������ ����� �������: ";
	std::cin >> maxV;
	std::cout << std::endl;
	std::cout << "������������ ��� �������, �� ������������� ������������ ����� �������: " << volumCheck(box, n, maxV) << std::endl; //������� 4.
	std::cout << "����� �� ������� ���� ������� � ������, ������� � ����� ���������: " << matryoshka(box, n) << std::endl;
	std::cout << "������� ������ �������, ������� �� ������ ��������: " << std::endl;
	std::cin >> n1 >> n2;
	std::cout << "����� �� ������� �� ���� ����������? " << operator==(box[n1 + 1], box[n2 + 1]) << " (Correct is 1)" << std::endl;
	std::cout << "������� ����� �������, ������� �� ������ ��������: ";
	std::cin >> n;
	std::cout << std::endl;
	std::cin >>  box[n + 1];
	std::cout << "����� ��������� ������� #" << n + 1 << std::endl;
	std::cout << box[n];
	delete[] box; */