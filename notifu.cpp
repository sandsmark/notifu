// notiFU - bennys html and css popup notification
// GPL 2 or later
// copyright 2009 sandsmark
// love long and prosper

#include <iostream>

#include <QtCore>
#include <QtGui>
#include <QtWebKit>

int main(int argc, char * argv[])
{
    if (argc < 7)
    {
        std::cout << "Usage: " << argv[0] << " URL width height x y timeout" << std::endl;
        return 0;
    }

    QUrl url(argv[1], QUrl::TolerantMode);

    if (!url.isValid())
    {
        std::cout << "Please supply a valid URL!" << std::endl;
        return 0;
    }

    int w = QString::fromLatin1(argv[2]).toInt();
    int h = QString::fromLatin1(argv[3]).toInt();
    int x = QString::fromLatin1(argv[4]).toInt();
    int y = QString::fromLatin1(argv[5]).toInt();

    if (x <= 0 || y <= 0 || w <= 0 || h <= 0)
    {
        std::cout << "Please supply a valid size!" << std::endl;
        return 0;
    }
    int timeout = QString::fromLatin1(argv[6]).toInt();
    if (timeout <= 0)
    {
        std::cout << "Please supply a valid timeout!" << std::endl;
        return 0;
    }


    QApplication app(argc, argv);
    QWebView view(NULL);
    view.load(url);
    view.setWindowFlags(Qt::ToolTip);
    view.show();
    view.move(x, y);
    view.resize(w, h);

    QTimer::singleShot(timeout, &app, SLOT(quit()));

    app.exec();
}

