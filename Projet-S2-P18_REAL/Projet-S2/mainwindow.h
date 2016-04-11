#include <QtWidgets>
#include <QObject>
#include <QMainWindow>
#include <fstream>
#include <string>
#include "platform.h"

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
	void showScoreBoard();
	void fermer();
	void aPropos();
	void pbDemarrer_cliquee();
	void demarrer();

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
};