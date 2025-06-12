#include <iostream>
#include<algorithm>
using namespace std;
template<typename T>

class SimpleVector 
{
	T* data;
	int currentSize = 0;
	int currentCapacity = 0;
public:
	SimpleVector(int capacity1 = 10) : currentCapacity(capacity1) { data=new T [capacity1]; }
	SimpleVector(const SimpleVector& other)
	{
		T* newdata = new T(*data);
	}
	~SimpleVector() { delete[] data; }                                   //소멸자를 이용한 동적할당 해제
	
	void push_back(const T& value) {                                    //레퍼런스를 이용한 매개변수 값 
		if (currentSize < currentCapacity)
			data[currentSize++] = value;
		else if (currentSize >= currentCapacity) {
			int newsize = currentCapacity + 5;
			T* newdata = new T[newsize];
			for (int i = 0; i < currentSize; i++) {
				newdata[i] = data[i];
			}

			delete[] data;
			data = newdata;
			currentCapacity = newsize;
			data[currentSize++] = value;

		}
		;
	}
	void pop_back() {
		if (currentSize > 0)
			currentSize--;
	}
		void resize(int newCapacity) {
			if (newCapacity > currentCapacity) {
				T* newdata = new T[newCapacity];
				for (int i = 0; i < currentSize; i++) {
					newdata[i] = data[i];
				}
				delete[] data;
				data = newdata;
				currentCapacity = newCapacity;
			}
		}
	
	int size() const { return currentSize; }
	int capacity() const { return currentCapacity; }
	void sortData()
	{
		sort(data, data + currentSize);	
		cout << "정렬된 데이터 :  \n";
		for (int i = 0; i < currentSize; i++) {
			cout <<"data["<<i<<"]"<< data[i] << endl;
		}
	}
};






int main()
{
	//생성자를 불러와서 arr의 크기 할당
	SimpleVector<int> arr;
	arr.push_back(15);                                        //push_back 함수를 이용한 값 추가
	arr.push_back(2);
	arr.push_back(12);
	arr.push_back(4);
	arr.push_back(5);
	arr.push_back(6);
	arr.push_back(16);
	arr.push_back(8);
	arr.push_back(9);
	arr.push_back(10); 
	arr.push_back(11);
	arr.push_back(3);
	arr.push_back(13);
	arr.push_back(14);
	arr.push_back(1);
	arr.push_back(7);
	
	arr.sortData();
	arr.pop_back();
	arr.pop_back();	
	arr.pop_back();	
	arr.pop_back();	
	arr.pop_back();				//pop_back 함수를 이용한 값 제거
	arr.resize(35);
	cout << arr.size() << endl;
	cout << arr.capacity();

	return 0;
}

