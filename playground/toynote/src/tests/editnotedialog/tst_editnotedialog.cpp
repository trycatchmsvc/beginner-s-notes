#include <memory> // unique_ptr

#include <QObject>
#include <QSignalSpy>
#include <QTimer>
#include <QtTest>

#include "editnotedialog.hpp"
#include "note.hpp"
#include "testlib.hpp"

class EditNoteDialogTest: public QObject
{
    Q_OBJECT
private slots:
    void init();
    void cleanup();
    void testRejectEmptyNote_data();
    void testRejectEmptyNote();
    void testEditNote_data();
    void testEditNote();
private:
    std::unique_ptr<EditNoteDialog> m_dlg;
};

void EditNoteDialogTest::init()
{
    m_dlg.reset(new EditNoteDialog);
}

void EditNoteDialogTest::cleanup()
{
    m_dlg.reset();
}

void EditNoteDialogTest::testRejectEmptyNote_data()
{
    QTest::addColumn<QString>("title");
    QTest::addColumn<QString>("text");

    QTest::newRow("empty note") << "" << "";
    QTest::newRow("empty title") << "" << "text";
    QTest::newRow("empty text") << "title" << "";
}

void EditNoteDialogTest::testRejectEmptyNote()
{
    QFETCH(QString, title);
    QFETCH(QString, text);
    Note note;
    m_dlg->setNote(&note);
    QSignalSpy spy(m_dlg.get(), &EditNoteDialog::accepted);
    m_dlg->setNoteTitle(title);
    m_dlg->setNoteText(text);
    m_dlg->open();
    QTimer::singleShot(0, [=]()
    {
        Testlib::accept_active_message_box();
        m_dlg->reject();
    });
    m_dlg->accept();
    QVERIFY2(spy.count() == 0, "Incorrect note accepted");
}

void EditNoteDialogTest::testEditNote_data()
{
    QTest::addColumn<QString>("title");
    QTest::addColumn<QString>("text");

    QTest::newRow("single-line note") << "title" << "text";
    QTest::newRow("multiple-line note") << "title" << "text line1\ntext line 2";
}

void EditNoteDialogTest::testEditNote()
{
    QFETCH(QString, title);
    QFETCH(QString, text);
    Note note;
    m_dlg->setNote(&note);
    QSignalSpy spy(m_dlg.get(), &EditNoteDialog::accepted);
    m_dlg->setNoteTitle(title);
    m_dlg->setNoteText(text);
    m_dlg->open();
    m_dlg->accept();
    QVERIFY2(spy.count() > 0, "Correct note rejected");
}

QTEST_MAIN(EditNoteDialogTest)

#include "tst_editnotedialog.moc"
