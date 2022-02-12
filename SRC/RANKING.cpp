///////////////////////////////////////////////////////////////////////////
// C++ code generated with wxFormBuilder (version Oct 26 2018)
// http://www.wxformbuilder.org/
//
// PLEASE DO *NOT* EDIT THIS FILE!
///////////////////////////////////////////////////////////////////////////

#include "RANKING.h"

///////////////////////////////////////////////////////////////////////////

MyDialog5::MyDialog5( wxWindow* parent, wxWindowID id, const wxString& title, const wxPoint& pos, const wxSize& size, long style ) : wxDialog( parent, id, title, pos, size, style )
{
	this->SetSizeHints( wxDefaultSize, wxDefaultSize );
	SetTitle(_("Uk\u0142adanka obrazkowa"));
	wxIcon mainicon;
	mainicon.LoadFile("ikona.ico", wxBITMAP_TYPE_ICO);
	SetIcon(mainicon);

	wxBoxSizer* bSizer1;
	bSizer1 = new wxBoxSizer( wxVERTICAL );

	wxBoxSizer* bSizer2;
	bSizer2 = new wxBoxSizer( wxVERTICAL );

	m_staticText1 = new wxStaticText( this, wxID_ANY, wxT("Ranking"), wxDefaultPosition, wxDefaultSize, 0 );
	m_staticText1->Wrap( -1 );
	bSizer2->Add( m_staticText1, 0, wxALIGN_CENTER|wxALL, 19 );


	bSizer1->Add( bSizer2, 1, wxEXPAND, 5 );

	wxBoxSizer* bSizer4;
	bSizer4 = new wxBoxSizer( wxHORIZONTAL );

	m_staticText2 = new wxStaticText( this, wxID_ANY, wxT("Sortuj po: "), wxDefaultPosition, wxDefaultSize, 0 );
	m_staticText2->Wrap( -1 );
	bSizer4->Add( m_staticText2, 0, wxALIGN_CENTER|wxLEFT, 170 );

	m_listBox = new wxListBox( this, wxID_ANY, wxDefaultPosition, wxSize( 130,-1 ), 0, NULL, 0 );
	m_listBox->Append( wxT("NICK") );
	m_listBox->Append( wxT("Obraz") );
	m_listBox->Append( wxT("Liczba podzia³ów") );
	m_listBox->Append( wxT("Czas") );
	m_listBox->Append( wxT("Liczba krok\u00F3w") );
	bSizer4->Add( m_listBox, 0, wxALIGN_CENTER|wxLEFT, 8 );



	bSizer1->Add( bSizer4, 1, wxEXPAND, 5 );

	m_scrolledWindow = new wxScrolledWindow( this, wxID_ANY, wxDefaultPosition, wxDefaultSize, wxHSCROLL|wxVSCROLL );
	m_scrolledWindow->SetScrollRate( 5, 5 );
	wxBoxSizer* bSizer6;
	bSizer6 = new wxBoxSizer( wxVERTICAL );

	m_grid = new wxGrid( m_scrolledWindow, wxID_ANY, wxDefaultPosition, wxSize( -1,-1 ), 0 );

	// Grid
	m_grid->CreateGrid( 0, 5 );
	m_grid->EnableEditing( false );
	m_grid->EnableGridLines( true );
	m_grid->EnableDragGridSize( false );
	m_grid->SetMargins( 0, 0 );

	// Columns
	m_grid->SetColSize( 0, 73 );
	m_grid->SetColSize( 1, 68 );
	m_grid->SetColSize( 2, 126 );
	m_grid->SetColSize( 3, 80 );
	m_grid->SetColSize( 4, 118 );
	m_grid->EnableDragColMove( false );
	m_grid->EnableDragColSize( true );
	m_grid->SetColLabelSize( 30 );
	m_grid->SetColLabelValue( 0, wxT("Nick") );
	m_grid->SetColLabelValue( 1, wxT("Obraz") );
	m_grid->SetColLabelValue( 2, wxT("Liczba podzia\u0142\u00F3w") );
	m_grid->SetColLabelValue( 3, wxT("Czas") );
	m_grid->SetColLabelValue( 4, wxT("Liczba krok\u00F3w") );
	m_grid->SetColLabelAlignment( wxALIGN_CENTER, wxALIGN_CENTER );

	// Rows
	m_grid->EnableDragRowSize( true );
	m_grid->SetRowLabelSize( 80 );
	m_grid->SetRowLabelAlignment( wxALIGN_CENTER, wxALIGN_CENTER );
		// Label Appearance

	// Cell Defaults
	m_grid->SetDefaultCellAlignment( wxALIGN_LEFT, wxALIGN_TOP );
	bSizer6->Add( m_grid, 0, wxALIGN_CENTER|wxALL, 5 );


	m_scrolledWindow->SetSizer( bSizer6 );
	m_scrolledWindow->Layout();
	bSizer6->Fit( m_scrolledWindow );
	bSizer1->Add( m_scrolledWindow, 6, wxEXPAND | wxALL, 5 );

	this->SetSizer( bSizer1 );
	this->Layout();

	this->Centre( wxBOTH );
	Set();
	// Connect Events
	m_listBox->Connect(wxEVT_COMMAND_LISTBOX_SELECTED, wxCommandEventHandler(MyDialog5::Sort), NULL, this);
}
using std::string;
using std::vector;
void split(const string& s, char delim, vector<string>& elems) {
	std::stringstream ss(s);
	string item;
	while (getline(ss, item, delim)) {
		elems.push_back(item);
	}
}
using namespace std::placeholders;
bool t(const User& a, const User& b, wxString c)
{
	if (c == "NICK")
	{
		return a._n < b._n;
	}
	else if (c == "Obraz")
	{
		return a._o < b._o;
	}
	else if (c == "Liczba po")
	{
		
		return a._lp._col * a._lp._row < b._lp._col* b._lp._row;
	}
	else if (c == "Czas")
	{
		if (a._czas._hr < b._czas._hr)
		{
			return true;
		}
		else if (a._czas._hr == b._czas._hr)
		{
			if (a._czas._min < b._czas._min)
			{
				return true;
			}
			else if (a._czas._min == b._czas._min)
			{
				if (a._czas._sec < b._czas._sec)
				{
					return true;
				}
				else
				{
					return false;
				}
			}
			else
			{
				return false;
			}
		}
		else
		{
			return false;
		}
	}
	else
	{
		return a._lk < b._lk;
	}
}
void MyDialog5::Sort(wxCommandEvent& event)
{
	auto g = std::bind(t, _1, _2, event.GetString());
	std::sort(std::begin(users), std::end(users), g);
	for (int i = 0; i < users.size(); i++)
	{
		m_grid->SetCellValue(i, 0, users[i]._n);
		m_grid->SetCellValue(i, 1, users[i]._o);
		m_grid->SetCellValue(i, 2, wxString::Format("%d", users[i]._lp._col) + "x" + wxString::Format("%d", users[i]._lp._col));
		m_grid->SetCellValue(i, 3, wxString::Format("%d", users[i]._czas._hr) + ":" + wxString::Format("%d", users[i]._czas._min)+":"+ wxString::Format("%d", users[i]._czas._sec));
		m_grid->SetCellValue(i, 4, wxString::Format("%d", users[i]._lk));
	}
}
void MyDialog5::Set()
{
	std::string line;
	std::ifstream myfile("DataBase.txt");

	int i = 0;
	if (myfile.is_open())
	{
		while (getline(myfile, line))
		{
			std::vector<std::string> p;
			split(line, ' ', p);
			m_grid->AppendRows(1);
			m_grid->SetCellValue(i, 0, p[0]);
			m_grid->SetCellValue(i, 1, p[1]);
			m_grid->SetCellValue(i, 2, p[2]+"x"+p[3]);
			m_grid->SetCellValue(i, 3, p[4] + ":" + p[5]+":"+p[6]);
			m_grid->SetCellValue(i, 4, p[7]);
			users.push_back(User(p[0], p[1], Division(atoi(p[2].c_str()), atoi(p[3].c_str())), Time(atoi(p[6].c_str()), atoi(p[5].c_str()), atoi(p[4].c_str())), atoi(p[7].c_str())));
			i++;
		}
		myfile.close();
	}
}
MyDialog5::~MyDialog5()
{
}
