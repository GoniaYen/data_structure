#include "PriorityQueue.cpp"
#include <iostream>

using namespace std;

int main(int argc, char **argv)
{
    // PriorityQueue<int > p;
    //  p.enQueue(20);
    //  p.enQueue(1);
    //  p.enQueue(2);
    //  p.enQueue(5);
    //  p.enQueue(19);

    //  cout << p.deQueue() << endl;
    //  cout << p.deQueue() << endl;
    //  cout << p.deQueue() << endl;
    //  cout << p.deQueue() << endl;
    //  cout << p.deQueue() << endl;

    int test[] = {1, 5, 7, 20, 23, 22, 70, 9, 43, 101, 34, 78};
    PriorityQueue<int> pr(test, sizeof(test) / sizeof(test[1]));

    while (!pr.isEmpty())
    {
        cout << pr.deQueue() << endl;
    }

    // cout<<sizeof(test)/sizeof(test[1]);

    return 0;
}