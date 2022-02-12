#include "GUIMyFrame1.h"

GUIMyFrame1::GUIMyFrame1( wxWindow* parent ): MyFrame( parent )
{
	SetTitle(_("Uk³adanka obrazkowa"));
	wxIcon mainicon;
	mainicon.LoadFile("ikona.ico", wxBITMAP_TYPE_ICO);
	SetIcon(mainicon);
	SetSize(0, 0, 1000, 800);
	Bind(wxEVT_CHAR_HOOK, &GUIMyFrame1::TAB, this);
	WxTimer1 = new wxTimer();
	WxTimer1->SetOwner(this);
	Bind(wxEVT_TIMER, &GUIMyFrame1::Timer, this);
	panel->Bind(wxEVT_LEFT_UP, &GUIMyFrame1::Click,this);
	Bind(wxEVT_CLOSE_WINDOW, &GUIMyFrame1::OnExit, this);
	panel->Bind(wxEVT_MOTION, &GUIMyFrame1::Mouse_Move, this);
	dialog_START = nullptr;
	dialog_INFO = nullptr;
	dialog_HELP = nullptr;
	dialog_PARTITION = nullptr;
	dialog_RANKING = nullptr;
	flag = false;
	number_of_steps = height = width = 0;
	gametime._hr = gametime._min = gametime._sec = 0;
	division = Division(1, 1);
	step = 8;
	sort_degree = 30;
	Center();
	SetMinSize(GetSize());
	SetMaxSize(GetSize());
}

void GUIMyFrame1::OnClickNewGame( wxCommandEvent& event )
{
	Draw();
}
void GUIMyFrame1::OnClickPreview( wxCommandEvent& event )
{
	Preview();
}

void GUIMyFrame1::MenuNewGame(wxCommandEvent& event)
{
	Draw();
}

void GUIMyFrame1::MenuPreview(wxCommandEvent& event)
{
	Preview();
}

void GUIMyFrame1::MenuChangeNick(wxCommandEvent& event)
{
	dialog_START = new MyDialog1(this);
	dialog_START->ShowModal();
}

void GUIMyFrame1::MenuChangeDivision(wxCommandEvent& event)
{
	dialog_PARTITION = new MyDialog4(this);
	dialog_PARTITION->ShowModal();
	number_of_steps = 0;
	Draw();
}

void GUIMyFrame1::MenuExit(wxCommandEvent& event)
{
	Close(true);
}

void GUIMyFrame1::MenuInfo(wxCommandEvent& event)
{
	dialog_INFO = new MyDialog2(this);
	dialog_INFO->ShowModal();
}

void GUIMyFrame1::MenuRanking(wxCommandEvent& event)
{
	dialog_RANKING = new MyDialog5(this);
	dialog_RANKING->ShowModal();
}

void GUIMyFrame1::MenuHelp(wxCommandEvent& event)
{
	dialog_HELP = new MyDialog3(this);
	dialog_HELP->ShowModal();
}

void GUIMyFrame1::CallStart()
{
	dialog_START = new MyDialog1(this);
	dialog_START->ShowModal();
}

void GUIMyFrame1::CallDivision()
{
	dialog_PARTITION = new MyDialog4(this);
	dialog_PARTITION->ShowModal();
}

void GUIMyFrame1::ChoiceA(wxCommandEvent& event)
{
	Draw();
}

void GUIMyFrame1::ChoiceB(wxCommandEvent& event)
{
	Draw();
}

void GUIMyFrame1::OnExit(wxCloseEvent& event)
{
	if (wxMessageDialog(NULL, "Czy na pewno chcesz zamkn¹æ?", "Pytanie", wxOK | wxCANCEL).ShowModal() == wxID_OK) Destroy();
}

void GUIMyFrame1::TAB(wxKeyEvent& event)
{
	if (event.GetKeyCode()== 9)
	{
		Preview();
	}
}

void GUIMyFrame1::Mouse_Move(wxMouseEvent& event)
{
	if (menu_choiceA->IsChecked())
	{
		if((event.GetX() >= empty.x-step-width && event.GetX() <= empty.x - step && event.GetY() >= empty.y && event.GetY() <= empty.y + height) || (event.GetX() >= empty.x + step + width && event.GetX() <= empty.x + step +2*width && event.GetY() >= empty.y && event.GetY() <= empty.y + height) || (event.GetX() >= empty.x && event.GetX() <= empty.x + width && event.GetY() >= empty.y-step-height && event.GetY() <= empty.y -step) || (event.GetX() >= empty.x&& event.GetX() <= empty.x + width && event.GetY() >= empty.y+step+height && event.GetY() <= empty.y +step+ 2*height))
		{
			SetCursor(wxCursor(wxCURSOR_HAND));
		}
		else
		{
			SetCursor(wxCursor(wxCURSOR_ARROW));
		}
	}
	else
	{
		if (event.GetX() % (width + step) >= step && event.GetY() % (height + step) >= step)
		{
			SetCursor(wxCursor(wxCURSOR_ARROW));
		}
		else
		{
			SetCursor(wxCursor(wxCURSOR_HAND));
		}
	}
}

void GUIMyFrame1::StartTimer()
{
	if (WxTimer1->IsRunning())
	{
		gametime._sec = 0;
		gametime._min = 0;
		gametime._hr = 0;
	}
	else
	{
		WxTimer1->Start(1000);
	}
}

void GUIMyFrame1::Timer(wxTimerEvent& event)
{
	wxDateTime now = wxDateTime::Now();
	text_output_time->SetLabel(wxString::Format("%d", gametime._hr) + ":" + wxString::Format("%02d", gametime._min) + ":" + wxString::Format("%02d", gametime._sec));
	gametime._sec++;
	if (gametime._sec >= 60)
	{
		gametime._sec = 0;
		gametime._min++;
	}
	if (gametime._min >= 60)
	{
		gametime._min = 0;
		gametime._hr++;
	}
}

void GUIMyFrame1::Win()
{
	WxTimer1->Stop();
	std::ofstream file("DataBase.txt", std::ios_base::app);
	if (file.is_open())
	{
		file << "\n";
		file << nick << " ";
		file << name_of_image << " ";
		file << division._col << " ";
		file << division._row << " ";
		file << gametime._hr << " ";
		file << gametime._min << " ";
		file << gametime._sec << " ";
		file << number_of_steps;
		file.close();
	}
	wxImage ima;
	ima.LoadFile("correct.jpg");
	ima = ima.Scale(80, 80);
	wxBitmap bitm(ima);
	bitmap->SetBitmap(bitm);
	dialog_RANKING = new MyDialog5(this);
	dialog_RANKING->ShowModal();
}

void GUIMyFrame1::EndOfTheGame()
{
	int l = 0;
	bool end = true;
	wxImage image1 = image.Scale(panel->GetSize().GetWidth() - (division._col + 1) * step, panel->GetSize().GetHeight() - (division._row + 1) * step);
	for (int i = 0; i < division._row; i++)
	{
		for (int j = 0; j < division._col; j++)
		{
			if (menu_choiceA->IsChecked())
			{
				if (j != division._col - 1 || i != division._row - 1)
				{
					if (o[l]._pos != wxPoint((image1.GetWidth() / division._col) * j + step * j + step, (image1.GetHeight() / division._row) * i + step * i + step))
					{
						end = false;
						break;
					}
				}
				else
				{
					if (empty != wxPoint((image1.GetWidth() / division._col) * j + step * j + step, (image1.GetHeight() / division._row) * i + step * i + step))
					{
						end = false;
						break;
					}
				}
				l++;
			}
			else if (menu_choiceB->IsChecked())
			{
				if (o[l]._pos != wxPoint((image1.GetWidth() / division._col) * j + step * j + step, (image1.GetHeight() / division._row) * i + step * i + step))
				{
					end = false;
					break;
				}
				
				if (o[l]._mirror_hor || o[l]._mirror_ver)
				{
					end = false;
					break;
				}
				l++;
			}
		}
	}
	if (end) Win();
}


void GUIMyFrame1::Draw()
{
	wxImage ima;
	ima.LoadFile("wrong.jpg");
	ima = ima.Scale(90, 90);
	wxBitmap bitm(ima);
	bitmap->SetBitmap(bitm);
	
	o.clear();
	hor.clear();
	ver.clear();
	srand(time(0));
	wxClientDC MyDC(panel);
	MyDC.Clear();
	std::vector<std::string> t = { "Koala.jpg","Lipa.jpg", "Pengiuns.jpg"};
	int p = (rand() % (t.size() - 1));
	name_of_image = "";
	for (int i = 0; i < t[p].size()-4; i++)
	{
		name_of_image += t[p][i];
	}
	height = (panel->GetSize().GetHeight() - (division._row + 1) * step) / division._row;
	width = (panel->GetSize().GetWidth() - (division._col + 1) * step) / division._col;
	if (!image.LoadFile(t[p]))
	{
		wxMessageBox(_("Cannot open a file"));
	}
	else
	{
		image.LoadFile(t[p]);
	}
	
	int l = 0;
	wxImage image1 = image.Scale(panel->GetSize().GetWidth() - (division._col + 1) * step, panel->GetSize().GetHeight() - (division._row + 1) * step);
	for (int i = 0; i < division._row; i++)
	{
		for (int j = 0; j < division._col; j++)
		{
			if (j != division._col - 1 || i != division._row - 1)
			{
				wxRect square((image1.GetWidth() / division._col) * j, (image1.GetHeight() / division._row) * i, image1.GetWidth() / division._col, image1.GetHeight() / division._row);
				o.push_back(Picture(image1.GetSubImage(square), l, wxPoint((image1.GetWidth() / division._col) * j + step * j + step, (image1.GetHeight() / division._row) * i + step * i + step)));
				l++;
			}
			else
			{
				if (menu_choiceA->IsChecked())
				{
					empty.x = (image1.GetWidth() / division._col) * j + step * j + step;
					empty.y = (image1.GetHeight() / division._row) * i + step * i + step;
				}
				else
				{
					wxRect square((image1.GetWidth() / division._col)* j, (image1.GetHeight() / division._row)* i, image1.GetWidth() / division._col, image1.GetHeight() / division._row);
					o.push_back(Picture(image1.GetSubImage(square), l, wxPoint((image1.GetWidth() / division._col)* j + step * j + step, (image1.GetHeight() / division._row)* i + step * i + step)));
					l++;
				}
			}
		}
	}
	if (menu_choiceB->IsChecked())
	{
		for (int i = 0; i < division._row + 1; i++)
		{
			for (int j = 0; j < division._col; j++)
			{
				hor.push_back(wxPoint(step + j * (width + step), i * (step + height)));
			}
		}
		for (int i = 0; i < division._row; i++)
		{
			for (int j = 0; j < division._col + 1; j++)
			{
				ver.push_back(wxPoint(j * (step + width), step + i * (height + step)));
			}
		}
		for (int i = 0; i < division._row - 1; i++)
		{
			for (int j = 0; j < division._col - 1; j++)
			{
				mid.push_back(wxPoint(step + width + j * (step + width), step + height + i * (step + height)));
			}
		}
	}
	Mix();
	l = 0;
	for (int i = 0; i < division._row; i++)
	{
		for (int j = 0; j < division._col; j++)
		{
			if (j != division._col - 1 || i != division._row - 1)
			{

				wxBitmap bitmap(o[l]._image);
				MyDC.DrawBitmap(bitmap, o[l]._pos.x, o[l]._pos.y, true);
				l++;
			}
			else
			{
				if (menu_choiceB->IsChecked())
				{
					wxBitmap bitmap(o[l]._image);
					MyDC.DrawBitmap(bitmap, o[l]._pos.x, o[l]._pos.y, true);
					l++;
				}
			}
		}
	}
	number_of_steps = 0;
	text_output_number_of_steps->SetLabel(wxString::Format("%d", number_of_steps));
	flag = true;
	StartTimer();
}
void GUIMyFrame1::Preview()
{
	wxClientDC MyDC(panel);
	MyDC.Clear();
	int l = 0;
	wxImage image1 = image.Scale(panel->GetSize().GetWidth() - (division._col + 1) * step, panel->GetSize().GetHeight() - (division._row + 1) * step);
	if (flag == true)
	{
		for (int i = 0; i < division._row; i++)
		{
			for (int j = 0; j < division._col; j++)
			{
				if (menu_choiceB->IsChecked())
				{
					Picture temp = o[l];
					if (o[l]._mirror_ver)
					{
						temp._image = temp._image.Copy().Mirror(true);
					}
					if (o[l]._mirror_hor)
					{
						temp._image = temp._image.Copy().Mirror(false);
					}
					wxBitmap bitmap(temp._image);
					MyDC.DrawBitmap(bitmap, (image1.GetWidth() / division._col) * j + step * j + step, (image1.GetHeight() / division._row) * i + step * i + step, true);
					l++;
				}
				else if(j != division._col - 1 || i != division._row - 1)
				{
					wxBitmap bitmap(o[l]._image);
					MyDC.DrawBitmap(bitmap, (image1.GetWidth() / division._col) * j + step * j + step, (image1.GetHeight() / division._row) * i + step * i + step, true);
					l++;
				}
			}
		}
		flag = false;
	}
	else
	{
		for (int i = 0; i < division._row; i++)
		{
			for (int j = 0; j < division._col; j++)
			{
				if (j != division._col - 1 || i != division._row - 1)
				{
					wxBitmap bitmap(o[l]._image);
					MyDC.DrawBitmap(bitmap, o[l]._pos.x, o[l]._pos.y, true);
					l++;
				}
				else
				{
					if (menu_choiceB->IsChecked())
					{
						wxBitmap bitmap(o[l]._image);
						MyDC.DrawBitmap(bitmap, o[l]._pos.x, o[l]._pos.y, true);
						l++;
					}
				}
			}
		}
		flag = true;
	}
}


bool invec(const Picture& a,int h,int w)
{
	return (a._pos.x <= h && h<= a._image.GetHeight() + a._pos.x && a._pos.y <= w && w <= a._image.GetWidth()+ a._pos.y);
}
bool invec2(const Picture& a, int h, int w)
{
	return (a._pos.x == h && a._pos.y==w);
}
bool invec1(const wxPoint& a, int h, int w,char p,int height,int width,int step)
{
	if (p == 'h')
	{
		return (a.x <= h && h <= a.x+ width && a.y <= w && w <= a.y + step);
	}
	else if (p == 'v')
	{
		return (a.x <= h && h <= a.x + step && a.y <= w && w <= a.y + height);
	}
	else
	{
		return (a.x <= h && h <= a.x + step && a.y <= w && w <= a.y + step);
	}
}
void GUIMyFrame1::Click(wxMouseEvent& event)
{
	Click1(event.GetX(), event.GetY());
	number_of_steps++;
	text_output_number_of_steps->SetLabel(wxString::Format("%d", number_of_steps));
	EndOfTheGame();
}
void GUIMyFrame1::Click1(int x,int y)
{
	if (menu_choiceB->IsChecked())
	{
		int l = 0;
		wxClientDC MyDC(panel);
		int height = (panel->GetSize().GetHeight() - (division._row + 1) * step) / division._row;
		int width = (panel->GetSize().GetWidth() - (division._row + 1) * step) / division._col;
		auto t = std::bind(invec1, _1, x, y, 'h', height, width, step);
		auto result3 = std::find_if(std::begin(hor), std::end(hor), t);
		if (result3 == std::end(hor))
		{
			t = std::bind(invec1, _1, x, y, 'v', height, width, step);
			result3 = std::find_if(std::begin(ver), std::end(ver), t);
			if (result3 == std::end(ver))
			{
				t = std::bind(invec1, _1, x, y, 'm', height, width, step);
				result3 = std::find_if(std::begin(mid), std::end(mid), t);
				if (result3 == std::end(mid))
				{
					return;
				}
				else
				{
					auto t1 = std::bind(invec2, _1, result3->x - width, result3->y - height);
					auto result1 = std::find_if(std::begin(o), std::end(o), t1);
					auto t2 = std::bind(invec2, _1, result3->x + step, result3->y - height);
					auto result2 = std::find_if(std::begin(o), std::end(o), t2);
					auto t3 = std::bind(invec2, _1, result3->x - width, result3->y + step);
					auto result5 = std::find_if(std::begin(o), std::end(o), t3);
					auto t4 = std::bind(invec2, _1, result3->x + step, result3->y + step);
					auto result4 = std::find_if(std::begin(o), std::end(o), t4);
					result1->_image = result1->_image.Copy().Mirror(true);
					result2->_image = result2->_image.Copy().Mirror(true);
					result1->_mirror_ver = !result1->_mirror_ver;
					result2->_mirror_ver = !result2->_mirror_ver;
					std::swap(result1->_pos, result2->_pos);
					result5->_image = result5->_image.Copy().Mirror(false);
					result2->_image = result2->_image.Copy().Mirror(false);
					result5->_mirror_hor = !result5->_mirror_hor;
					result2->_mirror_hor = !result2->_mirror_hor;
					std::swap(result5->_pos, result2->_pos);
					result4->_image = result4->_image.Copy().Mirror(true);
					result2->_image = result2->_image.Copy().Mirror(true);
					result4->_mirror_ver = !result4->_mirror_ver;
					result2->_mirror_ver = !result2->_mirror_ver;
					std::swap(result4->_pos, result2->_pos);
					for (int i = 0; i < division._row; i++)
					{
						for (int j = 0; j < division._col; j++)
						{
							wxBitmap bitmap(o[l]._image);
							MyDC.DrawBitmap(bitmap, o[l]._pos.x, o[l]._pos.y, true);
							l++;
						}
					}
				}
			}
			else
			{
				if (result3->x == 0)
				{
					for (int i = 0; i < division._col - 1; i++)
					{
						auto t11 = std::bind(invec2, _1, 0 + step, result3->y);
						auto result11 = std::find_if(std::begin(o), std::end(o), t11);
						auto t12 = std::bind(invec2, _1, 0 + step + (division._col - 1 - i) * (step + width), result3->y);
						auto result12 = std::find_if(std::begin(o), std::end(o), t12);
						std::swap(result11->_pos, result12->_pos);
					}
				}
				else if (result3->x == division._col*(step + width))
				{
					for (int i = 0; i < division._col - 1; i++)
					{
						auto t11 = std::bind(invec2, _1, 0 + step + (division._col - 1) * (step + width), result3->y);
						auto result11 = std::find_if(std::begin(o), std::end(o), t11);
						auto t12 = std::bind(invec2, _1, 0 + step + (i) * (step + width), result3->y);
						auto result12 = std::find_if(std::begin(o), std::end(o), t12);
						std::swap(result11->_pos, result12->_pos);
					}
				}
				else
				{
					auto t11 = std::bind(invec2, _1, result3->x-width, result3->y);
					auto result11 = std::find_if(std::begin(o), std::end(o), t11);
					auto t12 = std::bind(invec2, _1, result3->x +step, result3->y);
					auto result12 = std::find_if(std::begin(o), std::end(o), t12);
					result12->_image= result12->_image.Copy().Mirror(true);
					result11->_image = result11->_image.Copy().Mirror(true);
					result11->_mirror_ver = !result11->_mirror_ver;
					result12->_mirror_ver = !result12->_mirror_ver;
					std::swap(result11->_pos, result12->_pos);
				}
				for (int i = 0; i < division._row; i++)
				{
					for (int j = 0; j < division._col; j++)
					{
						wxBitmap bitmap(o[l]._image);
						MyDC.DrawBitmap(bitmap, o[l]._pos.x, o[l]._pos.y, true);
						l++;
					}
				}
			}
		}
		else
		{
			if (result3->y == 0)
			{
				for (int i = 0; i < division._row - 1; i++)
				{
					auto t11 = std::bind(invec2, _1, result3->x, 0 + step);
					auto result11 = std::find_if(std::begin(o), std::end(o), t11);
					auto t12 = std::bind(invec2, _1, result3->x, 0 + step + (division._row - 1 - i) * (step + height));
					auto result12 = std::find_if(std::begin(o), std::end(o), t12);
					std::swap(result11->_pos, result12->_pos);
				}
			}
			else if (result3->y == division._row * (step + height))
			{
				for (int i = 0; i < division._row - 1; i++)
				{
					auto t11 = std::bind(invec2, _1, result3->x, 0 + step + (division._row - 1) * (step + height));
					auto result11 = std::find_if(std::begin(o), std::end(o), t11);
					auto t12 = std::bind(invec2, _1, result3->x, 0 + step + (i) * (step + height));
					auto result12 = std::find_if(std::begin(o), std::end(o), t12);
					std::swap(result11->_pos, result12->_pos);
				}
			}
			else
			{
				auto t11 = std::bind(invec2, _1, result3->x, result3->y-height);
				auto result11 = std::find_if(std::begin(o), std::end(o), t11);
				auto t12 = std::bind(invec2, _1, result3->x, result3->y+step);
				auto result12 = std::find_if(std::begin(o), std::end(o), t12);
				result12->_image = result12->_image.Copy().Mirror(false);
				result11->_image = result11->_image.Copy().Mirror(false);
				result11->_mirror_hor = !result11->_mirror_hor;
				result12->_mirror_hor = !result12->_mirror_hor;
				std::swap(result11->_pos, result12->_pos);
			}
			for (int i = 0; i < division._row; i++)
			{
				for (int j = 0; j < division._col; j++)
				{
					wxBitmap bitmap(o[l]._image);
					MyDC.DrawBitmap(bitmap, o[l]._pos.x, o[l]._pos.y, true);
					l++;
				}
			}
		}

	}
	else
	{
		auto t = std::bind(invec, _1, x, y);
		int height = (panel->GetSize().GetHeight() - (division._row + 1) * step) / division._row;
		int width = (panel->GetSize().GetWidth() - (division._row + 1) * step) / division._col;
		auto result3 = std::find_if(std::begin(o), std::end(o), t);
		if (result3 == std::end(o))
		{
			return;
		}
		bool left = false, right = false, up = false, down = false;
		if (result3->_pos.x - step - width == empty.x && result3->_pos.y == empty.y)
		{
			left = true;
		}
		else if (result3->_pos.x + step + width == empty.x && result3->_pos.y == empty.y)
		{
			right = true;
		}
		else if (result3->_pos.x == empty.x && result3->_pos.y - step - height == empty.y)
		{
			up = true;
		}
		else if (result3->_pos.x == empty.x && result3->_pos.y + step + height == empty.y)
		{
			down = true;
		}
		if (left == true || right == true || down == true || up == true)
		{
			int l = 0;
			wxClientDC MyDC(panel);
			const wxRect* square = new wxRect(result3->_pos.x, result3->_pos.y, width, height);
			std::swap(empty, result3->_pos);
			int xPos = empty.x;
			int yPos = empty.y;
			wxRect blank;
			wxImage frame = o[0]._image;
			frame.SetRGB(blank, panel->GetBackgroundColour().Red(), panel->GetBackgroundColour().Green(), panel->GetBackgroundColour().Blue());

			for (int i = 0; i < division._row; i++)
			{
				for (int j = 0; j < division._col; j++)
				{
					if (j != division._col - 1 || i != division._row - 1)
					{
						wxBitmap bitmap(o[l]._image);
						if (left && result3->_id == o[l]._id)
						{
							frame.Rescale(step, o[0]._image.GetHeight());
							wxBitmap frameBitmap(frame);
							while (xPos >= o[l]._pos.x)
							{
								MyDC.DrawBitmap(bitmap, xPos, o[l]._pos.y, true);
								MyDC.DrawBitmap(frameBitmap, xPos + width, o[l]._pos.y, true);
								xPos--;
								std::this_thread::sleep_for(std::chrono::microseconds(4));
							}
						}
						else if (right && result3->_id == o[l]._id)
						{
							frame.Rescale(step, o[0]._image.GetHeight());
							wxBitmap frameBitmap(frame);
							while (xPos <= o[l]._pos.x)
							{
								MyDC.DrawBitmap(bitmap, xPos, o[l]._pos.y, true);
								MyDC.DrawBitmap(frameBitmap, xPos - step, o[l]._pos.y, true);
								xPos++;
								std::this_thread::sleep_for(std::chrono::microseconds(4));
							}
						}
						else if (down && result3->_id == o[l]._id)
						{
							frame.Rescale(o[0]._image.GetWidth(), step);
							wxBitmap frameBitmap(frame);
							while (yPos <= o[l]._pos.y)
							{
								MyDC.DrawBitmap(bitmap, o[l]._pos.x, yPos, true);
								MyDC.DrawBitmap(frameBitmap, o[l]._pos.x, yPos - step, true);
								yPos++;
								std::this_thread::sleep_for(std::chrono::microseconds(4));
							}
						}
						else if (up && result3->_id == o[l]._id)
						{
							frame.Rescale(o[0]._image.GetWidth(), step);
							wxBitmap frameBitmap(frame);
							while (yPos >= o[l]._pos.y)
							{
								MyDC.DrawBitmap(bitmap, o[l]._pos.x, yPos, true);
								MyDC.DrawBitmap(frameBitmap, o[l]._pos.x, yPos + height, true);
								yPos--;
								std::this_thread::sleep_for(std::chrono::microseconds(4));
							}
						}
						else MyDC.DrawBitmap(bitmap, o[l]._pos.x, o[l]._pos.y, true);
						l++;
					}
				}
			}
			panel->Refresh(true, square);
		}
	}
}
void GUIMyFrame1::Mix()
{
	int j = 0;
	if (menu_choiceB->IsChecked())
	{
		for (int i = 0; i < sort_degree; i++)
		{
			j = 0 + rand() % ((division._col + 1) * (division._row) - 1);
			Click1(ver[j].x, ver[j].y);
			j = 0 + rand() % ((division._col) * (division._row + 1) - 1);
			Click1(hor[j].x, hor[j].y);
			j = 0 + rand() % ((division._col - 1) * (division._row - 1) - 1);
			Click1(mid[j].x, mid[j].y);
		}
	}
	else
	{
		int n = o.size();
		for (int i = 0; i < n; i++)
		{
			int j = 0 + rand() % (n - 1);
			std::swap(o[i]._pos, o[j]._pos);
		}
	}
}