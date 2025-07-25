/*!
 * \file
 * \brief Файл главной функции.
 * \author Кирилл Пушкарёв
 */
#include <QApplication>
#include <QTranslator>
#include <QDebug>
#include <QLibraryInfo>

#include "mainwindow.hpp"

/*!
 * \brief main
 * \param argc количество параметров командной строки
 * \param argv параметры командной строки
 * \return код результата
 *
 * Главная функция программы
 */
int main(int argc, char *argv[])
{
    // Создать объект класса QApplication. Класс QApplication является частью
    // библиотеки Qt и отвечает за функционирование программы в целом
    QApplication a(argc, argv);

    //! Создание обьекта класса перевода
    QTranslator translator;
    //! Получение языка системы
    QString locale = QLocale::system().name();

    bool translate = translator.load(QString(":/translations/toynote_") + QString(locale) + QString(".qm"));
    a.installTranslator(&translator);

    if (!translate){
        qDebug() << "Error translate";
    }



    qDebug() << locale;




    // Создать объект класса MainWindow. Класс MainWindow является частью
    // данной программы и отвечает за функционирование её главного окна
    MainWindow w;
    // Отобразить главное окно
    w.show();

    // Начать обработку событий (щелчков мыши по элементам интерфейса и т. д.)
    return a.exec();
}
