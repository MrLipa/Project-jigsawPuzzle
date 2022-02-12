///////////////////////////////////////////////////////////////////////////
// C++ code generated with wxFormBuilder (version Oct 26 2018)
// http://www.wxformbuilder.org/
//
// PLEASE DO *NOT* EDIT THIS FILE!
///////////////////////////////////////////////////////////////////////////

#pragma once

#include <wx/artprov.h>
#include <wx/xrc/xmlres.h>
#include <wx/string.h>
#include <wx/stattext.h>
#include <wx/gdicmn.h>
#include <wx/font.h>
#include <wx/colour.h>
#include <wx/settings.h>
#include <wx/sizer.h>
#include <wx/listbox.h>
#include <wx/grid.h>
#include <wx/scrolwin.h>
#include <wx/dialog.h>
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
#include <fstream>
#include <sstream>
#include "GUI.h"
///////////////////////////////////////////////////////////////////////////

class User {
public:
	User(string n, string o, Division lp, Time czas, int lk) : _n(n), _o(o), _lp(lp), _czas(czas), _lk(lk) {}
	string _n;
	string _o;
	Division _lp;
	Time _czas;
	int _lk;
};
///////////////////////////////////////////////////////////////////////////////
/// Class MyDialog5
///////////////////////////////////////////////////////////////////////////////
class MyDialog5 : public wxDialog
{
	protected:
		wxScrolledWindow* m_scrolledWindow;
		wxStaticText* m_staticText1;
		wxStaticText* m_staticText2;
		wxListBox* m_listBox;
		wxGrid* m_grid;
		/**
		Wektor przechowujacy dane wszystkich uzytkownikow, ktorzy z powodzeniem ukonczyli gre
		*/
		vector<User> users;
		/**
		Metoda sortujaca wektor Users wedlug podanej kolumny
		*/
		void Sort(wxCommandEvent& event);
		/**
		Metoda zapisujaca do pliku dane uzytkownika, ktory z powodzeniem ukonczyl gre
		*/
		void Set();
		

	public:
		/**
		Konstruktor, ktory tworzy okno rankingu o rozmiarze ( 600,550 )
		*/
		MyDialog5( wxWindow* parent, wxWindowID id = wxID_ANY, const wxString& title = wxEmptyString, const wxPoint& pos = wxDefaultPosition, const wxSize& size = wxSize( 600,550 ), long style = wxDEFAULT_DIALOG_STYLE );
		/**
		Destruktor klasy MyDialog5 czyszczacy zaalokowana pamiec
		*/
		~MyDialog5();

};

