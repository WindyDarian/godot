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
	/** Get local rotation of a spatial node as a quaternion. */
	Quat spatial_get_rotation_quat(const Node* spatial) const;
	/** Set local rotation of a spatial node from a quaternion. This will reset local scale to one. */
	void spatial_set_rotation_quat(Node* spatial, const Quat& rotation) const;
	/** Set local rotation of a spatial node from a quaternion. This will keep local scale. */
	void spatial_set_rotation_quat_keep_scale(Node* spatial, const Quat& rotation) const;

	static _W* get_singleton() {return singleton;};
	_W();
};
