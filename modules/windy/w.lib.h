// Copyright (c) 2019 Windy Darian, all rights reserved.
// Custom script library for things.

#pragma once

#include "core/object.h"
#include "core/math/quat.h"
#include "scene/3d/spatial.h"

class _W : public Object {
	GDCLASS(_W, Object);
	static _W* singleton;

protected:
	static void _bind_methods();

public:
	Quat spatial_get_rotation_quat(const Node* spatial) const;
	void spatial_set_rotation_quat(Node* spatial, const Quat& rotation_quat) const;

	static _W* get_singleton() {return singleton;};
	_W();
};
