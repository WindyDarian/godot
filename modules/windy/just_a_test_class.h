#pragma once

#include "core/reference.h"

class JustATestClass : public Reference {
	GDCLASS(JustATestClass, Reference);

	int count;

protected:
	static void _bind_methods();

public:
	void add(int value);
	void reset();
	int get_total() const;

	JustATestClass();
};
