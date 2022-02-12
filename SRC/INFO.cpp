///////////////////////////////////////////////////////////////////////////
// C++ code generated with wxFormBuilder (version Oct 26 2018)
// http://www.wxformbuilder.org/
//
// PLEASE DO *NOT* EDIT THIS FILE!
///////////////////////////////////////////////////////////////////////////

#include "INFO.h"

///////////////////////////////////////////////////////////////////////////

MyDialog2::MyDialog2( wxWindow* parent, wxWindowID id, const wxString& title, const wxPoint& pos, const wxSize& size, long style ) : wxDialog( parent, id, title, pos, size, style )
{
	this->SetSizeHints(wxDefaultSize, wxDefaultSize);

	wxBoxSizer* bSizer1;
	bSizer1 = new wxBoxSizer(wxVERTICAL);

	SetTitle(_("Uk\u0142adanka obrazkowa"));
	wxIcon mainicon;
	mainicon.LoadFile("ikona.ico", wxBITMAP_TYPE_ICO);
	SetIcon(mainicon);

	wxImage imag;
	imag.LoadFile("info.jpg");
	wxBitmap bitm(imag.Scale(100, 100));

	bitmap = new wxStaticBitmap(this, wxID_ANY, bitm, wxDefaultPosition, wxDefaultSize, 0);
	bSizer1->Add(bitmap, 0, wxALIGN_CENTER | wxTOP, 60);

	m_staticText1 = new wxStaticText(this, wxID_ANY, wxT("Sliding puzzle to jedyna w swoim rodzaju gra familijna, w której\ngracz ma za zadanie u³o¿enie kompletnego obrazka z jego \npomieszanych fragmentów. Uk³adanka obrazkowa wprowadzi ciê\nw wir emocjonuj¹cej, trzymaj¹cej w napiêciu rozgrywki, w której\nty sam decydujesz o poziomie trudnoœci. Ciesz siê prostot¹ gry, \nodkrywaj nowe plansze z zaskakuj¹cymi zdjêciami, podnoœ \npoprzeczkê zwiêkszaj¹c liczbê puzzli, powiêksz swoj¹ wiedzê \no œwiecie gry, zyskaj wy¿sze notowania w rankingu staraj¹c siê \nwykonaæ jak najmniejsza liczbê ruchów, stañ siê mistrzem \npuzzli. SprawdŸ czy podo³asz wyzwaniu. Wierzymy,\n¿e ¿aden level/poziom nie stanowi dla ciebie trudnoœci :)\n\nProjekt realizowany jako praca zaliczeniowa z przedmiotu \nPodstawy Grafiki Komputerowej z u¿yciem biblioteki wxWidgets\n\n\n"), wxDefaultPosition, wxDefaultSize, 0);
	m_staticText1->SetLabelMarkup(wxT("Sliding puzzle to jedyna w swoim rodzaju gra familijna  w której\ngracz ma za zadanie u³o¿enie kompletnego obrazka z jego \npomieszanych fragmentów. Uk³adanka obrazkowa wprowadzi ciê\nw wir emocjonuj¹cej, trzymaj¹cej w napiêciu rozgrywki, w której\nty sam decydujesz o poziomie trudnoœci. Ciesz siê prostot¹ gry, \nodkrywaj nowe plansze z zaskakuj¹cymi zdjêciami, podnoœ \npoprzeczkê zwiêkszaj¹c liczbê puzzli, powiêksz swoj¹ wiedzê \no œwiecie gry, zyskaj wy¿sze notowania w rankingu staraj¹c siê \nwykonaæ jak najmniejsza liczbê ruchów, stañ siê mistrzem \npuzzli. SprawdŸ czy podo³asz wyzwaniu. Wierzymy,\n¿e ¿aden level/poziom nie stanowi dla ciebie trudnoœci :)\n\nProjekt realizowany jako praca zaliczeniowa z przedmiotu \nPodstawy Grafiki Komputerowej z u¿yciem biblioteki wxWidgets\n\n\n"));
	m_staticText1->Wrap(-1);
	bSizer1->Add(m_staticText1, 0, wxALIGN_CENTER | wxTOP, 50);

	m_staticText2 = new wxStaticText(this, wxID_ANY, wxT("Autorzy:\nTomasz Szkaradek,\nMonika Kidawska ,\n£ukasz Wajda.\n"), wxDefaultPosition, wxDefaultSize, 0);
	m_staticText2->Wrap(-1);
	bSizer1->Add(m_staticText2, 0, wxALIGN_CENTER | wxALL, 5);


	this->SetSizer(bSizer1);
	this->Layout();

	this->Centre(wxBOTH);
}


MyDialog2::~MyDialog2()
{
}
