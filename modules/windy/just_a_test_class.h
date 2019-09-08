// Copyright (c) 2019 Windy Darian, all rights reserved.
// A random class!?

#pragma once

#include "core/reference.h"
#include "core/math/quat.h"

class JustATestClass : public Reference {
	GDCLASS(JustATestClass, Reference);

	int count;

protected:
	static void _bind_methods();

public:
	void add(int value);
	void reset();
	int get_total() const;
	int get_one();
	Quat get_quat_inverse(const Quat &quat);  // Appearantly it will fail if passing value

	JustATestClass();
};
