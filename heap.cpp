//Writing program to implemenent MINIMUM Binary Heap using Arrays.

//including libraries
#include<iostream>
#include<climits>
using namespace std;

//writing class Binary Heap
class BinaryHeap{
	public:
	//declaring pointer to point to array of elements
	int *ptr;
	//declaring variable to store maximum possible size of array
	int msize;
	//declaring variable to store the current size of the array
	int csize;
	//writing constructor to assign values of pointer and variables
	BinaryHeap(int msize){
		//making ptr point to a new array
		ptr = new int[msize];
		//making the class variable msize equal to the msize provided in the function
		this->msize=msize;
		//making current size zero as the array is empty till now
		csize=0;
	}

	//writing function to return value of parent's position of any node
	int parent(int i){
		//returning parent's position
		return((i-1)/2);
	}

	//writing function to return value of left child's position of any node
	int left(int i){
		//returning left child's position
		return((i*2)+1);
	}

	//writing function to return value of right child's position of any node
	int right(int i){
		//returning right child's position
		return((i*2)+2);
	}

	//writing function to swap two values
	void swap(int *p1, int *p2){
		//creating temp variable to store any one value temporarily and swapping
		int temp=*p1;
		*p1=*p2;
		*p2=temp;
	}

	//writing function to heapify
	void heapify(int* point){
		//declaring and initializing variables
		int i, j, prp,pr, v;
		i=0;
		//start checking from the beginning of the array
		for(j=csize-1; j>0; j--){
			//getting the position of parent of any node
			prp=parent(j);
			//value of parent
			pr=*(point+prp);
			v=*(point+j);
			//checking if parent is greater than the node, if yes then swapping the values
			if(pr > v) swap(point+prp, point+j);
		}
	}

	//writing function to insert values in the array
	void insert(int n){
		//declaring variables
		int i, pr;
		//Base condition, to check if the heap has overflowed
		if(msize==csize) cout<<"The Binary Heap is full. No more values can be inserted."<<endl;
		else {
			//checking if the array is empty
			if(csize==0){
				//inserting value at position
				*(ptr+csize)=n;
				//incrementing value of csize
				csize++;
				//cout<<"Current size="<<csize<<endl;
			}
			//if array is not empty
			else{
				//inserting value at position
				*(ptr+csize)=n;
				//incrementing value of csize
				csize++;
				//cout<<"Current size="<<csize<<endl;
			}
			//heapify
			heapify(ptr);
		}
	}

	//writing function to get min value
	int getMin(){
		//returning the value of root, as root is the min value of the Binary Heap
		return(*ptr);
	}
	
	void extractMin(){
		//replacing root with the last element
		*ptr=*(ptr+csize-1);
		csize--; //reducing casize value to remove last element
		//heapifying to get proper Binary Heap
		heapify(ptr);
	}
	
	//setting i'th element to least value 
	void decreaseKey(int i){
		//replacing i'th value with the lowest value of inetger allowed
		*(ptr+i)=INT_MIN;
		//heapifying the array to get proper Binary Heap
		heapify(ptr);
	}
	
	//writing delete function to delete some element from array
	void Delete(int n){
		//declaring variables
		int i;
		//finding the position of n in array
		for(i=0; i<csize;i++){
			if(*(ptr+i)==n) break;
		}
		if(i==csize) cout<<"No such value in array."<<endl;
		else{
			//applying decreasekey on the i'th position
			decreaseKey(i);
			//extracting the min value, essentially deleting the value required
			extractMin();
		}
	}

	//writing function to display the binary heap
	void display(){
		//declaring variables
		int j;
		//running for loop to display
		for(j=0; j<csize; j++) cout<<*(ptr+j)<<" ";
		cout<<endl;
	}
};

//writing main function
int main(){
	//creating object of class binaryheap
	BinaryHeap bh(10);
	//inserting values
	bh.insert(10);
	bh.insert(9);
	bh.insert(8);
	bh.insert(7);
	bh.insert(6);
	bh.display();
	//deleting 7
	bh.Delete(7);
	bh.display();
	//deleting 5
	bh.Delete(5);
	bh.display();
	bh.Delete(6);
	bh.display();
	return 0;
}
