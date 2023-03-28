#include <bits/stdc++.h>

using namespace std;

int heap_arr[100];
int heap_size;

void swap(int node, int swap_node, int swap_index) {
	heap_arr[swap_index/2] = node;
	heap_arr[swap_index] = swap_node;
}

void push(int node) {
	heap_size += 1;
	int index = heap_size;
	while(index != 1 && heap_arr[index/2] < node) {
		swap(node, heap_arr[index/2], index);
		index /= 2;
	}
	if(index == 1) {
		return;
	}
	else {
		heap_arr[index] = node;
	}
} 

void pop(int node) {
	// node의 위치를 찾을것. 
	heap_arr[1] = heap_arr[heap_size];
	heap_arr[heap_size] = node;
	int index = heap_size;
	while(index < heap_size && heap_arr[index * 2] > node) {
	}
	
}

int main(void) {
	fill_n(heap_arr, 100, 0); // 배열 초기화
	heap_size = 0;
	
	int node;
	
	while(node != -1) {
		cout << "Heap 현황 : ";
		for(int i = 1; i < heap_size + 1; i++) {
			cout << heap_arr[i] << " ";
		}
		cout << endl;
		 
		cin >> node;
		
		if(node == -1) {
			break;
		}
		
		if(heap_size == 0) {
			heap_arr[1] = node;
			heap_size++;
		}
		else {
			int pp;
			cout << "1. push | 2. pop" << endl;
			cin >> pp;
			while(1) {
				if(pp == 1) {
					push(node);
					break;
				}
				else if(pp == 2) {
					pop(node);
					break;
				}
				else {
					cout << "1 or 2" << endl;
					cin >> pp;
				}
			}
		}
	}
}
