#include <array>
#include <memory> // unique_ptr

#include <QAction>
#include <QDesktopServices>
#include <QMenu>
#include <QMenuBar>
#include <QMessageBox>
#include <QObject>
#include <QSignalSpy>
#include <QTimer>
#include <QWidget>
#include <QtGlobal> // qUtf8Printable
#include <QtTest>

#include "mainwindow.hpp"
#include "note.hpp"
#include "test_url_hanlders.hpp"
#include "testlib.hpp"

class MainWindowTest : public QObject
{
    Q_OBJECT
private slots:
    void init();
    void cleanup();

    void testDelete();
    void testEditMenu();
    void testExit();
    void testFileShortcuts();
    void testNotebookDependentWidgetsEnabled();
    void testVisitWebsite();
private:
    QAction *triggerAction(const QString &name);
    void addNote(QString title, QString text);
    void verifyNotebookDependentWidgetsEnabled(bool state, const QString &msg);

    std::unique_ptr<MainWindow> m_wnd;
};

void MainWindowTest::init()
{
    m_wnd.reset(new MainWindow);
}

void MainWindowTest::cleanup()
{
    m_wnd.reset();
}

void MainWindowTest::testDelete()
{
    addNote("delete", "delete");
    addNote("save", "save");
    m_wnd->selectNote(0);
    Testlib::post_active_message_box_click({QMessageBox::Yes, QMessageBox::Ok});
    m_wnd->deleteNotes();
    // Use the QTRY_ form first to run the event loop
    QTRY_COMPARE(m_wnd->notebookSize(), 1);
    QCOMPARE(m_wnd->getNote(0).title(), "save");
    m_wnd->selectNote(0);
    Testlib::post_active_message_box_click({QMessageBox::No, QMessageBox::Cancel});
    m_wnd->deleteNotes();
    QTRY_COMPARE(m_wnd->notebookSize(), 1);
    QCOMPARE(m_wnd->getNote(0).title(), "save");
}

void MainWindowTest::testEditMenu()
{
    QVERIFY(m_wnd->menuBar()->findChild<QMenu *>("menuEdit"));
}

void MainWindowTest::testExit()
{
    QSignalSpy spy(m_wnd.get(), &MainWindow::windowClosing);
    QVERIFY2(triggerAction("actionExit"), "Exit action doesn't exist");
    QTRY_VERIFY2(spy.count() > 0, "MainWindow::windowClosing() isn't called");
}

void MainWindowTest::testFileShortcuts()
{
    QMenu *m = m_wnd->menuBar()->findChild<QMenu *>("menuFile");
    QVERIFY(m);
    for (QAction *a : m->actions())
    {
        QVERIFY2(a->isSeparator() || !a->shortcut().isEmpty(), qUtf8Printable(QString("No keyboard shortcut for action %1").arg(a->text())));
    }
}

void MainWindowTest::testNotebookDependentWidgetsEnabled()
{
    verifyNotebookDependentWidgetsEnabled(true, "Notebook dependent %1 %2 is not enabled with notebook present");
    m_wnd->discardNotebook();
    verifyNotebookDependentWidgetsEnabled(false, "Notebook dependent %1 %2 is enabled without notebook");
}

void MainWindowTest::testVisitWebsite()
{
    Testlib::UrlVisitTestHandler https_handler(QUrl("https://ikit.sfu-kras.ru"));
    QDesktopServices::setUrlHandler("https", &https_handler, "handle");
    Testlib::LastVisitedUrlHandler http_handler;
    QDesktopServices::setUrlHandler("http", &http_handler, "handle");
    QVERIFY2(triggerAction("actionVisit_Website"), "Visit Website action doesn't exist");
    // Use the QTRY_ form first to run the event loop
    QTRY_VERIFY2(https_handler.visited(), "Correct HTTPS URL isn't visited");
    QVERIFY2(!http_handler.visited(), "Incorrect HTTP URL is visited");
}

QAction *MainWindowTest::triggerAction(const QString &name)
{
    QAction *a = m_wnd->findChild<QAction *>(name);
    if (a)
    {
        QTimer::singleShot(0, a, &QAction::trigger);
    }
    return a;
}

void MainWindowTest::addNote(QString title, QString text)
{
    m_wnd->addNote(Note(title, text));
}

auto notebook_dependent_action_names = std::array{
            "actionNew_Note", "actionDelete_Notes", "actionSave"
            "actionSave_As", "actionClose_Notebook"
};

auto notebook_dependent_widget_names = std::array{"notesView"};

void MainWindowTest::verifyNotebookDependentWidgetsEnabled(bool state, const QString &msg)
{
    for (auto aname : notebook_dependent_action_names)
    {
        QAction *a = m_wnd->findChild<QAction *>(aname);
        if (a)
        {
            QVERIFY2(a->isEnabled() == state, qUtf8Printable(msg.arg("action").arg(aname)));
        }
    }
    for (auto wname : notebook_dependent_widget_names)
    {
        QWidget *w = m_wnd->findChild<QWidget *>(wname);
        if (w)
        {
            QVERIFY2(w->isEnabled() == state, qUtf8Printable(msg.arg("widget").arg(wname)));
        }
    }
}

QTEST_MAIN(MainWindowTest)

#include "tst_mainwindow.moc"
