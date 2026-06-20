#pragma once
#include "Familiar.h"
#include <msclr/marshal_cppstd.h>
namespace ArbolRecuerdos {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;

	/// <summary>
	/// Resumen de FormularioArbolRecuerdos
	/// </summary>
	public ref class FormularioArbolRecuerdos : public System::Windows::Forms::Form
	{
	private:
		ArbolGenealogico* miArbol = new ArbolGenealogico();

	private:
		// Función para limpiar y redibujar el TreeView desde la raíz (Lucía)
		void actualizarArbolVisual() {
			treeVisualizacion->Nodes->Clear(); // Borramos lo que haya antes
			if (miArbol->raiz != nullptr) {
				// Creamos el nodo visual para la matriarca Lucía
				String^ nomRaiz = gcnew String(miArbol->raiz->nombre.c_str());
				String^ relRaiz = gcnew String(miArbol->raiz->relacion.c_str());
				TreeNode^ nodoVisualRaiz = gcnew TreeNode(nomRaiz + " (" + relRaiz + ")");

				treeVisualizacion->Nodes->Add(nodoVisualRaiz);

				// Llamamos a la función que dibuja a todos sus hijos y descendientes
				llenarNodosVisuales(miArbol->raiz->primerHijo, nodoVisualRaiz);
			}
			treeVisualizacion->ExpandAll(); // Hace que el árbol aparezca completamente abierto
		}

		// Función recursiva que va amarrando a cada hijo con su respectivo padre en la pantalla
		void llenarNodosVisuales(Persona* nodoLogico, TreeNode^ nodoVisualPadre) {
			if (nodoLogico == nullptr) return;

			while (nodoLogico != nullptr) {
				// Convertimos los textos de C++ a formato visual de la pantalla
				String^ nombre = gcnew String(nodoLogico->nombre.c_str());
				String^ relacion = gcnew String(nodoLogico->relacion.c_str());
				TreeNode^ nuevoNodoVisual = gcnew TreeNode(nombre + " (" + relacion + ")");

				// Lo añadimos debajo de su papá/mamá visual
				nodoVisualPadre->Nodes->Add(nuevoNodoVisual);

				// Si este familiar tiene hijos, los dibujamos debajo de él
				if (nodoLogico->primerHijo != nullptr) {
					llenarNodosVisuales(nodoLogico->primerHijo, nuevoNodoVisual);
				}

				// Pasamos al siguiente hermano
				nodoLogico = nodoLogico->siguienteHermano;
			}
		}
	public:
		FormularioArbolRecuerdos(void)
		{
			InitializeComponent();
			//
			//TODO: agregar código de constructor aquí
			txtNombrePadre->Text = "";
			actualizarArbolVisual();
			//
		}

	protected:
		/// <summary>
		/// Limpiar los recursos que se estén usando.
		/// </summary>
		~FormularioArbolRecuerdos()
		{
			if (components)
			{
				delete components;
			}
		}
	private: System::Windows::Forms::GroupBox^ groupRegistro;
	protected:
	private: System::Windows::Forms::Button^ btnRegistrar;
	private: System::Windows::Forms::TextBox^ txtNombrePadre;
	private: System::Windows::Forms::Label^ label4;
	private: System::Windows::Forms::ComboBox^ cmbRelacion;
	private: System::Windows::Forms::Label^ label3;
	private: System::Windows::Forms::TextBox^ txtFechaNacimiento;
	private: System::Windows::Forms::Label^ label2;
	private: System::Windows::Forms::TextBox^ txtNombre;
	private: System::Windows::Forms::Label^ label1;
	private: System::Windows::Forms::GroupBox^ groupOperaciones;
	private: System::Windows::Forms::Button^ btnCalcularGeneraciones;
	private: System::Windows::Forms::Button^ btnContarDescendientes;

	private: System::Windows::Forms::Button^ btnMostrarHijosNietos;
	private: System::Windows::Forms::Button^ btnBuscar;
	private: System::Windows::Forms::TextBox^ txtBuscar;
	private: System::Windows::Forms::Label^ label5;
	private: System::Windows::Forms::Label^ label6;
	private: System::Windows::Forms::TreeView^ treeVisualizacion;
	private: System::Windows::Forms::ListBox^ lstResultados;
	private: System::Windows::Forms::Button^ btnCronologiaFecha;

	private: System::Windows::Forms::Label^ label7;
	private: System::Windows::Forms::Label^ label8;
	private: System::Windows::Forms::Button^ btnSalir;

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
			this->groupRegistro = (gcnew System::Windows::Forms::GroupBox());
			this->btnRegistrar = (gcnew System::Windows::Forms::Button());
			this->txtNombrePadre = (gcnew System::Windows::Forms::TextBox());
			this->label4 = (gcnew System::Windows::Forms::Label());
			this->cmbRelacion = (gcnew System::Windows::Forms::ComboBox());
			this->label3 = (gcnew System::Windows::Forms::Label());
			this->txtFechaNacimiento = (gcnew System::Windows::Forms::TextBox());
			this->label2 = (gcnew System::Windows::Forms::Label());
			this->txtNombre = (gcnew System::Windows::Forms::TextBox());
			this->label1 = (gcnew System::Windows::Forms::Label());
			this->groupOperaciones = (gcnew System::Windows::Forms::GroupBox());
			this->btnCalcularGeneraciones = (gcnew System::Windows::Forms::Button());
			this->btnContarDescendientes = (gcnew System::Windows::Forms::Button());
			this->btnMostrarHijosNietos = (gcnew System::Windows::Forms::Button());
			this->btnBuscar = (gcnew System::Windows::Forms::Button());
			this->txtBuscar = (gcnew System::Windows::Forms::TextBox());
			this->label5 = (gcnew System::Windows::Forms::Label());
			this->label6 = (gcnew System::Windows::Forms::Label());
			this->treeVisualizacion = (gcnew System::Windows::Forms::TreeView());
			this->lstResultados = (gcnew System::Windows::Forms::ListBox());
			this->btnCronologiaFecha = (gcnew System::Windows::Forms::Button());
			this->label7 = (gcnew System::Windows::Forms::Label());
			this->label8 = (gcnew System::Windows::Forms::Label());
			this->btnSalir = (gcnew System::Windows::Forms::Button());
			this->groupRegistro->SuspendLayout();
			this->groupOperaciones->SuspendLayout();
			this->SuspendLayout();
			// 
			// groupRegistro
			// 
			this->groupRegistro->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(255)), static_cast<System::Int32>(static_cast<System::Byte>(192)),
				static_cast<System::Int32>(static_cast<System::Byte>(128)));
			this->groupRegistro->Controls->Add(this->btnRegistrar);
			this->groupRegistro->Controls->Add(this->txtNombrePadre);
			this->groupRegistro->Controls->Add(this->label4);
			this->groupRegistro->Controls->Add(this->cmbRelacion);
			this->groupRegistro->Controls->Add(this->label3);
			this->groupRegistro->Controls->Add(this->txtFechaNacimiento);
			this->groupRegistro->Controls->Add(this->label2);
			this->groupRegistro->Controls->Add(this->txtNombre);
			this->groupRegistro->Controls->Add(this->label1);
			this->groupRegistro->Font = (gcnew System::Drawing::Font(L"Segoe UI", 10, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->groupRegistro->ForeColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(192)), static_cast<System::Int32>(static_cast<System::Byte>(64)),
				static_cast<System::Int32>(static_cast<System::Byte>(0)));
			this->groupRegistro->Location = System::Drawing::Point(19, 57);
			this->groupRegistro->Name = L"groupRegistro";
			this->groupRegistro->Size = System::Drawing::Size(517, 306);
			this->groupRegistro->TabIndex = 0;
			this->groupRegistro->TabStop = false;
			this->groupRegistro->Text = L"1. Registro Miembro de la Familia";
			// 
			// btnRegistrar
			// 
			this->btnRegistrar->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(255)), static_cast<System::Int32>(static_cast<System::Byte>(128)),
				static_cast<System::Int32>(static_cast<System::Byte>(0)));
			this->btnRegistrar->FlatStyle = System::Windows::Forms::FlatStyle::Flat;
			this->btnRegistrar->Font = (gcnew System::Drawing::Font(L"Segoe UI", 10, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->btnRegistrar->ForeColor = System::Drawing::Color::Transparent;
			this->btnRegistrar->Location = System::Drawing::Point(122, 246);
			this->btnRegistrar->Name = L"btnRegistrar";
			this->btnRegistrar->Size = System::Drawing::Size(194, 37);
			this->btnRegistrar->TabIndex = 8;
			this->btnRegistrar->Text = L"Vincular al Árbol";
			this->btnRegistrar->UseVisualStyleBackColor = false;
			this->btnRegistrar->Click += gcnew System::EventHandler(this, &FormularioArbolRecuerdos::btnRegistrar_Click);
			// 
			// txtNombrePadre
			// 
			this->txtNombrePadre->Location = System::Drawing::Point(290, 194);
			this->txtNombrePadre->Name = L"txtNombrePadre";
			this->txtNombrePadre->Size = System::Drawing::Size(217, 34);
			this->txtNombrePadre->TabIndex = 4;
			// 
			// label4
			// 
			this->label4->AutoSize = true;
			this->label4->Location = System::Drawing::Point(25, 194);
			this->label4->Name = L"label4";
			this->label4->Size = System::Drawing::Size(259, 28);
			this->label4->TabIndex = 6;
			this->label4->Text = L"Nombre del Padre o Madre :";
			// 
			// cmbRelacion
			// 
			this->cmbRelacion->FormattingEnabled = true;
			this->cmbRelacion->Items->AddRange(gcnew cli::array< System::Object^  >(4) { L"Hijo", L"Nieto", L"Bisnieto", L"Tataranieto" });
			this->cmbRelacion->Location = System::Drawing::Point(308, 139);
			this->cmbRelacion->Name = L"cmbRelacion";
			this->cmbRelacion->Size = System::Drawing::Size(199, 36);
			this->cmbRelacion->TabIndex = 3;
			// 
			// label3
			// 
			this->label3->AutoSize = true;
			this->label3->Location = System::Drawing::Point(25, 142);
			this->label3->Name = L"label3";
			this->label3->Size = System::Drawing::Size(282, 28);
			this->label3->TabIndex = 4;
			this->label3->Text = L"Línea de Parentesco (Relación) :";
			// 
			// txtFechaNacimiento
			// 
			this->txtFechaNacimiento->Location = System::Drawing::Point(348, 93);
			this->txtFechaNacimiento->Name = L"txtFechaNacimiento";
			this->txtFechaNacimiento->Size = System::Drawing::Size(159, 34);
			this->txtFechaNacimiento->TabIndex = 2;
			// 
			// label2
			// 
			this->label2->AutoSize = true;
			this->label2->Location = System::Drawing::Point(25, 93);
			this->label2->Name = L"label2";
			this->label2->Size = System::Drawing::Size(327, 28);
			this->label2->TabIndex = 2;
			this->label2->Text = L"Fecha de Nacimiento (AA-MM-DD) :";
			// 
			// txtNombre
			// 
			this->txtNombre->Location = System::Drawing::Point(225, 45);
			this->txtNombre->Name = L"txtNombre";
			this->txtNombre->Size = System::Drawing::Size(282, 34);
			this->txtNombre->TabIndex = 1;
			// 
			// label1
			// 
			this->label1->AutoSize = true;
			this->label1->Location = System::Drawing::Point(25, 45);
			this->label1->Name = L"label1";
			this->label1->Size = System::Drawing::Size(199, 28);
			this->label1->TabIndex = 0;
			this->label1->Text = L"Nombre del Familiar :";
			// 
			// groupOperaciones
			// 
			this->groupOperaciones->BackColor = System::Drawing::Color::NavajoWhite;
			this->groupOperaciones->Controls->Add(this->btnCalcularGeneraciones);
			this->groupOperaciones->Controls->Add(this->btnContarDescendientes);
			this->groupOperaciones->Controls->Add(this->btnMostrarHijosNietos);
			this->groupOperaciones->Controls->Add(this->btnBuscar);
			this->groupOperaciones->Controls->Add(this->txtBuscar);
			this->groupOperaciones->Controls->Add(this->label5);
			this->groupOperaciones->ForeColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(192)),
				static_cast<System::Int32>(static_cast<System::Byte>(64)), static_cast<System::Int32>(static_cast<System::Byte>(0)));
			this->groupOperaciones->Location = System::Drawing::Point(19, 388);
			this->groupOperaciones->Name = L"groupOperaciones";
			this->groupOperaciones->Size = System::Drawing::Size(517, 227);
			this->groupOperaciones->TabIndex = 1;
			this->groupOperaciones->TabStop = false;
			this->groupOperaciones->Text = L"2. Consultas y Analíticas del Legado";
			// 
			// btnCalcularGeneraciones
			// 
			this->btnCalcularGeneraciones->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(255)),
				static_cast<System::Int32>(static_cast<System::Byte>(128)), static_cast<System::Int32>(static_cast<System::Byte>(0)));
			this->btnCalcularGeneraciones->FlatStyle = System::Windows::Forms::FlatStyle::Flat;
			this->btnCalcularGeneraciones->Font = (gcnew System::Drawing::Font(L"Segoe UI", 10, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->btnCalcularGeneraciones->ForeColor = System::Drawing::Color::White;
			this->btnCalcularGeneraciones->Location = System::Drawing::Point(16, 147);
			this->btnCalcularGeneraciones->Name = L"btnCalcularGeneraciones";
			this->btnCalcularGeneraciones->Size = System::Drawing::Size(231, 42);
			this->btnCalcularGeneraciones->TabIndex = 5;
			this->btnCalcularGeneraciones->Text = L"Total de Generaciones";
			this->btnCalcularGeneraciones->UseVisualStyleBackColor = false;
			this->btnCalcularGeneraciones->Click += gcnew System::EventHandler(this, &FormularioArbolRecuerdos::btnCalcularGeneraciones_Click);
			// 
			// btnContarDescendientes
			// 
			this->btnContarDescendientes->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(255)),
				static_cast<System::Int32>(static_cast<System::Byte>(128)), static_cast<System::Int32>(static_cast<System::Byte>(0)));
			this->btnContarDescendientes->FlatStyle = System::Windows::Forms::FlatStyle::Flat;
			this->btnContarDescendientes->Font = (gcnew System::Drawing::Font(L"Segoe UI", 10, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->btnContarDescendientes->ForeColor = System::Drawing::Color::White;
			this->btnContarDescendientes->Location = System::Drawing::Point(266, 150);
			this->btnContarDescendientes->Name = L"btnContarDescendientes";
			this->btnContarDescendientes->Size = System::Drawing::Size(231, 39);
			this->btnContarDescendientes->TabIndex = 4;
			this->btnContarDescendientes->Text = L"Contar Descendientes";
			this->btnContarDescendientes->UseVisualStyleBackColor = false;
			this->btnContarDescendientes->Click += gcnew System::EventHandler(this, &FormularioArbolRecuerdos::btnContarDescendientes_Click);
			// 
			// btnMostrarHijosNietos
			// 
			this->btnMostrarHijosNietos->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(255)),
				static_cast<System::Int32>(static_cast<System::Byte>(128)), static_cast<System::Int32>(static_cast<System::Byte>(0)));
			this->btnMostrarHijosNietos->FlatStyle = System::Windows::Forms::FlatStyle::Flat;
			this->btnMostrarHijosNietos->Font = (gcnew System::Drawing::Font(L"Segoe UI", 10, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->btnMostrarHijosNietos->ForeColor = System::Drawing::Color::White;
			this->btnMostrarHijosNietos->Location = System::Drawing::Point(266, 100);
			this->btnMostrarHijosNietos->Name = L"btnMostrarHijosNietos";
			this->btnMostrarHijosNietos->Size = System::Drawing::Size(231, 40);
			this->btnMostrarHijosNietos->TabIndex = 3;
			this->btnMostrarHijosNietos->Text = L"Ver Hijos y Nietos";
			this->btnMostrarHijosNietos->UseVisualStyleBackColor = false;
			this->btnMostrarHijosNietos->Click += gcnew System::EventHandler(this, &FormularioArbolRecuerdos::btnMostrarHijosNietos_Click);
			// 
			// btnBuscar
			// 
			this->btnBuscar->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(255)), static_cast<System::Int32>(static_cast<System::Byte>(128)),
				static_cast<System::Int32>(static_cast<System::Byte>(0)));
			this->btnBuscar->FlatStyle = System::Windows::Forms::FlatStyle::Flat;
			this->btnBuscar->Font = (gcnew System::Drawing::Font(L"Segoe UI", 10, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->btnBuscar->ForeColor = System::Drawing::Color::White;
			this->btnBuscar->Location = System::Drawing::Point(16, 99);
			this->btnBuscar->Name = L"btnBuscar";
			this->btnBuscar->Size = System::Drawing::Size(231, 41);
			this->btnBuscar->TabIndex = 2;
			this->btnBuscar->Text = L"Buscar Familiar";
			this->btnBuscar->UseVisualStyleBackColor = false;
			this->btnBuscar->Click += gcnew System::EventHandler(this, &FormularioArbolRecuerdos::btnBuscar_Click);
			// 
			// txtBuscar
			// 
			this->txtBuscar->Location = System::Drawing::Point(196, 47);
			this->txtBuscar->Name = L"txtBuscar";
			this->txtBuscar->Size = System::Drawing::Size(277, 34);
			this->txtBuscar->TabIndex = 1;
			// 
			// label5
			// 
			this->label5->AutoSize = true;
			this->label5->Location = System::Drawing::Point(20, 47);
			this->label5->Name = L"label5";
			this->label5->Size = System::Drawing::Size(170, 28);
			this->label5->TabIndex = 0;
			this->label5->Text = L"Nombre a Buscar :";
			// 
			// label6
			// 
			this->label6->AutoSize = true;
			this->label6->Font = (gcnew System::Drawing::Font(L"Segoe UI", 14, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->label6->ForeColor = System::Drawing::Color::Tomato;
			this->label6->Location = System::Drawing::Point(576, 9);
			this->label6->Name = L"label6";
			this->label6->Size = System::Drawing::Size(603, 38);
			this->label6->TabIndex = 2;
			this->label6->Text = L"Estructura Jerárquica del Árbol de Recuerdos";
			// 
			// treeVisualizacion
			// 
			this->treeVisualizacion->Location = System::Drawing::Point(583, 57);
			this->treeVisualizacion->Name = L"treeVisualizacion";
			this->treeVisualizacion->Size = System::Drawing::Size(611, 324);
			this->treeVisualizacion->TabIndex = 3;
			// 
			// lstResultados
			// 
			this->lstResultados->ForeColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(192)), static_cast<System::Int32>(static_cast<System::Byte>(64)),
				static_cast<System::Int32>(static_cast<System::Byte>(0)));
			this->lstResultados->FormattingEnabled = true;
			this->lstResultados->ItemHeight = 28;
			this->lstResultados->Location = System::Drawing::Point(583, 415);
			this->lstResultados->Name = L"lstResultados";
			this->lstResultados->Size = System::Drawing::Size(611, 144);
			this->lstResultados->TabIndex = 4;
			// 
			// btnCronologiaFecha
			// 
			this->btnCronologiaFecha->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(255)),
				static_cast<System::Int32>(static_cast<System::Byte>(128)), static_cast<System::Int32>(static_cast<System::Byte>(0)));
			this->btnCronologiaFecha->FlatStyle = System::Windows::Forms::FlatStyle::Flat;
			this->btnCronologiaFecha->Font = (gcnew System::Drawing::Font(L"Segoe UI", 10, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->btnCronologiaFecha->ForeColor = System::Drawing::Color::White;
			this->btnCronologiaFecha->Location = System::Drawing::Point(583, 570);
			this->btnCronologiaFecha->Name = L"btnCronologiaFecha";
			this->btnCronologiaFecha->Size = System::Drawing::Size(462, 45);
			this->btnCronologiaFecha->TabIndex = 5;
			this->btnCronologiaFecha->Text = L"Cronología: Ordenar por Fecha de Nacimiento";
			this->btnCronologiaFecha->UseVisualStyleBackColor = false;
			this->btnCronologiaFecha->Click += gcnew System::EventHandler(this, &FormularioArbolRecuerdos::btnCronologiaFecha_Click);
			// 
			// label7
			// 
			this->label7->AutoSize = true;
			this->label7->Font = (gcnew System::Drawing::Font(L"Segoe UI", 14, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->label7->ForeColor = System::Drawing::Color::Tomato;
			this->label7->Location = System::Drawing::Point(12, 9);
			this->label7->Name = L"label7";
			this->label7->Size = System::Drawing::Size(460, 38);
			this->label7->TabIndex = 6;
			this->label7->Text = L"Gestión y Operaciones del Legado";
			// 
			// label8
			// 
			this->label8->AutoSize = true;
			this->label8->Font = (gcnew System::Drawing::Font(L"Segoe UI", 10, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->label8->ForeColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(192)), static_cast<System::Int32>(static_cast<System::Byte>(64)),
				static_cast<System::Int32>(static_cast<System::Byte>(0)));
			this->label8->Location = System::Drawing::Point(578, 384);
			this->label8->Name = L"label8";
			this->label8->Size = System::Drawing::Size(294, 28);
			this->label8->TabIndex = 7;
			this->label8->Text = L"----Reportes y Estadísticas----";
			// 
			// btnSalir
			// 
			this->btnSalir->BackColor = System::Drawing::Color::Tomato;
			this->btnSalir->Font = (gcnew System::Drawing::Font(L"Segoe UI", 10, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->btnSalir->ForeColor = System::Drawing::Color::White;
			this->btnSalir->Location = System::Drawing::Point(1065, 570);
			this->btnSalir->Name = L"btnSalir";
			this->btnSalir->Size = System::Drawing::Size(129, 45);
			this->btnSalir->TabIndex = 8;
			this->btnSalir->Text = L"Salir";
			this->btnSalir->UseVisualStyleBackColor = false;
			this->btnSalir->Click += gcnew System::EventHandler(this, &FormularioArbolRecuerdos::btnSalir_Click);
			// 
			// FormularioArbolRecuerdos
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(11, 28);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->BackColor = System::Drawing::Color::AntiqueWhite;
			this->ClientSize = System::Drawing::Size(1253, 626);
			this->Controls->Add(this->btnSalir);
			this->Controls->Add(this->label8);
			this->Controls->Add(this->label7);
			this->Controls->Add(this->btnCronologiaFecha);
			this->Controls->Add(this->lstResultados);
			this->Controls->Add(this->treeVisualizacion);
			this->Controls->Add(this->label6);
			this->Controls->Add(this->groupOperaciones);
			this->Controls->Add(this->groupRegistro);
			this->Font = (gcnew System::Drawing::Font(L"Segoe UI", 10, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->KeyPreview = true;
			this->Margin = System::Windows::Forms::Padding(4);
			this->MaximizeBox = false;
			this->Name = L"FormularioArbolRecuerdos";
			this->StartPosition = System::Windows::Forms::FormStartPosition::CenterScreen;
			this->Text = L"El Árbol de los Recuerdos de Lucía";
			this->KeyPress += gcnew System::Windows::Forms::KeyPressEventHandler(this, &FormularioArbolRecuerdos::FormularioArbolRecuerdos_KeyPress);
			this->groupRegistro->ResumeLayout(false);
			this->groupRegistro->PerformLayout();
			this->groupOperaciones->ResumeLayout(false);
			this->groupOperaciones->PerformLayout();
			this->ResumeLayout(false);
			this->PerformLayout();

		}
#pragma endregion
	private: System::Void btnRegistrar_Click(System::Object^ sender, System::EventArgs^ e) {
		// 1. Validar que los campos no estén vacíos
		if (txtNombre->Text->Trim() == "" || txtFechaNacimiento->Text->Trim() == "") {
			MessageBox::Show("Por favor, llene el nombre y la fecha de nacimiento.", "Campos vacíos", MessageBoxButtons::OK, MessageBoxIcon::Warning);
			return;
		}

		// 2. Convertir los textos a std::string para tu estructura lógica
		std::string padre = msclr::interop::marshal_as<std::string>(txtNombrePadre->Text);
		std::string nombre = msclr::interop::marshal_as<std::string>(txtNombre->Text);
		std::string fecha = msclr::interop::marshal_as<std::string>(txtFechaNacimiento->Text);
		std::string relacion = msclr::interop::marshal_as<std::string>(cmbRelacion->Text);

		bool insertadoExitoso = false;

		// 3. Convertir a String^ de System para la interfaz gráfica
		String^ padreSystemStr = gcnew String(padre.c_str());
		String^ nombreSystemStr = gcnew String(nombre.c_str());
		String^ relacionSystemStr = gcnew String(relacion.c_str());

		// 4. Inserción en el TreeView Visual usando la herramienta nativa Find (busca cualquier nivel)
		if (treeVisualizacion->Nodes->Count == 0 || padreSystemStr->Trim() == "Lucia" || padreSystemStr->Trim() == "Lucía") {
			if (treeVisualizacion->Nodes->Count == 0) {
				treeVisualizacion->Nodes->Add(nombreSystemStr, nombreSystemStr + " (Matriarca)");
			}
			else {
				treeVisualizacion->Nodes[0]->Nodes->Add(nombreSystemStr, nombreSystemStr + " (" + relacionSystemStr + ")");
			}
			insertadoExitoso = true;
		}
		else {
			// Busca al padre automáticamente sin importar si es hijo o nieto
			array<TreeNode^>^ nodosEncontrados = treeVisualizacion->Nodes->Find(padreSystemStr->Trim(), true);
			if (nodosEncontrados->Length > 0) {
				nodosEncontrados[0]->Nodes->Add(nombreSystemStr, nombreSystemStr + " (" + relacionSystemStr + ")");
				insertadoExitoso = true;
			}
		}

		// 5. Si se insertó visualmente, guardamos en tu árbol lógico y limpiamos
		if (insertadoExitoso) {
			miArbol->insertar(padre, nombre, fecha, relacion);

			MessageBox::Show("Familiar registrado con éxito en el árbol.", "Éxito", MessageBoxButtons::OK, MessageBoxIcon::Information);

			txtNombre->Clear();
			txtFechaNacimiento->Clear();
			txtNombrePadre->Clear();
			cmbRelacion->SelectedIndex = -1;
			txtNombre->Focus();
		}
		else {
			MessageBox::Show("No se pudo registrar. Verifique si el nombre del padre/madre es correcto y existe en el árbol.", "Error de inserción", MessageBoxButtons::OK, MessageBoxIcon::Error);
		}
	}
private: System::Void btnBuscar_Click(System::Object^ sender, System::EventArgs^ e) {
	if (txtBuscar->Text->Trim() == "") {
		MessageBox::Show("Por favor, ingrese el nombre del familiar que desea buscar.", "Campo vacío", MessageBoxButtons::OK, MessageBoxIcon::Warning);
		return;
	}

	std::string nombreBuscar = msclr::interop::marshal_as<std::string>(txtBuscar->Text);
	Persona* encontrado = miArbol->buscar(miArbol->raiz, nombreBuscar);

	if (encontrado != nullptr) {
		lstResultados->Items->Clear();

		String^ nom = gcnew String(encontrado->nombre.c_str());
		String^ fecha = gcnew String(encontrado->fechaNacimiento.c_str());
		String^ rel = gcnew String(encontrado->relacion.c_str());

		lstResultados->Items->Add("--- FAMILIAR ENCONTRADO ---");
		lstResultados->Items->Add("Nombre: " + nom);
		lstResultados->Items->Add("Fecha de Nacimiento: " + fecha);
		lstResultados->Items->Add("Relación con Lucía: " + rel);
	}
	else {
		MessageBox::Show("El familiar no fue encontrado en el árbol genealógico.", "No encontrado", MessageBoxButtons::OK, MessageBoxIcon::Information);
	}
}
private: System::Void btnMostrarHijosNietos_Click(System::Object^ sender, System::EventArgs^ e) {
	if (txtBuscar->Text->Trim() == "") {
		MessageBox::Show("Por favor, ingrese el nombre del familiar en el cuadro de búsqueda.", "Campo vacío", MessageBoxButtons::OK, MessageBoxIcon::Warning);
		return;
	}

	std::string nombreBuscar = msclr::interop::marshal_as<std::string>(txtBuscar->Text);
	Persona* encontrado = miArbol->buscar(miArbol->raiz, nombreBuscar);

	if (encontrado != nullptr) {
		lstResultados->Items->Clear();

		String^ nombreBase = gcnew String(encontrado->nombre.c_str());
		lstResultados->Items->Add("--- HIJOS DE " + nombreBase->ToUpper() + " ---");

		// 1. Mostrar Hijos Directos
		Persona* hijo = encontrado->primerHijo;
		bool tieneHijos = false;
		while (hijo != nullptr) {
			String^ nomHijo = gcnew String(hijo->nombre.c_str());
			String^ relHijo = gcnew String(hijo->relacion.c_str());
			lstResultados->Items->Add("- " + nomHijo + " (" + relHijo + ")");
			tieneHijos = true;
			hijo = hijo->siguienteHermano;
		}
		if (!tieneHijos) {
			lstResultados->Items->Add("(No tiene hijos registrados)");
		}

		lstResultados->Items->Add("");
		lstResultados->Items->Add("--- NIETOS DE " + nombreBase->ToUpper() + " ---");

		// 2. Mostrar Nietos (Hijos de los hijos)
		Persona* hijoParaNieto = encontrado->primerHijo;
		bool tieneNietos = false;
		while (hijoParaNieto != nullptr) {
			Persona* nieto = hijoParaNieto->primerHijo;
			while (nieto != nullptr) {
				String^ nomNieto = gcnew String(nieto->nombre.c_str());
				String^ nomPadre = gcnew String(hijoParaNieto->nombre.c_str());
				lstResultados->Items->Add("- " + nomNieto + " (Hijo/a de " + nomPadre + ")");
				tieneNietos = true;
				nieto = nieto->siguienteHermano;
			}
			hijoParaNieto = hijoParaNieto->siguienteHermano;
		}
		if (!tieneNietos) {
			lstResultados->Items->Add("(No tiene nietos registrados)");
		}

	}
	else {
		MessageBox::Show("El familiar no fue encontrado para mostrar sus descendientes.", "No encontrado", MessageBoxButtons::OK, MessageBoxIcon::Information);
	}
}
private: System::Void btnCalcularGeneraciones_Click(System::Object^ sender, System::EventArgs^ e) {
	int totalGen = 0;
	// Si la raíz existe, como mínimo hay 1 generación (Lucía)
	if (miArbol->raiz != nullptr) {
		totalGen = 1;
		Persona* hijo = miArbol->raiz->primerHijo;
		if (hijo != nullptr) {
			totalGen = 2; // Hay hijos
			Persona* nieto = hijo->primerHijo;
			if (nieto != nullptr) {
				totalGen = 3; // Hay nietos
			}
		}
	}

	lstResultados->Items->Clear();
	lstResultados->Items->Add("--- ANALÍTICA DEL ÁRBOL ---");
	lstResultados->Items->Add("Total de generaciones: " + totalGen.ToString());
}
private: System::Void btnContarDescendientes_Click(System::Object^ sender, System::EventArgs^ e) {
	if (txtBuscar->Text->Trim() == "") {
		MessageBox::Show("Por favor, ingrese el nombre del familiar para contar sus descendientes.", "Campo vacío", MessageBoxButtons::OK, MessageBoxIcon::Warning);
		return;
	}

	std::string nombreBuscar = msclr::interop::marshal_as<std::string>(txtBuscar->Text);
	Persona* encontrado = miArbol->buscar(miArbol->raiz, nombreBuscar);

	if (encontrado != nullptr) {
		int contador = 0;

		// Contamos los hijos directos
		Persona* hijo = encontrado->primerHijo;
		while (hijo != nullptr) {
			contador++;

			// Contamos los hijos de este hijo (los nietos)
			Persona* nieto = hijo->primerHijo;
			while (nieto != nullptr) {
				contador++;
				nieto = nieto->siguienteHermano;
			}

			hijo = hijo->siguienteHermano;
		}

		lstResultados->Items->Clear();
		String^ nombreBase = gcnew String(encontrado->nombre.c_str());
		lstResultados->Items->Add("--- TOTAL DE DESCENDIENTES ---");
		lstResultados->Items->Add("Familiar: " + nombreBase);
		lstResultados->Items->Add("Cantidad de descendientes: " + contador.ToString());
	}
	else {
		MessageBox::Show("El familiar no fue encontrado para calcular sus descendientes.", "No encontrado", MessageBoxButtons::OK, MessageBoxIcon::Information);
	}
}
private: System::Void btnCronologiaFecha_Click(System::Object^ sender, System::EventArgs^ e) {
	lstResultados->Items->Clear();
	lstResultados->Items->Add("--- CRONOLOGÍA FAMILIAR ---");
	lstResultados->Items->Add("(Ordenado de mayor a menor)");
	lstResultados->Items->Add("---------------------------");

	// Lista dinámica para guardar a los familiares y ordenarlos
	System::Collections::Generic::List<String^>^ listaCronologica = gcnew System::Collections::Generic::List<String^>();

	if (miArbol->raiz != nullptr) {
		// Matriarca Lucía
		String^ fRaiz = gcnew String(miArbol->raiz->fechaNacimiento.c_str());
		String^ nRaiz = gcnew String(miArbol->raiz->nombre.c_str());
		listaCronologica->Add(fRaiz + " - " + nRaiz + " (Matriarca)");

		// Recorremos hijos
		Persona* hijo = miArbol->raiz->primerHijo;
		while (hijo != nullptr) {
			String^ fHijo = gcnew String(hijo->fechaNacimiento.c_str());
			String^ nHijo = gcnew String(hijo->nombre.c_str());
			listaCronologica->Add(fHijo + " - " + nHijo + " (Hijo/a)");

			// Recorremos nietos
			Persona* nieto = hijo->primerHijo;
			while (nieto != nullptr) {
				String^ fNieto = gcnew String(nieto->fechaNacimiento.c_str());
				String^ nNieto = gcnew String(nieto->nombre.c_str());
				listaCronologica->Add(fNieto + " - " + nNieto + " (Nieto/a)");

				// --- AGREGADO: Recorremos bisnietos ---
				Persona* bisnieto = nieto->primerHijo;
				while (bisnieto != nullptr) {
					String^ fBisnieto = gcnew String(bisnieto->fechaNacimiento.c_str());
					String^ nBisnieto = gcnew String(bisnieto->nombre.c_str());
					listaCronologica->Add(fBisnieto + " - " + nBisnieto + " (Bisnieto/a)");

					// --- AGREGADO: Recorremos tataranietos ---
					Persona* tataranieto = bisnieto->primerHijo;
					while (tataranieto != nullptr) {
						String^ fTatara = gcnew String(tataranieto->fechaNacimiento.c_str());
						String^ nTatara = gcnew String(tataranieto->nombre.c_str());
						listaCronologica->Add(fTatara + " - " + nTatara + " (Tataranieto/a)");

						tataranieto = tataranieto->siguienteHermano;
					}
					bisnieto = bisnieto->siguienteHermano;
				}
				nieto = nieto->siguienteHermano;
			}
			hijo = hijo->siguienteHermano;
		}
	}

	// Ordenar cronológicamente
	listaCronologica->Sort();

	// Mostrar resultados en la lista
	if (listaCronologica->Count > 0) {
		for (int i = 0; i < listaCronologica->Count; i++) {
			lstResultados->Items->Add(listaCronologica[i]);
		}
	}
	else {
		lstResultados->Items->Add("(No hay familiares registrados para ordenar)");
	}

}
private: System::Void FormularioArbolRecuerdos_KeyPress(System::Object^ sender, System::Windows::Forms::KeyPressEventArgs^ e) {
	if (e->KeyChar == (char)Keys::Enter) {
		e->Handled = true; // Quita el sonido molesto del sistema
		this->SelectNextControl(this->ActiveControl, true, true, true, true); // Salta al siguiente cuadro
	}
}
private: System::Void btnSalir_Click(System::Object^ sender, System::EventArgs^ e) {
	//Salida del programa
	MessageBox::Show("Los recuerdos se guardan en el corazón. ¡Hasta pronto!",
		"Cerrando el Árbol de los Recuerdos de Lucia",
		MessageBoxButtons::OK,
		MessageBoxIcon::Information);

	//Cierra la aplicacion por completo
	Application::Exit();
}
};
}
