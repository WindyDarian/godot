// Copyright (c) 2019 Windy Darian, all rights reserved.
// Custom script library for things.

#include "w.lib.h"

_W* _W::singleton = nullptr;

static void _spatial_set_rotation_quat(Spatial *spatial, const Quat &quat)
{
	ERR_FAIL_NULL(spatial);
	Transform transform = spatial->get_transform();  // TODO: can I avoid copying here???
	Vector3 original_scale(transform.basis.get_scale());
	transform.set_basis(Basis(quat, original_scale));
	spatial->set_transform(transform);
}
void _W::spatial_set_rotation_quat(Node *spatial, const Quat &quat) const   // Note: Spatial doesn't have conversion to Variant...
{
	_spatial_set_rotation_quat(Object::cast_to<Spatial>(spatial), quat);
}

static Quat _spatial_get_rotation_quat(const Spatial *spatial)
{
	ERR_FAIL_NULL_V(spatial, Quat());
	return spatial->get_transform().basis.get_rotation_quat();
}

Quat _W::spatial_get_rotation_quat(const Node *spatial) const
{
	return _spatial_get_rotation_quat(Object::cast_to<Spatial>(spatial));
}

void _W::_bind_methods() {
	ClassDB::bind_method(D_METHOD("spatial_set_rotation_quat", "spatial", "quat"), &_W::spatial_set_rotation_quat);
	ClassDB::bind_method(D_METHOD("spatial_get_rotation_quat", "spatial"), &_W::spatial_get_rotation_quat);
}

_W::_W()
{
	_W::singleton = this;
}
