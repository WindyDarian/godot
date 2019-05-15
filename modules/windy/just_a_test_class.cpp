#include "just_a_test_class.h"

void JustATestClass::add(int value) {

	count += value;
}

void JustATestClass::reset() {

	count = 0;
}

int JustATestClass::get_total() const {
	return count;
}

void JustATestClass::_bind_methods() {
	ClassDB::bind_method(D_METHOD("add", "value"), &JustATestClass::add);
	ClassDB::bind_method(D_METHOD("reset"), &JustATestClass::reset);
	ClassDB::bind_method(D_METHOD("get_total"), &JustATestClass::get_total);
}

JustATestClass::JustATestClass() {
	count = 0;
}
