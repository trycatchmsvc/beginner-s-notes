/*!
 * \file
 * \brief Файл реализации класса MainWindow.
 * \author Кирилл Пушкарёв
 */
#include "mainwindow.hpp"
// Заголовочный файл UI-класса, сгенерированного на основе mainwindow.ui
#include "ui_mainwindow.h"

#include <set>
#include <stdexcept>

#include <QCloseEvent>
#include <QDesktopServices>
#include <QFile>
#include <QFileDialog>
#include <QFileInfo>
#include <QMessageBox>
#include <QSaveFile>
#include <QUrl>
#include <QtGlobal> // qVersion()
#include <QTranslator>

#include "config.hpp"
#include "editnotedialog.hpp"

/*!
 * Конструирует объект класса с родительским объектом \a parent.
 * Параметр \p parent имеет значение по умолчанию 0. Указывать родительский
 * объект нужно, например чтобы дочерний объект был автоматически удалён
 * при удалении родительского. В случае главного окна родителя можно не указывать.
 */
MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent), // Передаём parent конструктору базового класса
    mUi(new Ui::MainWindow) // Создаём объект Ui::MainWindow
{
    // Присоединяем сигналы, соответствующие изменению статуса записной книжки,
    // к слоту, обеспечивающему обновление заголовка окна
    connect(this, &MainWindow::notebookReady, this, &MainWindow::refreshWindowTitle);
    connect(this, &MainWindow::notebookClosed, this, &MainWindow::refreshWindowTitle);
    // Подключение сигнала QAction Exit
    connect (this,&MainWindow::on_actionExit_triggered, this, &MainWindow::exit);
    // Подключение сигнала notebookReady/notebookClosed для включение/выключения UI
    connect(this, &MainWindow::notebookReady, this, [this](){setEnableNotebookUi(true);});
    connect(this, &MainWindow::notebookClosed, this, [this](){setEnableNotebookUi(false);});
    // Присоединяем сигнал создания записной книжки к лямбда-выражению,
    // устанавливающему в главном окне признак изменения (имеет ли текущий
    // документ несохранённые изменения). В заголовке окна при наличии
    // несохранённых изменений будет отображаться звёздочка или другое
    // обозначение, в зависимости от системы. "[this]" в лямбда-выражении
    // означает, что оно обращается к методам данного класса (в данном случае к
    // методу MainWindow::setWindowModified()).
    //
    // Лямбда-выражение — это выражение, результатом которого является
    // функциональный объект (объект, действующий как функция). В фигурных
    // скобках записывается тело этой функции. Таким образом, в данном случае
    // сигнал MainWindow::notebookCreated будет вызывать код, записанный в
    // фигурных скобках, то есть метод MainWindow::setWindowModified() с параметром true.
    connect(this, &MainWindow::notebookCreated, [this] { setWindowModified(true); });
    // Здесь можно присоединить сигналы готовности/закрытия записной книжки к слотам, отвечающим за
    // включение/отключение действий, требующих её наличия
    // <...>
    // Отображаем GUI, сгенерированный из файла mainwindow.ui, в данном окне
    mUi->setupUi(this);

    // Настраиваем таблицу заметок, чтобы её последняя колонка занимала всё доступное место
    mUi->notesView->horizontalHeader()->setStretchLastSection(true);
    // Обновляем заголовок окна
    refreshWindowTitle();
    // Создаём новую записную книжку
    newNotebook();

}

/*!
* Отвечает за уничтожение объектов MainWindow. Сюда можно поместить
* функции, которые надо выполнить перед уничтожением (например, закрыть
* какие-либо файлы или освободить память).
*/
MainWindow::~MainWindow()
{
    // Удаляем объект Ui::MainWindow
    delete mUi;
}

void MainWindow::displayAbout()
{
    /*
     * Создаём простой диалог типа QMessageBox, который является дочерним
     * по отношению к главному окну. Указатель this указывает на тот объект
     * класса (MainWindow), для которого был вызван данный метод (displayAbout()).
     *
     * Для создания стандартных вариантов этих окон (окно информации, сообщение
     * об ошибке и т. д.) есть статические методы, создающие готовое окно со
     * всеми необходимыми настройками: QMessageBox::information(),
     * QMessageBox::critical() и т. д.
     */
    QMessageBox aboutDlg(this);
    // Включаем расширенное форматирование текста (разновидность HTML, позволяет
    // выделять текст, ставить ссылки и т. д.) в окне aboutDlg
    aboutDlg.setTextFormat(Qt::RichText);
    /*
     * Устанавливаем заголовок окна aboutDlg. Функция tr() отвечает за перевод строки на другой
     * язык, если он предусмотрен в данной программе. Метод arg() заменяет в строке
     * %1, %2 и т. д. на переданную ему строку. В данном случае, с его помощью
     * в строку заголовка подставляется название программы, которое хранится
     * в пространстве имён Config в файле config.hpp
     */
    aboutDlg.setWindowTitle(tr("About %1").arg(Config::applicationName));
    // Устанавливаем иконку информационного сообщения
    aboutDlg.setIcon(QMessageBox::Information);
    // Устанавливаем основной текст в окне aboutDlg
    aboutDlg.setText(tr("%1 %2<br>"
        "Author: <a href=\"mailto:kpushkaryov@gmail.com\">Kirill Pushkaryov</a>, 2023.<br>"
        "Sokolov Anton Gennadievich, KI24-08B, 032427218.<br>"
        "This application is dynamically linked against the"
        "<a href=\"https://www.qt.io/developers/\">Qt Library</a>"
        "v. %3, which is under the LGPLv3 license.<br>"
        "Icons by <a href=\"http://tango.freedesktop.org/"
        "Tango_Desktop_Project\">The Tango! Desktop Project</a>.")
        .arg(Config::applicationName).arg(Config::applicationVersion)
        .arg(qVersion()));
    // Отображаем окно как модальное (блокирующее все остальные окна)
    aboutDlg.exec();
}


void MainWindow::newNotebook()
{
    // Прежде чем открыть новую, закрываем текущую записную книжку
    if (!closeNotebook())
    {
        // Если записная книжка не была закрыта, прерываем операцию
        return;
    }
    // Создаём новую записную книжку
    createNotebook();
    // Сбрасываем имя файла текущей записной книжки
    setNotebookFileName();
    // Сигнализируем о готовности
    emit notebookReady();
    // Сигнализируем о создании записной книжки
    emit notebookCreated();
}

bool MainWindow::saveNotebook()
{
    // Если записная книжка не открыта, выдаём сообщение об этом
    if (!isNotebookOpen())
    {
        QMessageBox::warning(this, Config::applicationName, tr("No open notebooks"));
        return false;
    }
    // Если для текущей записной книжки не установлено имя файла...
    if (mNotebookFileName.isEmpty())
    {
        // Задействуем функцию "сохранить как" и выходим
        return saveNotebookAs();
    }
    else
    {
        // Cохраняем в текущий файл
        saveNotebookToFile(mNotebookFileName);
    }
    // Сигнализируем о готовности
    emit notebookReady();
    // Сигнализируем о сохранении записной книжки
    emit notebookSaved();
    return true;
}

bool MainWindow::saveNotebookAs()
{
    // Если записная книжка не открыта, выдаём сообщение об этом
    if (!isNotebookOpen())
    {
        QMessageBox::warning(this, Config::applicationName, tr("No open notebooks"));
        return false;
    }
    // Выводим диалог выбора файла для сохранения
    QString fileName = QFileDialog::getSaveFileName(this, tr("Save Notebook As"), QString(), Config::notebookFileNameFilter);
    // Если пользователь не выбрал файл, возвращаем false
    if (fileName.isEmpty())
    {
        return false;
    }
    // Сохраняем записную книжку в выбранный файл
    saveNotebookToFile(fileName);
    // Устанавливаем выбранное имя файла в качестве текущего
    setNotebookFileName(fileName);
    // Сигнализируем о готовности
    emit notebookReady();
    // Сигнализируем о сохранении записной книжки
    emit notebookSaved();
    return true;
}

bool MainWindow::openNotebook()
{
    // Если записная книжка открыта, сначала закрываем её
    if (isNotebookOpen() && !closeNotebook())
    {
        // Если записная книжка не была закрыта, возвращаем false
        return false;
    }
    // Выводим диалог выбора файла для открытия
    QString fileName = QFileDialog::getOpenFileName(this, tr("Open Notebook"), QString(), Config::notebookFileNameFilter);
    // Если пользователь не выбрал файл, возвращаем false
    if (fileName.isEmpty())
    {
        return false;
    }
    // Блок обработки исключительных ситуаций
    try
    {
        // Создаём объект inf, связанный с файлом fileName
        QFile inf(fileName);
        // Открываем файл только для чтения
        if (!inf.open(QIODevice::ReadOnly))
        {
            throw std::runtime_error((tr("open(): ") + inf.errorString()).toStdString());
        }
        // Привязываем к файлу поток, позволяющий считывать объекты Qt
        QDataStream ist(&inf);
        // Создаём новый объект записной книжки
        std::unique_ptr<Notebook> nb(new Notebook);
        // Загружаем записную книжку из файла
        ist >> *nb;
        // Устанавливаем новую записную книжку в качестве текущей.
        // Метод release() забирает указатель у объекта nb
        setNotebook(nb.release());
    }
    catch (const std::exception &e)
    {
        // Если при открытии файла возникла исключительная ситуация, сообщить пользователю
        QMessageBox::critical(this, Config::applicationName, tr("Unable to open the file %1: %2").arg(fileName).arg(e.what()));
        return false;
    }
    // Устанавливаем текущее имя файла
    setNotebookFileName(fileName);
    // Сигнализируем о готовности
    emit notebookReady();
    // Сигнализируем об открытии записной книжки
    emit notebookOpened(mNotebookFileName);
    return true;
}

bool MainWindow::closeNotebook()
{
    // Если записная книжка не открыта, возвращаем true
    if (!isNotebookOpen())
    {
        return true;
    }
    // Создаём окно с вопросом о сохранении файла
    QMessageBox saveQuery(this);
    // Устанавливаем иконку вопроса
    saveQuery.setIcon(QMessageBox::Question);
    // Ставим название программы в заголовок
    saveQuery.setWindowTitle(Config::applicationName);
    // Устанавливаем текст вопроса. Вместо %1 метод arg() подставит в строку
    // результат notebookName() (название документа)
    saveQuery.setText(tr("Would you like to save %1?").arg(notebookName()));
    // Добавляем в окно стандартные кнопки: сохранить, не сохранять и отменить
    saveQuery.setStandardButtons(QMessageBox::Save | QMessageBox::Discard | QMessageBox::Cancel);
    // Выбираем кнопку по умолчанию — сохранить
    saveQuery.setDefaultButton(QMessageBox::Save);
    // Выводим модальный диалог saveQuery и смотрим результат
    switch (saveQuery.exec())
    {
    case QMessageBox::Save: // Сохранить
        // Сохранить записную книжку
        if (!saveNotebook())
        {
            return false;
        }
        // Здесь не должно быть break
        Q_FALLTHROUGH();
    case QMessageBox::Discard: // Закрыть без сохранения
        discardNotebook();
        break;
    case QMessageBox::Cancel: // Отмена
        return false;
    }
    return true;
}

void MainWindow::discardNotebook()
{
    // Если записная книжка не открыта, выходим
    if (!isNotebookOpen())
    {
        return;
    }
    // Уничтожаем объект записной книжки
    destroyNotebook();
    // Сбрасываем текущее имя файла
    setNotebookFileName();
    // Сигнализируем о закрытии записной книжки
    emit notebookClosed();
}

bool MainWindow::newNote()
{
    // Если записная книжка не открыта, выдаём сообщение об этом
    if (!isNotebookOpen())
    {
        QMessageBox::warning(this, Config::applicationName, tr("No open notebooks"));
        return false;
    }
    // Создаём диалог редактирования заметки
    EditNoteDialog noteDlg(this);
    // Устанавливаем заголовок noteDlg
    noteDlg.setWindowTitle(tr("New Note"));
    // Создаём заметку и передаём указатель на неё noteDlg
    Note note;
    noteDlg.setNote(&note);
    // Если пользователь не подтвердил изменения, возвращаем false
    if (noteDlg.exec() != EditNoteDialog::Accepted)
    {
        return false;
    }
    // Вставляем заметку в записную книжку
    addNote(note);
    return true;
}

bool MainWindow::editNote(const QModelIndex &idx)
{
    // Если индекс некорректен, возвращаем false
    if (!idx.isValid())
    {
        return false;
    }
    // Если записная книжка не открыта, выдаём сообщение об этом
    if (!isNotebookOpen())
    {
        QMessageBox::warning(this, Config::applicationName, tr("No open notebooks"));
        return false;
    }
    // Создаём диалог редактирования заметки
    EditNoteDialog noteDlg(this);
    // Устанавливаем заголовок noteDlg
    noteDlg.setWindowTitle(tr("Edit Note"));
    // Получаем индекс текущей заметки
//    QModelIndex idx = mUi->notesView->selectionModel()->currentIndex();

    // Копируем заметку из записной книжки и передаём указатель noteDlg
    Note note = (*mNotebook)[idx.row()];
    noteDlg.setNote(&note);
    // Если пользователь не подтвердил изменения, возвращаем false
    if (noteDlg.exec() != EditNoteDialog::Accepted)
    {
        return false;
    }
    // Обновляем заметку в записной книжке
    setNote(idx.row(), note);
    return true;
}

void MainWindow::deleteNotes()
{
    // Если ничего не выбрано, ничего не делаем
    if (!mUi->notesView->selectionModel()->hasSelection())
    {
        return;
    }

    if (QMessageBox::question(this, "Уведомление", "Вы точно хотите удалить заметку?",  QMessageBox::Yes | QMessageBox::No) == QMessageBox::StandardButton::No){
        return;
    }
    // Здесь можно запросить подтверждение удаления
    // <...>
    // Для хранения номеров строк создаём STL-контейнер "множество", элементы
    // которого автоматически упорядочиваются по возрастанию
    std::set<int> rows;
    {
        // Получаем от таблицы заметок список индексов выбранных в настоящий момент
        // элементов
        QModelIndexList idc = mUi->notesView->selectionModel()->selectedRows();
        // Вставляем номера выбранных строк в rows
        for (const auto &i : idc)
        {
            rows.insert(i.row());
        }
    }
    // Обходим множество номеров выбранных строк *по убыванию*, чтобы удаление предыдущих
    // не сбивало нумерацию следующих
    for (auto it = rows.rbegin(); it != rows.rend(); ++it)
    {
        // Удаляем строку
        mNotebook->erase(*it);
    }
}

void MainWindow::refreshWindowTitle()
{
    QString nbname = notebookName();
    // Если имя записной книжки не пусто...
    if (!nbname.isEmpty())
    {
        // Ставим в заголовок окна название программы (Config::applicationName)
        // и имя текущей записной книжки (nbname)
        // Метка "[*]" обозначает место, куда будет подставлена звёздочка, если
        // установлен флаг изменения окна (см. QWidget::setWindowModified())
        setWindowTitle(tr("%1 - %2[*]").arg(Config::applicationName).arg(nbname));
    }
    else
    {
        // Ставим в заголовок окна только название программы (Config::applicationName)
        setWindowTitle(Config::applicationName);
    }
}

void MainWindow::addNote(const Note &note)
{
    mNotebook->push_back(note);
}

const Note &MainWindow::getNote(Notebook::SizeType idx) const
{
    return (*mNotebook)[idx];
}

void MainWindow::setNote(Notebook::SizeType idx, Note note)
{
    mNotebook->setNote(idx, note);
}

Notebook::SizeType MainWindow::notebookSize() const
{
    return mNotebook->size();
}

void MainWindow::selectNote(Notebook::SizeType idx)
{
    mUi->notesView->selectRow(idx);
}

void MainWindow::visitWebsite()
{
    // Здесь можно открыть URL с помощью QDesktopServices::openUrl()
    // <...>
    QDesktopServices::openUrl(QUrl("https://ikit.sfu-kras.ru", QUrl::TolerantMode));

}

void MainWindow::exit()
{
    // Здесь можно закрыть главное окно программы с помощью a
    // <...>
    MainWindow::close();
}

/*!
 * Сохраняет текущую записную книжку в файл \a fileName. Данный метод
 * отвечает непосредственно за сохранение и не предусматривает диалога с
 * пользователем.
 */
void MainWindow::saveNotebookToFile(QString fileName)
{
    // Если записная книжка не открыта, прерываем операцию
    if (!isNotebookOpen())
    {
        return;
    }
    // Блок обработки исключительных ситуаций
    try
    {
        /*
         * Создаём объект outf, связанный с файлом fileName.
         * QSaveFile обеспечивает безопасное сохранение (через промежуточный
         * временный файл), чтобы избежать потери данных в случае нештатного
         * завершения операции сохранения. Само сохранение происходит при вызове
         * метода commit().
         */
        QSaveFile outf(fileName);
        // Открываем файл только для записи
        outf.open(QIODevice::WriteOnly);
        // Привязываем к файлу поток, позволяющий выводить объекты Qt
        QDataStream ost(&outf);
        // Выводим записную книжку в файл
        ost << *mNotebook;
        // Запускаем сохранение и смотрим результат.
        // В случае неудачи запускаем исключительную ситуацию (блок прерывается,
        // управление передаётся в блок catch)
        if (!outf.commit())
        {
            throw std::runtime_error(tr("Unable to commit the save").toStdString());
        }
        // Устанавливаем текущее имя файла
        setNotebookFileName(fileName);
    }
    catch (const std::exception &e)
    {
        // Если при сохранении файла возникла исключительная ситуация, сообщить пользователю
        QMessageBox::critical(this, Config::applicationName, tr("Unable to write to the file %1: %2").arg(fileName).arg(e.what()));
    }
}

bool MainWindow::isNotebookOpen() const
{
    // Преобразуем указатель mNotebook к типу bool. Нулевой указатель при этом
    // даст false, ненулевой — true
    return static_cast<bool>(mNotebook);
}

void MainWindow::setNotebookFileName(QString name)
{
    // Устанавливаем имя файла
    mNotebookFileName = name;
    // Сигнализируем о смене имени файла
    emit notebookFileNameChanged(name);
}

QString MainWindow::notebookName() const
{
    // Если записная книжка не открыта, возвращаем пустую строку
    if (!isNotebookOpen())
    {
        return QString();
    }
    // Иначе, если имя текущего файла пустое, возвращаем строку "Untitled"
    else if (mNotebookFileName.isEmpty())
    {
        return tr("Untitled");
    }
    // Возвращаем короткое имя текущего файла (без пути)
    return QFileInfo(mNotebookFileName).fileName();
}

void MainWindow::createNotebook()
{
    setNotebook(new Notebook);
}

void MainWindow::setNotebook(Notebook *notebook)
{
    /*
     * Заменяем имеющийся указатель на объект записной книжки новым.
     * Если в mNotebook хранился какой-то ненулевой указатель на объект,
     * то метод reset() удалит его автоматически
     */
    mNotebook.reset(notebook);
    // Связываем новый объект записной книжки с таблицей заметок в главном окне
    mUi->notesView->setModel(mNotebook.get());
}

/*!
 * Прекращает отображение текущей записной книжки в графическом интерфейсе
 * и удаляет объект Notebook по указателю mNotebook.
 */
void MainWindow::destroyNotebook()
{
    // Отключаем объект записной книжки от таблицы заметок в главном окне
    mUi->notesView->setModel(0);
    // Удаляем объект записной книжки
    mNotebook.reset();
}

void MainWindow::setEnableNotebookUi(bool enable)
{
    // Включаем/отключаем действия и список заметок
    mUi->actionNew_Note->setEnabled(enable);
    mUi->actionDelete_Notes->setEnabled(enable);
    mUi->notesView->setEnabled(enable);
    mUi->actionSave->setEnabled(enable);
    mUi->actionSave_As->setEnabled(enable);
    mUi->actionClose_Notebook->setEnabled(enable);
}

/*!
 * Выполняет последние действия перед закрытием окна. Является переопределением
 * унаследованного метода QWidget::closeEvent().
 */
void MainWindow::closeEvent(QCloseEvent *event)
{
    // Сигнализируем о закрытии окна
    emit windowClosing();
    // Подтверждаем закрытие
    event->accept();
}




