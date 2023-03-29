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

void pop() {
	//힙의 삭제는 가장 큰 값인 루트를 삭제하는 것. 
	//마지막 node와 뺄 node 바 꿈
	int temp = heap_arr[1]; 
	heap_arr[1] = heap_arr[heap_size];
	heap_arr[heap_size] = 0;
	 
	int index = 1;
	while(index < heap_size && heap_arr[index * 2] != 0) {
		if(heap_arr[index] > heap_arr[index*2] && heap_arr[index] > heap_arr[index*2 +1]) {
			break;
		}
		if(heap_arr[index*2] > heap_arr[index*2+1]) {
			swap(heap_arr[index*2], heap_arr[index], index * 2);
			index *= 2;
		}
		else {
			swap(heap_arr[index*2 + 1], heap_arr[index], index * 2 + 1);
			index = index * 2 + 1;
		}
	}
	heap_arr[heap_size] = 0;
	heap_size--;
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
		
		if(node <= 0) {
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
					pop();
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
