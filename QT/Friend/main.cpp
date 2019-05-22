#include <iostream>
#include <string.h>

using namespace std;

class CNode
{
    friend class CMyList;

private:
    char Name[32];
    CNode *pNext = nullptr;

public:
    explicit CNode(const char *pName)
    {
        strcpy_s(Name, sizeof(Name), pName);
    }
};


class CMyList
{
private:
    CNode HeadNode;

public:
    CMyList() : HeadNode("Dummy Head") {}
    ~CMyList()
    {
        //리스트에 담긴 모든 데이터들을 모두 출력하고 삭제
        CNode *pNode = HeadNode.pNext;
        CNode *pDelete = nullptr;

        while(pNode)
        {
            pDelete = pNode;
            pNode = pNode->pNext;

            cout << pDelete->Name <<endl;
            delete pDelete;
        }
        HeadNode.pNext = nullptr;
    }
    void AddNewNode(const char *pName)
    {
        CNode *pNode = new CNode(pName);
        HeadNode.pNext = pNode;
    }
};

int main()
{
    CMyList list;
    list.AddNewNode("tom");
    list.AddNewNode("jerry");
    list.AddNewNode("dog");

    return 0;
}
