///////////////////////////////////////////////////////////////////////////
// C++ code generated with wxFormBuilder (version Oct 26 2018)
// http://www.wxformbuilder.org/
//
// PLEASE DO *NOT* EDIT THIS FILE!
///////////////////////////////////////////////////////////////////////////

#include "GUI.h"

///////////////////////////////////////////////////////////////////////////

MyFrame::MyFrame( wxWindow* parent, wxWindowID id, const wxString& title, const wxPoint& pos, const wxSize& size, long style ) : wxFrame( parent, id, title, pos, size, style )
{
	this->SetSizeHints( wxDefaultSize, wxDefaultSize );
	this->SetBackgroundColour( wxSystemSettings::GetColour( wxSYS_COLOUR_SCROLLBAR ) );

	wxBoxSizer* bSizer1;
	bSizer1 = new wxBoxSizer( wxHORIZONTAL );

	wxBoxSizer* bSizer3;
	bSizer3 = new wxBoxSizer( wxVERTICAL );

	panel = new wxPanel( this, wxID_ANY, wxDefaultPosition, wxDefaultSize, wxTAB_TRAVERSAL );
	panel->SetBackgroundColour( wxSystemSettings::GetColour( wxSYS_COLOUR_INFOBK ) );

	bSizer3->Add( panel, 1, wxEXPAND | wxALL, 5 );


	bSizer1->Add( bSizer3, 1, wxEXPAND, 5 );

	wxBoxSizer* bSizer2;
	bSizer2 = new wxBoxSizer( wxHORIZONTAL );

	wxBoxSizer* bSizer5;
	bSizer5 = new wxBoxSizer( wxVERTICAL );

	button_new_game = new wxButton( this, wxID_ANY, wxT("Nowa Gra"), wxDefaultPosition, wxDefaultSize, 0 );
	bSizer5->Add(button_new_game, 0, wxALIGN_CENTER|wxALL, 10 );

	button_preview = new wxButton( this, wxID_ANY, wxT("Podgl¹d"), wxDefaultPosition, wxDefaultSize, 0 );
	bSizer5->Add(button_preview, 0, wxALIGN_CENTER|wxALL, 10 );

	wxBoxSizer* bSizer61;
	bSizer61 = new wxBoxSizer( wxHORIZONTAL );

	text_device = new wxStaticText( this, wxID_ANY, wxT("Liczba podzia\u0142\u00F3w:"), wxDefaultPosition, wxDefaultSize, 0 );
	text_device->Wrap( -1 );
	bSizer61->Add( text_device, 0, wxALIGN_CENTER|wxALL, 0);

	text_output_division = new wxStaticText( this, wxID_ANY, wxT("0"), wxDefaultPosition, wxDefaultSize, 0 );
	text_output_division->Wrap( -1 );
	bSizer61->Add( text_output_division, 0, wxALIGN_CENTER | wxALL, 2);


	bSizer5->Add( bSizer61, 1, wxEXPAND, 5 );

	wxBoxSizer* bSizer6;
	bSizer6 = new wxBoxSizer( wxHORIZONTAL );

	text_time = new wxStaticText( this, wxID_ANY, wxT("Czas gry:"), wxDefaultPosition, wxDefaultSize, 0 );
	text_time->Wrap( -1 );
	bSizer6->Add(text_time, 0, wxALIGN_CENTER|wxLEFT, 44 );

	text_output_time = new wxStaticText( this, wxID_ANY, wxT("00:00:00"), wxDefaultPosition, wxDefaultSize, 0 );
	text_output_time->Wrap( -1 );
	bSizer6->Add(text_output_time, 0, wxALIGN_CENTER|wxALL, 4 );


	bSizer5->Add( bSizer6, 1, wxEXPAND, 5 );

	wxBoxSizer* bSizer62;
	bSizer62 = new wxBoxSizer(wxHORIZONTAL);

	text_number_of_steps = new wxStaticText(this, wxID_ANY, wxT("Liczba krok\u00F3w:"), wxDefaultPosition, wxDefaultSize, 0);
	text_number_of_steps->Wrap(-1);
	bSizer62->Add(text_number_of_steps, 0, wxALIGN_CENTER | wxLEFT, 13);

	text_output_number_of_steps = new wxStaticText(this, wxID_ANY, wxT("0"), wxDefaultPosition, wxDefaultSize, 0);
	text_output_number_of_steps->Wrap(-1);
	bSizer62->Add(text_output_number_of_steps, 0, wxALIGN_CENTER | wxALL, 4);


	bSizer5->Add(bSizer62, 1, wxEXPAND, 5);

	wxImage ima;
	ima.LoadFile("wrong.jpg");
	ima = ima.Scale(80, 80);
	wxBitmap bitm(ima);

	bitmap = new wxStaticBitmap( this, wxID_ANY, bitm, wxDefaultPosition, wxDefaultSize, 0 );
	bSizer5->Add(bitmap, 0, wxALIGN_CENTER|wxTOP, 90 );

	text_nick = new wxStaticText( this, wxID_ANY, wxT("NICK"), wxDefaultPosition, wxDefaultSize, 0 );
	text_nick->Wrap( -1 );
	bSizer5->Add(text_nick, 0, wxALIGN_CENTER|wxTOP, 180 );


	bSizer2->Add( bSizer5, 1, wxALIGN_CENTER, 5 );


	bSizer1->Add( bSizer2, 0, wxALIGN_CENTER, 5 );


	this->SetSizer( bSizer1 );
	this->Layout();
	menubar = new wxMenuBar( 0 );
	menu_menu = new wxMenu();
	wxMenuItem* m_menuItem2;
	m_menuItem2 = new wxMenuItem(menu_menu, wxID_ANY, wxString( wxT("Nowa Gra") ) , wxEmptyString, wxITEM_NORMAL );
	menu_menu->Append( m_menuItem2 );

	wxMenuItem* m_menuItem3;
	m_menuItem3 = new wxMenuItem(menu_menu, wxID_ANY, wxString( wxT("Podgl¹d") ) , wxEmptyString, wxITEM_NORMAL );
	menu_menu->Append( m_menuItem3 );

	wxMenuItem* m_menuItem4;
	m_menuItem4 = new wxMenuItem(menu_menu, wxID_ANY, wxString( wxT("Zmie\u0144 Nick") ) , wxEmptyString, wxITEM_NORMAL );
	menu_menu->Append( m_menuItem4 );

	wxMenuItem* m_menuItem8;
	m_menuItem8 = new wxMenuItem(menu_menu, wxID_ANY, wxString(wxT("Zmie\u0144 liczba podzia\u0142\u00F3w")), wxEmptyString, wxITEM_NORMAL);
	menu_menu->Append(m_menuItem8);

	menu_choiceA = new wxMenuItem(menu_menu, wxID_ANY, wxString(wxT("Wersja 1")), wxEmptyString, wxITEM_RADIO);
	menu_menu->Append(menu_choiceA);

	
	menu_choiceB = new wxMenuItem(menu_menu, wxID_ANY, wxString(wxT("Wersja 2")), wxEmptyString, wxITEM_RADIO);
	menu_menu->Append(menu_choiceB);

	menu_menu->AppendSeparator();

	wxMenuItem* m_menuItem5;
	m_menuItem5 = new wxMenuItem(menu_menu, wxID_ANY, wxString( wxT("Exit") ) , wxEmptyString, wxITEM_NORMAL );
	menu_menu->Append( m_menuItem5 );

	menubar->Append(menu_menu, wxT("Menu") );

	menu_about = new wxMenu();
	wxMenuItem* m_menuItem6;
	m_menuItem6 = new wxMenuItem(menu_about, wxID_ANY, wxString( wxT("Informacja o grze") ) , wxEmptyString, wxITEM_NORMAL );
	menu_about->Append( m_menuItem6 );

	wxMenuItem* m_menuItem9;
	m_menuItem9 = new wxMenuItem(menu_about, wxID_ANY, wxString(wxT("Ranking")), wxEmptyString, wxITEM_NORMAL);
	menu_about->Append(m_menuItem9);

	menu_about->AppendSeparator();

	wxMenuItem* m_menuItem7;
	m_menuItem7 = new wxMenuItem(menu_about, wxID_ANY, wxString( wxT("Help") ) , wxEmptyString, wxITEM_NORMAL );
	menu_about->Append( m_menuItem7 );

	menubar->Append(menu_about, wxT("About") );

	this->SetMenuBar( menubar );


	this->Centre( wxBOTH );

	// Connect Events
	button_new_game->Connect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( MyFrame::OnClickNewGame ), NULL, this );
	button_preview->Connect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( MyFrame::OnClickPreview ), NULL, this );
	menu_menu->Bind(wxEVT_COMMAND_MENU_SELECTED, wxCommandEventHandler( MyFrame::MenuNewGame ), this, m_menuItem2->GetId());
	menu_menu->Bind(wxEVT_COMMAND_MENU_SELECTED, wxCommandEventHandler( MyFrame::MenuPreview ), this, m_menuItem3->GetId());
	menu_menu->Bind(wxEVT_COMMAND_MENU_SELECTED, wxCommandEventHandler( MyFrame::MenuChangeNick ), this, m_menuItem4->GetId());
	menu_menu->Bind(wxEVT_COMMAND_MENU_SELECTED, wxCommandEventHandler( MyFrame::MenuChangeDivision), this, m_menuItem8->GetId());
	menu_menu->Bind(wxEVT_COMMAND_MENU_SELECTED, wxCommandEventHandler( MyFrame::MenuExit ), this, m_menuItem5->GetId());
	menu_menu->Bind(wxEVT_COMMAND_MENU_SELECTED, wxCommandEventHandler(MyFrame::ChoiceA), this, menu_choiceA->GetId());
	menu_menu->Bind(wxEVT_COMMAND_MENU_SELECTED, wxCommandEventHandler(MyFrame::ChoiceB), this, menu_choiceB->GetId());
	menu_about->Bind(wxEVT_COMMAND_MENU_SELECTED, wxCommandEventHandler( MyFrame::MenuInfo ), this, m_menuItem6->GetId());
	menu_about->Bind(wxEVT_COMMAND_MENU_SELECTED, wxCommandEventHandler( MyFrame::MenuRanking), this, m_menuItem9->GetId());
	menu_about->Bind(wxEVT_COMMAND_MENU_SELECTED, wxCommandEventHandler( MyFrame::MenuHelp ), this, m_menuItem7->GetId());

}

MyFrame::~MyFrame()
{
	// Disconnect Events
	button_new_game->Disconnect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( MyFrame::OnClickNewGame ), NULL, this );
	button_preview->Disconnect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( MyFrame::OnClickPreview ), NULL, this );

}
