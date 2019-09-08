// Copyright (c) 2019 Windy Darian, all rights reserved.
// A random class!?

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
	ClassDB::bind_method(D_METHOD("get_one"), &JustATestClass::get_one);
	ClassDB::bind_method(D_METHOD("get_quat_inverse", "quat"), &JustATestClass::get_quat_inverse);
}

int JustATestClass::get_one() {
	return 1;
}

JustATestClass::JustATestClass() {
	count = 0;
}

Quat JustATestClass::get_quat_inverse(const Quat &quat) {
	return quat.inverse();
}
