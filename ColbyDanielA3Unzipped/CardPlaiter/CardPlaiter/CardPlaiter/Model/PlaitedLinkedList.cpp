#include "PlaitedLinkedList.h"

#include <cassert>
#include <stdexcept>
#include <algorithm>
using namespace Model;

PlaitedLinkedList::PlaitedLinkedList()
{
	this->nameHead = nullptr;
	this->yearHead = nullptr;
	this->conditionHead = nullptr;
}

PlaitedLinkedList::~PlaitedLinkedList()
{
	delete this->nameHead;
	this->nameHead = nullptr;
}

Node* PlaitedLinkedList::getNext(PlaitedLinkedList::Strands strand, Node* current) const
{
	switch (strand)
	{
	case NAME:
		return current->getNextName();

	case YEAR:
		return current->getNextYear();

	case CONDITION:
		return current->getNextCondition();
	}
	return nullptr;
}

void PlaitedLinkedList::removeNode(Node* node, Node*& head, Strands strand) const
{
	assert(node != nullptr);
	assert(head != nullptr);

	Node* current = head;
	Node* previous = nullptr;

	while (current != node)
	{
		previous = current;
		current = getNext(strand, current);
	}
	if (previous == nullptr)
	{
		head = this->getNext(strand, current);
	}
	else
	{
		switch (strand)
		{
		case NAME:
			previous->setNextName(current->getNextName());
			break;
		case YEAR:
			previous->setNextYear(current->getNextYear());
			break;
		case CONDITION:
			previous->setNextCondition(current->getNextCondition());
			break;
		}
	}
}

void PlaitedLinkedList::removeNode(const std::string& firstName, const std::string& lastName)
{
	Node* nodeToRemove = this->getNode(firstName, lastName);
	this->removeNode(nodeToRemove, this->nameHead, NAME);
	this->removeNode(nodeToRemove, this->yearHead, YEAR);
	this->removeNode(nodeToRemove, this->conditionHead, CONDITION);

	nodeToRemove->setNextName(nullptr);
	nodeToRemove->setNextCondition(nullptr);
	nodeToRemove->setNextYear(nullptr);
	delete nodeToRemove;
}

void PlaitedLinkedList::insertNode(Node& node)
{
	this->insertNode(node, this->nameHead, NAME);
	this->insertNode(node, this->yearHead, YEAR);
	this->insertNode(node, this->conditionHead, CONDITION);
}

void PlaitedLinkedList::insertNode(Node& node, Node*& head, Strands strand)
{
	if (head == nullptr)
	{
		head = &node;
	}
	else
	{
		Node* current = head;
		Node* previous = nullptr;
		bool insertHere = false;
		while (current != nullptr)
		{
			switch (strand)
			{
			case NAME:
				if (node.getCard()->compareName(current->getCard()->GetFirstName(), current->getCard()->GetLastName()) <
					0)
				{
					insertHere = true;
				}
				break;
			case YEAR:
				if (node.getCard()->compareYear(current->getCard()->GetYear(), current->getCard()->GetPrice()) > 0)
				{
					insertHere = true;
				}
				break;
			case CONDITION:
				if (node.getCard()->compareCondition(current->getCard()->GetCondition(), current->getCard()->GetPrice())
					> 0)
				{
					insertHere = true;
				}
				break;
			}
			if (insertHere)
			{
				break;
			}
			previous = current;
			current = this->getNext(strand, current);
		}
		if (previous == nullptr)
		{
			switch (strand)
			{
			case NAME:
				node.setNextName(head);
				break;
			case YEAR:
				node.setNextYear(head);
				break;
			case CONDITION:
				node.setNextCondition(head);
				break;
			}
			head = &node;
		}
		else
		{
			switch (strand)
			{
			case NAME:
				node.setNextName(previous->getNextName());
				previous->setNextName(&node);
				break;
			case YEAR:
				node.setNextYear(previous->getNextYear());
				previous->setNextYear(&node);
				break;
			case CONDITION:
				node.setNextCondition(previous->getNextCondition());
				previous->setNextCondition(&node);
				break;
			}
		}
	}
}

Node* PlaitedLinkedList::getNode(const std::string& firstName, const std::string& lastName) const
{
	Node* current = this->nameHead;
	while (current != nullptr)
	{
		if (current->getCard()->compareName(firstName, lastName) == 0)
		{
			return current;
		}
		current = current->getNextName();
	}
	throw std::runtime_error("Node not found");
}

Node* Model::PlaitedLinkedList::getHead(Strands strand) const
{
	switch (strand)
	{
	case NAME:
		return this->nameHead;
	case YEAR:
		return this->yearHead;
	case CONDITION:
		return this->conditionHead;
	}
	return nullptr;
}
