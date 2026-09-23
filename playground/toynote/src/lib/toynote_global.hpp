/*!
 * \file
 * \brief Глобальный заголовочный файл библиотеки.
 * \author Кирилл Пушкарёв
 */
#ifndef TOYNOTE_GLOBAL_HPP
#define TOYNOTE_GLOBAL_HPP
#include <QtCore/QtGlobal>

/*!
 * \def TOYNOTELIB_EXPORT
 * \brief Макроопределение для обозначения экспортируемых из библиотеки символов
 */
#if defined(TOYNOTELIB_LIBRARY)
#define TOYNOTELIB_EXPORT Q_DECL_EXPORT
#else
#define TOYNOTELIB_EXPORT Q_DECL_IMPORT
#endif

#endif // TOYNOTE_GLOBAL_HPP
