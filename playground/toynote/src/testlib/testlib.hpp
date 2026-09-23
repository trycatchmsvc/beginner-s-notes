#ifndef TESTLIB_HPP
#define TESTLIB_HPP

#include <QAbstractButton>
#include <QMessageBox>
#include <QVector>

#include "testlib_global.hpp"

namespace Testlib {

TESTLIB_EXPORT QAbstractButton *click_standard_button(QMessageBox *box, QVector<QMessageBox::StandardButton> buttons);

TESTLIB_EXPORT QMessageBox *get_active_message_box();

TESTLIB_EXPORT void post_active_message_box_click(QVector<QMessageBox::StandardButton> buttons);

TESTLIB_EXPORT void accept_active_message_box();

TESTLIB_EXPORT void post_active_message_box_accept();

} // namespace Testlib
#endif // TESTLIB_HPP
