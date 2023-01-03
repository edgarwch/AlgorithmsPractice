//
//  main.cpp
//  coding_pac
//
//  Created by Edgar Wong on 29/07/2022.
//

#include <iostream>
#include <string>
#include "delete_num.hpp"
#include <OpenGL/gl.h>
#include <OpenGl/glu.h>
#include <GLUT/glut.h>
#include <vector>
#include "heapsort.hpp"
#include "PriorityQueue.hpp"
//int main(int argc, const char * argv[])
//{
//    std::vector<int> jj{0,2,4,6,2,3,1};
//    DeleteNum a;
//    //DeleteNumTwoPointer a;
//    int b = a.removeElement(jj, 2);
//    jj.resize(b);
//    cout<<b;
//}

class Ins{
public:
    virtual void play(int i){
        cout<<"ins play"<<endl;
    }
};
class b:public Ins
{
public:
    void play(int i)
    {
        cout<<"b play"<<endl;
    }
};
class c:public Ins
{};
void tune(Ins& i)
{
    i.play(2);
}


int main()
{
	PriorityQueue pq;
	pq.MaxHeapInsert(45);
	pq.MaxHeapInsert(20);
	pq.MaxHeapInsert(14);
	pq.MaxHeapInsert(12);
	pq.MaxHeapInsert(31);
	pq.MaxHeapInsert(7);
	pq.MaxHeapInsert(11);
	pq.MaxHeapInsert(13);
	pq.MaxHeapInsert(7);
	pq.MaxHeapExtractMax();
	pq.MaxHeapIncreaseKey(2, 49);
	pq.printval();
	
}
