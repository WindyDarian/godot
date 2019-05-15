#include "register_types.h"

#include "core/class_db.h"
#include "just_a_test_class.h"

void register_windy_types() {
	ClassDB::register_class<JustATestClass>();
}

void unregister_windy_types() {
}
