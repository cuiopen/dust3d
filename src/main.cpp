#include <QApplication>
#include <QDesktopWidget>
#include <QStyleFactory>
#include <QFontDatabase>
#include <QDebug>
#include <QtGlobal>
#include "skeletondocumentwindow.h"
#include "theme.h"
#include "version.h"

int main(int argc, char ** argv)
{
    QApplication app(argc, argv);
    
    // QuantumCD/Qt 5 Dark Fusion Palette
    // https://gist.github.com/QuantumCD/6245215
    qApp->setStyle(QStyleFactory::create("Fusion"));
    QPalette darkPalette;
    darkPalette.setColor(QPalette::Window, Theme::black);
    darkPalette.setColor(QPalette::WindowText, Theme::white);
    darkPalette.setColor(QPalette::Base, QColor(25,25,25));
    darkPalette.setColor(QPalette::AlternateBase, QColor(53,53,53));
    darkPalette.setColor(QPalette::ToolTipBase, Theme::white);
    darkPalette.setColor(QPalette::ToolTipText, Theme::white);
    darkPalette.setColor(QPalette::Text, Theme::white);
    darkPalette.setColor(QPalette::Disabled, QPalette::Text, Theme::black);
    darkPalette.setColor(QPalette::Button, QColor(53,53,53));
    darkPalette.setColor(QPalette::ButtonText, Theme::white);
    darkPalette.setColor(QPalette::BrightText, Theme::red);
    darkPalette.setColor(QPalette::Link, QColor(42, 130, 218));
    darkPalette.setColor(QPalette::Highlight, Theme::white);
    darkPalette.setColor(QPalette::HighlightedText, Theme::black);
    qApp->setPalette(darkPalette);
    qApp->setStyleSheet("QToolTip { color: #ffffff; background-color: #fc6621; border: 1px solid white; }");
    
    QCoreApplication::setApplicationName(APP_NAME);
    
    QFont font;
    font.setWeight(QFont::Light);
    font.setPixelSize(11);
    font.setBold(false);
    QApplication::setFont(font);
    
    SkeletonDocumentWindow::createDocumentWindow();
    
    return app.exec();
}
