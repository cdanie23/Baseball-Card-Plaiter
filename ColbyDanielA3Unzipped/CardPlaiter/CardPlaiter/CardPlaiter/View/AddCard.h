#pragma once
#include "AddCard.h"
#include "../Model/BaseballCard.h"
#include <string>
using namespace Model;

namespace View {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;

	/// <summary>
	/// Summary for AddCard
	/// </summary>
	public ref class AddCard : public System::Windows::Forms::Form
	{
	public:
		/// \brief Constructs the AddCard dialog
		///	\precondition none
		AddCard(void);

		/// \brief Gets the first name that was entered
		///	\precondition none
		/// \return The first name
		std::string GetFirstName();

		/// \brief Gets the last name that was entered
		///	\precondition none
		/// \return The last name
		std::string GetLastName();

		/// \brief Gets the year that was entered
		///	\precondition none
		/// \return The year
		int GetYear();

		/// \brief Gets the price that was entered
		///	\precondition none
		/// \return The price
		double GetPrice();

		/// \brief Gets the condition that was selected
		///	\precondition none
		/// \return The condition
		Condition GetCondition();

	protected:
		/// \brief Clean up any resources being used.
		~AddCard();

	private:
		String^ firstName;
		String^ lastName;
		int year;
		double price;
		Condition condition;

		System::Windows::Forms::Label^ firstNameLabel;
		System::Windows::Forms::Label^ lastNameLabel;
		System::Windows::Forms::Label^ yearLabel;
		System::Windows::Forms::Label^ priceLabel;
		System::Windows::Forms::Label^ conditionLabel;
		System::Windows::Forms::Button^ okButton;
		System::Windows::Forms::Button^ cancelButton;
		System::Windows::Forms::TextBox^ firstNameTextBox;
		System::Windows::Forms::TextBox^ lastNameTextBox;
		System::Windows::Forms::NumericUpDown^ yearNumericUpDown;
		System::Windows::Forms::TextBox^ priceTextBox;
		System::Windows::Forms::ComboBox^ conditionComboBox;

		/// \brief Required designer variable.
		System::ComponentModel::Container^ components;

#pragma region Windows Form Designer generated code
		/// \brief Required method for Designer support - do not modify
		/// the contents of this method with the code editor.
		void InitializeComponent(void)
		{
			this->firstNameLabel = (gcnew System::Windows::Forms::Label());
			this->lastNameLabel = (gcnew System::Windows::Forms::Label());
			this->conditionLabel = (gcnew System::Windows::Forms::Label());
			this->yearLabel = (gcnew System::Windows::Forms::Label());
			this->okButton = (gcnew System::Windows::Forms::Button());
			this->cancelButton = (gcnew System::Windows::Forms::Button());
			this->firstNameTextBox = (gcnew System::Windows::Forms::TextBox());
			this->lastNameTextBox = (gcnew System::Windows::Forms::TextBox());
			this->yearNumericUpDown = (gcnew System::Windows::Forms::NumericUpDown());
			this->conditionComboBox = (gcnew System::Windows::Forms::ComboBox());
			this->priceLabel = (gcnew System::Windows::Forms::Label());
			this->priceTextBox = (gcnew System::Windows::Forms::TextBox());
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->yearNumericUpDown))->BeginInit();
			this->SuspendLayout();
			// 
			// firstNameLabel
			// 
			this->firstNameLabel->AutoSize = true;
			this->firstNameLabel->Location = System::Drawing::Point(50, 40);
			this->firstNameLabel->Margin = System::Windows::Forms::Padding(6, 0, 6, 0);
			this->firstNameLabel->Name = L"firstNameLabel";
			this->firstNameLabel->Size = System::Drawing::Size(119, 25);
			this->firstNameLabel->TabIndex = 0;
			this->firstNameLabel->Text = L"First name:";
			// 
			// lastNameLabel
			// 
			this->lastNameLabel->AutoSize = true;
			this->lastNameLabel->Location = System::Drawing::Point(51, 94);
			this->lastNameLabel->Margin = System::Windows::Forms::Padding(6, 0, 6, 0);
			this->lastNameLabel->Name = L"lastNameLabel";
			this->lastNameLabel->Size = System::Drawing::Size(118, 25);
			this->lastNameLabel->TabIndex = 1;
			this->lastNameLabel->Text = L"Last name:";
			// 
			// conditionLabel
			// 
			this->conditionLabel->AutoSize = true;
			this->conditionLabel->Location = System::Drawing::Point(60, 256);
			this->conditionLabel->Margin = System::Windows::Forms::Padding(6, 0, 6, 0);
			this->conditionLabel->Name = L"conditionLabel";
			this->conditionLabel->Size = System::Drawing::Size(109, 25);
			this->conditionLabel->TabIndex = 4;
			this->conditionLabel->Text = L"Condition:";
			// 
			// yearLabel
			// 
			this->yearLabel->AutoSize = true;
			this->yearLabel->Location = System::Drawing::Point(105, 148);
			this->yearLabel->Margin = System::Windows::Forms::Padding(6, 0, 6, 0);
			this->yearLabel->Name = L"yearLabel";
			this->yearLabel->Size = System::Drawing::Size(64, 25);
			this->yearLabel->TabIndex = 2;
			this->yearLabel->Text = L"Year:";
			// 
			// okButton
			// 
			this->okButton->Location = System::Drawing::Point(59, 313);
			this->okButton->Margin = System::Windows::Forms::Padding(6);
			this->okButton->Name = L"okButton";
			this->okButton->Size = System::Drawing::Size(150, 44);
			this->okButton->TabIndex = 10;
			this->okButton->Text = L"Ok";
			this->okButton->UseVisualStyleBackColor = true;
			this->okButton->Click += gcnew System::EventHandler(this, &AddCard::okButton_Click);
			// 
			// cancelButton
			// 
			this->cancelButton->DialogResult = System::Windows::Forms::DialogResult::Cancel;
			this->cancelButton->Location = System::Drawing::Point(225, 313);
			this->cancelButton->Margin = System::Windows::Forms::Padding(6);
			this->cancelButton->Name = L"cancelButton";
			this->cancelButton->Size = System::Drawing::Size(150, 44);
			this->cancelButton->TabIndex = 11;
			this->cancelButton->Text = L"Cancel";
			this->cancelButton->UseVisualStyleBackColor = true;
			this->cancelButton->Click += gcnew System::EventHandler(this, &AddCard::cancelButton_Click);
			// 
			// firstNameTextBox
			// 
			this->firstNameTextBox->Location = System::Drawing::Point(180, 35);
			this->firstNameTextBox->Margin = System::Windows::Forms::Padding(6);
			this->firstNameTextBox->Name = L"firstNameTextBox";
			this->firstNameTextBox->Size = System::Drawing::Size(196, 31);
			this->firstNameTextBox->TabIndex = 5;
			// 
			// lastNameTextBox
			// 
			this->lastNameTextBox->Location = System::Drawing::Point(180, 90);
			this->lastNameTextBox->Margin = System::Windows::Forms::Padding(6);
			this->lastNameTextBox->Name = L"lastNameTextBox";
			this->lastNameTextBox->Size = System::Drawing::Size(196, 31);
			this->lastNameTextBox->TabIndex = 6;
			// 
			// yearNumericUpDown
			// 
			this->yearNumericUpDown->Location = System::Drawing::Point(180, 145);
			this->yearNumericUpDown->Margin = System::Windows::Forms::Padding(6);
			this->yearNumericUpDown->Maximum = System::Decimal(gcnew cli::array< System::Int32 >(4) { 2025, 0, 0, 0 });
			this->yearNumericUpDown->Minimum = System::Decimal(gcnew cli::array< System::Int32 >(4) { 1886, 0, 0, 0 });
			this->yearNumericUpDown->Name = L"yearNumericUpDown";
			this->yearNumericUpDown->Size = System::Drawing::Size(196, 31);
			this->yearNumericUpDown->TabIndex = 7;
			this->yearNumericUpDown->Value = System::Decimal(gcnew cli::array< System::Int32 >(4) { 1886, 0, 0, 0 });
			// 
			// conditionComboBox
			// 
			this->conditionComboBox->FormattingEnabled = true;
			this->conditionComboBox->Location = System::Drawing::Point(180, 255);
			this->conditionComboBox->Margin = System::Windows::Forms::Padding(6);
			this->conditionComboBox->Name = L"conditionComboBox";
			this->conditionComboBox->Size = System::Drawing::Size(196, 33);
			this->conditionComboBox->TabIndex = 9;
			// 
			// priceLabel
			// 
			this->priceLabel->AutoSize = true;
			this->priceLabel->Location = System::Drawing::Point(102, 202);
			this->priceLabel->Margin = System::Windows::Forms::Padding(6, 0, 6, 0);
			this->priceLabel->Name = L"priceLabel";
			this->priceLabel->Size = System::Drawing::Size(67, 25);
			this->priceLabel->TabIndex = 3;
			this->priceLabel->Text = L"Price:";
			// 
			// priceTextBox
			// 
			this->priceTextBox->Location = System::Drawing::Point(180, 200);
			this->priceTextBox->Margin = System::Windows::Forms::Padding(6);
			this->priceTextBox->Name = L"priceTextBox";
			this->priceTextBox->Size = System::Drawing::Size(196, 31);
			this->priceTextBox->TabIndex = 8;
			this->priceTextBox->Text = L"0";
			this->priceTextBox->KeyPress += gcnew System::Windows::Forms::KeyPressEventHandler(this, &AddCard::priceTextBox_KeyPress);
			// 
			// AddCard
			// 
			this->AcceptButton = this->okButton;
			this->AutoScaleDimensions = System::Drawing::SizeF(12, 25);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->CancelButton = this->cancelButton;
			this->ClientSize = System::Drawing::Size(430, 380);
			this->Controls->Add(this->priceTextBox);
			this->Controls->Add(this->priceLabel);
			this->Controls->Add(this->conditionComboBox);
			this->Controls->Add(this->yearNumericUpDown);
			this->Controls->Add(this->lastNameTextBox);
			this->Controls->Add(this->firstNameTextBox);
			this->Controls->Add(this->cancelButton);
			this->Controls->Add(this->okButton);
			this->Controls->Add(this->yearLabel);
			this->Controls->Add(this->conditionLabel);
			this->Controls->Add(this->lastNameLabel);
			this->Controls->Add(this->firstNameLabel);
			this->Margin = System::Windows::Forms::Padding(6);
			this->Name = L"AddCard";
			this->Text = L"Add Baseball Card";
			this->Load += gcnew System::EventHandler(this, &AddCard::addCard_Load);
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->yearNumericUpDown))->EndInit();
			this->ResumeLayout(false);
			this->PerformLayout();

		}
#pragma endregion

		void okButton_Click(System::Object^ sender, System::EventArgs^ e);
		void cancelButton_Click(System::Object^ sender, System::EventArgs^ e);
		void addCard_Load(System::Object^ sender, System::EventArgs^ e);
		void priceTextBox_KeyPress(System::Object^ sender, System::Windows::Forms::KeyPressEventArgs^ e); 
	};
}
