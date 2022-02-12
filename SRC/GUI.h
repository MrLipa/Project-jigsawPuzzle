///////////////////////////////////////////////////////////////////////////
// C++ code generated with wxFormBuilder (version Oct 26 2018)
// http://www.wxformbuilder.org/
//
// PLEASE DO *NOT* EDIT THIS FILE!
///////////////////////////////////////////////////////////////////////////

#pragma once

#include <wx/artprov.h>
#include <wx/xrc/xmlres.h>
#include <wx/panel.h>
#include <wx/gdicmn.h>
#include <wx/font.h>
#include <wx/colour.h>
#include <wx/settings.h>
#include <wx/string.h>
#include <wx/sizer.h>
#include <wx/bitmap.h>
#include <wx/image.h>
#include <wx/icon.h>
#include <wx/button.h>
#include <wx/stattext.h>
#include <wx/statbmp.h>
#include <wx/menu.h>
#include <wx/frame.h>
#include <wx/wxprec.h>
#include <random>
#include <iostream>
#include <string>
#include <vector>
#include <functional>
#include <numeric>
#include <cmath>
#include <algorithm>
#include <iomanip>
#include <thread>
#include <chrono>

using std::string;
using std::vector;
///////////////////////////////////////////////////////////////////////////
/**
Klasa Time reprezentujaca czas gry, posiadajaca konstruktory oraz nastepujace skladowe:
- _sec - liczba sekund
- _min - liczba minut
- _hr - liczba godzin
*/
class Time {
public:
	Time() = default;
	Time(int sec, int min, int hr) : _sec(sec), _min(min), _hr(hr) {}
	int _sec;
	int _min;
	int _hr;
};
/**
Klasa Division reprezentujaca liczbe podzialow obrazka i jednoczesnie trudnosc gry. Posiada konstruktory oraz nastepujace skladowe:
- _col - liczba kolumn
- _row - liczba wierszy
*/
class Division {
public:
	Division() = default;
	Division(int col, int row) : _col(col), _row(row) {}
	int _col;
	int _row;
};

using namespace std::placeholders;

///////////////////////////////////////////////////////////////////////////////
/// Class MyFrame1
///////////////////////////////////////////////////////////////////////////////
/**
Klasa MyFrame reprezentujaca glowny widok panelu, w ktorym trwa rozgrywka
*/
class MyFrame : public wxFrame
{
	protected:
		wxPanel* panel;
		wxButton* button_new_game;
		wxButton* button_preview;
		wxStaticText* text_time;
		wxStaticText* text_number_of_steps;
		wxStaticText* text_device;
		wxStaticText* text_output_time;
		wxStaticText* text_output_number_of_steps;
		wxStaticBitmap* bitmap;
		wxMenuItem* menu_choiceA;
		wxMenuItem* menu_choiceB;
		wxMenuBar* menubar;
		wxMenu* menu_menu;
		wxMenu* menu_about;
		
		
		enum
		{
			ID_MENU_WYBOR_A_1013 = 1013,
			ID_MENU_WYBOR_B_1014 = 1014,
		};


		/**
		Metoda wirtualna, ktora obsluguje zdarzenie klikniecia w przycisk Nowa Gra rozpoczynajac rozgrywke o ustalonej wersji oraz liczbie
		podzialow
		*/
		virtual void OnClickNewGame( wxCommandEvent& event ) { event.Skip(); }
		/**
		Metoda wirtualna, ktora obsluguje zdarzenie klikniecia w przycisk Podglad wyswietlajac prawidlowe ulozenie obrazka
		*/
		virtual void OnClickPreview( wxCommandEvent& event ) { event.Skip(); }
		/**
		Metoda wirtualna, ktora obsluguje zdarzenie klikniecia w przycisk Nowa Gra, znajdujace sie w pasku Menu, rozpoczynajac rozgrywke
		o ustalonej wersji oraz liczbie podzialow
		*/
		virtual void MenuNewGame( wxCommandEvent& event ) { event.Skip(); }
		/**
		Metoda wirtualna, ktora obsluguje zdarzenie klikniecia w przycisk Podglad, znajdujace sie w pasku Menu, wyswietlajac prawidlowe
		ulozenie obrazka
		*/
		virtual void MenuPreview( wxCommandEvent& event ) { event.Skip(); }
		/**
		Metoda wirtualna, ktora obsluguje zdarzenie klikniecia w przycisk Zmien Nick, znajdujace sie w pasku Menu, umozliwiajac graczowi
		dokonanie zmiany Nicku
		*/
		virtual void MenuChangeNick( wxCommandEvent& event ) { event.Skip(); }
		/**
		Metoda wirtualna, ktora obsluguje zdarzenie klikniecia w przycisk Zmien liczbe podzialow, znajdujace sie w pasku Menu, umozliwiajac
		graczowi dokonanie zmiany liczby podzialow
		*/
		virtual void MenuChangeDivision(wxCommandEvent& event) { event.Skip(); }
		/**
		Metoda wirtualna, ktora obsluguje zdarzenie klikniecia w przycisk Exit, znajdujace sie w pasku Menu, umozliwiajac graczowi opuszczenie
		gry
		*/
		virtual void MenuExit( wxCommandEvent& event ) { event.Skip(); }
		/**
		Metoda wirtualna, ktora obsluguje zdarzenie klikniecia w przycisk Info, znajdujace sie w pasku About, wyswietlajac podstawowe informacje
		o grze
		*/
		virtual void MenuInfo( wxCommandEvent& event ) { event.Skip(); }
		/**
		Metoda wirtualna, ktora obsluguje zdarzenie klikniecia w przycisk Ranking, znajdujace sie w pasku About, wyswietlajac ranking graczy,
		ktorzy skonczyli ukladanie danego obrazka
		*/
		virtual void MenuRanking(wxCommandEvent& event) { event.Skip(); }
		/**
		Metoda wirtualna, ktora obsluguje zdarzenie klikniecia w przycisk Help, znajdujace sie w pasku About, wyswietlajac pomocne informacje
		o programie razem z adresem kontaktowym
		*/
		virtual void MenuHelp( wxCommandEvent& event ) { event.Skip(); }
		/**
		Metoda wirtualna, ktora obsluguje zdarzenie klikniecia w przycisk Wersja 1, znajdujace sie w pasku Menu, pozwalajac graczowi na zmiane
		sposobu ukladania obrazka
		*/
		virtual void ChoiceA(wxCommandEvent& event) { event.Skip(); }
		/**
		Metoda wirtualna, ktora obsluguje zdarzenie klikniecia w przycisk Wersja 2, znajdujace sie w pasku Menu, pozwalajac graczowi na zmiane
		sposobu ukladania obrazka
		*/
		virtual void ChoiceB(wxCommandEvent& event) { event.Skip(); }



	public:
		wxStaticText* text_output_division;
		wxStaticText* text_nick;


		/**
		Konstruktor, ktory tworzy okno gry o podanych rozmiarach ( 1200,700 )
		*/
		MyFrame( wxWindow* parent, wxWindowID id = wxID_ANY, const wxString& title = wxEmptyString, const wxPoint& pos = wxDefaultPosition, const wxSize& size = wxSize( 1200,700 ), long style = wxDEFAULT_FRAME_STYLE|wxTAB_TRAVERSAL );
		/**
		Destruktor klasy MyFrame czyszczacy zaaalokowana pamiec
		*/
		~MyFrame();

};

