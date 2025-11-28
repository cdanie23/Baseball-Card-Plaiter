#include "TestRemoveNode.h"
#include "../Model/PlaitedLinkedList.h"
using namespace Test;

void TestRemoveNode::testRemoveNode()
{
    Model::PlaitedLinkedList* list = new Model::PlaitedLinkedList();
    Model::BaseballCard* card = new Model::BaseballCard("John", "Doe", 1990, 100.0, MINT);
    Model::Node* node = new Model::Node(card);
    list->insertNode(node);
    list->removeNode(node);
    delete list;
    delete card;
    delete node;
}
int main()
{
	TestRemoveNode test;
    test.testRemoveNode();
    return 0;
}