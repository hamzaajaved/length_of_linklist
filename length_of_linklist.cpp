#include<iostream>
#include<stdlib.h>
using namespace std;

struct Node{
	int value;
	struct Node* next;
};
void insert(int val);
void print();
void deleteNode(int val);
void searchNode(int val);
void length();
struct Node* start = NULL;
int main(){
	searchNode(10);
	insert(5);
	insert(10);
	insert(15);
	insert(20);
	length();
	print();
	deleteNode(15);
	cout << "------" << endl;
	print();
	length();
	searchNode(10);
	
}

void insert(int val){
	struct Node* ptr;
	ptr = (struct Node*) malloc (sizeof(struct Node));
	ptr->value = val;
	ptr->next = NULL;
	if(start == NULL){
		start = ptr;
	}else{
		struct Node* curr = start;
		while(curr->next != NULL){
			curr = curr->next;
		}
		curr->next = ptr;
	}
}
void deleteNode(int val){
	struct Node* curr = start;
	if(curr->value == val){
		start = start->next;
		free(curr);
	}else{
		struct Node* prev = start;
		curr = curr->next;
		while(curr->value != val){
			curr = curr->next;
			prev = prev->next;
		}
		prev->next = curr->next;
		free(curr);
	}
}

void searchNode(int val){
	if(start == NULL){
		cout << "List is Empty" << endl;
	}else{
		struct Node* curr = start;
		while(curr->next != NULL){
			if(curr->value == val){
				cout << "Found in List" << endl;
				break;
			}
			curr = curr->next;
			if(curr->next == NULL){
				if(curr->value == val){
					cout << "Found in List" << endl;
					break;
				}else{
					cout << "Not Found in List " << endl;
				}
			}
		}	
	}
}

void length(){
	struct Node* curr = start;
	int count = 0;
	while(curr->next != NULL){
		count++;
		curr = curr->next;
		if(curr->next == NULL){
			count++;
		}
	}
	cout << "Length is : " << count << endl;
}

void print(){
	struct Node* curr = start;
	while(curr->next != NULL){
		cout << curr->value << endl;
		curr = curr->next;
	}
	cout << curr->value << endl;
}
