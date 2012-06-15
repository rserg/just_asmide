#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QObject>
#include "qscilexerasm.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    setWindowTitle("ASM EDITOR");
    //statusBar()->showMessage("READY");
    qsci = new QsciScintilla;
    qsci->setUtf8(true);
    setCentralWidget(qsci);
    QsciLexerAsm * lexCpp = new QsciLexerAsm(this);
    qsci->setLexer(lexCpp);
    qsci->setCaretLineBackgroundColor(Qt::gray);
    qsci->setMarginsBackgroundColor(Qt::black);
    qsci->setUtf8(true);
    qsci->setCaretLineVisible(true);
    qsci->setIndentationGuides(true);
    qsci->setFirstVisibleLine(0);
    qsci->setFixedHeight(350);
    qsci->setAcceptDrops(false);
   // QsciLexerAsm::connect(&qsci, SIGNAL(qsci->linesChanged()));
   // QObject::connect(&qsci, SIGNAL(qsci->linesChanged()));

    qsci->setAutoIndent(true);
    qsci->setIndentationWidth(2);

    qsci->setMarginsBackgroundColor(QColor("gainsboro"));
    qsci->setMarginLineNumbers(1, true);
    qsci->setMarginWidth(1, 50);

    qsci->setUnmatchedBraceForegroundColor(Qt::blue);
    qsci->setIndentationsUseTabs(true);

    qsci->setBraceMatching(QsciScintilla::SloppyBraceMatch);
    qsci->setMatchedBraceBackgroundColor(Qt::yellow);
}

MainWindow::~MainWindow()
{
    delete ui;
}
