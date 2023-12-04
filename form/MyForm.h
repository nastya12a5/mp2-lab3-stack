#pragma once

#include "../mp2-lab3-stack/TCalculator.h"
#include <string>
#include <iostream>
#include "../mp2-lab3-stack/TStack.h"
#include <msclr/marshal_cppstd.h>
#include <msclr/marshal.h>
using namespace System;
using namespace std;

namespace CppWinForm1 {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;
    #include <iostream>
	/// <summary>
	/// Summary for MyForm
	/// </summary>
	public ref class MyForm : public System::Windows::Forms::Form
	{
	public:
		MyForm(void)
		{
			InitializeComponent();
			
			//TCalculator a;
			gr = CreateGraphics();
			//Graphics^ gr = CreateGraphics();
			//
			//TODO: Add the constructor code here
			//
		}

	protected:
		/// <summary>
		/// Clean up any resources being used.
		/// </summary>
		~MyForm()
		{
			if (components)
			{
				delete components;
			}
		}

		
		Graphics^ gr;
	private: System::Windows::Forms::Button^ button1;
	private: System::Windows::Forms::TextBox^ textBox1;
	private: System::Windows::Forms::TextBox^ textBox2;
	private: System::Windows::Forms::Button^ button2;
	private: System::Windows::Forms::Timer^ timer1;
	private: System::ComponentModel::IContainer^ components;

	protected:

	private:
		/// <summary>
		/// Required designer variable.
		/// </summary>


#pragma region Windows Form Designer generated code
		/// <summary>
		/// Required method for Designer support - do not modify
		/// the contents of this method with the code editor.
		/// </summary>
		void InitializeComponent(void)
		{
			this->components = (gcnew System::ComponentModel::Container());
			this->button1 = (gcnew System::Windows::Forms::Button());
			//this->textBox1 = (gcnew System::Windows::Forms::TextBox());
			this->textBox2 = (gcnew System::Windows::Forms::TextBox());
			this->button2 = (gcnew System::Windows::Forms::Button());
			this->timer1 = (gcnew System::Windows::Forms::Timer(this->components));
			this->SuspendLayout();
			// 
			// button1
			// 
			this->button1->Location = System::Drawing::Point(197, 12);
			this->button1->Name = L"button1";
			this->button1->Size = System::Drawing::Size(75, 23);
			this->button1->TabIndex = 0;
			this->button1->Text = L"button1";
			this->button1->UseVisualStyleBackColor = true;
			this->button1->Click += gcnew System::EventHandler(this, &MyForm::button1_Click);
			// 
			// textBox1
			// 
			/*this->textBox1->Location = System::Drawing::Point(0, 0);
			this->textBox1->Name = L"textBox1";
			this->textBox1->Size = System::Drawing::Size(100, 20);
			this->textBox1->TabIndex = 1;*/
			// 
			// textBox2
			// 
			this->textBox2->Location = System::Drawing::Point(0, 26);
			this->textBox2->Name = L"textBox2";
			this->textBox2->Size = System::Drawing::Size(100, 20);
			this->textBox2->TabIndex = 2;
			// 
			// button2
			// 
			/*this->button2->Location = System::Drawing::Point(197, 41);
			this->button2->Name = L"button2";
			this->button2->Size = System::Drawing::Size(75, 23);
			this->button2->TabIndex = 3;
			this->button2->Text = L"button2";
			this->button2->UseVisualStyleBackColor = true;
			this->button2->Click += gcnew System::EventHandler(this, &MyForm::button2_Click);*/
			// 
			// MyForm
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(6, 13);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->BackColor = System::Drawing::Color::White;
			this->ClientSize = System::Drawing::Size(284, 261);
			this->Controls->Add(this->button2);
			this->Controls->Add(this->textBox2);
			this->Controls->Add(this->textBox1);
			this->Controls->Add(this->button1);
			this->ForeColor = System::Drawing::Color::DarkOrange;
			this->Name = L"MyForm";
			this->Text = L"MyForm";
			this->Load += gcnew System::EventHandler(this, &MyForm::MyForm_Load);
			this->ResumeLayout(false);
			this->PerformLayout();

		}
#pragma endregion
	private: System::Void MyForm_Load(System::Object^ sender, System::EventArgs^ e) {
	}
	private: System::Void button1_Click(System::Object^ sender, System::EventArgs^ e) {
		
		/*for (int i = 0; i < 3; i++)
		{
			figures[i]->Show(gr);
		}*/
		/*String^ str = textBox1->Text;
		
		
		std::string s = msclr::interop::marshal_as<std::string>(str);


		TCalculator a(s);
		cout << "Res: " << a.Calc() << endl;*/

	}

	private: System::Void button2_Click(System::Object^ sender, System::EventArgs^ e)
	{
		
		//int dx = Convert::ToInt32(textBox1->Text);
		/*int dy = Convert::ToInt32(textBox2->Text);
		for (int i = 0; i < 3; i++)
		{
			figures[i]->Move(gr, dx, dy);
		}
		if (timer1->Enabled == false)
			timer1->Enabled == true;
		else
			timer1->Enabled == false;
	}
	private: System::Void timer1_Tick(System::Object^ sender, System::EventArgs^ e) {
		
		for (int i = 0; i < 3; i++)
		{
			figures[i]->Hide(gr);
		}
		int dx = Convert::ToInt32(textBox1->Text);
		int dy = Convert::ToInt32(textBox2->Text);

		for (int i = 0; i < 3; i++)
		{
			figures[i]->Show(gr);
		}*/

	}
	
    };

}