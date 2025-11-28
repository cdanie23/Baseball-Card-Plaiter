#include "AddCard.h"
#include "Constants.h"
#include "../Utils/Utils.h"

namespace View
{
	AddCard::AddCard(void)
	{
		InitializeComponent();

	}

	std::string AddCard::GetFirstName()
	{
		return toStandardString(this->firstName);
	}

	std::string AddCard::GetLastName()
	{
		return toStandardString(this->lastName);
	}

	Condition AddCard::GetCondition()
	{
		return this->condition;
	}

	int AddCard::GetYear()
	{
		return this->year;
	}

	double AddCard::GetPrice()
	{
		return this->price;
	}

	AddCard::~AddCard()
	{
		if (components)
		{
			delete components;
		}
	}

	void AddCard::addCard_Load(System::Object^ sender, System::EventArgs^ e)
	{
		for (int i = Condition::POOR; i <= Condition::MINT; i++)
		{
			Condition type = static_cast<Condition>(i);
			String^ name = gcnew String(GetConditionName(type).c_str());
			this->conditionComboBox->Items->Add(name);
			this->conditionComboBox->SelectedItem = gcnew String(GetConditionName(Condition::POOR).c_str());
		}
	}

	void AddCard::okButton_Click(System::Object^ sender, System::EventArgs^ e)
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

		if (String::IsNullOrEmpty(this->priceTextBox->Text))
		{
			MessageBox::Show(PRICE_REQUIRED, MISSING_DATA, MessageBoxButtons::OK);
			return;
		}

		this->firstName = this->firstNameTextBox->Text;
		this->lastName = this->lastNameTextBox->Text;
		this->year = static_cast<int>(this->yearNumericUpDown->Value);
		this->price = double::Parse(this->priceTextBox->Text);
		this->condition = static_cast<Condition>(this->conditionComboBox->SelectedIndex);

		this->DialogResult = Windows::Forms::DialogResult::OK;
	}

	void AddCard::cancelButton_Click(System::Object^ sender, System::EventArgs^ e)
	{
		this->firstName = EMPTY_STRING;
		this->lastName = EMPTY_STRING;
		this->year = 0;
		this->price = 0.0;
		this->condition = Condition::POOR;

		this->DialogResult = Windows::Forms::DialogResult::Cancel;
	}

	void AddCard::priceTextBox_KeyPress(System::Object^ sender, System::Windows::Forms::KeyPressEventArgs^ e)
	{
		if (!Char::IsControl(e->KeyChar) && !Char::IsDigit(e->KeyChar) && (e->KeyChar != '.')) {
			e->Handled = true;
		}

		if ((e->KeyChar == '.') && this->priceTextBox->Text->IndexOf('.') > -1) {
			e->Handled = true;
		}
	}

}


