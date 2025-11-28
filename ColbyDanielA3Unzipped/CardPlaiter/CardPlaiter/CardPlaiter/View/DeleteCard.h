#pragma once
#include <string>

namespace View {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;

	/// <summary>
	/// Summary for DeleteCard
	/// </summary>
	public ref class DeleteCard : public System::Windows::Forms::Form
	{
	public:
		/// \brief Constructs the DeleteCard dialog
		///	\precondition none
		DeleteCard(void);

		/// \brief Gets the first name that was entered
		///	\precondition none
		/// \return The first name
		std::string GetFirstName();

		/// \brief Gets the last name that was entered
		///	\precondition none
		/// \return The last name
		std::string GetLastName();

	protected:
		/// \brief Clean up any resources being used.
		~DeleteCard();

	private:
		String^ firstName;
		String^ lastName;

		System::Windows::Forms::Label^ firstNameLabel;
		System::Windows::Forms::Label^ lastNameLabel;
		System::Windows::Forms::TextBox^ firstNameTextBox;
		System::Windows::Forms::TextBox^ lastNameTextBox;
		System::Windows::Forms::Button^ okButton;
		System::Windows::Forms::Button^ cancelButton;

		/// \brief Required designer variable.
		System::ComponentModel::Container^ components;

#pragma region Windows Form Designer generated code
		/// \brief Required method for Designer support - do not modify
		/// the contents of this method with the code editor.
		void InitializeComponent(void)
		{
			this->firstNameLabel = (gcnew System::Windows::Forms::Label());
			this->lastNameLabel = (gcnew System::Windows::Forms::Label());
			this->firstNameTextBox = (gcnew System::Windows::Forms::TextBox());
			this->lastNameTextBox = (gcnew System::Windows::Forms::TextBox());
			this->okButton = (gcnew System::Windows::Forms::Button());
			this->cancelButton = (gcnew System::Windows::Forms::Button());
			this->SuspendLayout();
			// 
			// firstNameLabel
			// 
			this->firstNameLabel->AutoSize = true;
			this->firstNameLabel->Location = System::Drawing::Point(43, 34);
			this->firstNameLabel->Margin = System::Windows::Forms::Padding(6, 0, 6, 0);
			this->firstNameLabel->Name = L"firstNameLabel";
			this->firstNameLabel->Size = System::Drawing::Size(119, 25);
			this->firstNameLabel->TabIndex = 0;
			this->firstNameLabel->Text = L"First name:";
			// 
			// lastNameLabel
			// 
			this->lastNameLabel->AutoSize = true;
			this->lastNameLabel->Location = System::Drawing::Point(43, 79);
			this->lastNameLabel->Margin = System::Windows::Forms::Padding(6, 0, 6, 0);
			this->lastNameLabel->Name = L"lastNameLabel";
			this->lastNameLabel->Size = System::Drawing::Size(118, 25);
			this->lastNameLabel->TabIndex = 1;
			this->lastNameLabel->Text = L"Last name:";
			// 
			// firstNameTextBox
			// 
			this->firstNameTextBox->Location = System::Drawing::Point(171, 29);
			this->firstNameTextBox->Margin = System::Windows::Forms::Padding(6, 6, 6, 6);
			this->firstNameTextBox->Name = L"firstNameTextBox";
			this->firstNameTextBox->Size = System::Drawing::Size(196, 31);
			this->firstNameTextBox->TabIndex = 2;
			// 
			// lastNameTextBox
			// 
			this->lastNameTextBox->Location = System::Drawing::Point(171, 79);
			this->lastNameTextBox->Margin = System::Windows::Forms::Padding(6, 6, 6, 6);
			this->lastNameTextBox->Name = L"lastNameTextBox";
			this->lastNameTextBox->Size = System::Drawing::Size(196, 31);
			this->lastNameTextBox->TabIndex = 3;
			// 
			// okButton
			// 
			this->okButton->Location = System::Drawing::Point(55, 144);
			this->okButton->Margin = System::Windows::Forms::Padding(6, 6, 6, 6);
			this->okButton->Name = L"okButton";
			this->okButton->Size = System::Drawing::Size(150, 44);
			this->okButton->TabIndex = 4;
			this->okButton->Text = L"Ok";
			this->okButton->UseVisualStyleBackColor = true;
			this->okButton->Click += gcnew System::EventHandler(this, &DeleteCard::okButton_Click);
			// 
			// cancelButton
			// 
			this->cancelButton->DialogResult = System::Windows::Forms::DialogResult::Cancel;
			this->cancelButton->Location = System::Drawing::Point(217, 144);
			this->cancelButton->Margin = System::Windows::Forms::Padding(6, 6, 6, 6);
			this->cancelButton->Name = L"cancelButton";
			this->cancelButton->Size = System::Drawing::Size(150, 44);
			this->cancelButton->TabIndex = 5;
			this->cancelButton->Text = L"Cancel";
			this->cancelButton->UseVisualStyleBackColor = true;
			this->cancelButton->Click += gcnew System::EventHandler(this, &DeleteCard::cancelButton_Click);
			// 
			// DeleteCard
			// 
			this->AcceptButton = this->okButton;
			this->AutoScaleDimensions = System::Drawing::SizeF(12, 25);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->CancelButton = this->cancelButton;
			this->ClientSize = System::Drawing::Size(417, 218);
			this->Controls->Add(this->cancelButton);
			this->Controls->Add(this->okButton);
			this->Controls->Add(this->lastNameTextBox);
			this->Controls->Add(this->firstNameTextBox);
			this->Controls->Add(this->lastNameLabel);
			this->Controls->Add(this->firstNameLabel);
			this->Margin = System::Windows::Forms::Padding(6, 6, 6, 6);
			this->Name = L"DeleteCard";
			this->Text = L"Delete Card";
			this->ResumeLayout(false);
			this->PerformLayout();

		}
#pragma endregion

		void okButton_Click(System::Object^ sender, System::EventArgs^ e);
		void cancelButton_Click(System::Object^ sender, System::EventArgs^ e);
	};
}
