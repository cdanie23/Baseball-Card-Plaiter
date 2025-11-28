#include "DeleteCard.h"
#include "Constants.h"
#include "../Utils/Utils.h"

namespace View
{
	DeleteCard::DeleteCard(void)
	{
		InitializeComponent();
	}

	DeleteCard::~DeleteCard()
	{
		if (components)
		{
			delete components;
		}
	}

	std::string DeleteCard::GetFirstName()
	{
		return toStandardString(this->firstName);
	}

	std::string DeleteCard::GetLastName()
	{
		return toStandardString(this->lastName);
	}

	void DeleteCard::okButton_Click(System::Object^ sender, System::EventArgs^ e)
	{
		if (String::IsNullOrEmpty(this->firstNameTextBox->Text))
		{
			MessageBox::Show(FIRST_NAME_REQUIRED, MISSING_DATA, MessageBoxButtons::OK);
			return;
		}

		if (String::IsNullOrEmpty(this->lastNameTextBox->Text))
		{
			MessageBox::Show(LAST_NAME_REQUIRED, MISSING_DATA, MessageBoxButtons::OK);
			return;
		}

		this->firstName = this->firstNameTextBox->Text;
		this->lastName = this->lastNameTextBox->Text;

		this->DialogResult = Windows::Forms::DialogResult::OK;
	}

	void DeleteCard::cancelButton_Click(System::Object^ sender, System::EventArgs^ e)
	{
		this->firstName = EMPTY_STRING;
		this->lastName = EMPTY_STRING;
		this->DialogResult = Windows::Forms::DialogResult::Cancel;
	}

}


