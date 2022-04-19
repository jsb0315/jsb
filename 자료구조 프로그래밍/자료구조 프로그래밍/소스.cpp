#include <stdio.h>
#include <stdlib.h> 

typedef struct person {
	char *Name; //문자열 접근을 위해 포인터 사용
	int Age;
	double Height; //각 데이터 타입에 맞는 데이터 저장
	person* link; //자체 참조
} person;

person* create(char *name, int age, double height) {
	//인자: char 포인터, int, double
	person* new_node = NULL;
	new_node = (person*)malloc(sizeof(person));	//새 노드 메모리 할당
	if (new_node == NULL)
		printf("메모리 할당 에러");
	new_node->Name = name;
	new_node->Age = age;
	new_node->Height = height;
	new_node->link=NULL;	//data/link field 저장
	return new_node;	//새 노드의 주소값 반환
}

void add(person **pHead, person *new_node) {
	//인자: head 더블포인터와 새 노드 주소값
	person* p = NULL;
	p = *pHead;	//노드 접근을 위해 포인터 생성
	if (*pHead == NULL) {	//노드 X
		new_node->link = NULL;
		*pHead = new_node;	//head가 새 노드 가리킴
		return;
	}
	while (p->link != NULL) 
		p = p->link;	//반복문으로 마지막 노드 방문
	new_node->link = NULL;
	p->link = new_node; //마지막 노드 뒤에 추가
}

void display(person** pHead)
	//인자: head 더블포인터
{
	person* p = NULL;
	p = *pHead;	//노드 접근을 위해 포인터 생성
	while (p != NULL) {	//노드 탐색
		printf("%s, %d, %f -> ", p->Name, p->Age, p->Height);
		p = p->link;	//출력하고 다음 노드로 넘어감
	}
}

int main() {
	person* head = NULL;	//헤드포인터
	char name1[] = { "kim" };	//문자열 생성
	add(&head, create(name1, 34, 1.7));	//생성한 노드 추가
	char name2[] = { "park" };
	add(&head, create(name2, 27, 1.2));
	char name3[] = { "lee" };
	add(&head, create(name3, 48, 1.4));
	char name4[] = { "choi" };
	add(&head, create(name4, 30, 1.3));	//반복

	display(&head);
}