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
#include <wx/bitmap.h>
#include <wx/image.h>
#include <wx/icon.h>
#include <wx/button.h>
#include <wx/textctrl.h>
#include <wx/dialog.h>

///////////////////////////////////////////////////////////////////////////


///////////////////////////////////////////////////////////////////////////////
/// Class MyDialog4
///////////////////////////////////////////////////////////////////////////////
class MyDialog4 : public wxDialog
{
	protected:
		wxStaticText* m_staticText1;
		wxStaticText* m_staticText2;
		wxStaticText* m_staticText3;
		wxStaticText* m_staticText4;
		wxTextCtrl* textCtrl1;
		wxTextCtrl* textCtrl2;
		wxButton* button_3x3;
		wxButton* button_5x5;
		wxButton* button_8x8;
		wxButton* button_10x10;
		wxButton* button_start;

		// Virtual event handlers, overide them in your derived class
		virtual void Size3x3(wxCommandEvent& event);
		virtual void Size5x5(wxCommandEvent& event);
		virtual void Size8x8(wxCommandEvent& event);
		virtual void Size10x10(wxCommandEvent& event);
		virtual void Start(wxCommandEvent& event);


	public:
		/**
		Konstruktor tworzacy okno o rozmiarze (800, 700), w ktorym dokonujemy wyboru liczby podzialow
		*/
		MyDialog4( wxWindow* parent, wxWindowID id = wxID_ANY, const wxString& title = wxEmptyString, const wxPoint& pos = wxDefaultPosition, const wxSize& size = wxSize( 800,700 ), long style = wxDEFAULT_DIALOG_STYLE );
		/**
		Destruktor klasy MyDialog4 czyszczacy zaaalokowana pamiec
		*/
		~MyDialog4();

};

