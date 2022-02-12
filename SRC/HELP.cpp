///////////////////////////////////////////////////////////////////////////
// C++ code generated with wxFormBuilder (version Oct 26 2018)
// http://www.wxformbuilder.org/
//
// PLEASE DO *NOT* EDIT THIS FILE!
///////////////////////////////////////////////////////////////////////////

#include "HELP.h"

///////////////////////////////////////////////////////////////////////////

MyDialog3::MyDialog3( wxWindow* parent, wxWindowID id, const wxString& title, const wxPoint& pos, const wxSize& size, long style ) : wxDialog( parent, id, title, pos, size, style )
{
	this->SetSizeHints(wxDefaultSize, wxDefaultSize);

	wxBoxSizer* bSizer1;
	bSizer1 = new wxBoxSizer(wxVERTICAL);

	SetTitle(_("Uk\u0142adanka obrazkowa"));
	wxIcon mainicon;
	mainicon.LoadFile("ikona.ico", wxBITMAP_TYPE_ICO);
	SetIcon(mainicon);

	wxImage imag;
	imag.LoadFile("help.jpg");
	wxBitmap bitm(imag.Scale(100, 100));

	bitmap = new wxStaticBitmap(this, wxID_ANY, bitm, wxDefaultPosition, wxDefaultSize, 0);
	bSizer1->Add(bitmap, 0, wxALIGN_CENTER | wxTOP, 30);

	m_staticText1 = new wxStaticText(this, wxID_ANY, wxT("WPROWADZENIE:"), wxDefaultPosition, wxDefaultSize, 0);
	m_staticText1->Wrap(-1);
	m_staticText1->SetFont(wxFont(10, wxFONTFAMILY_SWISS, wxFONTSTYLE_NORMAL, wxFONTWEIGHT_BOLD, false, wxT("Arial")));

	bSizer1->Add(m_staticText1, 0, wxLEFT | wxTOP, 40);

	m_staticText2 = new wxStaticText(this, wxID_ANY, wxT("WprowadŸ NICK/NAZWÊ gracza oraz liczbê wierszy i kolumn do podzia³u obrazka.\nZatwierdŸ wybór przyciskiem START."), wxDefaultPosition, wxDefaultSize, 0);
	m_staticText2->Wrap(-1);
	bSizer1->Add(m_staticText2, 0, wxLEFT, 40);

	m_staticText3 = new wxStaticText(this, wxID_ANY, wxT("PODSTAWOWE STEROWANIE:"), wxDefaultPosition, wxDefaultSize, 0);
	m_staticText3->Wrap(-1);
	m_staticText3->SetFont(wxFont(10, wxFONTFAMILY_SWISS, wxFONTSTYLE_NORMAL, wxFONTWEIGHT_BOLD, false, wxT("Arial")));

	bSizer1->Add(m_staticText3, 0, wxLEFT, 40);

	m_staticText4 = new wxStaticText(this, wxID_ANY, wxT("Rozpocznij rozgrywkê klikaj¹c lewym przyciskiem myszy w pole NOWA GRA. \nW celu zmiany wersji gry, rozwiñ pasek Menu i dokonaj wyboru.\nWersja 1:\nAby przemieœciæ fragment obrazka w puste pole, wska¿ go kursorem i kliknij\nlewym przyciskiem myszy (oczywiœcie wskazany puzzel musi s¹siadowaæ\nz pustym polem).\nWersja 2: \nAby zamieniæ ze sob¹ dwa s¹siaduj¹ce fragmenty, kliknij w ramkê miedzy nimi. \nW celu przemieszczenia czterech s¹siaduj¹cych elementów kliknij \nw skrzy¿owanie ich krawêdzi. Po wskazaniu ramki przy krawêdzi planszy gry spowodujesz przesuniêcie ca³ego wiersza lub ca³ej kolumny.\nPoprawne u³o¿enie obrazka sygnalizowane jest zielon¹ ikonk¹ (znajduj¹c¹ siê\nw prawym panelu), a niepoprawne - czerwon¹.\nKlik. Klik. Klik. \nNaciœnij klawisz [Tab], w trakcie rozgrywki, aby  wyœwietliæ  na planszy gry\npoprawnie u³o¿ony obrazek. Ponowne wciœniêcie klawisza [Tab] przywraca\npoprzedni uk³ad planszy gry. \nAby zakoñczyæ grê wejdŸ w MENU->EXIT lub klikaj¹c lewym przyciskiem myszy\nw czerwony krzy¿yk w górnym lewym rogu ekranu. \n"), wxDefaultPosition, wxDefaultSize, 0);
	m_staticText4->Wrap(-1);
	bSizer1->Add(m_staticText4, 0, wxLEFT, 40);

	m_staticText5 = new wxStaticText(this, wxID_ANY, wxT("INNE:"), wxDefaultPosition, wxDefaultSize, 0);
	m_staticText5->Wrap(-1);
	m_staticText5->SetFont(wxFont(10, wxFONTFAMILY_SWISS, wxFONTSTYLE_NORMAL, wxFONTWEIGHT_BOLD, false, wxT("Arial")));

	bSizer1->Add(m_staticText5, 0, wxLEFT, 40);

	m_staticText6 = new wxStaticText(this, wxID_ANY, wxT("U³ó¿ obrazek w jak najmniejszej liczbie ruchów, w jak najkrótszym czasie \noraz w jak najwiêkszej liczbie puzzli, aby uzyskaæ wy¿sze notowania \nw rankingu. Przedstawione informacje zawarto w prawym panelu gry. \nPowodzenia. ¯yczymy udanej zabawy :)\n\nW razie dalszych problemów oraz pytañ proszê o pisemny kontakt \nz dzia³em obs³ugi klienta na adres mailowy: ITakNieOdpiszemy@gmail.com"), wxDefaultPosition, wxDefaultSize, 0);
	m_staticText6->Wrap(-1);
	bSizer1->Add(m_staticText6, 0, wxLEFT, 40);


	this->SetSizer(bSizer1);
	this->Layout();

	this->Centre(wxBOTH);
}

MyDialog3::~MyDialog3()
{
}
