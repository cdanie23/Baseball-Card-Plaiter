#include "MainForm.h"

#include <iomanip>
#include <sstream>

#include "AddCard.h"
#include "Constants.h"
#include "DeleteCard.h"
#include "../Model/PlaitedLinkedList.h"
#include "../FileIO/FileReader.h"
#include "../FileIO/FileWriter.h"
#include "../Utils/Utils.h"

using namespace System;
using namespace System::Windows::Forms;
using namespace View;
using namespace Model;
using namespace FileIO;

/// \brief Entry point into the program
/// \param args Command-line args (none for this program)
[STAThread]
int main(array<String^>^ args)
{
	Application::EnableVisualStyles();
	Application::SetCompatibleTextRenderingDefault(false);
	CardPlaiter::MainForm form;
	Application::Run(%form);

	return 0;
}

namespace CardPlaiter
{
	MainForm::MainForm(void)
	{
		InitializeComponent();

		this->nameAscendingRadioButton->Tag = safe_cast<int>(SortOrder::NAME_ASCENDING);
		this->nameDescendingRadioButton->Tag = safe_cast<int>(SortOrder::NAME_DESCENDING);
		this->yearAscendingRadioButton->Tag = safe_cast<int>(SortOrder::YEAR_ASCENDING);
		this->yearDescendingRadioButton->Tag = safe_cast<int>(SortOrder::YEAR_DESCENDING);
		this->conditionAscendingRadioButton->Tag = safe_cast<int>(SortOrder::CONDITION_ASCENDING);
		this->conditionDescendingRadioButton->Tag = safe_cast<int>(SortOrder::CONDITION_DESCENDING);


		this->list = new PlaitedLinkedList();
	}

	MainForm::~MainForm()
	{
		if (components)
		{
			delete components;
		}
		if (this->list)
		{
			delete this->list;
			this->list = nullptr;
		}
	}

	void MainForm::print(Node* node, bool descending, PlaitedLinkedList::Strands strand)
	{
		if (node == nullptr)
		{
		}
		else
		{
			switch (strand)
			{
			case PlaitedLinkedList::NAME:
				if (descending)
				{
					this->summaryTextBox->Text += gcnew String(this->formatNode(node).c_str()) + Environment::NewLine;
					print(node->getNextName(), descending, strand);
				}
				else
				{
					print(node->getNextName(), descending, strand);
					this->summaryTextBox->Text += gcnew String(this->formatNode(node).c_str()) + Environment::NewLine;
				}
				break;
			case PlaitedLinkedList::YEAR:
				if (descending)
				{
					this->summaryTextBox->Text += gcnew String(this->formatNode(node).c_str()) + Environment::NewLine;
					print(node->getNextYear(), descending, strand);
				}
				else
				{
					print(node->getNextYear(), descending, strand);
					this->summaryTextBox->Text += gcnew String(this->formatNode(node).c_str()) + Environment::NewLine;
				}
				break;
			case PlaitedLinkedList::CONDITION:
				if (descending)
				{
					this->summaryTextBox->Text += gcnew String(this->formatNode(node).c_str()) + Environment::NewLine;
					print(node->getNextCondition(), descending, strand);
				}
				else
				{
					print(node->getNextCondition(), descending, strand);
					this->summaryTextBox->Text += gcnew String(this->formatNode(node).c_str()) + Environment::NewLine;
				}
				break;
			}
		}
	}

	void MainForm::loadButton_Click(Object^ sender, EventArgs^ e)
	{
		auto openFileDialog = gcnew OpenFileDialog();

		openFileDialog->Filter = TEXT_FILE_FILTER;
		openFileDialog->FilterIndex = 2;
		openFileDialog->RestoreDirectory = true;

		if (openFileDialog->ShowDialog() == Windows::Forms::DialogResult::OK)
		{
			delete this->list;
			FileReader fileReader(toStandardString(openFileDialog->FileName));
			this->list = fileReader.readFile();
			this->summaryTextBox->Text = openFileDialog->FileName;
		}
	}

	void MainForm::saveButton_Click(Object^ sender, EventArgs^ e)
	{
		auto saveFileDialog = gcnew SaveFileDialog();

		saveFileDialog->Filter = TEXT_FILE_FILTER;
		saveFileDialog->FilterIndex = 2;
		saveFileDialog->RestoreDirectory = true;

		if (saveFileDialog->ShowDialog() == ::DialogResult::OK)
		{
			FileWriter fileWriter(toStandardString(saveFileDialog->FileName));
			fileWriter.writeFile(this->list);
			this->summaryTextBox->Text = saveFileDialog->FileName;
		}
	}

	void MainForm::addButton_Click(Object^ sender, EventArgs^ e)
	{
		AddCard addDialog;

		const auto result = addDialog.ShowDialog();
		if (result == Windows::Forms::DialogResult::OK)
		{
			BaseballCard* card = new BaseballCard(addDialog.GetFirstName(), addDialog.GetLastName(),
			                                      addDialog.GetYear(), addDialog.GetPrice(), addDialog.GetCondition());
			Node* node = new Node(card);
			this->list->insertNode(*node);
			this->summaryTextBox->Text = "AddCard::Ok was invoked.";
		}
	}

	void MainForm::deleteButton_Click(Object^ sender, EventArgs^ e)
	{
		DeleteCard deleteDialog;

		const auto result = deleteDialog.ShowDialog();
		if (result == Windows::Forms::DialogResult::OK)
		{
			this->summaryTextBox->Text = "DeleteCard::Ok was invoked.";
			try
			{
				this->list->removeNode(deleteDialog.GetFirstName(), deleteDialog.GetLastName());
			}
			catch (const std::exception& e)
			{
				this->summaryTextBox->Text = gcnew String(e.what());
			}
		}
	}

	void MainForm::sortOrderRadioButton_CheckedChanged(System::Object^ sender, System::EventArgs^ e)
	{
		RadioButton^ button = safe_cast<RadioButton^>(sender);

		if (button->Checked)
		{
			SortOrder sortOrder = static_cast<SortOrder>(safe_cast<int>(button->Tag));
			this->summaryTextBox->Text = "";
			switch (sortOrder)
			{
			case NAME_ASCENDING:
				this->print(this->list->getHead(PlaitedLinkedList::NAME), true, PlaitedLinkedList::NAME);
				break;
			case NAME_DESCENDING:
				this->print(this->list->getHead(PlaitedLinkedList::NAME), false, PlaitedLinkedList::NAME);
				break;
			case YEAR_ASCENDING:
				this->print(this->list->getHead(PlaitedLinkedList::YEAR), false, PlaitedLinkedList::YEAR);
				break;
			case YEAR_DESCENDING:
				this->print(this->list->getHead(PlaitedLinkedList::YEAR), true, PlaitedLinkedList::YEAR);
				break;
			case CONDITION_ASCENDING:
				this->print(this->list->getHead(PlaitedLinkedList::CONDITION), false, PlaitedLinkedList::CONDITION);
				break;
			case CONDITION_DESCENDING:
				this->print(this->list->getHead(PlaitedLinkedList::CONDITION), true, PlaitedLinkedList::CONDITION);
				break;
			default:
				this->summaryTextBox->Text = "Error with selection";
			}
		}
	}

	std::string MainForm::formatNode(const Node* node)
	{
		std::stringstream ss;
		ss << std::left << std::setw(20) << node->getCard()->GetFirstName() + " " + node->getCard()->GetLastName()
			<< std::left << std::setw(10) << node->getCard()->GetYear()
			<< std::left << std::setw(10) << GetConditionName(node->getCard()->GetCondition())
			<< std::fixed << std::setprecision(2) << "$" << node->getCard()->GetPrice();
		return ss.str();
	}
}
