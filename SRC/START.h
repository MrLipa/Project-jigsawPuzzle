///////////////////////////////////////////////////////////////////////////
// C++ code generated with wxFormBuilder (version Oct 26 2018)
// http://www.wxformbuilder.org/
//
// PLEASE DO *NOT* EDIT THIS FILE!
///////////////////////////////////////////////////////////////////////////

#pragma once

#include <wx/artprov.h>
#include <wx/xrc/xmlres.h>
#include <wx/bitmap.h>
#include <wx/image.h>
#include <wx/icon.h>
#include <wx/statbmp.h>
#include <wx/gdicmn.h>
#include <wx/font.h>
#include <wx/colour.h>
#include <wx/settings.h>
#include <wx/string.h>
#include <wx/stattext.h>
#include <wx/textctrl.h>
#include <wx/sizer.h>
#include <wx/button.h>
#include <wx/dialog.h>
#include <wx/wxprec.h>
#include "GUI.h"

///////////////////////////////////////////////////////////////////////////


///////////////////////////////////////////////////////////////////////////////
/// Class MyDialog1
///////////////////////////////////////////////////////////////////////////////
class MyDialog1 : public wxDialog
{
	protected:
		wxStaticText* staticText1;
		wxStaticText* staticText2;
		wxStaticBitmap* bitmap;
		wxTextCtrl* textCtrl;
		wxButton* button_start;
		

	public:
		/**
		Metoda, ktora zamyka okno startowe oraz ustawia wpisany przez gracza nick
		*/
		void Start(wxCommandEvent& event);
		/**
		Konstruktor, ktory tworzy okno startowe o rozmiarze ( 600,500 )
		*/
		MyDialog1( wxWindow* parent, wxWindowID id = wxID_ANY, const wxString& title = wxEmptyString, const wxPoint& pos = wxDefaultPosition, const wxSize& size = wxSize( 600,500 ), long style = wxDEFAULT_DIALOG_STYLE );
		/**
		Destruktor klasy MyDialog1 czyszczacy zaaalokowana pamiec
		*/
		~MyDialog1();

};

