#pragma once
#include "../Model/PlaitedLinkedList.h"

namespace CardPlaiter
{
	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;
	using namespace Model;

	enum SortOrder
	{
		NAME_ASCENDING, NAME_DESCENDING, YEAR_ASCENDING, YEAR_DESCENDING, CONDITION_ASCENDING, CONDITION_DESCENDING,
		UNDEFINED
	};

	/// \brief Summary for MainForm
	public ref class MainForm : public System::Windows::Forms::Form
	{
	public:
		/// \brief Constructs the MainForm
		///	\precondition none
		MainForm(void);

	protected:
		/// \brief Clean up any resources being used.
		~MainForm();

	private:
		System::Windows::Forms::RadioButton^ nameAscendingRadioButton;
		System::Windows::Forms::RadioButton^ nameDescendingRadioButton;
		System::Windows::Forms::RadioButton^ conditionAscendingRadioButton;
		System::Windows::Forms::RadioButton^ conditionDescendingRadioButton;
		System::Windows::Forms::RadioButton^ yearAscendingRadioButton;
		System::Windows::Forms::RadioButton^ yearDescendingRadioButton;

		System::Windows::Forms::GroupBox^ sortOrderGroupBox;
		System::Windows::Forms::Label^ summaryLabel;
		System::Windows::Forms::TextBox^ summaryTextBox;
		System::Windows::Forms::Button^ loadButton;
		System::Windows::Forms::Button^ saveButton;
		System::Windows::Forms::Button^ addButton;
		System::Windows::Forms::Button^ deleteButton;

		Model::PlaitedLinkedList* list;
		void print(Node* node, bool descending, PlaitedLinkedList::Strands strand);
		std::string formatNode(const Node* node);
		/// \brief Required designer variable.
		System::ComponentModel::Container^ components;

#pragma region Windows Form Designer generated code
		/// \brief Required method for Designer support - do not modify
		/// the contents of this method with the code editor.
		void InitializeComponent(void)
		{
			this->nameAscendingRadioButton = (gcnew System::Windows::Forms::RadioButton());
			this->nameDescendingRadioButton = (gcnew System::Windows::Forms::RadioButton());
			this->conditionAscendingRadioButton = (gcnew System::Windows::Forms::RadioButton());
			this->conditionDescendingRadioButton = (gcnew System::Windows::Forms::RadioButton());
			this->yearAscendingRadioButton = (gcnew System::Windows::Forms::RadioButton());
			this->yearDescendingRadioButton = (gcnew System::Windows::Forms::RadioButton());
			this->sortOrderGroupBox = (gcnew System::Windows::Forms::GroupBox());
			this->summaryLabel = (gcnew System::Windows::Forms::Label());
			this->summaryTextBox = (gcnew System::Windows::Forms::TextBox());
			this->loadButton = (gcnew System::Windows::Forms::Button());
			this->saveButton = (gcnew System::Windows::Forms::Button());
			this->addButton = (gcnew System::Windows::Forms::Button());
			this->deleteButton = (gcnew System::Windows::Forms::Button());
			this->sortOrderGroupBox->SuspendLayout();
			this->SuspendLayout();
			// 
			// nameAscendingRadioButton
			// 
			this->nameAscendingRadioButton->AutoSize = true;
			this->nameAscendingRadioButton->Location = System::Drawing::Point(12, 60);
			this->nameAscendingRadioButton->Margin = System::Windows::Forms::Padding(6);
			this->nameAscendingRadioButton->Name = L"nameAscendingRadioButton";
			this->nameAscendingRadioButton->Size = System::Drawing::Size(204, 29);
			this->nameAscendingRadioButton->TabIndex = 0;
			this->nameAscendingRadioButton->TabStop = true;
			this->nameAscendingRadioButton->Text = L"Name ascending";
			this->nameAscendingRadioButton->UseVisualStyleBackColor = true;
			this->nameAscendingRadioButton->CheckedChanged += gcnew System::EventHandler(
				this, &MainForm::sortOrderRadioButton_CheckedChanged);
			// 
			// nameDescendingRadioButton
			// 
			this->nameDescendingRadioButton->AutoSize = true;
			this->nameDescendingRadioButton->Location = System::Drawing::Point(12, 129);
			this->nameDescendingRadioButton->Margin = System::Windows::Forms::Padding(6);
			this->nameDescendingRadioButton->Name = L"nameDescendingRadioButton";
			this->nameDescendingRadioButton->Size = System::Drawing::Size(216, 29);
			this->nameDescendingRadioButton->TabIndex = 1;
			this->nameDescendingRadioButton->TabStop = true;
			this->nameDescendingRadioButton->Text = L"Name descending";
			this->nameDescendingRadioButton->UseVisualStyleBackColor = true;
			this->nameDescendingRadioButton->CheckedChanged += gcnew System::EventHandler(
				this, &MainForm::sortOrderRadioButton_CheckedChanged);
			// 
			// conditionAscendingRadioButton
			// 
			this->conditionAscendingRadioButton->AutoSize = true;
			this->conditionAscendingRadioButton->Location = System::Drawing::Point(455, 60);
			this->conditionAscendingRadioButton->Margin = System::Windows::Forms::Padding(6);
			this->conditionAscendingRadioButton->Name = L"conditionAscendingRadioButton";
			this->conditionAscendingRadioButton->Size = System::Drawing::Size(239, 29);
			this->conditionAscendingRadioButton->TabIndex = 4;
			this->conditionAscendingRadioButton->TabStop = true;
			this->conditionAscendingRadioButton->Text = L"Condition ascending";
			this->conditionAscendingRadioButton->UseVisualStyleBackColor = true;
			this->conditionAscendingRadioButton->CheckedChanged += gcnew System::EventHandler(
				this, &MainForm::sortOrderRadioButton_CheckedChanged);
			// 
			// conditionDescendingRadioButton
			// 
			this->conditionDescendingRadioButton->AutoSize = true;
			this->conditionDescendingRadioButton->Location = System::Drawing::Point(455, 129);
			this->conditionDescendingRadioButton->Margin = System::Windows::Forms::Padding(6);
			this->conditionDescendingRadioButton->Name = L"conditionDescendingRadioButton";
			this->conditionDescendingRadioButton->Size = System::Drawing::Size(251, 29);
			this->conditionDescendingRadioButton->TabIndex = 5;
			this->conditionDescendingRadioButton->TabStop = true;
			this->conditionDescendingRadioButton->Text = L"Condition descending";
			this->conditionDescendingRadioButton->UseVisualStyleBackColor = true;
			this->conditionDescendingRadioButton->CheckedChanged += gcnew System::EventHandler(
				this, &MainForm::sortOrderRadioButton_CheckedChanged);
			// 
			// yearAscendingRadioButton
			// 
			this->yearAscendingRadioButton->AutoSize = true;
			this->yearAscendingRadioButton->Location = System::Drawing::Point(237, 60);
			this->yearAscendingRadioButton->Margin = System::Windows::Forms::Padding(6);
			this->yearAscendingRadioButton->Name = L"yearAscendingRadioButton";
			this->yearAscendingRadioButton->Size = System::Drawing::Size(194, 29);
			this->yearAscendingRadioButton->TabIndex = 2;
			this->yearAscendingRadioButton->TabStop = true;
			this->yearAscendingRadioButton->Text = L"Year ascending";
			this->yearAscendingRadioButton->UseVisualStyleBackColor = true;
			this->yearAscendingRadioButton->CheckedChanged += gcnew System::EventHandler(
				this, &MainForm::sortOrderRadioButton_CheckedChanged);
			// 
			// yearDescendingRadioButton
			// 
			this->yearDescendingRadioButton->AutoSize = true;
			this->yearDescendingRadioButton->Location = System::Drawing::Point(237, 129);
			this->yearDescendingRadioButton->Margin = System::Windows::Forms::Padding(6);
			this->yearDescendingRadioButton->Name = L"yearDescendingRadioButton";
			this->yearDescendingRadioButton->Size = System::Drawing::Size(206, 29);
			this->yearDescendingRadioButton->TabIndex = 3;
			this->yearDescendingRadioButton->TabStop = true;
			this->yearDescendingRadioButton->Text = L"Year descending";
			this->yearDescendingRadioButton->UseVisualStyleBackColor = true;
			this->yearDescendingRadioButton->CheckedChanged += gcnew System::EventHandler(
				this, &MainForm::sortOrderRadioButton_CheckedChanged);
			// 
			// sortOrderGroupBox
			// 
			this->sortOrderGroupBox->Controls->Add(this->nameAscendingRadioButton);
			this->sortOrderGroupBox->Controls->Add(this->yearDescendingRadioButton);
			this->sortOrderGroupBox->Controls->Add(this->nameDescendingRadioButton);
			this->sortOrderGroupBox->Controls->Add(this->yearAscendingRadioButton);
			this->sortOrderGroupBox->Controls->Add(this->conditionAscendingRadioButton);
			this->sortOrderGroupBox->Controls->Add(this->conditionDescendingRadioButton);
			this->sortOrderGroupBox->Location = System::Drawing::Point(46, 40);
			this->sortOrderGroupBox->Margin = System::Windows::Forms::Padding(6);
			this->sortOrderGroupBox->Name = L"sortOrderGroupBox";
			this->sortOrderGroupBox->Padding = System::Windows::Forms::Padding(6);
			this->sortOrderGroupBox->Size = System::Drawing::Size(718, 204);
			this->sortOrderGroupBox->TabIndex = 0;
			this->sortOrderGroupBox->TabStop = false;
			this->sortOrderGroupBox->Text = L"Sort order";
			// 
			// summaryLabel
			// 
			this->summaryLabel->AutoSize = true;
			this->summaryLabel->Location = System::Drawing::Point(40, 279);
			this->summaryLabel->Margin = System::Windows::Forms::Padding(6, 0, 6, 0);
			this->summaryLabel->Name = L"summaryLabel";
			this->summaryLabel->Size = System::Drawing::Size(151, 25);
			this->summaryLabel->TabIndex = 7;
			this->summaryLabel->Text = L"Cards summary";
			// 
			// summaryTextBox
			// 
			this->summaryTextBox->Font = (gcnew System::Drawing::Font(L"Courier New", 8.25F,
			                                                          System::Drawing::FontStyle::Regular,
			                                                          System::Drawing::GraphicsUnit::Point,
			                                                          static_cast<System::Byte>(0)));
			this->summaryTextBox->Location = System::Drawing::Point(46, 312);
			this->summaryTextBox->Margin = System::Windows::Forms::Padding(6);
			this->summaryTextBox->Multiline = true;
			this->summaryTextBox->Name = L"summaryTextBox";
			this->summaryTextBox->Size = System::Drawing::Size(714, 296);
			this->summaryTextBox->TabIndex = 1;
			// 
			// loadButton
			// 
			this->loadButton->Location = System::Drawing::Point(92, 640);
			this->loadButton->Margin = System::Windows::Forms::Padding(6);
			this->loadButton->Name = L"loadButton";
			this->loadButton->Size = System::Drawing::Size(150, 44);
			this->loadButton->TabIndex = 2;
			this->loadButton->Text = L"Load";
			this->loadButton->UseVisualStyleBackColor = true;
			this->loadButton->Click += gcnew System::EventHandler(this, &MainForm::loadButton_Click);
			// 
			// saveButton
			// 
			this->saveButton->Location = System::Drawing::Point(254, 640);
			this->saveButton->Margin = System::Windows::Forms::Padding(6);
			this->saveButton->Name = L"saveButton";
			this->saveButton->Size = System::Drawing::Size(150, 44);
			this->saveButton->TabIndex = 3;
			this->saveButton->Text = L"Save";
			this->saveButton->UseVisualStyleBackColor = true;
			this->saveButton->Click += gcnew System::EventHandler(this, &MainForm::saveButton_Click);
			// 
			// addButton
			// 
			this->addButton->Location = System::Drawing::Point(416, 640);
			this->addButton->Margin = System::Windows::Forms::Padding(6);
			this->addButton->Name = L"addButton";
			this->addButton->Size = System::Drawing::Size(150, 44);
			this->addButton->TabIndex = 4;
			this->addButton->Text = L"Add";
			this->addButton->UseVisualStyleBackColor = true;
			this->addButton->Click += gcnew System::EventHandler(this, &MainForm::addButton_Click);
			// 
			// deleteButton
			// 
			this->deleteButton->Location = System::Drawing::Point(578, 640);
			this->deleteButton->Margin = System::Windows::Forms::Padding(6);
			this->deleteButton->Name = L"deleteButton";
			this->deleteButton->Size = System::Drawing::Size(150, 44);
			this->deleteButton->TabIndex = 5;
			this->deleteButton->Text = L"Delete";
			this->deleteButton->UseVisualStyleBackColor = true;
			this->deleteButton->Click += gcnew System::EventHandler(this, &MainForm::deleteButton_Click);
			// 
			// MainForm
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(12, 25);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->ClientSize = System::Drawing::Size(808, 712);
			this->Controls->Add(this->deleteButton);
			this->Controls->Add(this->addButton);
			this->Controls->Add(this->saveButton);
			this->Controls->Add(this->loadButton);
			this->Controls->Add(this->summaryTextBox);
			this->Controls->Add(this->summaryLabel);
			this->Controls->Add(this->sortOrderGroupBox);
			this->Margin = System::Windows::Forms::Padding(6);
			this->Name = L"MainForm";
			this->Text = L"A3 by Colby Daniel";
			this->sortOrderGroupBox->ResumeLayout(false);
			this->sortOrderGroupBox->PerformLayout();
			this->ResumeLayout(false);
			this->PerformLayout();
		}
#pragma endregion

		void loadButton_Click(System::Object^ sender, System::EventArgs^ e);
		void saveButton_Click(System::Object^ sender, System::EventArgs^ e);
		void addButton_Click(System::Object^ sender, System::EventArgs^ e);
		void deleteButton_Click(System::Object^ sender, System::EventArgs^ e);
		void sortOrderRadioButton_CheckedChanged(System::Object^ sender, System::EventArgs^ e);
	};
}
