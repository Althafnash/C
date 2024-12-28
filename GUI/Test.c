#include <forms.h>

void button_callback(FL_OBJECT *obj, long data) {
    fl_alert("Button clicked!");
}

int main() {
    FL_FORM *form;
    FL_OBJECT *button;

    fl_initialize(&argc, argv, 0, 0, 0);
    form = fl_bgn_form(FL_NO_BOX, 300, 200);
    button = fl_add_button(FL_NORMAL_BUTTON, 100, 75, 100, 40, "Click Me");
    fl_set_object_callback(button, button_callback, 0);
    fl_end_form();

    fl_show_form(form, FL_PLACE_CENTER, FL_NOBORDER, "XForms Example");

    fl_do_forms();
    return 0;
}
