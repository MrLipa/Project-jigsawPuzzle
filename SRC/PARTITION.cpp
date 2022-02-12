///////////////////////////////////////////////////////////////////////////
// C++ code generated with wxFormBuilder (version Oct 26 2018)
// http://www.wxformbuilder.org/
//
// PLEASE DO *NOT* EDIT THIS FILE!
///////////////////////////////////////////////////////////////////////////

#include "PARTITION.h"

///////////////////////////////////////////////////////////////////////////

MyDialog4::MyDialog4( wxWindow* parent, wxWindowID id, const wxString& title, const wxPoint& pos, const wxSize& size, long style ) : wxDialog( parent, id, title, pos, size, style )
{
	this->SetSizeHints( wxDefaultSize, wxDefaultSize );

	SetTitle(_("Uk\u0142adanka obrazkowa"));
	wxIcon mainicon;
	mainicon.LoadFile("ikona.ico", wxBITMAP_TYPE_ICO);
	SetIcon(mainicon);

	wxBoxSizer* bSizer1;
	bSizer1 = new wxBoxSizer( wxVERTICAL );

	wxBoxSizer* bSizer8;
	bSizer8 = new wxBoxSizer( wxVERTICAL );

	m_staticText1 = new wxStaticText( this, wxID_ANY, wxT("Wybierz poziom trudno\u015Bci"), wxDefaultPosition, wxDefaultSize, 0 );
	m_staticText1->Wrap( -1 );
	bSizer8->Add( m_staticText1, 0, wxALIGN_CENTER|wxALL|wxLEFT, 50 );


	bSizer1->Add( bSizer8, 1, wxEXPAND, 5 );

	wxBoxSizer* bSizer2;
	bSizer2 = new wxBoxSizer( wxHORIZONTAL );

	button_3x3 = new wxButton( this, wxID_ANY, wxT("3x3"), wxDefaultPosition, wxDefaultSize, 0 );
	button_3x3->SetBackgroundColour( wxSystemSettings::GetColour( wxSYS_COLOUR_HIGHLIGHT ) );

	bSizer2->Add(button_3x3, 0, wxALIGN_CENTER|wxLEFT, 320 );

	button_5x5 = new wxButton( this, wxID_ANY, wxT("5x5"), wxDefaultPosition, wxDefaultSize, 0 );
	button_5x5->SetBackgroundColour( wxSystemSettings::GetColour( wxSYS_COLOUR_HIGHLIGHT ) );

	bSizer2->Add(button_5x5, 0, wxALIGN_CENTER|wxALL, 5 );


	bSizer1->Add( bSizer2, 1, wxEXPAND, 5 );

	wxBoxSizer* bSizer21;
	bSizer21 = new wxBoxSizer( wxHORIZONTAL );

	button_8x8 = new wxButton( this, wxID_ANY, wxT("8x8"), wxDefaultPosition, wxDefaultSize, 0 );
	button_8x8->SetBackgroundColour( wxSystemSettings::GetColour( wxSYS_COLOUR_HIGHLIGHT ) );

	bSizer21->Add(button_8x8, 0, wxALIGN_CENTER|wxLEFT, 320 );

	button_10x10 = new wxButton( this, wxID_ANY, wxT("10x10"), wxDefaultPosition, wxDefaultSize, 0 );
	button_10x10->SetBackgroundColour( wxSystemSettings::GetColour( wxSYS_COLOUR_HIGHLIGHT ) );

	bSizer21->Add(button_10x10, 0, wxALIGN_CENTER|wxALL, 5 );


	bSizer1->Add( bSizer21, 1, wxEXPAND, 5 );

	wxBoxSizer* bSizer13;
	bSizer13 = new wxBoxSizer( wxVERTICAL );

	m_staticText2 = new wxStaticText( this, wxID_ANY, wxT("Wybierz przedzia\u0142"), wxDefaultPosition, wxDefaultSize, 0 );
	m_staticText2->Wrap( -1 );
	bSizer13->Add( m_staticText2, 0, wxALIGN_CENTER|wxALL, 30 );


	bSizer1->Add( bSizer13, 1, wxEXPAND, 5 );

	wxBoxSizer* bSizer14;
	bSizer14 = new wxBoxSizer( wxHORIZONTAL );

	m_staticText3 = new wxStaticText( this, wxID_ANY, wxT("Liczba kolumn: "), wxDefaultPosition, wxDefaultSize, 0 );
	m_staticText3->Wrap( -1 );
	bSizer14->Add( m_staticText3, 0, wxALIGN_CENTER|wxLEFT, 261 );

	textCtrl1 = new wxTextCtrl( this, wxID_ANY, wxEmptyString, wxDefaultPosition, wxDefaultSize, 0 );
	bSizer14->Add( textCtrl1, 0, wxALIGN_CENTER|wxALL, 5 );


	bSizer1->Add( bSizer14, 1, wxEXPAND, 5 );

	wxBoxSizer* bSizer141;
	bSizer141 = new wxBoxSizer( wxHORIZONTAL );

	m_staticText4 = new wxStaticText( this, wxID_ANY, wxT("Liczba wierszy: "), wxDefaultPosition, wxDefaultSize, 0 );
	m_staticText4->Wrap( -1 );
	bSizer141->Add( m_staticText4, 0, wxALIGN_CENTER|wxLEFT, 263 );

	textCtrl2 = new wxTextCtrl( this, wxID_ANY, wxEmptyString, wxDefaultPosition, wxDefaultSize, 0 );
	bSizer141->Add( textCtrl2, 0, wxALIGN_CENTER|wxALL, 5 );


	bSizer1->Add( bSizer141, 1, wxEXPAND, 5 );

	wxBoxSizer* bSizer18;
	bSizer18 = new wxBoxSizer( wxVERTICAL );

	m_staticText3 = new wxStaticText(this, wxID_ANY, wxT("Nieprawid³owe dane"), wxDefaultPosition, wxDefaultSize, 0);
	m_staticText3->Wrap(-1);
	m_staticText3->SetFont(wxFont(9, wxFONTFAMILY_SWISS, wxFONTSTYLE_NORMAL, wxFONTWEIGHT_BOLD, false, wxT("Arial Narrow")));
	m_staticText3->Hide();

	bSizer18->Add(m_staticText3, 0, wxALIGN_CENTER | wxTOP, 30);

	button_start = new wxButton( this, wxID_ANY, wxT("START"), wxDefaultPosition, wxDefaultSize, 0 );
	bSizer18->Add(button_start, 0, wxALIGN_CENTER|wxALL, 28 );


	bSizer1->Add( bSizer18, 1, wxEXPAND, 5 );


	this->SetSizer( bSizer1 );
	this->Layout();

	this->Centre( wxBOTH );

	// Connect Events
	button_3x3->Connect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( MyDialog4::Size3x3 ), NULL, this );
	button_5x5->Connect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( MyDialog4::Size5x5 ), NULL, this );
	button_8x8->Connect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( MyDialog4::Size8x8 ), NULL, this );
	button_10x10->Connect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( MyDialog4::Size10x10 ), NULL, this );
	button_start->Connect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( MyDialog4::Start ), NULL, this );
}
void MyDialog4::Size3x3(wxCommandEvent& event)
{
	textCtrl1->SetLabel(wxString::Format("%d", 3));
	textCtrl2->SetLabel(wxString::Format("%d", 3));
}
void MyDialog4::Size5x5(wxCommandEvent& event)
{
	textCtrl1->SetLabel(wxString::Format("%d", 5));
	textCtrl2->SetLabel(wxString::Format("%d", 5));
}
void MyDialog4::Size8x8(wxCommandEvent& event)
{
	textCtrl1->SetLabel(wxString::Format("%d", 8));
	textCtrl2->SetLabel(wxString::Format("%d", 8));
}
void MyDialog4::Size10x10(wxCommandEvent& event)
{
	textCtrl1->SetLabel(wxString::Format("%d", 10));
	textCtrl2->SetLabel(wxString::Format("%d", 10));
}
MyDialog4::~MyDialog4()
{
	// Disconnect Events
	button_3x3->Disconnect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( MyDialog4::Size3x3 ), NULL, this );
	button_5x5->Disconnect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( MyDialog4::Size5x5 ), NULL, this );
	button_8x8->Disconnect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( MyDialog4::Size8x8 ), NULL, this );
	button_10x10->Disconnect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( MyDialog4::Size10x10 ), NULL, this );
	button_start->Disconnect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( MyDialog4::Start ), NULL, this );

}
