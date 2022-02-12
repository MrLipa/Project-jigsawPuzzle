///////////////////////////////////////////////////////////////////////////
// C++ code generated with wxFormBuilder (version Oct 26 2018)
// http://www.wxformbuilder.org/
//
// PLEASE DO *NOT* EDIT THIS FILE!
///////////////////////////////////////////////////////////////////////////

#include "START.h"

///////////////////////////////////////////////////////////////////////////

MyDialog1::MyDialog1( wxWindow* parent, wxWindowID id, const wxString& title, const wxPoint& pos, const wxSize& size, long style ) : wxDialog( parent, id, title, pos, size, style )
{
	this->SetSizeHints( wxDefaultSize, wxDefaultSize );
	this->SetBackgroundColour( wxColour( 255, 255, 255 ) );

	SetTitle(_("Uk\u0142adanka obrazkowa"));
	wxIcon mainicon;
	mainicon.LoadFile("ikona.ico", wxBITMAP_TYPE_ICO);
	SetIcon(mainicon);
	wxImage imag;
	imag.LoadFile("Ikona.jpg");
	wxBitmap bitm(imag.Scale(100, 100));

	wxBoxSizer* bSizer1;
	bSizer1 = new wxBoxSizer( wxVERTICAL );

	bitmap = new wxStaticBitmap( this, wxID_ANY, bitm, wxDefaultPosition, wxSize( 100,100 ), 0 );
	bSizer1->Add( bitmap, 0, wxALIGN_CENTER|wxALL|wxTOP, 15 );

	wxBoxSizer* bSizer5;
	bSizer5 = new wxBoxSizer( wxVERTICAL );

	wxBoxSizer* bSizer21;
	bSizer21 = new wxBoxSizer( wxVERTICAL );

	staticText1 = new wxStaticText( this, wxID_ANY, wxT("NICK"), wxDefaultPosition, wxDefaultSize, 0 );
	staticText1->Wrap( -1 );
	bSizer21->Add( staticText1, 0, wxALIGN_CENTER|wxALL, 5 );

	textCtrl = new wxTextCtrl( this, wxID_ANY, wxEmptyString, wxDefaultPosition, wxDefaultSize, 0 );
	bSizer21->Add( textCtrl, 0, wxALIGN_CENTER|wxALL, 5 );


	bSizer5->Add( bSizer21, 1, wxEXPAND, 5 );

	wxBoxSizer* bSizer211;
	bSizer211 = new wxBoxSizer( wxVERTICAL );

	bSizer5->Add( bSizer211, 1, wxEXPAND, 5 );

	wxBoxSizer* bSizer51;
	bSizer51 = new wxBoxSizer( wxVERTICAL );

	button_start = new wxButton( this, wxID_ANY, wxT("START"), wxDefaultPosition, wxDefaultSize, 0 );
	bSizer51->Add( button_start, 0, wxALIGN_CENTER|wxALL, 5 );

	staticText2 = new wxStaticText(this, wxID_ANY, wxT("Nieprawid³owe dane"), wxDefaultPosition, wxDefaultSize, 0);
	staticText2->Wrap(-1);
	staticText2->SetFont(wxFont(9, wxFONTFAMILY_SWISS, wxFONTSTYLE_NORMAL, wxFONTWEIGHT_BOLD, false, wxT("Arial Narrow")));
	staticText2->Hide();

	bSizer51->Add(staticText2, 0, wxALIGN_CENTER | wxALL, 0);


	bSizer5->Add( bSizer51, 1, wxEXPAND, 5 );


	bSizer1->Add( bSizer5, 1, wxEXPAND, 5 );


	this->SetSizer( bSizer1 );
	this->Layout();

	this->Centre( wxBOTH );

	// Connect Events
	button_start->Connect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( MyDialog1::Start ), NULL, this );
}


MyDialog1::~MyDialog1()
{
	// Disconnect Events
	button_start->Disconnect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( MyDialog1::Start ), NULL, this );

}
