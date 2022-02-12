#include "GUI.h"
#include "GUIMyFrame1.h"

extern class GUIMyFrame1* mainFrame;
GUIMyFrame1* mainFrame;

class MyApp : public wxApp {

public:

	virtual bool OnInit();
	virtual int OnExit() { return 0; }

};

IMPLEMENT_APP(MyApp);

bool MyApp::OnInit()
{
	wxImage::AddHandler(new wxJPEGHandler);
	mainFrame = new GUIMyFrame1(NULL);
	mainFrame->CallStart();
	mainFrame->CallDivision();
	mainFrame->Show(true);
	mainFrame->Draw();
	SetTopWindow(mainFrame);
	return true;
}
void MyDialog1::Start(wxCommandEvent& event)
{
	bool f1 = true;
	for (int i = 0; i < textCtrl->GetValue().size(); i++)
	{
		if (!std::isalnum(textCtrl->GetValue()[i]))
		{
			f1 = false;
		}
	}
	if (textCtrl->GetValue().size() == 0)
	{
		f1 = false;
	}
	else if (f1 == true)
	{
		mainFrame->text_nick->SetLabel(textCtrl->GetValue());
		mainFrame->nick = textCtrl->GetValue();
		Close(true);
	}
	else
	{
		staticText2->SetPosition(wxPoint(245, 270));
		staticText2->Show();
	}
}

void MyDialog4::Start(wxCommandEvent& event)
{
	bool f1=true;
	for (int i = 0; i < textCtrl1->GetValue().size(); i++)
	{
		if (!std::isdigit(textCtrl1->GetValue()[i]))
		{
			f1 = false;
		}
	}
	for (int i = 0; i < textCtrl2->GetValue().size(); i++)
	{
		if (!std::isdigit(textCtrl2->GetValue()[i]))
		{
			f1 = false;
		}
	}
	if (atoi(std::string(textCtrl1->GetValue()).c_str()) <= 2 || atoi(std::string(textCtrl2->GetValue()).c_str()) <= 2)
	{
		f1 = false;
	}
	if (f1 == true)
	{
		mainFrame->division._col = atoi(std::string(textCtrl1->GetValue()).c_str());
		mainFrame->division._row = atoi(std::string(textCtrl2->GetValue()).c_str());
		mainFrame->text_output_division->SetLabel(textCtrl1->GetValue() + wxString::Format(" x ") + textCtrl2->GetValue());
		Close(true);
	}
	else
	{
		m_staticText3->SetPosition(wxPoint(350, 560));
		m_staticText3->Show();
	}
}