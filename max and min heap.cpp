#include<iostream>
using namespace std;

class Heap{
	int h[20],h1[20],x,n1,i;
	public:
	Heap(){
		h[0]=0;
		h1[0]=0;
	}
	void getdata();
	void insert1(int h[],int);
	void swap1(int h[],int);
	void insert2(int h1[],int);
	void swap2(int h1[],int);
	void minmax();
};

void Heap::getdata(){
	cout<<"\n Enter the No. of Students: ";
	cin>>n1;
	cout<<"\n Enter The Marks: ";
	for(i=0;i<n1;i++){
		cin>>x;
		insert1(h,x);
		insert2(h1,x);
	}
}

void Heap::insert1(int h[20],int x){
	int n;
	n=h[0];
	h[n+1]=x;
	h[0]=n+1;
	swap1(h,n+1);
}

void Heap::swap1(int h[20],int i){
	int temp;
	while(i>1&&h[i]>h[i/2]){
		temp=h[i];
		h[i]=h[i/2];
		h[i/2]=temp;
		i=i/2;
	}
}

void Heap::insert2(int h[20],int x){
	int n;
	n=h1[0];
	h1[n+1]=x;
	h1[0]=n+1;
	swap2(h1,n+1);
}

void Heap::swap2(int h1[20],int i){
	int temp;
	while(i>1&&h1[i]>h1[i/2]){
		temp=h1[i];
		h1[i]=h1[i/2];
		h1[i/2]=temp;
		i=i/2;
	}
}

void Heap::minmax(){
	cout<<"\n Max Marks"<<h[1];
	cout<<"\n##";
	for(i=0;i<=n1;i++){
		cout<<"\n"<<h[i];
	}
	cout<<"\n Min Marks"<<h1[1];
	cout<<"\n##";
	for(i=0;i<=n1;i++){
		cout<<"\n"<<h1[i];
	}
}

int main(){
	Heap heap;
	heap.getdata();
	heap.minmax();
	return 0;
}
