#include "HFMTree.cpp"
#include <iostream>

using namespace std;

int main(int argc, char **argv)
{
    char ch[] = {"aeistdn"};
    int w[] = {10, 15, 12, 3, 4, 13, 1};
    HFMTree < char > tree(ch, w, 7);
    HFMTree<char>::HFMCode result[7];
    tree.get_code(result);

    for (int i = 0; i < 7; i++)
    {
        cout << result[i].data << " " << result[i].code << endl;
    }

    return 0;
}