/*!
 * \file
 * \brief Файл конфигурации.
 * \author Кирилл Пушкарёв
 */
#ifndef CONFIG
#define CONFIG

#include <QtGlobal> // QT_TRANSLATE_NOOP

namespace Config
{

/*!
 * \brief Название приложения.
 * \note QT_TRANSLATE_NOOP() используется, чтобы строки отображались в файле
 * строк для перевода на другие языки в контексте Config.
 */
const char applicationName[] = QT_TRANSLATE_NOOP("Config", "Toynote");

//! Версия приложения
const char applicationVersion[] = "20230622";

/*!
 * \brief Фильтр для имён файлов записных книжек.
 *
 * Фильтры используются диалогом QFileDialog, в котором пользователь выбирает
 * файл при сохранении или открытии записной книжки. Обычно они отображаются
 * в выпадающем списке внизу окна. При выборе фильтра в окне показываются
 * только файлы, имена которых соответствуют одной из масок фильтра.
 *
 * Маски фильтра указываются в скобках через пробел. В одной строке можно указать
 * несколько фильтров через парную точку с запятой (;;). Подробнее см. в
 * документации QFileDialog.
 */
const char notebookFileNameFilter[] = QT_TRANSLATE_NOOP("Config", "Notebooks (*.tnb)");

}
#endif // CONFIG

