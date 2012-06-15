#ifndef QSCILEXERASM_H
#define QSCILEXERASM_H
#ifndef QSCLIEXERASM_H
#define QSCLIEXERASM_H

#include <qcolor.h>
#include <qfont.h>
#include <QVector>
#include <qsettings.h>
#include <Qsci/qsciapis.h>
#include <Qsci/qscicommand.h>

#include <Qsci/qsciglobal.h>
#include <Qsci/qscilexer.h>
#include <Qsci/qscilexercustom.h>
#include <Qsci/qsciscintilla.h>
//#include <qscistyle.h>

#endif // QSCLIEXERASM_H

//QsciLexerCustom for create new language lexers
//http://www.riverbankcomputing.com/static/Docs/QScintilla2/classQsciLexerCustom.html
class  QsciLexerAsm : public QsciLexerCustom
{
     Q_OBJECT
public:



    enum {
        //! The default.
        Default = 0,

        //! An error.
        Error,
        //! A keyword.
        Keyword,

        //Keywords about comparing (test, cmp)
        CmpKeyword,

        Function
    };

    QsciLexerAsm(QObject *parent=0);

   // const char *language() const;

    //! Returns the name of the lexer.  Some lexers support a number of
    //! languages.

     //list of keywords
     QString description(int style) const;

     virtual ~QsciLexerAsm ();

     void styleText(int start, int end);

     QColor defaultColor(int style) const;
     QFont defaultFont(int style) const;
     QColor defaultPaper()const;

     virtual const char *language() const;

     int GetKeyWord(QString line);

     QsciStyle myStyle(int style)const;

     //Скобки
     //void bracks(QString str, int start)const;
     //Функция по умолчанию
     void defaultPaint(QString str, QVector<QString> list, int start,int style);
     void colorFunctions(QString data,int start, int style);

     /*void pushStyle(int style);
     int popStyle();
     int getStyle();*/

private:
    QsciLexerAsm(const QsciLexerAsm &);
    QsciLexerAsm &operator=(const QsciLexerAsm &);
    QString keywordsList, thisline;
    QVector<QString> wordslist,cmpwordslist,
    knowfuncs; //Запоминаем имена функций
    QList<int>styles;

};

#endif // QSCILEXERASM_H
