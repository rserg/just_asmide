#include "qscilexerasm.h"
#include <QColor>
#include <QFont>
#include <QtGui>
#include <Qsci/qsciscintilla.h>
#include <Qsci/qscistyle.h>
#include <QVector>

//http://www.riverbankcomputing.com/static/Docs/QScintilla2/annotated.html
//http://permalink.gmane.org/gmane.comp.lib.qt.qscintilla/51
//http://habrahabr.ru/post/144855/

QsciLexerAsm::QsciLexerAsm (QObject *parent):
    QsciLexerCustom(parent)
{


    wordslist << "mov" << "add" << "jmp" <<
                 "lea"<< "sub"<< "mul" << "imul" << "call"
              << "rep" << "ret" << "push" << "pop" <<
                 "loop" << "jz" << "jne" << "jo" << "ja" << "int"<<
                 "pushad" << "lea" << "add" << "and" << "or" << "inc"<<
                 "dec" << "je" << "ret";

    cmpwordslist << "cmp" << "test";

    //know registers
    knowfuncs << "eax" << "ebx" << "ecx" << "edx"
              <<"ebp" << "esi" << "esp";

}

QsciLexerAsm::~QsciLexerAsm ()
{

}


const char *QsciLexerAsm::language() const
{
    return "ASM";
}



QString QsciLexerAsm::description(int style) const
{
    switch(style)
    {
    case Default:
        return tr("Default");

    case Error:
        return tr("Error");

    case Keyword:
        return tr("Keyword");

    case CmpKeyword:
        return tr("CmpKeyword");

    case Function:
        return tr("Function");

    }

    return QString();
}


QsciStyle QsciLexerAsm::myStyle(int style)const
{
    return QsciStyle(style,"this",defaultColor(style),defaultPaper(),defaultFont(style),true);
}


void QsciLexerAsm::defaultPaint(QString data, QVector<QString> list, int start,int style)
{
    int cont = 0;
    foreach(QString str, list)
    {
        data = data.toLower();
        int len = data.count(str);
        for(int i = 0;i < len;++i)
        {
            int myfirst = data.indexOf(str + " ",cont);
            if(myfirst != -1)
            {
                cont += myfirst+1;
                this->startStyling(start+myfirst);
               // qDebug() << str;
                this->setStyling(str.length(), myStyle(style));
            }

            //this->startStyling(start+myfirst);
        }
    }
}


void QsciLexerAsm::colorFunctions(QString data, int start, int style)
{
    int cont = 0;
    int len = data.count(":");
    for(int i = 0;i < len;++i)
    {
        int myfirst = data.indexOf(":",cont);
        QStringList func = data.split("\n");
        cont += myfirst+1;
        if(myfirst != -1)
        {
            QString thisfunc = func.at(0);
            knowfuncs.append(func.at(0));
            this->startStyling(start+myfirst-thisfunc.length());
            this->setStyling(thisfunc.length(), myStyle(style));
        }

    }

}


void QsciLexerAsm::styleText(int start, int end)
{
    QString data;

    if(!editor())
        return;

    char *chars = new char[end-start+1];
            editor()->SendScintilla(QsciScintilla::SCI_GETTEXTRANGE,start, end, chars);
            data = QString(chars);
            delete[]chars;
            startStyling(start, 0x1f);

            defaultPaint(data, wordslist,start,Keyword);
            defaultPaint(data, cmpwordslist,start,CmpKeyword);
            colorFunctions(data, start, Function);



}


QColor QsciLexerAsm::defaultColor(int style) const
{
    switch(style)
    {
        case Default:
            return QColor(style);
        case Keyword:
            return QColor(Qt::blue);
        case CmpKeyword:
            return QColor(0x3f,0x5f,0x8);

        case Function:
            return QColor(Qt::red);
    }
}

QFont QsciLexerAsm::defaultFont(int style) const
{
    return QFont("Courier New", 12);
}

QColor QsciLexerAsm::defaultPaper()const
{
    return defaultColor(1);
}


//Stuff around style
/*int QsciLexerAsm::getStyle()
{
    return styles.at(styles.length()-1);
}

void QsciLexerAsm::pushStyle(int style)
{
    styles << style;
}

int QsciLexerAsm::popStyle()
{
    if(styles.size() > 0)
        styles.takeLast();
}*/

/*QsciLexerAsm::autoCompletionFillups()const
{
    */



