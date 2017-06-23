#pragma once

#include <iostream>
#include <cstdio>
#include <string>
#include <stdio.h>
#include <stdlib.h>
//для работа с ввод/вывод
#include <fstream>
#include <iostream>
#include <sstream>
#include <vector>
#include <string>
#include <queue>
//opencv
#include "opencv2/core/core.hpp"
#include "opencv2/imgproc/imgproc.hpp"
#include "opencv2/highgui/highgui.hpp"

#include <msclr\marshal_cppstd.h>
//gdal

//#include <gdal/include/cpl_string.h>
//#include <gdal/include/gdal_alg.h>
//#include <gdal/include/gdal_priv.h>
//#include <gdal/include/gdal.h>
//#include <gdal/include/cpl_conv.h>

namespace gdalVisual {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;
	using namespace System::IO;

	using namespace std;
	using namespace cv;
	/// <summary>
	/// Сводка для gdalForm
	/// </summary>
	public ref class gdalForm : public System::Windows::Forms::Form
	{
	public:
		gdalForm(void)
		{
			InitializeComponent();
			//
			//TODO: добавьте код конструктора
			//
		}

	protected:
		/// <summary>
		/// Освободить все используемые ресурсы.
		/// </summary>
		~gdalForm()
		{
			if (components)
			{
				delete components;
			}
		}
	private: System::Windows::Forms::Button^  buttonExit;
	private: System::Windows::Forms::Label^  label1;
	private: System::Windows::Forms::Label^  label2;



	private: System::Windows::Forms::Button^  geoTiffImageChoose;
	private: System::Windows::Forms::Button^  defaultImageChoose;
	private: System::Windows::Forms::PictureBox^  pictureBoxOriginal;

	private: System::Windows::Forms::Label^  label4;



	private: System::Windows::Forms::SaveFileDialog^  saveFileDialogWkt;
	private: System::Windows::Forms::OpenFileDialog^  openFileDialogGeotiff;
	private: System::Windows::Forms::OpenFileDialog^  openFileDialogDefaultImage;
	private: System::Windows::Forms::Button^  buttonStart;

	private: System::Windows::Forms::Label^  label3;
	private: System::Windows::Forms::Label^  label7;
	private: System::Windows::Forms::SaveFileDialog^  saveFileDialog1;

	private: System::Windows::Forms::TextBox^  textBoxDefault;
	private: System::Windows::Forms::TextBox^  textBoxGeo;


	private: System::ComponentModel::IContainer^  components;

	protected: 

	private:
		/// <summary>
		/// Требуется переменная конструктора.
		/// </summary>


#pragma region Windows Form Designer generated code
		/// <summary>
		/// Обязательный метод для поддержки конструктора - не изменяйте
		/// содержимое данного метода при помощи редактора кода.
		/// </summary>
		void InitializeComponent(void)
		{
			this->buttonExit = (gcnew System::Windows::Forms::Button());
			this->label1 = (gcnew System::Windows::Forms::Label());
			this->label2 = (gcnew System::Windows::Forms::Label());
			this->geoTiffImageChoose = (gcnew System::Windows::Forms::Button());
			this->defaultImageChoose = (gcnew System::Windows::Forms::Button());
			this->pictureBoxOriginal = (gcnew System::Windows::Forms::PictureBox());
			this->label4 = (gcnew System::Windows::Forms::Label());
			this->saveFileDialogWkt = (gcnew System::Windows::Forms::SaveFileDialog());
			this->openFileDialogGeotiff = (gcnew System::Windows::Forms::OpenFileDialog());
			this->openFileDialogDefaultImage = (gcnew System::Windows::Forms::OpenFileDialog());
			this->buttonStart = (gcnew System::Windows::Forms::Button());
			this->label3 = (gcnew System::Windows::Forms::Label());
			this->label7 = (gcnew System::Windows::Forms::Label());
			this->saveFileDialog1 = (gcnew System::Windows::Forms::SaveFileDialog());
			this->textBoxDefault = (gcnew System::Windows::Forms::TextBox());
			this->textBoxGeo = (gcnew System::Windows::Forms::TextBox());
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^  >(this->pictureBoxOriginal))->BeginInit();
			this->SuspendLayout();
			// 
			// buttonExit
			// 
			this->buttonExit->BackColor = System::Drawing::Color::Transparent;
			this->buttonExit->Location = System::Drawing::Point(190, 511);
			this->buttonExit->Name = L"buttonExit";
			this->buttonExit->Size = System::Drawing::Size(279, 23);
			this->buttonExit->TabIndex = 0;
			this->buttonExit->Text = L"Выход";
			this->buttonExit->UseVisualStyleBackColor = false;
			this->buttonExit->Click += gcnew System::EventHandler(this, &gdalForm::buttonExit_Click);
			// 
			// label1
			// 
			this->label1->AutoSize = true;
			this->label1->Font = (gcnew System::Drawing::Font(L"Arial Narrow", 20.25F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point, 
				static_cast<System::Byte>(204)));
			this->label1->ForeColor = System::Drawing::SystemColors::ButtonShadow;
			this->label1->Location = System::Drawing::Point(38, 22);
			this->label1->Name = L"label1";
			this->label1->Size = System::Drawing::Size(498, 31);
			this->label1->TabIndex = 1;
			this->label1->Text = L"Модуль распознования полигонов для ГИС";
			// 
			// label2
			// 
			this->label2->AutoSize = true;
			this->label2->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 12, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point, 
				static_cast<System::Byte>(204)));
			this->label2->Location = System::Drawing::Point(40, 89);
			this->label2->Name = L"label2";
			this->label2->Size = System::Drawing::Size(283, 40);
			this->label2->TabIndex = 2;
			this->label2->Text = L"Работа с растровым изображением \r\nв  формате GeoTIFF";
			// 
			// geoTiffImageChoose
			// 
			this->geoTiffImageChoose->Location = System::Drawing::Point(44, 186);
			this->geoTiffImageChoose->Name = L"geoTiffImageChoose";
			this->geoTiffImageChoose->Size = System::Drawing::Size(279, 21);
			this->geoTiffImageChoose->TabIndex = 6;
			this->geoTiffImageChoose->Text = L"Выбрать";
			this->geoTiffImageChoose->UseVisualStyleBackColor = true;
			this->geoTiffImageChoose->Click += gcnew System::EventHandler(this, &gdalForm::geoTiffImageChoose_Click);
			// 
			// defaultImageChoose
			// 
			this->defaultImageChoose->Location = System::Drawing::Point(366, 187);
			this->defaultImageChoose->Name = L"defaultImageChoose";
			this->defaultImageChoose->Size = System::Drawing::Size(279, 20);
			this->defaultImageChoose->TabIndex = 7;
			this->defaultImageChoose->Text = L"Выбрать";
			this->defaultImageChoose->UseVisualStyleBackColor = true;
			this->defaultImageChoose->Click += gcnew System::EventHandler(this, &gdalForm::defaultImageChoose_Click);
			// 
			// pictureBoxOriginal
			// 
			this->pictureBoxOriginal->Location = System::Drawing::Point(735, 89);
			this->pictureBoxOriginal->Name = L"pictureBoxOriginal";
			this->pictureBoxOriginal->Size = System::Drawing::Size(547, 445);
			this->pictureBoxOriginal->TabIndex = 8;
			this->pictureBoxOriginal->TabStop = false;
			// 
			// label4
			// 
			this->label4->AutoSize = true;
			this->label4->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 12, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point, 
				static_cast<System::Byte>(204)));
			this->label4->Location = System::Drawing::Point(863, 48);
			this->label4->Name = L"label4";
			this->label4->Size = System::Drawing::Size(308, 20);
			this->label4->TabIndex = 10;
			this->label4->Text = L"Оригинальное (исходное) изображение";
			// 
			// saveFileDialogWkt
			// 
			this->saveFileDialogWkt->FileName = L"saveFileDialogWkt";
			// 
			// openFileDialogGeotiff
			// 
			this->openFileDialogGeotiff->FileName = L"openFileDialogGeotiff";
			// 
			// openFileDialogDefaultImage
			// 
			this->openFileDialogDefaultImage->FileName = L"openFileDialogDefaultImage";
			// 
			// buttonStart
			// 
			this->buttonStart->Location = System::Drawing::Point(190, 301);
			this->buttonStart->Name = L"buttonStart";
			this->buttonStart->Size = System::Drawing::Size(279, 23);
			this->buttonStart->TabIndex = 14;
			this->buttonStart->Text = L"Выполнить";
			this->buttonStart->UseVisualStyleBackColor = true;
			this->buttonStart->Click += gcnew System::EventHandler(this, &gdalForm::buttonStart_Click);
			// 
			// label3
			// 
			this->label3->AutoSize = true;
			this->label3->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 12, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point, 
				static_cast<System::Byte>(204)));
			this->label3->Location = System::Drawing::Point(362, 89);
			this->label3->Name = L"label3";
			this->label3->Size = System::Drawing::Size(283, 40);
			this->label3->TabIndex = 3;
			this->label3->Text = L"Работа с растровым изображением \r\nв  формате .JPG, .PNG";
			// 
			// label7
			// 
			this->label7->AutoSize = true;
			this->label7->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 12, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point, 
				static_cast<System::Byte>(204)));
			this->label7->Location = System::Drawing::Point(63, 237);
			this->label7->Name = L"label7";
			this->label7->Size = System::Drawing::Size(582, 40);
			this->label7->TabIndex = 16;
			this->label7->Text = L"Нажмите на кнопку ниже для запуска программы\r\nФайл с расширением WKT будет создан" 
				L" автоматически на рабочем столе \r\n";
			this->label7->TextAlign = System::Drawing::ContentAlignment::MiddleCenter;
			// 
			// textBoxDefault
			// 
			this->textBoxDefault->Location = System::Drawing::Point(366, 151);
			this->textBoxDefault->Name = L"textBoxDefault";
			this->textBoxDefault->Size = System::Drawing::Size(279, 20);
			this->textBoxDefault->TabIndex = 18;
			// 
			// textBoxGeo
			// 
			this->textBoxGeo->Location = System::Drawing::Point(44, 151);
			this->textBoxGeo->Name = L"textBoxGeo";
			this->textBoxGeo->Size = System::Drawing::Size(279, 20);
			this->textBoxGeo->TabIndex = 19;
			// 
			// gdalForm
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(6, 13);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->ClientSize = System::Drawing::Size(1328, 570);
			this->Controls->Add(this->textBoxGeo);
			this->Controls->Add(this->textBoxDefault);
			this->Controls->Add(this->label7);
			this->Controls->Add(this->buttonStart);
			this->Controls->Add(this->label4);
			this->Controls->Add(this->pictureBoxOriginal);
			this->Controls->Add(this->defaultImageChoose);
			this->Controls->Add(this->geoTiffImageChoose);
			this->Controls->Add(this->label3);
			this->Controls->Add(this->label2);
			this->Controls->Add(this->label1);
			this->Controls->Add(this->buttonExit);
			this->Name = L"gdalForm";
			this->StartPosition = System::Windows::Forms::FormStartPosition::CenterScreen;
			this->Text = L"gdalForm";
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^  >(this->pictureBoxOriginal))->EndInit();
			this->ResumeLayout(false);
			this->PerformLayout();

		}
#pragma endregion
	//ИЗОБРАЖЕНИЕ ТИФФ
	private: 
		System::Void geoTiffImageChoose_Click(System::Object^  sender, System::EventArgs^  e) {
				openFileDialogGeotiff->InitialDirectory = "c:\\";	
				openFileDialogGeotiff->Filter = "Image Files(*.TIF)|*.TIF|All files (*.*)|*.*";
				openFileDialogGeotiff->ShowDialog();
				
				openFileDialogDefaultImage->FileName = " ";
				textBoxDefault->Text = " ";
				textBoxGeo->Text = openFileDialogGeotiff->FileName;
		}
	//=============================================================================
	//=============================================================================
	//=============================================================================
	private: 
		System::Void textBoxDefaultImage_TextChanged(System::Object^  sender, System::EventArgs^  e) {
		}
	//ВЫБОР И ЗАГРУЗКА ПРОСТОГО ИЗОБРАЖЕНИЯ
	private: 
		System::Void defaultImageChoose_Click(System::Object^  sender, System::EventArgs^  e) {
				openFileDialogDefaultImage->InitialDirectory = "c:\\";	
				openFileDialogDefaultImage->Filter = "Image Files(*.BMP;*.JPG)|*.BMP;*.JPG";
				openFileDialogDefaultImage->ShowDialog();
				
				openFileDialogGeotiff->FileName = " ";
				textBoxGeo->Text = " ";
				textBoxDefault->Text = openFileDialogDefaultImage->FileName;
		}
	//ВЫХОД
	private: 
		System::Void buttonExit_Click(System::Object^  sender, System::EventArgs^  e) {
				 Application::Exit();
		}

	private:
		System::Void buttonStart_Click(System::Object^  sender, System::EventArgs^  e) {
				//чтобы путь преобразовался в строку
				if(openFileDialogDefaultImage->FileName != " "){
					System::String^ pathToString = openFileDialogDefaultImage->FileName;
					std::string newPathToString = msclr::interop::marshal_as<std::string>(pathToString);
					//провека соответствует ли формат изоражения
					string pathTail = newPathToString.substr(newPathToString.size() - 3);

					cv::Mat image = cv::imread(newPathToString, CV_LOAD_IMAGE_ANYCOLOR | CV_LOAD_IMAGE_ANYDEPTH);
					if (image.data) {
						if(pathTail == "png" || "jpg"){
							System::Drawing::Graphics^ graphics = pictureBoxOriginal->CreateGraphics();
							System::IntPtr ptr(image.ptr());
							System::Drawing::Bitmap^ b  = gcnew System::Drawing::Bitmap(image.cols,image.rows,image.step,System::Drawing::Imaging::PixelFormat::Format24bppRgb,ptr);
							System::Drawing::RectangleF rect(0,0,pictureBoxOriginal->Width,pictureBoxOriginal->Height);
							graphics->DrawImage(b,rect);
					
							//изменение цветв
							cv::cvtColor(image, image, CV_BGR2GRAY);
							//перевод в бинарное
							cv::threshold(image, image, 128, 255, CV_THRESH_BINARY);

							//нахождение контура
							//contourOutput для того чтобы оригинальоне изображение не перезаписалаось
							std::vector<std::vector<cv::Point> > contours;
							cv::Mat contourOutput = image.clone();
							//CV_RETR_TREE для того чтобы получить иерархисеское дерево контуров
							cv::findContours(contourOutput, contours, CV_RETR_TREE, CV_CHAIN_APPROX_NONE);

							//Рисуем контуры
							cv::Mat contourImage(image.size(), CV_8UC3, cv::Scalar(0, 0, 0));
							cv::Scalar colors[3];
							colors[0] = cv::Scalar(255, 0, 0);
							colors[1] = cv::Scalar(0, 255, 0);
							colors[2] = cv::Scalar(0, 0, 255);

							//работа с файлом
							std::ofstream tempOutFile;
							tempOutFile.open("contours.txt");
							for (size_t idx = 0; idx < contours.size(); idx++) {
								cv::drawContours(contourImage, contours, idx, colors[idx % 3]);
								tempOutFile << contours[idx] << 'A';
							}
							tempOutFile.close();

							//поиск и замена в файле
							ifstream inFile;
							inFile.open("contours.txt");//open the input file
							ofstream fileout("C:\\Users\\User\\Desktop\\result.wkt"); //file
							stringstream strStream;
							strStream << inFile.rdbuf();//читать файл
							string str = strStream.str();//запись в строку содержмого файла

							replace( str.begin(), str.end(), '[', '(' );
							replace( str.begin(), str.end(), ']', ')');
							replace( str.begin(), str.end(), ',', ' ');
							replace( str.begin(), str.end(), ';', ',' );
							replace( str.begin(), str.end(), 'A', ',' );
							fileout << "POLYGON (";
							str.erase(str.begin() + (str.size() - 1));
							fileout << str;
							fileout << ")";
							inFile.close();
							fileout.close();
							remove( "contours.txt" );
							//отобразить найденые контуры
							cv::namedWindow("Contours", CV_WINDOW_NORMAL);
							cv::resizeWindow("Contours",547,445);
							cv::imshow("Contours", contourImage);
							cvMoveWindow("Contours",500, 0);
						}
					}
				}if(openFileDialogGeotiff->FileName != " "){
					System::String^ geopathToString = openFileDialogGeotiff->FileName;
					std::string geonewPathToString = msclr::interop::marshal_as<std::string>(geopathToString);
					//провека соответствует ли формат изоражения
					string geopathTail = geonewPathToString.substr(geonewPathToString.size() - 3);
					
					cv::Mat image = cv::imread(geonewPathToString, cv::IMREAD_LOAD_GDAL | cv::IMREAD_ANYDEPTH);
					
					if(image.data){
						if(geopathTail == "tif"){
							System::Drawing::Graphics^ graphics = pictureBoxOriginal->CreateGraphics();
							System::IntPtr ptr(image.ptr());
							System::Drawing::Bitmap^ b  = gcnew System::Drawing::Bitmap(image.cols,image.rows,image.step,System::Drawing::Imaging::PixelFormat::Format24bppRgb,ptr);
							System::Drawing::RectangleF rect(0,0,pictureBoxOriginal->Width,pictureBoxOriginal->Height);
							graphics->DrawImage(b,rect);

							image.convertTo(image, CV_8UC1);

							//нахождение контура
							//contourOutput для того чтобы оригинальоне изображение не перезаписалаось
							std::vector<std::vector<cv::Point> > contours;
							cv::Mat contourOutput = image.clone();
							//CV_RETR_TREE для того чтобы получить иерархисеское дерево контуров
							cv::findContours(contourOutput, contours, CV_RETR_TREE, CV_CHAIN_APPROX_NONE);

							//Рисуем контуры
							cv::Mat contourImage(image.size(), CV_8UC3, cv::Scalar(0, 0, 0));
							cv::Scalar colors[3];
							colors[0] = cv::Scalar(255, 0, 0);
							colors[1] = cv::Scalar(0, 255, 0);
							colors[2] = cv::Scalar(0, 0, 255);

							//работа с файлом
							std::ofstream tempOutFile;
							tempOutFile.open("contours.txt");
							for (size_t idx = 0; idx < contours.size(); idx++) {
								cv::drawContours(contourImage, contours, idx, colors[idx % 3]);
								tempOutFile << contours[idx] << 'A';
							}
							tempOutFile.close();

							//поиск и замена в файле
							ifstream inFile;
							inFile.open("contours.txt");//open the input file
							ofstream fileout("C:\\Users\\User\\Desktop\\resultTiff.wkt"); //file
							stringstream strStream;
							strStream << inFile.rdbuf();//читать файл
							string str = strStream.str();//запись в строку содержмого файла

							replace( str.begin(), str.end(), '[', '(' );
							replace( str.begin(), str.end(), ']', ')');
							replace( str.begin(), str.end(), ',', ' ');
							replace( str.begin(), str.end(), ';', ',' );
							replace( str.begin(), str.end(), 'A', ',' );
							fileout << "POLYGON (";
							str.erase(str.begin() + (str.size() - 1));
							fileout << str;
							fileout << ")";
							inFile.close();
							fileout.close();
							remove( "contours.txt" );
							//отобразить найденые контуры
							cv::namedWindow("Contours", CV_WINDOW_NORMAL);
							cv::resizeWindow("Contours",547,445);
							cv::imshow("Contours", contourImage);
							cvMoveWindow("Contours",500, 0);
							
						}
					}
				}
		}
};
}
