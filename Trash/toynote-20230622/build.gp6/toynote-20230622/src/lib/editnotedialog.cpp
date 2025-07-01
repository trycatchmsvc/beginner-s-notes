/*!
 * \file
 * \brief Файл реализации класса EditNoteDialog.
 * \author Кирилл Пушкарёв
 */
#include "editnotedialog.hpp"
// Заголовочный файл UI-класса, сгенерированного на основе editnotedialog.ui
#include "ui_editnotedialog.h"

#include <QDialog>
#include <QMessageBox>
#include <QString>

#include "config.hpp"
#include "note.hpp"

/*!
* Конструирует объект класса с родительским объектом \a parent.
* Параметр \p parent имеет значение по умолчанию 0. Указывать родительский
* объект нужно, например чтобы дочерний объект был автоматически удалён
* при удалении родительского. Для EditNoteDialog родителем будет
* окно более высокого уровня, например главное.
*/
EditNoteDialog::EditNoteDialog(QWidget *parent) :
    QDialog(parent), // Передаём parent конструктору базового класса
    mUi(new Ui::EditNoteDialog) // Создаём объект Ui::EditNoteDialog
{
    // Отображаем GUI, сгенерированный из файла editnotedialog.ui, в данном окне
    mUi->setupUi(this);
}

/*!
* Отвечает за уничтожение объектов EditNoteDialog. Сюда можно поместить
* функции, которые надо выполнить перед уничтожением (например, закрыть
* какие-либо файлы или освободить память).
*/
EditNoteDialog::~EditNoteDialog()
{
    // Удаляем объект Ui::EditNoteDialog
    delete mUi;
}

Note *EditNoteDialog::note() const
{
    return mNote;
}

void EditNoteDialog::setNote(Note *note)
{
    mNote = note;
    if (note)
    {
        setNoteTitle(note->title());
        setNoteText(note->text());
    }
}

void EditNoteDialog::setNoteTitle(const QString &title)
{
    mUi->titleEdit->setText(title);
}

void EditNoteDialog::setNoteText(const QString &text)
{
    mUi->plainTextEdit->setPlainText(text);
}

/*!
 * Этот метод вызывается, когда пользователь подтверждает диалог, например
 * нажатием кнопки «OK». Метод изначально определён в базовом классе QDialog,
 * а здесь он переопределяется, то есть при вызове метода accept() у объекта
 * EditNoteDialog будет выполняться этот код, а не тот, что есть в классе
 * QDialog.
 *
 * Метод отвечает за обработку введённых пользователем в диалоге данных.
 * Он считывает данные из полей диалога и записывает их в соответствующие
 * атрибуты редактируемой заметки.
 */
void EditNoteDialog::accept()
{
    QString title = mUi->titleEdit->text();
    QString text = mUi->plainTextEdit->toPlainText();
    // Здесь можно проверить, что заголовок или текст заметки не пусты
    // <...>
    // Читаем заголовок и текст заметки из полей диалога и записываем
    // их в соответствующие атрибуты заметки по указателю mNote
    mNote->setTitle(title);
    // Получаем текст заметки из QPlainTextEdit
    mNote->setText(text);
    // Вызываем метод базового класса, чтобы он выполнил стандартные операции
    // при закрытии диалогового окна. Если не вызвать его, то диалог не
    // будет считаться подтверждённым и не закроется.
    // Таким образом, в данном случае метод EditNoteDialog::accept() не подменяет
    // собой метод QDialog::accept() совсем, а дополняет его.
    QDialog::accept();
}
