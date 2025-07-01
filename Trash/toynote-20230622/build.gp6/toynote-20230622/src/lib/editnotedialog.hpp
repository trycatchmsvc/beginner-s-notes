/*!
 * \file
 * \brief Заголовочный файл класса EditNoteDialog.
 * \author Кирилл Пушкарёв
 */
#ifndef EDITNOTEDIALOG_HPP
#define EDITNOTEDIALOG_HPP

#include <memory> // unique_ptr

#include <QDialog>

#include "toynote_global.hpp"

// Объявляем класс Note, чтобы ниже можно было упоминать указатели на него,
// не включая определение класса. Это увеличивает скорость сборки проекта за
// счёт уменьшения количества обрабатываемых заголовочных файлов.
class Note;

// Объявляем класс Ui::EditNoteDialog, чтобы ниже можно было упоминать указатели на него,
// не включая определение класса. Этот класс создаётся автоматически из UI-файла.
// Данное объявление также было создано автоматически, когда Qt Creator
// добавлял в проект UI-файл и класс для него.
namespace Ui {
class EditNoteDialog;
}

/*!
 * \brief Класс диалога (диалогового окна) редактирования заметки.
 *
 * Является потомком класса QDialog, стандартного диалогового окна Qt. Интерфейс
 * окна создаётся в редакторе Qt Designer и сохраняется в файле editnotedialog.ui.
 * При сборке проекта, из UI-файла автоматически генерируется код на C++ —
 * класс Ui::EditNoteDialog, который отвечает приведение нашего диалога в нужный
 * вид.
 *
 * Редактируемая заметка передаётся по указателю через метод setNote(). Прочитать
 * текущий указатель можно через метод note().
 * \sa \ref faq_qt_designer_how
 */
class TOYNOTELIB_EXPORT EditNoteDialog : public QDialog
{
    Q_OBJECT

public:
    /*!
     * \brief Конструктор с необязательным указанием родительского объекта.
     * \param parent Указатель на родительский объект.
    */
    explicit EditNoteDialog(QWidget *parent = 0);
    //! Деструктор
    ~EditNoteDialog();
    //! Возвращает указатель на редактируемую заметку.
    Note *note() const;
    //! Устанавливает указатель на редактируемую заметку.
    void setNote(Note *note);
public slots:
    //! Устанавливает значение в поле для ввода заголовка заметки
    void setNoteTitle(const QString &title);
    //! Устанавливает значение в поле для ввода текста заметки
    void setNoteText(const QString &text);
    //! Обрабатывает подтверждение диалога.
    void accept() Q_DECL_OVERRIDE;
private:
    /*!
     * \brief Указатель на сгенерированный интерфейс.
     *
     * Указатель на объект UI-класса, сгенерированного на основе UI-файла
     * mainwindow.ui.
     *
     * Через этот указатель можно обратиться к элементам главного окна,
     * созданного в Qt Designer.
     * \sa \ref faq_qt_designer_whatis
     * \note std::unique_ptr обеспечивает автоматическое удаление объекта
     * по указателю, когда уничтожается объект EditNoteDialog
     */
    Ui::EditNoteDialog *mUi;
    //! Указатель на редактируемую заметку
    Note *mNote;
};

#endif // EDITNOTEDIALOG_HPP
