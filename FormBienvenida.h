#pragma once
#include "FormularioArbolRecuerdos.h"
#include "FormBienvenida.h"
namespace ArbolRecuerdos {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;

	/// <summary>
	/// Resumen de FormBienvenida
	/// </summary>
	public ref class FormBienvenida : public System::Windows::Forms::Form
	{
	public:
		FormBienvenida(void)
		{
			InitializeComponent();
		}

	protected:
		/// <summary>
		/// Limpiar los recursos que se estén usando.
		/// </summary>
		~FormBienvenida()
		{
			if (components)
			{
				delete components;
			}
		}
	private: System::Windows::Forms::PictureBox^ pictureBox1;
	protected:
	private: System::Windows::Forms::Label^ label1;
	private: System::Windows::Forms::Label^ label2;
	private: System::Windows::Forms::Label^ label3;
	private: System::Windows::Forms::Button^ btnEntrar;
	private: System::Windows::Forms::Label^ label4;

	private:
		/// <summary>
		/// Variable del diseñador necesaria.
		/// </summary>
		System::ComponentModel::Container ^components;

#pragma region Windows Form Designer generated code
		/// <summary>
		/// Método necesario para admitir el Diseñador. No se puede modificar
		/// el contenido de este método con el editor de código.
		/// </summary>
		void InitializeComponent(void)
		{
			System::ComponentModel::ComponentResourceManager^ resources = (gcnew System::ComponentModel::ComponentResourceManager(FormBienvenida::typeid));
			this->pictureBox1 = (gcnew System::Windows::Forms::PictureBox());
			this->label1 = (gcnew System::Windows::Forms::Label());
			this->label2 = (gcnew System::Windows::Forms::Label());
			this->label3 = (gcnew System::Windows::Forms::Label());
			this->btnEntrar = (gcnew System::Windows::Forms::Button());
			this->label4 = (gcnew System::Windows::Forms::Label());
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pictureBox1))->BeginInit();
			this->SuspendLayout();
			// 
			// pictureBox1
			// 
			this->pictureBox1->Image = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"pictureBox1.Image")));
			this->pictureBox1->Location = System::Drawing::Point(12, 12);
			this->pictureBox1->Name = L"pictureBox1";
			this->pictureBox1->Size = System::Drawing::Size(569, 612);
			this->pictureBox1->SizeMode = System::Windows::Forms::PictureBoxSizeMode::StretchImage;
			this->pictureBox1->TabIndex = 0;
			this->pictureBox1->TabStop = false;
			// 
			// label1
			// 
			this->label1->AutoSize = true;
			this->label1->Font = (gcnew System::Drawing::Font(L"Lucida Handwriting", 16, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->label1->ForeColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(255)), static_cast<System::Int32>(static_cast<System::Byte>(128)),
				static_cast<System::Int32>(static_cast<System::Byte>(0)));
			this->label1->Location = System::Drawing::Point(659, 90);
			this->label1->Name = L"label1";
			this->label1->Size = System::Drawing::Size(365, 41);
			this->label1->TabIndex = 1;
			this->label1->Text = L"Memorias y Raíces";
			// 
			// label2
			// 
			this->label2->Font = (gcnew System::Drawing::Font(L"Segoe UI", 11, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->label2->ForeColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(192)), static_cast<System::Int32>(static_cast<System::Byte>(64)),
				static_cast<System::Int32>(static_cast<System::Byte>(0)));
			this->label2->Location = System::Drawing::Point(661, 186);
			this->label2->Name = L"label2";
			this->label2->Size = System::Drawing::Size(375, 166);
			this->label2->TabIndex = 2;
			this->label2->Text = L"\"A sus 70 años, Lucía comenzó a escribir sus memorias para regalarnos un legado. "
				L"Hoy, sus cartas y documentos cobran vida en este árbol interactivo.\"";
			// 
			// label3
			// 
			this->label3->Font = (gcnew System::Drawing::Font(L"Segoe UI Semibold", 11, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->label3->ForeColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(192)), static_cast<System::Int32>(static_cast<System::Byte>(64)),
				static_cast<System::Int32>(static_cast<System::Byte>(0)));
			this->label3->Location = System::Drawing::Point(661, 366);
			this->label3->Name = L"label3";
			this->label3->Size = System::Drawing::Size(349, 37);
			this->label3->TabIndex = 3;
			this->label3->Text = L"Bienvenidos a Nuestra Historia";
			// 
			// btnEntrar
			// 
			this->btnEntrar->BackColor = System::Drawing::Color::Salmon;
			this->btnEntrar->Font = (gcnew System::Drawing::Font(L"Segoe UI", 10, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->btnEntrar->ForeColor = System::Drawing::Color::White;
			this->btnEntrar->Location = System::Drawing::Point(768, 514);
			this->btnEntrar->Name = L"btnEntrar";
			this->btnEntrar->Size = System::Drawing::Size(132, 43);
			this->btnEntrar->TabIndex = 4;
			this->btnEntrar->Text = L"Acceder";
			this->btnEntrar->UseVisualStyleBackColor = false;
			this->btnEntrar->Click += gcnew System::EventHandler(this, &FormBienvenida::btnEntrar_Click);
			// 
			// label4
			// 
			this->label4->AutoSize = true;
			this->label4->Font = (gcnew System::Drawing::Font(L"Segoe UI", 8, System::Drawing::FontStyle::Italic, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->label4->ForeColor = System::Drawing::SystemColors::ControlDarkDark;
			this->label4->Location = System::Drawing::Point(707, 560);
			this->label4->Name = L"label4";
			this->label4->Size = System::Drawing::Size(248, 21);
			this->label4->TabIndex = 5;
			this->label4->Text = L"Haga clic para ingresar al sistema.";
			// 
			// FormBienvenida
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(9, 20);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->ClientSize = System::Drawing::Size(1097, 624);
			this->Controls->Add(this->label4);
			this->Controls->Add(this->btnEntrar);
			this->Controls->Add(this->label3);
			this->Controls->Add(this->label2);
			this->Controls->Add(this->label1);
			this->Controls->Add(this->pictureBox1);
			this->MaximizeBox = false;
			this->Name = L"FormBienvenida";
			this->StartPosition = System::Windows::Forms::FormStartPosition::CenterScreen;
			this->Text = L"Bienvenida";
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pictureBox1))->EndInit();
			this->ResumeLayout(false);
			this->PerformLayout();

		}
#pragma endregion
	private: System::Void btnEntrar_Click(System::Object^ sender, System::EventArgs^ e) {
		// 1. Instanciamos el formulario principal del árbol
		FormularioArbolRecuerdos^ pantallaPrincipal = gcnew FormularioArbolRecuerdos();

		// 2. Ocultamos la bienvenida para que no se quede atrás estorbando
		this->Hide();

		// 3. Mostramos el árbol principal como una ventana de diálogo
		pantallaPrincipal->ShowDialog();

		// 4. Cuando se cierre el principal, cerramos definitivamente la aplicación
		this->Close();
	}
};
}
