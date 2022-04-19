#include <stdio.h>
#include <stdlib.h> 

typedef struct person {
	char *Name; //���ڿ� ������ ���� ������ ���
	int Age;
	double Height; //�� ������ Ÿ�Կ� �´� ������ ����
	person* link; //��ü ����
} person;

person* create(char *name, int age, double height) {
	//����: char ������, int, double
	person* new_node = NULL;
	new_node = (person*)malloc(sizeof(person));	//�� ��� �޸� �Ҵ�
	if (new_node == NULL)
		printf("�޸� �Ҵ� ����");
	new_node->Name = name;
	new_node->Age = age;
	new_node->Height = height;
	new_node->link=NULL;	//data/link field ����
	return new_node;	//�� ����� �ּҰ� ��ȯ
}

void add(person **pHead, person *new_node) {
	//����: head ���������Ϳ� �� ��� �ּҰ�
	person* p = NULL;
	p = *pHead;	//��� ������ ���� ������ ����
	if (*pHead == NULL) {	//��� X
		new_node->link = NULL;
		*pHead = new_node;	//head�� �� ��� ����Ŵ
		return;
	}
	while (p->link != NULL) 
		p = p->link;	//�ݺ������� ������ ��� �湮
	new_node->link = NULL;
	p->link = new_node; //������ ��� �ڿ� �߰�
}

void display(person** pHead)
	//����: head ����������
{
	person* p = NULL;
	p = *pHead;	//��� ������ ���� ������ ����
	while (p != NULL) {	//��� Ž��
		printf("%s, %d, %f -> ", p->Name, p->Age, p->Height);
		p = p->link;	//����ϰ� ���� ���� �Ѿ
	}
}

int main() {
	person* head = NULL;	//���������
	char name1[] = { "kim" };	//���ڿ� ����
	add(&head, create(name1, 34, 1.7));	//������ ��� �߰�
	char name2[] = { "park" };
	add(&head, create(name2, 27, 1.2));
	char name3[] = { "lee" };
	add(&head, create(name3, 48, 1.4));
	char name4[] = { "choi" };
	add(&head, create(name4, 30, 1.3));	//�ݺ�

	display(&head);
}