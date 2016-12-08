#pragma once

#include "opencv2/imgproc/imgproc.hpp"
#include "opencv2/highgui/highgui.hpp"
#include "opencv2/objdetect/objdetect.hpp"
#include "opencv2/core/core.hpp"
#include "opencv2/contrib/contrib.hpp"
#include "opencv2/ml/ml.hpp"
#include <opencv2/gpu/gpu.hpp>
#include <windows.h>
#include <dirent.h>
#include <iomanip>
#include <windows.h> 

#include <iostream>
#include <fstream>
#include <stdio.h>
#include <string.h>
#include <sstream>

using namespace std;
using namespace cv;
using namespace System;
using namespace System::Windows::Forms;
using namespace System::Drawing;
using namespace System::Runtime::InteropServices;
int AVI_position = 0;
int time_interval = 33; //ms
CvCapture* capture = NULL;
int frames =0; //總frames數

//ROI
int roi_size = 4;
int draw_state = 0;
int start_point_x=0,start_point_y=0;
int current_m_x=0,current_m_y=0;
int proportion_x=0,proportion_y=0;

//save file
int file_num = 0;

namespace roi {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;

	/// <summary>
	/// Form1 的摘要
	/// </summary>
	public ref class Form1 : public System::Windows::Forms::Form
	{
	public:
		Form1(void)
		{
			InitializeComponent();
			//
			//TODO: 在此加入建構函式程式碼
			//
		}

	protected:
		/// <summary>
		/// 清除任何使用中的資源。
		/// </summary>
		~Form1()
		{
			if (components)
			{
				delete components;
			}
		}
	private: System::Windows::Forms::Button^  button1;

	private: System::Windows::Forms::OpenFileDialog^  openFileDialog1;
	private: System::Windows::Forms::Timer^  timer1;
	private: System::Windows::Forms::TrackBar^  trackBar1;
	private: System::Windows::Forms::PictureBox^  pictureBox1;
	private: System::Windows::Forms::Label^  label1;
	private: System::Windows::Forms::Label^  label2;
	private: System::Windows::Forms::Button^  button2;
	private: System::Windows::Forms::Button^  button3;
	private: System::Windows::Forms::Button^  button4;
	private: System::Windows::Forms::Button^  button5;
	private: System::Windows::Forms::Button^  button6;
	private: System::Windows::Forms::Button^  button7;
	private: System::Windows::Forms::Panel^  panel1;
	private: System::Windows::Forms::Panel^  panel2;
	private: System::Windows::Forms::Panel^  panel3;
	private: System::Windows::Forms::GroupBox^  groupBox1;
	private: System::Windows::Forms::ComboBox^  comboBox2;
	private: System::Windows::Forms::ComboBox^  comboBox1;
	private: System::Windows::Forms::GroupBox^  groupBox2;
	private: System::Windows::Forms::Button^  button8;
	private: System::Windows::Forms::Button^  button9;
	private: System::Windows::Forms::FolderBrowserDialog^  folderBrowserDialog1;

	private: System::ComponentModel::IContainer^  components;
	protected: 

	private:
		/// <summary>
		/// 設計工具所需的變數。
		/// </summary>


#pragma region Windows Form Designer generated code
		/// <summary>
		/// 此為設計工具支援所需的方法 - 請勿使用程式碼編輯器
		/// 修改這個方法的內容。
		/// </summary>
		void InitializeComponent(void)
		{
			this->components = (gcnew System::ComponentModel::Container());
			this->button1 = (gcnew System::Windows::Forms::Button());
			this->openFileDialog1 = (gcnew System::Windows::Forms::OpenFileDialog());
			this->timer1 = (gcnew System::Windows::Forms::Timer(this->components));
			this->trackBar1 = (gcnew System::Windows::Forms::TrackBar());
			this->pictureBox1 = (gcnew System::Windows::Forms::PictureBox());
			this->label1 = (gcnew System::Windows::Forms::Label());
			this->label2 = (gcnew System::Windows::Forms::Label());
			this->button2 = (gcnew System::Windows::Forms::Button());
			this->button3 = (gcnew System::Windows::Forms::Button());
			this->button4 = (gcnew System::Windows::Forms::Button());
			this->button5 = (gcnew System::Windows::Forms::Button());
			this->button6 = (gcnew System::Windows::Forms::Button());
			this->button7 = (gcnew System::Windows::Forms::Button());
			this->panel1 = (gcnew System::Windows::Forms::Panel());
			this->panel2 = (gcnew System::Windows::Forms::Panel());
			this->groupBox1 = (gcnew System::Windows::Forms::GroupBox());
			this->groupBox2 = (gcnew System::Windows::Forms::GroupBox());
			this->button9 = (gcnew System::Windows::Forms::Button());
			this->button8 = (gcnew System::Windows::Forms::Button());
			this->comboBox1 = (gcnew System::Windows::Forms::ComboBox());
			this->comboBox2 = (gcnew System::Windows::Forms::ComboBox());
			this->panel3 = (gcnew System::Windows::Forms::Panel());
			this->folderBrowserDialog1 = (gcnew System::Windows::Forms::FolderBrowserDialog());
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^  >(this->trackBar1))->BeginInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^  >(this->pictureBox1))->BeginInit();
			this->panel1->SuspendLayout();
			this->panel2->SuspendLayout();
			this->groupBox1->SuspendLayout();
			this->groupBox2->SuspendLayout();
			this->panel3->SuspendLayout();
			this->SuspendLayout();
			// 
			// button1
			// 
			this->button1->Font = (gcnew System::Drawing::Font(L"新細明體", 12, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point, 
				static_cast<System::Byte>(136)));
			this->button1->Location = System::Drawing::Point(21, 0);
			this->button1->Name = L"button1";
			this->button1->Size = System::Drawing::Size(111, 60);
			this->button1->TabIndex = 0;
			this->button1->Text = L"Load file";
			this->button1->UseVisualStyleBackColor = true;
			this->button1->Click += gcnew System::EventHandler(this, &Form1::button1_Click);
			// 
			// openFileDialog1
			// 
			this->openFileDialog1->FileName = L"openFileDialog1";
			// 
			// timer1
			// 
			this->timer1->Tick += gcnew System::EventHandler(this, &Form1::timer1_Tick);
			// 
			// trackBar1
			// 
			this->trackBar1->Location = System::Drawing::Point(3, 33);
			this->trackBar1->Name = L"trackBar1";
			this->trackBar1->Size = System::Drawing::Size(841, 56);
			this->trackBar1->TabIndex = 2;
			this->trackBar1->Scroll += gcnew System::EventHandler(this, &Form1::trackBar1_Scroll);
			// 
			// pictureBox1
			// 
			this->pictureBox1->BackColor = System::Drawing::SystemColors::ActiveCaptionText;
			this->pictureBox1->Location = System::Drawing::Point(3, 12);
			this->pictureBox1->Name = L"pictureBox1";
			this->pictureBox1->Size = System::Drawing::Size(1280, 720);
			this->pictureBox1->SizeMode = System::Windows::Forms::PictureBoxSizeMode::AutoSize;
			this->pictureBox1->TabIndex = 1;
			this->pictureBox1->TabStop = false;
			this->pictureBox1->Click += gcnew System::EventHandler(this, &Form1::pictureBox1_Click);
			this->pictureBox1->Paint += gcnew System::Windows::Forms::PaintEventHandler(this, &Form1::pictureBox1_Paint);
			this->pictureBox1->MouseDown += gcnew System::Windows::Forms::MouseEventHandler(this, &Form1::pictureBox1_MouseDown);
			this->pictureBox1->MouseMove += gcnew System::Windows::Forms::MouseEventHandler(this, &Form1::pictureBox1_MouseMove);
			this->pictureBox1->MouseUp += gcnew System::Windows::Forms::MouseEventHandler(this, &Form1::pictureBox1_MouseUp);
			// 
			// label1
			// 
			this->label1->AutoSize = true;
			this->label1->Font = (gcnew System::Drawing::Font(L"新細明體", 16));
			this->label1->Location = System::Drawing::Point(894, 62);
			this->label1->Name = L"label1";
			this->label1->Size = System::Drawing::Size(25, 27);
			this->label1->TabIndex = 3;
			this->label1->Text = L"0";
			// 
			// label2
			// 
			this->label2->AutoSize = true;
			this->label2->Font = (gcnew System::Drawing::Font(L"新細明體", 13.8F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point, 
				static_cast<System::Byte>(136)));
			this->label2->Location = System::Drawing::Point(850, 25);
			this->label2->Name = L"label2";
			this->label2->Size = System::Drawing::Size(118, 24);
			this->label2->TabIndex = 4;
			this->label2->Text = L"Frame pos :";
			// 
			// button2
			// 
			this->button2->Font = (gcnew System::Drawing::Font(L"新細明體", 16.2F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point, 
				static_cast<System::Byte>(136)));
			this->button2->Location = System::Drawing::Point(994, 13);
			this->button2->Name = L"button2";
			this->button2->Size = System::Drawing::Size(44, 76);
			this->button2->TabIndex = 5;
			this->button2->Text = L"<";
			this->button2->UseVisualStyleBackColor = true;
			this->button2->Click += gcnew System::EventHandler(this, &Form1::button2_Click);
			// 
			// button3
			// 
			this->button3->Font = (gcnew System::Drawing::Font(L"新細明體", 16.2F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point, 
				static_cast<System::Byte>(136)));
			this->button3->Location = System::Drawing::Point(1064, 13);
			this->button3->Name = L"button3";
			this->button3->Size = System::Drawing::Size(44, 76);
			this->button3->TabIndex = 6;
			this->button3->Text = L">";
			this->button3->UseVisualStyleBackColor = true;
			this->button3->Click += gcnew System::EventHandler(this, &Form1::button3_Click);
			// 
			// button4
			// 
			this->button4->Font = (gcnew System::Drawing::Font(L"新細明體", 12, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point, 
				static_cast<System::Byte>(136)));
			this->button4->Location = System::Drawing::Point(21, 80);
			this->button4->Name = L"button4";
			this->button4->Size = System::Drawing::Size(111, 60);
			this->button4->TabIndex = 7;
			this->button4->Text = L"Play";
			this->button4->UseVisualStyleBackColor = true;
			this->button4->Click += gcnew System::EventHandler(this, &Form1::button4_Click);
			// 
			// button5
			// 
			this->button5->Font = (gcnew System::Drawing::Font(L"新細明體", 12, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point, 
				static_cast<System::Byte>(136)));
			this->button5->Location = System::Drawing::Point(21, 158);
			this->button5->Name = L"button5";
			this->button5->Size = System::Drawing::Size(111, 60);
			this->button5->TabIndex = 8;
			this->button5->Text = L"Pause";
			this->button5->UseVisualStyleBackColor = true;
			this->button5->Click += gcnew System::EventHandler(this, &Form1::button5_Click);
			// 
			// button6
			// 
			this->button6->Font = (gcnew System::Drawing::Font(L"新細明體", 12, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point, 
				static_cast<System::Byte>(136)));
			this->button6->Location = System::Drawing::Point(15, 24);
			this->button6->Name = L"button6";
			this->button6->Size = System::Drawing::Size(111, 60);
			this->button6->TabIndex = 9;
			this->button6->Text = L"ROI";
			this->button6->UseVisualStyleBackColor = true;
			this->button6->Click += gcnew System::EventHandler(this, &Form1::button6_Click);
			// 
			// button7
			// 
			this->button7->Font = (gcnew System::Drawing::Font(L"新細明體", 12, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point, 
				static_cast<System::Byte>(136)));
			this->button7->Location = System::Drawing::Point(15, 309);
			this->button7->Name = L"button7";
			this->button7->Size = System::Drawing::Size(111, 60);
			this->button7->TabIndex = 10;
			this->button7->Text = L"Save";
			this->button7->UseVisualStyleBackColor = true;
			this->button7->Click += gcnew System::EventHandler(this, &Form1::button7_Click);
			// 
			// panel1
			// 
			this->panel1->AutoScroll = true;
			this->panel1->Controls->Add(this->pictureBox1);
			this->panel1->Location = System::Drawing::Point(12, 12);
			this->panel1->Name = L"panel1";
			this->panel1->Size = System::Drawing::Size(1408, 865);
			this->panel1->TabIndex = 11;
			// 
			// panel2
			// 
			this->panel2->Controls->Add(this->groupBox1);
			this->panel2->Controls->Add(this->button1);
			this->panel2->Controls->Add(this->button4);
			this->panel2->Controls->Add(this->button5);
			this->panel2->Location = System::Drawing::Point(1426, 12);
			this->panel2->Name = L"panel2";
			this->panel2->Size = System::Drawing::Size(158, 618);
			this->panel2->TabIndex = 12;
			// 
			// groupBox1
			// 
			this->groupBox1->Controls->Add(this->groupBox2);
			this->groupBox1->Controls->Add(this->button6);
			this->groupBox1->Controls->Add(this->button7);
			this->groupBox1->Location = System::Drawing::Point(6, 224);
			this->groupBox1->Name = L"groupBox1";
			this->groupBox1->Size = System::Drawing::Size(140, 391);
			this->groupBox1->TabIndex = 11;
			this->groupBox1->TabStop = false;
			this->groupBox1->Text = L"ROI";
			// 
			// groupBox2
			// 
			this->groupBox2->Controls->Add(this->button9);
			this->groupBox2->Controls->Add(this->button8);
			this->groupBox2->Controls->Add(this->comboBox1);
			this->groupBox2->Controls->Add(this->comboBox2);
			this->groupBox2->Location = System::Drawing::Point(9, 108);
			this->groupBox2->Name = L"groupBox2";
			this->groupBox2->Size = System::Drawing::Size(125, 180);
			this->groupBox2->TabIndex = 2;
			this->groupBox2->TabStop = false;
			this->groupBox2->Text = L"Proportion";
			// 
			// button9
			// 
			this->button9->ForeColor = System::Drawing::Color::Red;
			this->button9->Location = System::Drawing::Point(6, 120);
			this->button9->Name = L"button9";
			this->button9->Size = System::Drawing::Size(108, 36);
			this->button9->TabIndex = 15;
			this->button9->Text = L"none";
			this->button9->UseVisualStyleBackColor = true;
			this->button9->Click += gcnew System::EventHandler(this, &Form1::button9_Click);
			// 
			// button8
			// 
			this->button8->Location = System::Drawing::Point(6, 71);
			this->button8->Name = L"button8";
			this->button8->Size = System::Drawing::Size(108, 36);
			this->button8->TabIndex = 14;
			this->button8->Text = L"check";
			this->button8->UseVisualStyleBackColor = true;
			this->button8->Click += gcnew System::EventHandler(this, &Form1::button8_Click);
			// 
			// comboBox1
			// 
			this->comboBox1->FormattingEnabled = true;
			this->comboBox1->Items->AddRange(gcnew cli::array< System::Object^  >(11) {L"0", L"1", L"2", L"3", L"4", L"5", L"6", L"7", 
				L"8", L"9", L"16"});
			this->comboBox1->Location = System::Drawing::Point(6, 33);
			this->comboBox1->Name = L"comboBox1";
			this->comboBox1->Size = System::Drawing::Size(44, 23);
			this->comboBox1->TabIndex = 11;
			this->comboBox1->Text = L"0";
			// 
			// comboBox2
			// 
			this->comboBox2->FormattingEnabled = true;
			this->comboBox2->Items->AddRange(gcnew cli::array< System::Object^  >(11) {L"0", L"1", L"2", L"3", L"4", L"5", L"6", L"7", 
				L"8", L"9", L"16"});
			this->comboBox2->Location = System::Drawing::Point(70, 33);
			this->comboBox2->Name = L"comboBox2";
			this->comboBox2->Size = System::Drawing::Size(44, 23);
			this->comboBox2->TabIndex = 12;
			this->comboBox2->Text = L"0";
			// 
			// panel3
			// 
			this->panel3->Controls->Add(this->trackBar1);
			this->panel3->Controls->Add(this->label1);
			this->panel3->Controls->Add(this->label2);
			this->panel3->Controls->Add(this->button3);
			this->panel3->Controls->Add(this->button2);
			this->panel3->Location = System::Drawing::Point(12, 883);
			this->panel3->Name = L"panel3";
			this->panel3->Size = System::Drawing::Size(1125, 101);
			this->panel3->TabIndex = 13;
			// 
			// Form1
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(8, 15);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->AutoSize = true;
			this->ClientSize = System::Drawing::Size(1596, 983);
			this->Controls->Add(this->panel3);
			this->Controls->Add(this->panel2);
			this->Controls->Add(this->panel1);
			this->Name = L"Form1";
			this->Text = L"ROI CUT";
			this->Load += gcnew System::EventHandler(this, &Form1::Form1_Load);
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^  >(this->trackBar1))->EndInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^  >(this->pictureBox1))->EndInit();
			this->panel1->ResumeLayout(false);
			this->panel1->PerformLayout();
			this->panel2->ResumeLayout(false);
			this->groupBox1->ResumeLayout(false);
			this->groupBox2->ResumeLayout(false);
			this->panel3->ResumeLayout(false);
			this->panel3->PerformLayout();
			this->ResumeLayout(false);

		}
#pragma endregion
	string int2str(int &i) {
		string s;
		stringstream ss(s);
		ss << i;

		return ss.str();
	}
	void roi_variable_reset(){
		start_point_x=0;
		start_point_y=0;
		current_m_x=0;
		current_m_y=0;
	}
	void calculate_current_point(int *c_x,int *c_y,int m_x,int m_y){
		int r_x,r_y;
		int m_width  = (int)((m_x-start_point_x)/roi_size) + 1 ;
		int m_height = (int)((m_y-start_point_y)/roi_size) + 1 ;
		r_x = m_width  * roi_size + start_point_x;
		r_y = m_height * roi_size + start_point_y;

		if(proportion_x==0||proportion_y==0){
			//沒有設定比例限制
		}
		else{
			int tmp_x = m_width/proportion_x;
			int tmp_y = m_height/proportion_y;
			if(tmp_x>=tmp_y){
				r_x = tmp_x * proportion_x * roi_size + start_point_x;
				r_y = tmp_x * proportion_y * roi_size + start_point_y;
			}
			else{
				r_x = tmp_y * proportion_x * roi_size + start_point_x;
				r_y = tmp_y * proportion_y * roi_size + start_point_y;
			}
		}
		if(r_x < start_point_x){
			r_x = start_point_x;
		}
		if(r_y < start_point_y){
			r_y = start_point_y;
		}
		*c_x = r_x;
		*c_y = r_y;
	}
	void capture_frame(){
		timer1->Enabled = false;
		int trackValue = trackBar1->Value;
		cvSetCaptureProperty(capture, CV_CAP_PROP_POS_FRAMES, trackBar1->Value);
		IplImage* frame;
		frame = cvQueryFrame(capture);

		if (frame){
			pictureBox1->Image  = gcnew System::Drawing::Bitmap
			(frame->width,frame->height,frame->widthStep,
			System::Drawing::Imaging::PixelFormat::Format24bppRgb,(System::IntPtr) frame->imageData);
				pictureBox1->Refresh(); 
				AVI_position = 0;
		}
		label1->Text = cvGetCaptureProperty(capture,1).ToString();
		//label1->Text = trackBar1->Value.ToString();
	}
	private: System::Void button1_Click(System::Object^  sender, System::EventArgs^  e) {
				 timer1->Enabled = false;
				 if(openFileDialog1->ShowDialog() == System::Windows::Forms::DialogResult::OK){
					System::IO::StreamReader ^ sr = gcnew
					System::IO::StreamReader(openFileDialog1->FileName);
					sr->Close();

					if(capture!=NULL){
					   cvReleaseCapture(&capture);
					}
					pictureBox1->Image = nullptr; 
					draw_state = 0;
					roi_variable_reset();
					this->pictureBox1->Invalidate();
					button6->Text = "ROI";

					char* str = (char*) (Marshal::StringToHGlobalAnsi(openFileDialog1->FileName)).ToPointer();
					//得到所有影片的Capture
					capture = cvCreateFileCapture(str);
					frames = (int)cvGetCaptureProperty(capture, CV_CAP_PROP_FRAME_COUNT)-1;
					// Set to 1/30 second.
					timer1->Interval = time_interval;
					trackBar1->Maximum = frames;
					trackBar1->TickFrequency = 5;
					// Enable timer.
					timer1->Enabled = true;
					//timer1->OnTick();
				 }
			 }
		 private: System::Void trackBar1_Scroll(System::Object^  sender, System::EventArgs^  e) {
					  capture_frame();
		 }
		 private: System::Void Form1_Load(System::Object^  sender, System::EventArgs^  e) {
			  //OutputDebugStringW(L"My output string.");
		 }
private: System::Void timer1_Tick(System::Object^  sender, System::EventArgs^  e) {
				if (frames != 0){
					//建立時間軸
				}
				IplImage* frame;
				//printf("CV_CAP_PROP_POS_FRAMES : %.2f\n",cvGetCaptureProperty(capture,1)); //經過的frame數
				//printf("CV_CAP_PROP_FRAME_WIDTH : %.2f\n",cvGetCaptureProperty(capture,3)); //寬度
				//printf("CV_CAP_PROP_FRAME_HEIGHT : %.2f\n",cvGetCaptureProperty(capture,4));//高度
				//printf("CV_CAP_PROP_FRAME_COUNT : %.2f\n",cvGetCaptureProperty(capture,7)); //frame總數
				frame = cvQueryFrame(capture);

				if (frame){
					pictureBox1->Image  = gcnew System::Drawing::Bitmap
					(frame->width,frame->height,frame->widthStep,
						System::Drawing::Imaging::PixelFormat::Format24bppRgb,(System::IntPtr) frame->imageData);
					pictureBox1->Refresh(); 
				}
				else{
					timer1->Enabled = false;
				}

				trackBar1->Value = (int)cvGetCaptureProperty(capture,1);
				label1->Text = cvGetCaptureProperty(capture,1).ToString();
		 }
private: System::Void button2_Click(System::Object^  sender, System::EventArgs^  e) {
			 if(trackBar1->Value > 0){
				 trackBar1->Value = trackBar1->Value - 1;
				 capture_frame();
			 }
		 }
private: System::Void button3_Click(System::Object^  sender, System::EventArgs^  e) {
			 if(trackBar1->Value < trackBar1->Maximum){
				 trackBar1->Value = trackBar1->Value + 1;
				 capture_frame();
			 }
		 }
private: System::Void button4_Click(System::Object^  sender, System::EventArgs^  e) {
			 timer1->Enabled = true;
		 }
private: System::Void button5_Click(System::Object^  sender, System::EventArgs^  e) {
			 timer1->Enabled = false;
		 }
private: System::Void pictureBox1_MouseDown(System::Object^  sender, System::Windows::Forms::MouseEventArgs^  e) {
			 if(draw_state==1 || draw_state==3){
				start_point_x = e->X;
				start_point_y = e->Y;
				draw_state = 2;
			 }
		 }
private: System::Void pictureBox1_Paint(System::Object^  sender, System::Windows::Forms::PaintEventArgs^  e) {
			 if(draw_state == 1||draw_state == 0){
				//清空畫面
			 }
			 else if(draw_state == 2 || draw_state == 3){
				Graphics^ g = e->Graphics;
				Pen^ p = gcnew Pen(Color::Red,1);
				g->DrawRectangle(p,start_point_x,start_point_y
					,current_m_x-start_point_x,current_m_y-start_point_y);
#if 1
				int x_offset = (float)(current_m_x-start_point_x)*3/16+0.5;
				int y_offset = (float)(current_m_y-start_point_y)*3/32+0.5;
				Pen^ p1 = gcnew Pen(Color::Yellow,1);
				g->DrawRectangle(p1,start_point_x+x_offset,start_point_y+y_offset
					,(current_m_x-start_point_x)-2*x_offset,(current_m_y-start_point_y)-2*y_offset);
#endif
			 }
		 }
private: System::Void pictureBox1_MouseMove(System::Object^  sender, System::Windows::Forms::MouseEventArgs^  e) {
			 if(draw_state == 2){
				int r_x,r_y;
				calculate_current_point(&r_x,&r_y,e->X,e->Y);
				current_m_x = r_x;
				current_m_y = r_y;
				this->pictureBox1->Invalidate();
			 }
		 }
private: System::Void button6_Click(System::Object^  sender, System::EventArgs^  e) {
			 if(draw_state!=0){
				draw_state = 0;
				button6->Text = "ROI";
			 }
			 else if(draw_state==0){
				draw_state = 1;
				button6->Text = "Disable ROI";
			 }
			 roi_variable_reset();
			 this->pictureBox1->Invalidate();
		 }
private: System::Void pictureBox1_MouseUp(System::Object^  sender, System::Windows::Forms::MouseEventArgs^  e) {
			 if(draw_state == 2){
				draw_state = 3;
				int r_x,r_y;
				calculate_current_point(&r_x,&r_y,e->X,e->Y);
				current_m_x = r_x;
				current_m_y = r_y;
				this->pictureBox1->Invalidate();
			 }
		 }
private: System::Void button7_Click(System::Object^  sender, System::EventArgs^  e) {
			 if(draw_state == 3){
				CvSize size;
				//const char *saveFilePath    = ".\\ROI_CUT_DATA\\00res.jpg";
				char *saveFileDir    = "C:\\ROI_CUT_DATA\\";

				//char* str = (char*) (Marshal::StringToHGlobalAnsi(openFileDialog1->FileName)).ToPointer();

				IplImage* frame;
				IplImage* dst;
				CvRect rect; //(start_point_x,start_point_y,roi_width,roi_height)
				int roi_width,roi_height;
				roi_width  = current_m_x-start_point_x;
				roi_height = current_m_y-start_point_y;
				rect=cvRect(start_point_x,start_point_y,roi_width,roi_height);

				cvSetCaptureProperty(capture, CV_CAP_PROP_POS_FRAMES, trackBar1->Value);
				frame = cvQueryFrame(capture);

				if(frame){
					if (folderBrowserDialog1->ShowDialog() == ::DialogResult::OK){
						saveFileDir = (char*) (Marshal::StringToHGlobalAnsi(folderBrowserDialog1->SelectedPath)).ToPointer();
					}

					size=cvGetSize(frame);
					dst = cvCreateImage( cvSize(rect.width, rect.height), frame->depth, frame->nChannels );
					//ROI框選不能超過frame大小
					if(current_m_x<=size.width && current_m_y<=size.height){
						//檢查是否有此資料夾，沒有就創一個
						if(!opendir(saveFileDir)){
							if(CreateDirectoryA(saveFileDir, NULL)){
								//創造資料夾成功;
							}
							else{
								MessageBox::Show("Create directory fail.");
							}
						}
						//檢查是否有此檔案
						while(1){
							FILE* fp;
							string tmp(saveFileDir);
							string file_n;
							file_n = int2str(file_num);
							string isfile = tmp +"\\"+ file_n +".jpg";
							if (!(fp = fopen(isfile.c_str(), "r"))){
								break;
							}
							else{
								fclose(fp);
								file_num++;
							}
						}

						cvSetImageROI( frame, rect );  
						cvCopy( frame, dst, 0 );  
						cvResetImageROI( frame );
							
						string tmp(saveFileDir);
						string file_n;
						file_n = int2str(file_num);
						string saveFile = tmp +"\\"+ file_n +".jpg";
						//label1->Text = System::Runtime::InteropServices::Marshal::PtrToStringAnsi(saveFile.c_str());
						if(cvSaveImage( saveFile.c_str(), dst )){
							MessageBox::Show("File saved");
						}
						else{
							MessageBox::Show("Fail to save file. (Pemission denied)");
						}
					}
				}
				else{
					MessageBox::Show("NO frame");
				}
			 }
		 }
private: System::Void button8_Click(System::Object^  sender, System::EventArgs^  e) {
			 int left,right;
			 //left  = comboBox1->Text->ToInt();
			 //right = comboBox2->Text->ToInt();
			 left  = System::Convert::ToInt32(comboBox1->Text);
			 right = System::Convert::ToInt32(comboBox2->Text);

			 proportion_x=left;
			 proportion_y=right;
			 button8->ForeColor = Color::Red;
			 button9->ForeColor = Color::Black;
		 }
private: System::Void button9_Click(System::Object^  sender, System::EventArgs^  e) {
			 proportion_x=0;
			 proportion_y=0;
			 comboBox1->Text = "0";
			 comboBox2->Text = "0";
			 button9->ForeColor = Color::Red;
			 button8->ForeColor = Color::Black;
		 }
private: System::Void pictureBox1_Click(System::Object^  sender, System::EventArgs^  e) {
		 }
};
}

