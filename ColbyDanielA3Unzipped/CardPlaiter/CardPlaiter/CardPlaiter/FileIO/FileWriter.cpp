#include "FileWriter.h"
using namespace FileIO;

FileWriter::FileWriter(const std::string& fileName)
{
	this->fileName = fileName;
	this->fileStream.open(fileName, fileStream.out, fileStream.trunc);
	if (!this->fileStream.is_open())
	{
		throw std::runtime_error("Could not open file");
	}
}

FileWriter::~FileWriter()
{
}

void FileWriter::writeFile(PlaitedLinkedList* list)
{
	Node* current = list->getHead(PlaitedLinkedList::Strands::NAME);
	while (current != nullptr)
	{
		this->fileStream << current->getCard()->GetLastName() << "," << current->getCard()->GetFirstName() << "," <<
			current->getCard()
			       ->GetYear() << "," << current->getCard()->GetPrice() << "," << GetConditionName(
				current->getCard()->GetCondition()) <<
			std::endl;
		current = list->getNext(PlaitedLinkedList::Strands::NAME, current);
	}
	this->fileStream.close();
}
