#include "Headers/mainwindow.h"
#include <QLatin1String>

using namespace std;

MainWindow::MainWindow()
{
	_platform = nullptr;
	//SETTINGS
	setWindowTitle("Projet P18");
	setFixedSize(421, 370);
	setGeometry(QStyle::alignedRect(Qt::LeftToRight, Qt::AlignCenter, size(), qApp->desktop()->availableGeometry()));
	statusBar()->show();
	creerObjets();
	creerLayout();
	creerActions();
	creerMenus();
}

MainWindow::~MainWindow()
{
	delete _platform;
}

void MainWindow::creerLayout()
{
	hbLayout->addWidget(lbControles, 0, Qt::AlignLeft);
	hbLayout->addWidget(cbControles, 0, Qt::AlignLeft);
	hbLayout->addWidget(lbBlank, 0, Qt::AlignLeft);
	wgHLayoutWidget->setLayout(hbLayout);

	vbLayout->addWidget(txteInfo);
	vbLayout->addWidget(wgHLayoutWidget);
	vbLayout->addWidget(pbDemarrer);

	wgMainWidget->setLayout(vbLayout);
	setCentralWidget(wgMainWidget);
}

void MainWindow::creerObjets()
{
	//Widgets
	wgMainWidget = new QWidget(this);
	wgHLayoutWidget = new QWidget(wgMainWidget);
	vbLayout = new QVBoxLayout(wgMainWidget);
	hbLayout = new QHBoxLayout(wgHLayoutWidget);

	//Demarrer bouton
	pbDemarrer = new QPushButton(wgMainWidget);
	pbDemarrer->setText(QLatin1String("Démarrer!"));
	pbDemarrer->setToolTip(QLatin1String("Démarrer le jeu"));
	connect(pbDemarrer, SIGNAL(clicked()), this, SLOT(pbDemarrer_cliquee()));

	//Controles label et combobox
	cbControles = new QComboBox(wgMainWidget);
	cbControles->addItem("FPGA");
	cbControles->addItem("Clavier");
	cbControles->setToolTip(QLatin1String("Choix de la méthode de contrôle pour le jeu"));
	lbBlank = new QLabel(wgMainWidget);
	lbControles = new QLabel(wgMainWidget);
	lbControles->setText(QLatin1String("Méthode de contrôles :"));

	//Informations controles texte
	txteInfo = new QTextEdit(wgMainWidget);
	txteInfo->setReadOnly(true);
	txteInfo->setPlainText(QLatin1String("Contrôles :\n\n"
		"- fpga :\n"
		"      - phonèmes :\n"
		"\tO -> mouvement gauche\n"
		"\tA -> mouvement droite\n"
		"\tShh -> utilisation power-ups\n"
		"      - boutons :\n"
		"\tbouton 3->mouvement gauche\n"
		"\tbouton 0->mouvement droite\n"
		"\tbouton 1->utilisation power-ups\n\n"
		"- clavier :\n"
		"      - mouvements : flèches de gauche et de droite\n"
		"      - utilisations des power-ups : flèche du haut\n\n"
		"Pour démarrer le jeu, appuyez sur le bouton Démarrer!"));
}

void MainWindow::creerMenus()
{
	//fichier
	menuFichier = menuBar()->addMenu(tr("&Fichier"));
	menuFichier->addAction(actScoreboard);
	menuFichier->addAction(actFermer);

	//setting
	menuEdition = menuBar()->addMenu(QLatin1String("Édition"));
	menuEdition->addAction(actVolume);
	//aide
	menuAide = menuBar()->addMenu(tr("&Aide"));
	menuAide->addAction(actAPropos);

	
}

void MainWindow::creerActions()
{
	actFermer = new QAction(this);
	actFermer->setText("Fermer");
	actFermer->setShortcut(QKeySequence(Qt::CTRL + Qt::Key_F));
	actFermer->setStatusTip(tr("Fermer le programme"));
	connect(actFermer, SIGNAL(triggered()), this, SLOT(fermer()));

	actScoreboard = new QAction(this);
	actScoreboard->setText("ScoreBoard");
	actScoreboard->setShortcut(QKeySequence(Qt::CTRL + Qt::Key_S));
	actScoreboard->setStatusTip(tr("Afficher la table des pointages"));
	connect(actScoreboard, SIGNAL(triggered()), this, SLOT(showScoreBoard()));

	actVolume = new QAction(this);
	actVolume->setText("Volumes");
	actVolume->setShortcut(QKeySequence(Qt::CTRL + Qt::Key_V));
	actVolume->setStatusTip(tr("Modifier Volume"));
	connect(actVolume,SIGNAL(triggered()),this,SLOT(ModifVolume()));

	actAPropos = new QAction(this);
	actAPropos->setText(QLatin1String("À propos"));
	actAPropos->setShortcut(QKeySequence(Qt::CTRL + Qt::Key_A));
	actAPropos->setStatusTip(tr("Informations sur le programme"));
	connect(actAPropos, SIGNAL(triggered()), this, SLOT(aPropos()));
}

void MainWindow::showScoreBoard()
{
	ifstream input;
	input.open("ScoreBoard.txt");
	
	string NAME;
	float SCORE;
	int COUNT = 0;
	while (!input.eof())
	{
		input >> SCORE >> NAME;
		COUNT++;
	}
	input.close();
	input.open("ScoreBoard.txt");
	int NPersonne = COUNT;
	string* name=new string[NPersonne];
	float* score=new float[NPersonne];
	int i;
	for (i = 0; i < NPersonne-1; i++)
		score[i] = 0;
	COUNT = 0;
	while (!input.eof())
	{
		input >> score[COUNT] >> name[COUNT];
		COUNT++;
	}
	input.close();

	int Ipivot = 0;
	float tempS;
	string tempN;
	while (Ipivot <=NPersonne)
	{
		COUNT = Ipivot + 1;
		for (COUNT; COUNT < NPersonne; COUNT++)
		{
			if (score[Ipivot]<score[COUNT])
			{
				tempS = score[Ipivot];
				tempN = name[Ipivot];
				score[Ipivot] = score[COUNT];
				name[Ipivot] = name[COUNT];
				score[COUNT] = tempS;
				name[COUNT] = tempN;
			}
		}
		Ipivot++;
	}

	QLabel* Title;
	QLabel* Number1;
	QLabel* Number2;
	QLabel* Number3;
	QLabel* Number4;
	QLabel* Number5;
	QPushButton* PBOk;
	
	QVBoxLayout* scLayout;

	statusBar()->showMessage(tr("Affichage du tableau des scores"));

	ScoreBoard = new QWidget();
	ScoreBoard->setFixedSize(270,200);
	ScoreBoard->setWindowTitle("Tableau de pointages");
	scLayout = new QVBoxLayout(ScoreBoard);

	Title = new QLabel(ScoreBoard);
	Title->setText(tr(" TOP 5 :"));
	Title->setAlignment(Qt::AlignCenter);
	scLayout->addWidget(Title);


	if (score[0] != 0)
	{
		Number1 = new QLabel(ScoreBoard);
		Number1->setAlignment(Qt::AlignCenter);
		Number1->setText(tr("1. ") + QString::fromStdString(name[0]) + tr(" ") + QString::number(score[0]));
		scLayout->addWidget(Number1);
	}

	if (NPersonne - 1>1)
	{
		Number2 = new QLabel(ScoreBoard);
		Number2->setAlignment(Qt::AlignCenter);
		Number2->setText(tr("2. ") + QString::fromStdString(name[1]) + tr(" ") + QString::number(score[1]));
		scLayout->addWidget(Number2);
	}

	if (NPersonne - 1>1)
	{
		Number3 = new QLabel(ScoreBoard);
		Number3->setAlignment(Qt::AlignCenter);
		Number3->setText(tr("3. ") + QString::fromStdString(name[2]) + tr(" ") + QString::number(score[2]));
		scLayout->addWidget(Number3);
	}

	if (NPersonne-1>3)
	{
		Number4 = new QLabel(ScoreBoard);
		Number4->setAlignment(Qt::AlignCenter);
		Number4->setText(tr("4. ") + QString::fromStdString(name[3]) + tr(" ") + QString::number(score[3]));
		scLayout->addWidget(Number4);
	}

	if (NPersonne-1>4)
	{
		Number5 = new QLabel(ScoreBoard);
		Number5->setAlignment(Qt::AlignCenter);
		Number5->setText(tr("5. ") + QString::fromStdString(name[4]) + tr(" ") + QString::number(score[4]));
		scLayout->addWidget(Number5);
	}
	
	PBOk = new QPushButton(ScoreBoard);
	PBOk->setText("OK");
	connect(PBOk,SIGNAL(clicked()), this, SLOT(NewGame()));
	scLayout->addWidget(PBOk);

	ScoreBoard->setLayout(scLayout);

	delete[] score;
	delete[] name;
	ScoreBoard->show();
}

void MainWindow::NewGame()
{
	ScoreBoard->close();
	if (_platform!=nullptr)
	{
		_platform->get_view()->close();
		delete _platform;
		_platform = nullptr;
		this->show();
	}
	
}

void MainWindow::fermer()
{
	statusBar()->showMessage(tr("Fermeture du programme"));
	exit(1);
}

void MainWindow::ModifVolume()
{
	MainVolume = new QWidget();
	QLabel* background=new QLabel(MainVolume);
	VMusicLayout = new QVBoxLayout(MainVolume);
	slider = new QSlider(Qt::Horizontal,MainVolume);
	pbVolume = new QPushButton(MainVolume);
	Valeur = new QLineEdit(MainVolume);

	background->setText("Volume de la musique principale:");
	VMusicLayout->addWidget(background);

	slider->setOrientation(Qt::Horizontal);
	slider->setMinimum(0);
	slider->setMaximum(100);
	slider->setSliderPosition(50);
	VMusicLayout->addWidget(slider);
	Valeur->setText("50");
	Valeur->setReadOnly(true);

	Valeur->setAlignment(Qt::AlignCenter);
	connect(slider, SIGNAL(valueChanged(int)),this, SLOT(onValueChanged()));
	connect(slider, SIGNAL(valueChanged(int)), this, SLOT(set_MusicVolume()));

	pbVolume->setText("OK");
	connect(pbVolume,SIGNAL(clicked()),MainVolume,SLOT(close()));
	VMusicLayout->addWidget(Valeur);
	VMusicLayout->addWidget(pbVolume);

	MainVolume->setLayout(VMusicLayout);
	MainVolume->show();
}


void MainWindow::aPropos()
{
	statusBar()->showMessage(QLatin1String("Affichage à propos"));
	QWidget* Win_aPropos;
	QVBoxLayout* VLayout;
	QPushButton* BoutonPropos;
	QTextEdit* Texte_Propos;

	Win_aPropos = new QWidget();
	VLayout = new QVBoxLayout(Win_aPropos);
	BoutonPropos  = new QPushButton(Win_aPropos);
	Texte_Propos = new QTextEdit(Win_aPropos);

	Win_aPropos->setWindowTitle(QLatin1String("À Propos"));
	Win_aPropos->setStatusTip(QLatin1String("À Propos"));
	Win_aPropos->setFixedSize(485, 200);

	Texte_Propos->setReadOnly(true);
	Texte_Propos->setPlainText(QLatin1String("Oh! Rich! Contre Aliens\n\n"
		" L'équipe INGENIUM NATUS a pour but dans ce projet d'exploiter\n"
		"la reconnaissance vocale afin "
		"de jouer à un jeu de style rétro dans l'univers de Star Wars.\n\n"
		"Dans ce jeux le joueur (BB8) a pour but de rester le plus longtemps\n "
		"en vie en évitant les lasers qui lui sont tirés dessus, ce dans une\n "
		"zone restreinte. "
		"L'utilisateur a deplus la possibilité d'utiliser des pouvoirs\n facilitant la partie au joueur.\n\n"
		"La musique provient du jeu Neon Drive et le style est fortement inspiré de Star Wars."
		));

	BoutonPropos->setText("OK");
	BoutonPropos->setToolTip(QLatin1String("Fermer la fenêtre"));
	connect(BoutonPropos,SIGNAL(clicked()),Win_aPropos,SLOT(close()));
	VLayout->addWidget(Texte_Propos);
	VLayout->addWidget(BoutonPropos);
	Win_aPropos->setLayout(VLayout);
	Win_aPropos->show();
}

void MainWindow::pbDemarrer_cliquee()
{
	statusBar()->showMessage(QLatin1String("Jeu demarré"));
	this->hide();
	_platform = new Platform();
	connect(_platform, SIGNAL(set_bg()), this, SLOT(set_bgMusic()));
	_platform->set_inputMode(cbControles->currentIndex());
	_platform->initializeGame();

	connect(_platform, SIGNAL(gameover()), this, SLOT(WhatYourName()));
	
}

void MainWindow::demarrer()
{
	statusBar()->showMessage(QLatin1String("Jeu demarré"));
}

void MainWindow::WhatYourName()
{
	name = new QWidget;
	wghLayout = new QWidget(name);
	text = new QLabel(name);
	Ans = new QLineEdit(name);
	OK = new QPushButton(name);
	HNameLayout = new QHBoxLayout(name);
	NameLayout = new QVBoxLayout(name);

	name->setWindowTitle("Nom pour tableau pointage");

	text->setText("Entrez votre surnom:");
	HNameLayout->addWidget(text);

	Ans->setReadOnly(false);
	Ans->setMaxLength(3);
	connect(Ans, SIGNAL(textChanged(QString)), this, SLOT(Uppercase(QString)));
	HNameLayout->addWidget(Ans);
	wghLayout->setLayout(HNameLayout);
	NameLayout->addWidget(wghLayout);

	OK->setText("OK");
	OK->setToolTip("confirmer le surnom");
	connect(OK, SIGNAL(clicked()), this, SLOT(ok()));
	NameLayout->addWidget(OK);

	name->setLayout(NameLayout);
	name->show();
}

void MainWindow::ok()
{
	ofstream output;
	output.open("ScoreBoard.txt", ios::app);
	QString contenu = Ans->text();
	string Contenu = contenu.toStdString();
	output << _platform->get_currentFrame() << " " << Contenu << "\n";
	name->close();
	output.close();
	showScoreBoard();
}

void MainWindow::Uppercase(QString text)
{
	QString tmp = text;

	tmp.truncate(1); // tmp is now first char of your text
	tmp = tmp.toUpper();

	if (text.size() > 1)
	{
		text.remove(0, 1);
		text = text.toUpper();
		text.prepend(tmp);
		Ans->setText(text);
	}
	else
	{
		Ans->setText(tmp);
	}
}
void MainWindow::onValueChanged()
{
	int pos = slider->sliderPosition();
	QString text = QString::number(pos);
	Valeur->setText(text);
}

void MainWindow::set_MusicVolume()
{
	int pos = slider->sliderPosition();
	MusicVolume = pos;
	
}

void MainWindow::set_bgMusic()
{
	_platform->set_BackgMusic(MusicVolume);
}