#include <QtWidgets>
#include <QObject>
#include <QMainWindow>
#include <fstream>
#include <string>
#include "Headers/platform.h"

using namespace std;

class MainWindow : public QMainWindow
{
	Q_OBJECT
public :
	MainWindow();
	~MainWindow();

	void creerObjets();
	void creerMenus();
	void creerActions();
	void creerLayout();


private slots:
	void WhatYourName();
	void showScoreBoard();
	void fermer();
	void aPropos();
	void pbDemarrer_cliquee();
	void demarrer();
	void ok();
	void Uppercase(QString text);
	void NewGame();
private :
	QWidget* wgMainWidget;
	QWidget* wgHLayoutWidget;
	QVBoxLayout* vbLayout;
	QHBoxLayout* hbLayout;
	QLabel* lbControles;
	QLabel* lbBlank;
	QTextEdit* txteInfo;
	QPushButton* pbDemarrer;
	QComboBox* cbControles;
	Platform* _platform;

	//MENUS
	QMenu* menuFichier;
	QMenu* menuAide;
	QAction* actFermer;
	QAction* actScoreboard;
	QAction* actAPropos;

	//Scoreboard
	QWidget* ScoreBoard;
	QWidget* name;
	QWidget* wghLayout;
	QLabel* text;
	QLineEdit* Ans;
	QPushButton* OK;
	QHBoxLayout* HNameLayout;
	QVBoxLayout* NameLayout;
	QLabel* Title;
	QLabel* Number1;
	QLabel* Number2;
	QLabel* Number3;
	QLabel* Number4;
	QLabel* Number5;
	QPushButton* PBOk;
	QVBoxLayout* scLayout;
};