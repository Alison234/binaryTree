#include<iostream>
using namespace std;


//элемент дерева
struct element {
	element* left; // указатель на левого потоика
	element* right; // указатель на левого потоика
	int value; // значение 
	int count = 1 ; // количество элемента
};

//класс бинарное дерево
class Three {
protected:
	element* head; 
	// защищенные рекурсивыне методы
	void printElement(element*,int);
	void addElem(int, element*);
	void InThreeHelp(int, element*);
	void InLevel(element*, int, int, int);
public:
	Three();
	void showTree();
	void add(int);
	int MaxElement();
	void InThree(int);
	int CountLvl(int);
};

void Three::InThreeHelp(int s, element* pElem) {

	if (pElem->value == s)
	{
		cout << "element is in the tree!"<<" Count element = "<<pElem->count<<"\n";
		return;
	}

	if (pElem->value > s) {
		if (pElem->left != NULL) {
			InThreeHelp(s, pElem->left);
		}
		else {
			cout << "element is not in the tree!" << " Count element = 0" << "\n";
			return;
		}
	
	}

	if (pElem->value < s) {
		if (pElem->right != NULL) {
			InThreeHelp(s, pElem->right);
		}
		else {
			cout << "element is not in the tree!" << " Count element = 0 " << "\n";
			return;
		}

	}
	return;

}

void Three::InThree(int s) {
	if (head == NULL) {
		cout << "Three is Empty";
		return;
	}


	InThreeHelp(s, head);
	return;
}

//Максимальный элемент в дереве;
int Three::MaxElement() {
	element* pElem = new element;
	pElem = head;
	while (pElem->right != NULL) {
		pElem= pElem->right;
	}
	return pElem->value;
}

//вывод данных в виде дерева;
void Three::showTree() {
	if (head == NULL) {
		cout << "Three is Empty"<<"\n";
		return;
	}
	printElement(head,0);
	return;
	}
	
//вывод элемента дерева ;

void Three::printElement(element* pElem,int lvl) {
	if (pElem == NULL) {
		return;
	}

	cout << pElem->value<< "\n";

	
	if (pElem->left != NULL) {
		for (int i = 0; i < lvl; i++) {
			cout << "\t";
		}
		cout << " left ";
		printElement(pElem->left,lvl + 1);
		cout << '\n';
	}

	if (pElem->right != NULL) {
		for (int i = 0; i < lvl; i++) {
			cout << "\t";
		}
		cout << " right ";
		printElement(pElem->right,lvl + 1);
		cout << '\n';
	}



	return;
}

//Проверка на пустое дерево
void Three::add(int s) {

	if (head == NULL) {
		head = new element;
		head->value = s;
		head->left = NULL;
		head->right = NULL;
		return;
	}
	addElem(s, head);
	return;

}

//добавление элемента 
void Three::addElem(int s, element* pElem) {


	if (pElem->value == s) {
		pElem->count += 1;
		return;
	}


	if (pElem->value > s) {
		if (pElem->left == NULL) {
			pElem->left = new element;
			pElem->left->value = s;
			pElem->left->left = NULL;
			pElem->left->right = NULL;
			return;
		}

		addElem(s, pElem->left);
	}

	if (pElem->value < s) {
		if (pElem->right == NULL) {
			pElem->right = new element;
			pElem->right->value = s;
			pElem->right->right = NULL;
			pElem->right->left = NULL;
			return;
		}
		addElem(s, pElem->right);
	}


	return;
}

//конструктор
Three::Three() {
	head = NULL;
}

int Three::CountLvl(int lvl) {

	return;
}



int main() {

	Three a;
	
	a.add(8);
	a.add(12);
	a.add(7);
	a.add(5);
	a.add(9);
	a.add(26);
	a.add(6);
	a.add(15);
	a.add(5);
	a.add(26);

	cout<<"Max element = "<<a.MaxElement()<<"\n";
	a.InThree(26);
	a.showTree();

	system("pause");

}



