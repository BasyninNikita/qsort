#include <iostream>
#include <string>
#include <utility>
#include <sstream>
using namespace std;
void vyvod(int *array,unsigned int size)
{
	for(unsigned int i=0;i<size;i++)
	{
		cout<<array[i]<<" ";
	}
}
bool vvod(int *array,unsigned int size)
{
    string stroka;
    getline(cin,stroka);
    istringstream stream(stroka);
    for(unsigned int i=0;i<size;i++)
    {
        if(!(stream>>array[i])){
            cout<<"nepolnuy massiv";
            return false;
        }   
    }
    return true;
}
void qsort(int *array,int i,int j)
{
	int l=i;int r=j;
	int nach=l;
	while(r>=l)
	{
		while((array[l]<array[nach])&&(l<=j)) l++;
		while((array[r]>array[nach])&&(r>=i)) r--;
		if(l<=r)
		{
			swap(array[l],array[r]);
			l++;
			r--;
		}
	}
	if(l<j) qsort(array,l,j);
	if (r>i) qsort(array,i,r);
}

int main(int argc, char** argv) {
	unsigned int size;
	string stroka;
        getline(cin,stroka);
        istringstream stream(stroka);
	if(!(stream>>size)){
        	cout<<"error"<<endl;
       		return -1;
    	}	
	int *array=new int[size];
	if(vvod(array,size))
	{
		qsort(array,0,size-1);
		vyvod(array,size);
	}
	delete[]array;
	return 0;
}
