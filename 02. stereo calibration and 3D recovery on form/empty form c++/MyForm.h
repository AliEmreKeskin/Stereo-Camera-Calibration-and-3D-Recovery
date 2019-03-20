#pragma once

#include "Calibration.h"
#include <atlstr.h>
#include <stdio.h>

using namespace System::IO;

int train_point_count = 0;
float* c1;
float* c2;
float* w;
float* P1 = new float[12];
float* P2 = new float[12];

namespace emptyformc {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;

	/// <summary>
	/// Summary for MyForm
	/// </summary>
	public ref class MyForm : public System::Windows::Forms::Form
	{
	public:
		MyForm(void)
		{
			InitializeComponent();
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
	private: System::Windows::Forms::PictureBox^  pictureBox1;
	private: System::Windows::Forms::Label^  label1;
	private: System::Windows::Forms::Label^  label2;
	private: System::Windows::Forms::PictureBox^  pictureBox2;
	private: System::Windows::Forms::Label^  label3;
	private: System::Windows::Forms::Label^  label4;
	private: System::Windows::Forms::Button^  button1;
	private: System::Windows::Forms::RichTextBox^  richTextBox1;
	private: System::Windows::Forms::RichTextBox^  richTextBox2;
	private: System::Windows::Forms::Button^  button2;
	private: System::Windows::Forms::RichTextBox^  richTextBox3;
	private: System::Windows::Forms::RichTextBox^  richTextBox4;
	private: System::Windows::Forms::Button^  button3;
	private: System::Windows::Forms::RichTextBox^  richTextBox5;
	private: System::Windows::Forms::MenuStrip^  menuStrip1;
	private: System::Windows::Forms::ToolStripMenuItem^  menuToolStripMenuItem;






	private: System::Windows::Forms::ToolStripMenuItem^  demoCalibrationToolStripMenuItem;



	protected:

	private:
		/// <summary>
		/// Required designer variable.
		/// </summary>
		System::ComponentModel::Container ^components;



#pragma region Windows Form Designer generated code
		/// <summary>
		/// Required method for Designer support - do not modify
		/// the contents of this method with the code editor.
		/// </summary>
		void InitializeComponent(void)
		{
			System::ComponentModel::ComponentResourceManager^  resources = (gcnew System::ComponentModel::ComponentResourceManager(MyForm::typeid));
			this->pictureBox1 = (gcnew System::Windows::Forms::PictureBox());
			this->label1 = (gcnew System::Windows::Forms::Label());
			this->label2 = (gcnew System::Windows::Forms::Label());
			this->pictureBox2 = (gcnew System::Windows::Forms::PictureBox());
			this->label3 = (gcnew System::Windows::Forms::Label());
			this->label4 = (gcnew System::Windows::Forms::Label());
			this->button1 = (gcnew System::Windows::Forms::Button());
			this->richTextBox1 = (gcnew System::Windows::Forms::RichTextBox());
			this->richTextBox2 = (gcnew System::Windows::Forms::RichTextBox());
			this->button2 = (gcnew System::Windows::Forms::Button());
			this->richTextBox3 = (gcnew System::Windows::Forms::RichTextBox());
			this->richTextBox4 = (gcnew System::Windows::Forms::RichTextBox());
			this->button3 = (gcnew System::Windows::Forms::Button());
			this->richTextBox5 = (gcnew System::Windows::Forms::RichTextBox());
			this->menuStrip1 = (gcnew System::Windows::Forms::MenuStrip());
			this->menuToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->demoCalibrationToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pictureBox1))->BeginInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pictureBox2))->BeginInit();
			this->menuStrip1->SuspendLayout();
			this->SuspendLayout();
			// 
			// pictureBox1
			// 
			this->pictureBox1->Image = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"pictureBox1.Image")));
			this->pictureBox1->Location = System::Drawing::Point(12, 27);
			this->pictureBox1->Name = L"pictureBox1";
			this->pictureBox1->Size = System::Drawing::Size(640, 480);
			this->pictureBox1->SizeMode = System::Windows::Forms::PictureBoxSizeMode::AutoSize;
			this->pictureBox1->TabIndex = 0;
			this->pictureBox1->TabStop = false;
			this->pictureBox1->MouseUp += gcnew System::Windows::Forms::MouseEventHandler(this, &MyForm::pictureBox1_MouseUp);
			// 
			// label1
			// 
			this->label1->AutoSize = true;
			this->label1->Location = System::Drawing::Point(573, 516);
			this->label1->Name = L"label1";
			this->label1->Size = System::Drawing::Size(35, 13);
			this->label1->TabIndex = 1;
			this->label1->Text = L"label1";
			// 
			// label2
			// 
			this->label2->AutoSize = true;
			this->label2->Location = System::Drawing::Point(614, 516);
			this->label2->Name = L"label2";
			this->label2->Size = System::Drawing::Size(35, 13);
			this->label2->TabIndex = 2;
			this->label2->Text = L"label2";
			// 
			// pictureBox2
			// 
			this->pictureBox2->Image = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"pictureBox2.Image")));
			this->pictureBox2->Location = System::Drawing::Point(658, 27);
			this->pictureBox2->Name = L"pictureBox2";
			this->pictureBox2->Size = System::Drawing::Size(640, 480);
			this->pictureBox2->SizeMode = System::Windows::Forms::PictureBoxSizeMode::AutoSize;
			this->pictureBox2->TabIndex = 3;
			this->pictureBox2->TabStop = false;
			this->pictureBox2->MouseUp += gcnew System::Windows::Forms::MouseEventHandler(this, &MyForm::pictureBox2_MouseUp);
			// 
			// label3
			// 
			this->label3->AutoSize = true;
			this->label3->Location = System::Drawing::Point(662, 516);
			this->label3->Name = L"label3";
			this->label3->Size = System::Drawing::Size(35, 13);
			this->label3->TabIndex = 4;
			this->label3->Text = L"label3";
			// 
			// label4
			// 
			this->label4->AutoSize = true;
			this->label4->Location = System::Drawing::Point(703, 516);
			this->label4->Name = L"label4";
			this->label4->Size = System::Drawing::Size(35, 13);
			this->label4->TabIndex = 5;
			this->label4->Text = L"label4";
			// 
			// button1
			// 
			this->button1->Location = System::Drawing::Point(622, 532);
			this->button1->Name = L"button1";
			this->button1->Size = System::Drawing::Size(75, 23);
			this->button1->TabIndex = 6;
			this->button1->Text = L"Add Feature";
			this->button1->UseVisualStyleBackColor = true;
			this->button1->Click += gcnew System::EventHandler(this, &MyForm::button1_Click);
			// 
			// richTextBox1
			// 
			this->richTextBox1->Location = System::Drawing::Point(467, 516);
			this->richTextBox1->Name = L"richTextBox1";
			this->richTextBox1->Size = System::Drawing::Size(100, 93);
			this->richTextBox1->TabIndex = 7;
			this->richTextBox1->Text = L"";
			// 
			// richTextBox2
			// 
			this->richTextBox2->Location = System::Drawing::Point(744, 516);
			this->richTextBox2->Name = L"richTextBox2";
			this->richTextBox2->Size = System::Drawing::Size(100, 93);
			this->richTextBox2->TabIndex = 8;
			this->richTextBox2->Text = L"";
			// 
			// button2
			// 
			this->button2->Location = System::Drawing::Point(622, 561);
			this->button2->Name = L"button2";
			this->button2->Size = System::Drawing::Size(75, 23);
			this->button2->TabIndex = 9;
			this->button2->Text = L"Calibrate";
			this->button2->UseVisualStyleBackColor = true;
			this->button2->Click += gcnew System::EventHandler(this, &MyForm::button2_Click);
			// 
			// richTextBox3
			// 
			this->richTextBox3->Location = System::Drawing::Point(12, 513);
			this->richTextBox3->Name = L"richTextBox3";
			this->richTextBox3->Size = System::Drawing::Size(449, 96);
			this->richTextBox3->TabIndex = 10;
			this->richTextBox3->Text = L"";
			// 
			// richTextBox4
			// 
			this->richTextBox4->Location = System::Drawing::Point(850, 513);
			this->richTextBox4->Name = L"richTextBox4";
			this->richTextBox4->Size = System::Drawing::Size(448, 96);
			this->richTextBox4->TabIndex = 11;
			this->richTextBox4->Text = L"";
			// 
			// button3
			// 
			this->button3->Location = System::Drawing::Point(622, 590);
			this->button3->Name = L"button3";
			this->button3->Size = System::Drawing::Size(75, 23);
			this->button3->TabIndex = 12;
			this->button3->Text = L"Reconstruct";
			this->button3->UseVisualStyleBackColor = true;
			this->button3->Click += gcnew System::EventHandler(this, &MyForm::button3_Click);
			// 
			// richTextBox5
			// 
			this->richTextBox5->Location = System::Drawing::Point(467, 619);
			this->richTextBox5->Name = L"richTextBox5";
			this->richTextBox5->Size = System::Drawing::Size(377, 96);
			this->richTextBox5->TabIndex = 13;
			this->richTextBox5->Text = L"";
			// 
			// menuStrip1
			// 
			this->menuStrip1->Items->AddRange(gcnew cli::array< System::Windows::Forms::ToolStripItem^  >(1) { this->menuToolStripMenuItem });
			this->menuStrip1->Location = System::Drawing::Point(0, 0);
			this->menuStrip1->Name = L"menuStrip1";
			this->menuStrip1->Size = System::Drawing::Size(1311, 24);
			this->menuStrip1->TabIndex = 14;
			this->menuStrip1->Text = L"menuStrip1";
			// 
			// menuToolStripMenuItem
			// 
			this->menuToolStripMenuItem->DropDownItems->AddRange(gcnew cli::array< System::Windows::Forms::ToolStripItem^  >(1) { this->demoCalibrationToolStripMenuItem });
			this->menuToolStripMenuItem->Name = L"menuToolStripMenuItem";
			this->menuToolStripMenuItem->Size = System::Drawing::Size(50, 20);
			this->menuToolStripMenuItem->Text = L"Menu";
			// 
			// demoCalibrationToolStripMenuItem
			// 
			this->demoCalibrationToolStripMenuItem->Name = L"demoCalibrationToolStripMenuItem";
			this->demoCalibrationToolStripMenuItem->Size = System::Drawing::Size(167, 22);
			this->demoCalibrationToolStripMenuItem->Text = L"Demo Calibration";
			this->demoCalibrationToolStripMenuItem->Click += gcnew System::EventHandler(this, &MyForm::demoCalibrationToolStripMenuItem_Click);
			// 
			// MyForm
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(6, 13);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->ClientSize = System::Drawing::Size(1311, 713);
			this->Controls->Add(this->richTextBox5);
			this->Controls->Add(this->button3);
			this->Controls->Add(this->richTextBox4);
			this->Controls->Add(this->richTextBox3);
			this->Controls->Add(this->button2);
			this->Controls->Add(this->richTextBox2);
			this->Controls->Add(this->richTextBox1);
			this->Controls->Add(this->button1);
			this->Controls->Add(this->label4);
			this->Controls->Add(this->label3);
			this->Controls->Add(this->pictureBox2);
			this->Controls->Add(this->label2);
			this->Controls->Add(this->label1);
			this->Controls->Add(this->pictureBox1);
			this->Controls->Add(this->menuStrip1);
			this->MainMenuStrip = this->menuStrip1;
			this->Name = L"MyForm";
			this->Text = L"MyForm";
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pictureBox1))->EndInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pictureBox2))->EndInit();
			this->menuStrip1->ResumeLayout(false);
			this->menuStrip1->PerformLayout();
			this->ResumeLayout(false);
			this->PerformLayout();

		}
#pragma endregion
	private: System::Void pictureBox1_MouseUp(System::Object^  sender, System::Windows::Forms::MouseEventArgs^  e) {
		int x = e->X;
		int y = e->Y;
		label1->Text = x.ToString();
		label2->Text = y.ToString();
	}
private: System::Void pictureBox2_MouseUp(System::Object^  sender, System::Windows::Forms::MouseEventArgs^  e) {
	int x = e->X;
	int y = e->Y;
	label3->Text = x.ToString();
	label4->Text = y.ToString();
}
private: System::Void button1_Click(System::Object^  sender, System::EventArgs^  e) {
	richTextBox1->AppendText(label1->Text->ToString() + " " + label2->Text->ToString() + " \n");
	richTextBox2->AppendText(label3->Text->ToString() + " " + label4->Text->ToString() + " \n");

	train_point_count++;

	StreamWriter^ yaz = gcnew StreamWriter("image points left.txt");
	yaz->WriteLine(richTextBox1->Text);
	yaz->Close();
	yaz = gcnew StreamWriter("image points right.txt");
	yaz->WriteLine(richTextBox2->Text);
	yaz->Close();
}
private: System::Void button2_Click(System::Object^  sender, System::EventArgs^  e) {
	richTextBox3->Clear();
	richTextBox4->Clear();

	c1 = new float[train_point_count * 2];
	c2 = new float[train_point_count * 2];
	w = new float[train_point_count * 3];

	/*read image and world coordinates from file*/
	FILE *wFile, *iFile, *iFile2, *iFileTest;
	iFile = fopen("image points left.txt", "r");
	rewind(iFile);
	iFile2 = fopen("image points right.txt", "r");
	rewind(iFile2);
	wFile = fopen("world points right hand.txt", "r");
	rewind(wFile);

	for (int i = 0; i < train_point_count; i++){
		fscanf(iFile, "%f", &c1[i*2]);
		fscanf(iFile, "%f", &c1[i*2+1]);
		fscanf(iFile2, "%f", &c2[i*2]);
		fscanf(iFile2, "%f", &c2[i*2+1]);
		fscanf(wFile, "%f", &w[i*3]);
		fscanf(wFile, "%f", &w[i*3+1]);
		fscanf(wFile, "%f", &w[i*3+2]);
	}
	
	fclose(wFile);
	fclose(iFile);
	fclose(iFile2);

	Compute_Projection_Matrix(train_point_count, w, c1, P1);
	Compute_Projection_Matrix(train_point_count, w, c2, P2);

	for (int i = 0; i < 3; i++)
	{
		richTextBox3->AppendText(P1[i * 4 + 0].ToString() + "     " + P1[i * 4 + 1].ToString() + "     " + P1[i * 4 + 2].ToString() + "     " + P1[i * 4 + 3].ToString() + "     \n");
		richTextBox4->AppendText(P2[i * 4 + 0].ToString() + "     " + P2[i * 4 + 1].ToString() + "     " + P2[i * 4 + 2].ToString() + "     " + P2[i * 4 + 3].ToString() + "     \n");
	}

	StreamWriter^ yaz = gcnew StreamWriter("parameters left.txt");
	yaz->WriteLine(richTextBox3->Text);
	yaz->Close();
	yaz = gcnew StreamWriter("parameters right.txt");
	yaz->WriteLine(richTextBox4->Text);
	yaz->Close();
}
private: System::Void button3_Click(System::Object^  sender, System::EventArgs^  e) {
	int test_count = 1;
	float* rw = new float[test_count * 3];
	float* t1 = new float[test_count * 2];
	float* t2 = new float[test_count * 2];
	t1[0] = System::Convert::ToInt32(label1->Text);
	t1[1] = System::Convert::ToInt32(label2->Text);
	t2[0] = System::Convert::ToInt32(label3->Text);
	t2[1] = System::Convert::ToInt32(label4->Text);
	Reconstruct(test_count, t1, t2, P1, P2, rw);
	richTextBox5->AppendText(rw[0] + "     " + rw[1] + "     " + rw[2] + "     \n");
}
private: System::Void loadCalibrationToolStripMenuItem_Click(System::Object^  sender, System::EventArgs^  e) {
}
private: System::Void demoCalibrationToolStripMenuItem_Click(System::Object^  sender, System::EventArgs^  e) {
	train_point_count = 19;

	richTextBox3->Clear();
	richTextBox4->Clear();

	c1 = new float[train_point_count * 2];
	c2 = new float[train_point_count * 2];
	w = new float[train_point_count * 3];

	/*read image and world coordinates from file*/
	FILE *wFile, *iFile, *iFile2, *iFileTest;
	iFile = fopen("demo image points left.txt", "r");
	rewind(iFile);
	iFile2 = fopen("demo image points right.txt", "r");
	rewind(iFile2);
	wFile = fopen("world points right hand.txt", "r");
	rewind(wFile);

	for (int i = 0; i < train_point_count; i++) {
		fscanf(iFile, "%f", &c1[i * 2]);
		fscanf(iFile, "%f", &c1[i * 2 + 1]);
		fscanf(iFile2, "%f", &c2[i * 2]);
		fscanf(iFile2, "%f", &c2[i * 2 + 1]);
		fscanf(wFile, "%f", &w[i * 3]);
		fscanf(wFile, "%f", &w[i * 3 + 1]);
		fscanf(wFile, "%f", &w[i * 3 + 2]);
	}

	fclose(wFile);
	fclose(iFile);
	fclose(iFile2);

	Compute_Projection_Matrix(train_point_count, w, c1, P1);
	Compute_Projection_Matrix(train_point_count, w, c2, P2);

	for (int i = 0; i < 3; i++)
	{
		richTextBox3->AppendText(P1[i * 4 + 0].ToString() + "     " + P1[i * 4 + 1].ToString() + "     " + P1[i * 4 + 2].ToString() + "     " + P1[i * 4 + 3].ToString() + "     \n");
		richTextBox4->AppendText(P2[i * 4 + 0].ToString() + "     " + P2[i * 4 + 1].ToString() + "     " + P2[i * 4 + 2].ToString() + "     " + P2[i * 4 + 3].ToString() + "     \n");
	}

	StreamWriter^ yaz = gcnew StreamWriter("parameters left.txt");
	yaz->WriteLine(richTextBox3->Text);
	yaz->Close();
	yaz = gcnew StreamWriter("parameters right.txt");
	yaz->WriteLine(richTextBox4->Text);
	yaz->Close();
}
};
}
