#include "MyFrame.h"
#include "enumeration.cpp"

/////////////////Constructeur ////////////////////////
MyFrame::MyFrame(const wxString& title, const wxPoint& pos, const wxSize& size)
: wxFrame(NULL, wxID_ANY, title, pos, size){
    m_panel = new MyPanel(this);

    Center();
    //---------------------------------------------------------------------------------------------------
	wxMenu *menuFile = new wxMenu ;
	menuFile->Append(ID_Hello, wxT("Hello...\tCtrl-H")) ;
	Bind(wxEVT_MENU, &MyFrame::OnHello, this, ID_Hello) ;

	menuFile->Append(ID_Truc, wxT("Je suis ...\tShift-J")) ;
	Bind(wxEVT_MENU, &MyFrame::OnSuperbe, this, ID_Truc) ;

	menuFile->Append(ID_Plus_Large, wxT("Plus large\tCtrl-+")) ;
	Bind(wxEVT_MENU, &MyFrame::OnResize, this, ID_Plus_Large) ;

	menuFile->Append(ID_Moins_large, wxT("Moins Large\tCtrl--")) ;
	Bind(wxEVT_MENU, &MyFrame::OnResize, this, ID_Moins_large) ;

	menuFile->Append(ID_Open, wxT("Open image ...\tCtrl-o")) ;
	Bind(wxEVT_MENU, &MyFrame::OnOpenImage, this, ID_Open) ;

	menuFile->Append(ID_OpenDefault, wxT("Open default image ...\tALT-o")) ;
	Bind(wxEVT_MENU, &MyFrame::OnOpenImageDefault, this, ID_OpenDefault) ;

	menuFile->Append(ID_Save, wxT("Save image ...\tCtrl-s")) ;
	Bind(wxEVT_MENU, &MyFrame::OnSave, this, ID_Save) ;

	menuFile->Append(wxID_EXIT) ;
	Bind(wxEVT_MENU, &MyFrame::OnExit, this, wxID_EXIT) ;
    //---------------------------------------------------------------------------------------------------

	Bind(wxEVT_MOTION, &MyFrame::OnMouse,this);
    //---------------------------------------------------------------------------------------------------


	wxMenu *menuProcess = new wxMenu ;

	menuProcess->Append(ID_Mirror_hor, wxT("Effet miroir horizontal\tCtrl-m"));
	Bind(wxEVT_MENU,&MyFrame::OnProcess, this, ID_Mirror_hor);

	menuProcess->Append(ID_Mirror_ver, wxT("Effet miroir vertical\tCtrl-Shift-m"));
	Bind(wxEVT_MENU,&MyFrame::OnProcess, this, ID_Mirror_ver);

	menuProcess->Append(ID_Blur, wxT("Effet Blur\tCtrl-b"));
	Bind(wxEVT_MENU,&MyFrame::OnProcess, this, ID_Blur);

	menuProcess->Append(ID_Anti_Blur, wxT("Effet Antiblur\tCtrl-Shift-b"));
	Bind(wxEVT_MENU,&MyFrame::OnProcess, this, ID_Anti_Blur);

	menuProcess->Append(ID_Rotate, wxT("Effet rotation +90°\tCtrl-r"));
	Bind(wxEVT_MENU,&MyFrame::OnProcess, this, ID_Rotate);

    menuProcess->Append(ID_Negatif, wxT("Effet negatif\tAlt-n"));
	Bind(wxEVT_MENU,&MyFrame::OnProcess, this, ID_Negatif);

	menuProcess->Append(ID_Desaturate, wxT("désaturation\tAlt-d"));
	Bind(wxEVT_MENU,&MyFrame::OnProcess, this, ID_Desaturate);

	menuProcess->Append(ID_Seuil, wxT("Seuillage\tAlt-s"));
	Bind(wxEVT_MENU,&MyFrame::OnProcess, this, ID_Seuil);

	menuProcess->Append(ID_Mirror_hor_main, wxT("Mirroir horizontal fait main\tAlt-m"));
	Bind(wxEVT_MENU,&MyFrame::OnProcess, this, ID_Mirror_hor_main);

	menuProcess->Append(ID_Mirror_ver_main, wxT("Mirroir vertical fait main\tAlt-Shift-m"));
	Bind(wxEVT_MENU,&MyFrame::OnProcess, this, ID_Mirror_ver_main);

	menuProcess->Append(ID_Rotate90Main, wxT("Rotation 90 fait main\tAlt-r"));
	Bind(wxEVT_MENU,&MyFrame::OnProcess, this, ID_Rotate90Main);

	menuProcess->Append(ID_Posterize, wxT("Faire un posterize\tAlt-k"));
	Bind(wxEVT_MENU,&MyFrame::OnProcess, this, ID_Posterize);

	menuProcess->Append(ID_Histogramme, wxT("Faire un histogramme\tAlt-h"));
	Bind(wxEVT_MENU,&MyFrame::OnProcess, this, ID_Histogramme);



    //---------------------------------------------------------------------------------------------------

	wxMenu *menuHelp = new wxMenu ;

	menuHelp->Append(ID_Truc, wxT("En construction ...")) ;
    //---------------------------------------------------------------------------------------------------


	wxMenuBar *menuBar = new wxMenuBar ;
	menuBar->Append(menuFile, wxT("File" )) ;
	menuBar->Append(menuProcess, wxT("Process" )) ;
	menuBar->Append(menuHelp, wxT("Help"));
	SetMenuBar(menuBar) ;



	//wxStatusBar *stat = new wxStatusBar();
	//stat->SetStatusText(wxT("une belle bar de statut"));
	//this->SetStatusBar(stat);

	CreateStatusBar();
}

void MyFrame::OnHello(wxCommandEvent& event)
{
	wxLogMessage(wxT("Hello world from wxWidgets!"));

}

void MyFrame::OnSuperbe(wxCommandEvent& event)
{
	wxLogMessage(wxT("Je suis superbe"));
}

void MyFrame::OnResize(wxCommandEvent& event)
{
    wxSize size = GetSize();
    int delta;
    if(event.GetId() == ID_Moins_large){
        delta = -100;    }
    if(event.GetId() == ID_Plus_Large){
        delta = 100;    }

    if(size.GetWidth() > 0){
        size.SetWidth(size.GetWidth() + delta);
    }
    if(size.GetHeight() > 0){
        size.SetHeight(size.GetHeight()+ delta);
    }
    this->SetSize(size);
}

void MyFrame::OnMouse(wxMouseEvent& event){
    //wxEVT_MOTION
    wxPoint coord = event.GetPosition();
    //char str[100] = coord;
    wxString s;
    s.sprintf("x : %d / y : %d",coord.x, coord.y);
    SetStatusText(s);
}

void MyFrame::OnOpenImage(wxCommandEvent& event){
    wxString path = wxFileSelector(wxT("choisir une image"));
    SetStatusText(path);
    if(!path.empty()){
        m_panel->OpenImage(path);
    }
}

void MyFrame::OnOpenImageDefault(wxCommandEvent& event){
    m_panel->OpenImage(wxT("/users/info/etu-s4/rueth/M4105C/tp4/default.jpg"));
}

void MyFrame::OnSave(wxCommandEvent& event)
{
	//wxLogMessage(wxT("Je suis sauvegarde"));
	wxString path = wxSaveFileSelector("image","jpeg");
	path += wxT(".jpeg");
    if(!path.empty()){
        this->m_panel->OnSaveFile(path);
    }
}

void MyFrame::OnExit(wxCommandEvent& event)
{
	Close( true );
}

void MyFrame::OnProcess(wxCommandEvent& event){
    if(m_panel->isImage()){

        switch (event.GetId()){
        case ID_Mirror_hor:
            m_panel->OnMirror(ID_Mirror_hor);
            break;
        case ID_Mirror_ver:
            m_panel->OnMirror(ID_Mirror_ver);
            break;
        case ID_Blur:
            m_panel->OnBlur(ID_Blur);
            break;
        case ID_Anti_Blur:
            m_panel->OnBlur(ID_Anti_Blur);
            break;
        case ID_Rotate:
            m_panel->OnRotate();
            break;
        case ID_Negatif:
            //t = clock();
            m_panel->OnNegatif();
            //t = clock() - t;
            /*wxString s;
            s.sprintf("%d",t);
            SetStatusText(s);*/
            break;
        case ID_Desaturate:
            m_panel->OnDesaturate();
            break;
        case ID_Seuil:
            m_panel->OnSeuil();
            break;
        case ID_Mirror_hor_main:
            m_panel->OnMirrorMain(ID_Mirror_hor_main);
            break;
        case ID_Mirror_ver_main:
            m_panel->OnMirrorMain(ID_Mirror_ver_main);
            break;
        case ID_Rotate90Main:
            m_panel->OnRotate90Main();
            break;
        case ID_Posterize:
            m_panel->OnPosterize();
            break;
        case ID_Histogramme:
            m_panel->OnHistogramme();
            break;

        }
    }
}
