#include "FileReader.h"

#include <sstream>
using namespace FileIO;

FileReader::FileReader(const std::string& fileName)
{
	this->fileName = fileName;
	this->fileStream.open(fileName);
	if (!this->fileStream.is_open())
	{
		throw std::runtime_error("Could not open file");
	}
}

FileReader::~FileReader()
{
}

PlaitedLinkedList* FileReader::readFile()
{
	PlaitedLinkedList* list = new PlaitedLinkedList();
	std::string line;
	while (std::getline(this->fileStream, line))
	{
		std::istringstream ss(line);
		std::string firstName, lastName, yearStr, priceStr, conditionStr;

		std::getline(ss, lastName, ',');
		std::getline(ss, firstName, ',');
		std::getline(ss, yearStr, ',');
		std::getline(ss, priceStr, ',');
		std::getline(ss, conditionStr, ',');

		int year = std::stoi(yearStr);
		double price = std::stod(priceStr);
		Condition condition;
		switch (conditionStr[0])
		{
		case 'P':
			condition = POOR;
			break;
		case 'F':
			condition = FAIR;
			break;
		case 'G':
			condition = GOOD;
			break;
		case 'E':
			condition = EXCELLENT;
			break;
		case 'M':
			condition = MINT;
			break;
		default:
			throw std::runtime_error("Invalid condition");
		}

		BaseballCard* card = new BaseballCard(firstName, lastName, year, price, condition);
		Node* node = new Node(card);
		list->insertNode(*node);
	}
	this->fileStream.close();
	return list;
}
